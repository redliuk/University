import java.util.LinkedList;

public class Server {
	public static void main (String[]args) {
		
		ListaEventi lista=new ListaEventi();
		
		LinkedList <Evento>	eventi = new LinkedList<Evento>();
		
		eventi.add(new Evento(20, "circo"));
		eventi.add(new Evento(100, "partita"));
		eventi.add(new Evento(50, "corsa"));
		
		Admin admin1 = new Admin(lista, eventi);
		new Thread(admin1).start();

		Utente utente1 = new Utente(lista, "circo", 25);
		Utente utente2 = new Utente(lista, "partita", 25);
		Utente utente3 = new Utente(lista, "corsa", -25);
		Utente utente4 = new Utente(lista, "corsa", 60);
		new Thread(utente1).start();
		new Thread(utente2).start();
		new Thread(utente3).start();
		new Thread(utente4).start();
		
	}

}
