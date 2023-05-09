package Server;
import java.util.concurrent.ConcurrentHashMap;

public class ListaEventi {

   ConcurrentHashMap<String, Evento> lista;
   
  public ListaEventi(){
    lista=new ConcurrentHashMap<String, Evento>();
  }
  
  public synchronized void crea(Evento e) {
    if(e.numeroPosti<0) {
      System.out.println("Errore: numero posti negativo");
      return;
      }
        lista.putIfAbsent(e.nomeEvento, e);
        notifyAll();
  }
  
  public synchronized void Aggiungi(String s, int n) {
    if(n<=0) {
      System.out.println("Errore: numero posti negativo");
      return;
      }
    Evento e = lista.get(s);
    e.numeroPosti+=n;
    lista.put(s, e);
    notifyAll();
  }
  
  public String Controllo(String s, int n) {
	  Evento e ;
	  e=lista.get(s);
	  String message = "";
	  if(n<=0) {
		  message=("Errore: numero posti negativo");
		  return message;
	  }
	  if(e==null) {
		  message=("Evento non ancora creato: attendere");
		  return message;
	  }
	  if(e.numeroPosti<n) {
		  message=("Numero posti insufficente: attendere");
		  return message;
	  }
	  return message;
  }
  
  public synchronized void Prenota(String s, int n) {
    Evento e = new Evento(n, s);
    e=lista.get(s);
    while(e==null) {
      try {
        wait();
      } catch (InterruptedException e1) {
        e1.printStackTrace();
      }
    e=lista.get(s);
    }
    if(n<=0) {
      return;
      }
    while(e.numeroPosti<n && lista.containsValue(e)) {
      try {
        wait();
      } catch (InterruptedException e1) {
        e1.printStackTrace();
      }
    }
    e.numeroPosti-=n;
    lista.put(s, e);
  }
  
  public String listaEventi() {
	String a = "Eventi in programma:";
    for (Evento value : lista.values()) {
    	a+=( " | " + value.nomeEvento + " " + value.numeroPosti);
    }
    return a;
  }

  public synchronized void chiudiEvento(String s) {
    lista.remove(s);
    notifyAll();
  }
}