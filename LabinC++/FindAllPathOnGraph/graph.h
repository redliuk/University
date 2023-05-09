#include <sstream>
#include <fstream> 
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace CFG {

	typedef string Label;

	struct halfEdgeNode;
	typedef halfEdgeNode* Edge;

	struct vertexNode;
	typedef vertexNode* Graph;

	//lista contenete gli archi di adiacenza di un nodo
	struct halfEdgeNode {
		vertexNode* nodePtr;			//puntatore a nodo del grafo
		bool counted;					//marcatura per il conteggio degli archi
		halfEdgeNode* next;				//puntatore a elemento successivo della lista di adiacenza
	};

	//lista contenente i nodi del grafo
	struct vertexNode {
	    Label label;					//etichetta del nodo
	    halfEdgeNode* adjList;			//puntatore a lista di adiacenza
	    int numEdge;					//numero di archi associati al nodo
	    vertexNode* next;				//puntatore a elemento successivo della lista dei nodi
	    bool visited;					//marcatura della visita del nodo
	};

	const Graph emptyGraph=NULL;

	Graph CreateEmptyGraph();
	Graph CreateNewNode(const Label);
	void addVertex(Graph&, const Label);
	Edge CreateNewEdge();
	Graph SearchNode(const Graph&, const Label);
	void addEdge(Graph&, const Label, const Label);
	int contaArchi(Graph const &);
	Edge searchUnvisited(Edge const &);
	Label searchEnd(const Graph &);
	void clearEdge(Edge& );
	void clearGraph(Graph& );
	void clearMarkEdge(Edge &);
	void clearMark(Graph &);
	void readFromStream(Graph&, istream&);
	int findPath(Graph&, Graph&, float , Graph&);
	void findPathControll(const Label, const Label, const int, Graph&);
	void printAdjList(Edge, const Graph&);	//sviluppata per testing
	void printGraph(const Graph&);			//sviluppata per testing
}