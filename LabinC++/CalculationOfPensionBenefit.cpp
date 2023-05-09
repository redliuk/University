#include <iostream>
#include<math.h>
#include<cstring>

using namespace std;

bool sesso;

float FattoreSconto(int, int, float);
double ValoreAttualeRendita(int, float);
bool controlloCarattere(string, bool&);
double PassivitAttuariale(float, int, int, float);
float ValoreRenditaTemporale(int, float);
float BStar(float, int, float);

int main()
{
    int etaIngresso, etaUscita, etaPensione, etaAttuale, anniLavoro, anno;
    float beneficio, tasso, B, Ay, NC, VAB, quotaBenefit, RetAnnua;
    float variabileAccessoria1, variabileAccessoria2;
    string carattere;
    char e;
    
    cout<<"inserire i seguenti valori\n";
    cout<<"età di ingresso in azienda:\n";
    cin >> etaIngresso;
    cout<<"età di pensionamento:\n";
    cin >> etaPensione;
    cout<<"età corrente:\n";
    cin >> etaAttuale;
    cout<<"contributi corrisposti in un singolo anno:\n";
    cin >> beneficio;
    cout<<"tasso di valutazione:\n";
    cin >> tasso;
    cout<<"digitare m oppure f a seconda del sesso:\n";
    cin >> carattere;
    while (!controlloCarattere(carattere, sesso)) {
        cout<<"digitare m oppure f a seconda del sesso:\n";
        cin >> carattere;
    }
    
    //variabili di prova per evitare l'inserimento
    /*etaIngresso=29;
    etaPensione=68;
    etaAttuale=39;
    beneficio=5000;
    tasso=0.06;
    sesso=true;
    RetAnnua=10000;
    quotaBenefit=0.0736;*/
    
    anniLavoro=etaAttuale-etaIngresso;
    
    B=(anniLavoro)*beneficio;
    cout<<"Secondo il metodo FLAT BENEFIT l'accrued benefit risulta: " <<B <<endl;
    
    Ay=ValoreAttualeRendita(etaPensione, tasso);
    cout<<"ValoreAttualeRendita--> " <<Ay <<endl;
    
    NC=FattoreSconto(etaPensione-etaIngresso, etaIngresso, tasso)*B*Ay;
    cout<<"Il Costo Normale tramite metodo di accantonamento iniziale: " <<NC <<endl;
    
    for(int i=1; i<=anniLavoro; i++){
        float plot[anniLavoro];
        VAB=PassivitAttuariale(NC, i, etaIngresso, tasso);
        plot[i-1]=VAB;
        cout<<"Passività Attuariale anno " <<i <<": " <<VAB <<endl;
    }
    cout <<"\nOra procediamo al calcolo tramite Metodo dell'Unità di Credito Proiettata\n";
    cout <<"Inserire i seguenti valori, Retribuzione annua:\n";
    cin >>RetAnnua;
    cout <<"Quota di Retribuzione annua destinata alla composizione dell'accrued benefit:\n";
    cin >>quotaBenefit;
    
    while(e!='e'){
        cout <<"inserire l'età del dipendente per la quale calcolare NC e VAB:" <<endl;
        cin >>anno;
        B=(anno-etaIngresso)*beneficio;
        variabileAccessoria1=ValoreRenditaTemporale(etaPensione-anno, tasso);
        variabileAccessoria2=FattoreSconto(etaPensione-anno, anno, tasso);
        NC=(B+quotaBenefit*RetAnnua*variabileAccessoria1*Ay*variabileAccessoria2)/(etaPensione-etaIngresso);
        cout <<"Costo Normale tramite metodo PUC rispetto all'età " <<anno <<" della testa interessata: " <<NC <<endl;
        VAB=(anno-etaIngresso)*NC;
        cout <<"\nPassività attuariale tramite metodo PUC rispetto all'età " <<anno <<" della testa interessata: " <<VAB <<endl;
        cout <<"Per uscire premere 'e'" <<endl;
        cout <<"altrimenti, per ripetere il calcolo rispetto ad un'altra età di riferimento, selezionare un altro tasto\n";
        cin >>e;
    }
}

