// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 10: Arboles libres
				---------------------------------------------------

		Para resolver este ejercicio hemos creado una estructura auxiliar Paciente que guarda
		la gravedad y su nombre, obtenemos la lista de pacientes curados con la funcion Pacientes_curados()
		luego lo mostramos con la funcion muestra_lista().
*/
#include <iostream>
#include <string>
#include "Grafo.h"
using namespace std;

const int TAM= 6 ;


void dfs_Aristas(Grafo const& G, size_t v, int &k, int &a, int recorrido[]) {

	 vector<size_t> lista;

	int w ;
	++k;


	recorrido[v] = k;;

// NO DEVUELVE LISTA DE  ADYACENCIA
	lista = G.adj(v);

	while (!lista.empty()){

		w = lista.back();
		lista.pop_back();

		if (v <= w){
			a = a + 1;
		}
		if (recorrido[w] == 0){
			dfs_Aristas(G, w, k, a, recorrido);
		}
	}
	
}
bool es_Arbol_libre(Grafo G,  size_t v_){

	int k = 0; int a = 0;
	int recorrido[TAM];

	// INICIALIZAMOS A 0
	for (size_t i = 0; i < v_; i++)
	{
		recorrido[i] = 0;
	}

	dfs_Aristas(G, 1, k, a, recorrido);

	return ( (k == TAM) && a == TAM - 1);
}




void Grafo::ponArista(size_t v, size_t w) {
	if (v >= _V || w >= _V) throw std::invalid_argument("Vértice inexistente");
	++_E;
	_adj[v].push_back(w);
	_adj[w].push_back(v);
}

const Adys& Grafo::adj(size_t v) const {
	if (v >= _V) throw std::invalid_argument("Vértice inexistente");
	return _adj[v];
}

/**
* Muestra el grafo en el stream de salida o
*/
void Grafo::print(std::ostream & o) const {
	o << _V << " vértices, " << _E << " aristas\n";
	for (auto v = 0; v < _V; ++v) {
		o << v << ": ";
		for (auto w : _adj[v]) {
			o << w << " ";
		}
		o << "\n";
	}
}

std::ostream& operator<<(std::ostream & o, Grafo const& g){
	g.print(o);
	return o;
}

/**
* Recorrido en profundidad de un grafo a partir de un vértice origen.
*/


DepthFirstSearch::DepthFirstSearch(Grafo const& G, size_t s) : _count(0), _marked(G.V(), false) {
	dfs(G, s);
}

void DepthFirstSearch::dfs(Grafo const& G, size_t v) {
	++_count;
	_marked[v] = true;
	for (auto w : G.adj(v)) {
		if (!_marked[w]) {
			dfs(G, w);
		}
	}
}


DepthFirstPaths::DepthFirstPaths(Grafo const& G, size_t s) : marked(G.V(), false),
edgeTo(G.V()), s(s) {
	dfs(G, s);
}


// Devuelve un camino desde el origen a v (vacío si no están conectados).
Path DepthFirstPaths::pathTo(size_t v) const {
	Path path;
	if (!hasPathTo(v)) return path;
	for (auto x = v; x != s; x = edgeTo[x])
		path.push_front(x);
	path.push_front(s);
	return path;
}


// recorrido en profundidad desde v
void DepthFirstPaths::dfs(Grafo const& G, size_t v) {
	marked[v] = true;
	for (auto w : G.adj(v)) {
		if (!marked[w]) {
			edgeTo[w] = v;
			dfs(G, w);
		}
	}
}


/**
* Recorrido en anchura de un grafo a partir de un vértice origen.
* Permite recuperar los caminos más cortos desde el origen a todos los vértices alcanzables.
*/

BreadthFirstPaths::BreadthFirstPaths(Grafo const& G, size_t s)
	: marked(G.V(), false), edgeTo(G.V()), distTo(G.V()), s(s) {
	bfs(G, s);
}

// Devuelve el camino más corto desde el origen a v (vacío si no están conectados).
Path BreadthFirstPaths::pathTo(size_t v) const {
	Path path;
	if (!hasPathTo(v)) return path;
	for (auto x = v; x != s; x = edgeTo[x])
		path.push_front(x);
	path.push_front(s);
	return path;
}


void BreadthFirstPaths::bfs(Grafo const& G, size_t s) {
	std::queue<size_t> q;
	distTo[s] = 0;
	marked[s] = true;
	q.push(s);
	while (!q.empty()) {
		auto v = q.front(); q.pop();
		for (auto w : G.adj(v)) {
			if (!marked[w]) {
				edgeTo[w] = v;
				distTo[w] = distTo[v] + 1;
				marked[w] = true;
				q.push(w);
			}
		}
	}
}


/**
* Componentes conexas de un grafo.
*/

ComponentesConexas::ComponentesConexas(Grafo const& G) : marked(G.V(), false), _id(G.V()),
_size(G.V(), 0), _count(0) {
	for (auto v = 0; v < G.V(); ++v) {
		if (!marked[v]) { // se recorre una nueva componente conexa
			dfs(G, v);
			++_count;
		}
	}
}


// recorrido en profundidad de la componente de v
void ComponentesConexas::dfs(Grafo const& G, size_t v) {
	marked[v] = true;
	_id[v] = _count;
	++_size[_count];
	for (auto w : G.adj(v)) {
		if (!marked[w]) {
			dfs(G, w);
		}
	}
}


/*
	Funcion estandar que lee un grafo
*/
Grafo leer_Grafo(size_t v_, size_t e){

	Grafo g(v_);
	size_t v, w;
	
	for (size_t i = 0; i < e; i++)
	{
		cin	 >> v;
		cin  >> w;
		g.ponArista(v, w);
	}
	return g;
}



void resuelveCaso(size_t v_ , size_t e){

	// leer grafo
	Grafo G = leer_Grafo(v_,e);

	G.print();

	bool ok =  es_Arbol_libre(G,v_);

	if (ok) cout << "SI" << endl;
	else cout << "NO" << endl;
	;
}

int main(){
	size_t v;
	size_t e;

	cin >> v;
	cin >> e;

	

	while (v != 0)
	{
		resuelveCaso(v,e);
		cin >> v;
		cin >> e;
	}

	return 0;
}