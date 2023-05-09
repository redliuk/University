import java.util.LinkedList;

public class Admin implements Runnable {

	ListaEventi lista;
	LinkedList <Evento>	eventi;
	
	public Admin(ListaEventi l, LinkedList <Evento> e) {
		this.lista=l;
		this.eventi=e;
	}
	
	@Override
	public void run() {
		
		for(int i=0; i<eventi.size() ; i++) {
			System.out.println("Creo l'evento " + eventi.get(i).getNome() + " con " + eventi.get(i).getPosti() + " posti");
			lista.crea(eventi.get(i));
		}
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e1) {
			e1.printStackTrace();
		}
		
		System.out.println("Aggiungo 10 posti all'evento corsa");
		lista.Aggiungi("corsa", 10);
		System.out.println("Aggiungo 5 posti all'evento circo");
		lista.Aggiungi("circo", 5);
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e1) {
			e1.printStackTrace();
		}
		
		lista.listaEventi();
		
		System.out.println("Chiudo l'evento partita");
		lista.chiudiEvento("partita");
		System.out.println("Chiudo l'evento circo");
		lista.chiudiEvento("circo");
		
		lista.listaEventi();
		
	}

}
