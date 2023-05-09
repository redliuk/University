#include "graph.h"

CFG::Graph CFG::CreateEmptyGraph(){
	Graph g=new vertexNode;
	g=emptyGraph;
	return g;
}

CFG::Graph CFG::CreateNewNode(const Label l){
	Graph g= new vertexNode;
	g->label=l;
	g->next=emptyGraph;
	g->adjList=nullptr;
	g->numEdge=0;
	g->visited=false;
	return g;
}

CFG::Graph CFG::SearchNode(const Graph& g, const Label l){
	Graph tmp=g;
	while(tmp!=emptyGraph)					//scorro i nodi
	{
		if(tmp->label==l)	return tmp;		//cerco il nodo considerato e ne restituisco il puntatore
		tmp=tmp->next;
	}
	return emptyGraph;						//non trovandolo restituisco puntatore nullo
}

void CFG::addVertex(Graph& g, const Label l){
	Graph aux=SearchNode(g, l);
	if(aux!=emptyGraph)
	{
		cout <<"ERRORE: vertice già presente nel grafo\n";
		return;
	}
	aux=CreateNewNode(l);
	Graph tmp=g;
	if (tmp==emptyGraph){	g=aux;					//se il grafo è vuoto aggiungo in testa
	}	else	{
	while(tmp->next!=emptyGraph)	tmp=tmp->next;
	tmp->next=aux;
	}
}

CFG::Edge CFG::CreateNewEdge(){
	Edge e= new halfEdgeNode;
	e->nodePtr=emptyGraph;
	e->next=nullptr;
	e->counted=false;
	return e;
}

void CFG::addEdge(Graph& g,const Label l1, const Label l2){
	Graph node1=SearchNode(g, l1);				//cerco i nodi e ne salvo i puntatori
	Graph node2=SearchNode(g, l2);
	if(node1==emptyGraph || node2==emptyGraph){	//controllo se entrambi i nodi sono nel grafo
		cout <<"ERRORE: un nodo dell'arco non è presente nel grafo\n";
		return;									//altrimenti non continuo
	}
	Edge aux=CreateNewEdge();
	Edge tmp=node1->adjList;
	aux->nodePtr=node2;							//aggiungo il puntatore al nodo2
	if (tmp==nullptr){	node1->adjList=aux;		//se la lista è vuota aggiungo
	}	else	{
	while(tmp->next!=nullptr) tmp=tmp->next;	//altrimenti scorro la lista di adiacenaza del nodo1
	tmp->next=aux;								//quindi aggiungo
	}
	node1->numEdge++;							//incremento il numero di archi associato al nodo
}

int CFG::contaArchi(Graph const &g){
	Graph tmp=g;
	int archiTotali=0;
	while(tmp!=emptyGraph)						//scorro i nodi
	{
		archiTotali=archiTotali+tmp->numEdge;	//sommo il numero di archi associati al nodo
		tmp=tmp->next;
	}
	return archiTotali;							//restituisco il totale
}

CFG::Edge CFG::searchUnvisited(Edge const &e){
	Edge tmp=e;
	while(tmp->next!=nullptr){					//scorro tutta la lista di adiacenza
		if(tmp->counted==false)	return tmp;		//restituisco un?adiacenza libera se la trovo
		tmp=tmp->next;
	}
	return nullptr;								//restituisco nullptr altrimenti
}

CFG::Label CFG::searchEnd(const Graph &g){
	Graph tmp=g;
	while(tmp->next!=emptyGraph){	//scorro alla fine della lista dei nodi del grafo
		tmp=tmp->next;
	}
	return tmp->label;				//restituisco la labele del nodo finale
}

void CFG::clearEdge(Edge& e){
	Edge tmp=e;
	if (tmp==nullptr)	return;
	if(tmp->next!=nullptr)
	{
		clearEdge(tmp->next);
	}
	delete tmp;
	return;
}

void CFG::clearGraph(Graph& g){
	Graph tmp=g;
	if (tmp==nullptr)	return;
	if(tmp->next!=nullptr)
	{
		clearGraph(tmp->next);
	}
	clearEdge(tmp->adjList);
	delete(tmp);
	return;
}

void CFG::clearMarkEdge(Edge &e){
	Edge tmp=e;
	if(tmp==nullptr)	return;
	if(tmp->next!=nullptr)	clearMarkEdge(tmp->next);
	tmp->counted=false;
	return;
}

void CFG::clearMark(Graph &g){
	Graph tmp=g;
	if(tmp->next!=nullptr)
	{
		clearMark(tmp->next);
	}
	clearMarkEdge(tmp->adjList);
	tmp->visited=false;
	return;
}

