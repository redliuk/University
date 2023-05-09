
import java.util.concurrent.*;

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
	
	public synchronized void Prenota(String s, int n) {
		boolean stampato=false;
		Evento e = new Evento(n, s);
		e=lista.get(s);
		while(e==null) {
			if(!stampato) {
				System.out.println("Evento non ancora creato: attendo");
				stampato=true;
			}
			try {
				wait();
			} catch (InterruptedException e1) {
				e1.printStackTrace();
			}
		e=lista.get(s);
		}
		stampato=false;
		if(n<=0 || e==null) {
			System.out.println("Errore: numero posti negativo");
			return;
			}
		while(e.numeroPosti<n && lista.containsValue(e)) {
			if(!stampato) {
				System.out.println("Errore: numero posti insufficente: attendo");
				stampato=true;
			}
			try {
				wait();
			} catch (InterruptedException e1) {
				e1.printStackTrace();
			}
		}
		e.numeroPosti-=n;
		lista.put(s, e);
	}
	
	public void listaEventi() {
		System.out.println("A seguire gli eventi in programma:");
		lista.forEach( (k, v) -> System.out.println(v.nomeEvento + " " + v.numeroPosti));
	}

	public synchronized void chiudiEvento(String s) {
		lista.remove(s);
		notifyAll();
	}
}