float FattoreSconto(int annoInteresse1, int annoInteresse2, float tasso){
    float x, y, E;
    float power;
    int lm[120]={100000, 99734, 99713, 99697, 99686, 99677, 99670, 99663, 99656, 99649, 99642, 99635, 99628, 99620, 99611, 99599, 99583, 99563, 99537, 99507, 99473, 99437, 99400, 99361, 99322, 99281, 99240, 99196, 99150, 99103, 99057, 99009, 98958, 98904, 98848, 98788, 98726, 98658, 98586, 98508, 98422, 98327, 98221, 98103, 97972, 97828, 97676, 97512, 97334, 97138, 96916, 96667, 96389, 96079, 95741, 95368, 94956, 94512, 94020, 93481, 92889, 92228, 91497, 90697, 89813, 88849, 87805, 86669, 85431, 84078, 82612, 81009, 79296, 77448, 75483, 73354, 71043, 68510, 65809, 62884, 59787, 56523, 53116, 49627, 45986, 42156, 38106, 33943, 29744, 25594, 21585, 17844, 14415, 11386, 8773, 6573, 4767, 3363, 2303, 1528, 978, 596, 341, 184, 93, 44, 19, 8, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0,0,0};
    int lf[120]={100000, 99767, 99751, 99740, 99731, 99724, 99717, 99711, 99706, 99699, 99693, 99686, 99679, 99672, 99665, 99656, 99647, 99635, 99623, 99609, 99595, 99582, 99569, 99555, 99542, 99526, 99510, 99492, 99474, 99454, 99434, 99412, 99389, 99364, 99336, 99306, 99273, 99236, 99196, 99150, 99101, 99045, 98982, 98912, 98836, 98751, 98658, 98556, 98444, 98324, 98190, 98041, 97875, 97689, 97487, 97267, 97031, 96780, 96502, 96195, 95858, 95488, 95082, 94637, 94151, 93623, 93046, 92416, 91719, 90946, 90109, 89181, 88154, 87006, 85783, 84460, 82999, 81348, 79509, 77403, 75100, 72579, 69807, 66811, 63498, 59818, 55778, 51405, 46790, 41932, 36958, 32045, 27226, 22666, 18423, 14582, 11227, 8433, 6150, 4337, 2941, 1905, 1170, 682, 376, 194, 94, 43, 18, 7, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, };

    if (sesso){
        x=lm[annoInteresse2+annoInteresse1];
        y=lm[annoInteresse2];
        power=pow((tasso+1),(-annoInteresse1));
        E=power*(x/y);
        return(E);
    } else {
        x=lf[annoInteresse2+annoInteresse1];
        y=lf[annoInteresse2];
        power=pow((tasso+1),(-annoInteresse1));
        E=power*(x/y);
        return(E);
    }
}

double ValoreAttualeRendita(int etaPensione, float tasso){
    double A, E;
    A=0;
    for(int i=0; i<=119-etaPensione; i++){
        E=FattoreSconto(i, etaPensione, tasso);
        A+=E;
    }
    return(A);
}

bool controlloCarattere(string c, bool &sesso){
    if(c=="m"){
        sesso=true;
        return true;
    }
    if(c=="f"){
        sesso=false;
        return true;
    }
    cout <<"inserimento sesso non riconosciuto\n";
    return false;
}

double PassivitAttuariale(float NC, int annoInteresse, int etaIngresso, float tasso){
    
    double FattoreScontoInverso=1/FattoreSconto(annoInteresse, etaIngresso, tasso);
    return(FattoreScontoInverso*NC);
}

float BStar(float accruedBen, float quotaBenefit, int RetAnnua, float SommatoriaFatSconto){
    float BStar=accruedBen*quotaBenefit*RetAnnua*SommatoriaFatSconto;
    return(BStar);
}

float ValoreRenditaTemporale(int annofin, float tasso){
    float S=0;
    for(int i=0; i<=annofin; i++) {
        S=S+FattoreSconto(i, annofin, tasso);
    }
    return(S);
}