void CFG::readFromStream(Graph& g, istream& str){
	bool first=true;
	Label lab, line;
	istringstream instream;	//variabile istringstream per scandire la riga
	getline(str, line);		//prendo la prima riga
	instream.clear();		//libero la variabile istringstream
    instream.str(line);		//vi inserisco la riga
    instream >> lab;		//estraggo il primo elemento della riga
	addVertex(g,lab);		//il primo elemento dello stream è sempre il primo nodo
	Graph tmp=g;
	while(!str.eof())		//finchè non finisco lo stream
	{
		getline(str, line);			//passo alla riga successiva
		instream.clear();
    	instream.str(line);	
		while(!instream.eof())		//finchè non trovo la fine della riga
		{
			instream >> lab;		//prendo un'elemento dalla riga
			if (first){				//se è il primo elemento della riga è un vertice
				if(SearchNode(g, lab)==emptyGraph) addVertex(g,lab);	//aggiungo il vertice
				first=false;		//pongo false perchè ho passato il primo elemento della riga
			} else {
			//cerco il nodo dell'adiacenza considerata
			if(SearchNode(g, lab)==emptyGraph)	addVertex(g, lab); //lo aggiungo se non c'è
			addEdge(g, tmp->label, lab);	//quindi aggiungo l'arco tra i 2 nodi
			}
		}
		tmp=tmp->next;	//finita la riga considero la lista di adiacenza del nodo sucessivo
		first=true;		//pongo true perchè sono a inizio riga
	}
}

int CFG::findPath(Graph& start,Graph& end, float archiVisitati,Graph& g) {
    cout <<start->label;				//stampo il nodo di partenza
    int random=0;
    Graph tmp=start;
    srand(time(NULL));						//inizzializzo la funzione rand
    while(tmp->label!=end->label)			//finchè non raggiungo il nodo finale
    {
    	cout <<"-";
    	Edge move=tmp->adjList;				//considero la lista di adiacenza del nodo
    	if(!tmp->visited)					//se il nodo non è ancora stato visitato
    	{
    		tmp->visited=true;				//lo marco
    		random=rand()%tmp->numEdge;		//scelgo una posizione random nella lista
    		for(int i=0; i<random; i++)
    		{
    			move=move->next;			//la raggiungo
    		}
    		if (!move->counted)				//se l'arco non è ancora stato visitato
    		{
    			archiVisitati++;			//segno che un nuovo arco è stato percorso
    			move->counted=true;			//marco l'adiacenza che sto considerando
    		}
    		tmp=move->nodePtr;			//passo al nodo adiacente
    		tmp->visited=true;			//lo marco
    		cout <<tmp->label;	//quindi ne stampo la label
    	}	
    	else
    	{
    		Edge controllo=searchUnvisited(move);
    		if(controllo!=nullptr)				//se c'è un adiacenza non ancora visitata
    		{
    			controllo->counted=true;		//marco l'adiacenza che sto considerando
    			tmp=controllo->nodePtr;			//procedo a visitare quel nodo adiacente
    			cout <<tmp->label;		//quindi ne stampo letichetta
    			archiVisitati++;				//segno che un nuovo arco è stato percorso
    		}	
    		else	//se non ci sono adiacenze inesplorate scelgo randomicamente	
    		{
    			random=rand()%tmp->numEdge;		//scelgo una posizione random nella lista
    			for(int i=0; i<random; i++)
    			{
    				move=move->next;			//la raggiungo
    			}
    			if (!move->counted)				//se l'arco non è ancora stato visitato
    			{
    				archiVisitati++;			//segno che un nuovo arco è stato percorso
    				move->counted=true;			//marco l'adiacenza che sto considerando
    			}
    			tmp=move->nodePtr;				//visito il primo nodo adiacente a quello considerato
    			cout <<tmp->label;		//quindi ne stampo letichetta
    		}
    	}
    }
    return archiVisitati;
}


void CFG::findPathControll(const Label v1, const Label v2,int buget, Graph& g) {
    float archiVisitati=0;
    float archiTotali=contaArchi(g);
    double appoggio;
    double Coverage;
	Graph from=SearchNode(g, v1);
	Graph to=SearchNode(g, v2);

	//controllo che il buget non sia zero
    if(buget==0)
    {
    	cout <<"buget zero!\n";
    	return;
	}
	// marco tutti i nodi ed archi come non visitati
	clearMark(g);

    //se partenza e arrivo concidono, oppure partenza e/o arrivo non esistono,finisce qui
    if (from == to || from == emptyGraph || to == emptyGraph)
    {
    	cout <<"errore di inserimento inizio o fine percorso\n";
        return;
    }

    //procedo a esplorare cammini finchè il buget lo concede 
    //oppure finchè non ho esplorato tutti gli archi del CFG
    while(archiVisitati!=archiTotali && buget>0)
    {
    	cout <<"cammino: ";
    	archiVisitati=findPath(from, to, archiVisitati, g);
    	buget--;
    	cout <<", Buget = " <<buget <<endl;
    }
    appoggio=archiVisitati/archiTotali;
    Coverage=appoggio*100;
    cout <<"Coverage raggiunta: " <<Coverage <<"%" <<endl;
    return;    
}

// Stampa la lista di adiacenza
void CFG::printAdjList(Edge e, const Graph& g) {
 if (e==nullptr) return;
 for (Edge n=e; n!=nullptr; n=n->next) {
    cout << n->nodePtr->label << " ";
  }
}

// Stampa il grafo
void CFG::printGraph(const Graph& g) {
	if(g==emptyGraph)
	{
		cout <<"nessun CFG ancora inserito\n";
		return;
	}
	cout << g->label <<endl;
  for (Graph v=g ; v!=emptyGraph; v=v->next) {
    cout << v->label <<" ";
    printAdjList(v->adjList, g);
    cout << endl;
  }
}