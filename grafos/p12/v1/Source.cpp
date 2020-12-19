// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 10: Arboles libres
				-----------------------------
		
*/
#include <iostream>
#include <string>
#include "Grafo.h"
#include<fstream>

using namespace std;


/*
	Funcion ###

	Complejidad O(n + m);
*/
void dfs_arborecencia(Grafo const& G, size_t v, size_t &k, bool *visitado, bool &arb) {

	 vector<size_t> lista;
	 size_t w ;
	 ++k;

	visitado[v] = true;
	lista = G.adj(v);

	while (!lista.empty()){

		w = lista.back();
		lista.pop_back();

		if (visitado[w]){

			arb = false;
		}
		else {
			dfs_arborecencia(G, w, k, visitado, arb);
		}
	}
	
}
/*
	Funcion ###

	Complejidad O(n + m);
*/
bool es_Arborecencia(Grafo G, size_t &raiz){

	size_t r = 0; 
	size_t k = 0;
	size_t *grado_de_entrada = new size_t[G.V()];
	
	bool *visitado = new bool[G.V()];
	bool b = false;
	// ### FALTA CODIGO obtener_grado_de entrada
	/*
		grado_de_entrada  = obtener_grados_de_entradas(G);
	*/
	for (size_t i = 0; i < G.V(); i++){

		if (grado_de_entrada[i] == 0){

			r++; raiz = i;
		} 
	}

	if (r == 1){
		k = 0;
		b = true;

		// INICIALIZAMO VISITADO A FALSE
		for (size_t i = 0; i < G.V(); i++) visitado[i] = false;
		
		dfs_arborecencia(G, raiz, k, visitado, b);

		b = (b && k == G.V());	
	}
	else {
		b = false;
	}
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



void resuelveCaso(Grafo G){

	
	// Arbol Libre
	size_t raiz;
	bool ok =  es_Arborecencia(G,raiz);

	// Mostrar solucion
	if (ok) cout << "SI" << endl;
	else cout << "NO" << endl;
	;
}

// Leer de fichero
void leer_Grafo_Archivo(string file) {

	ifstream entrada(file);
	size_t e, _V;
	size_t v, w;

	if (entrada.fail())
		throw std::runtime_error("Error en fichero.");
	
	// PRIMER GRAFO
	entrada >> _V;
	entrada >> e;

	while (_V != -1){
		
			// grafo auxiliar
				Grafo aux(_V);

				for (size_t i = 0; i < e; ++i) {
					entrada >> v;
					entrada >> w;
					aux.ponArista(v, w);
				}
				entrada.clear();
				resuelveCaso(aux);

		// SIGUIENTE GRAFO 
				entrada >> _V;
				entrada >> e;
				
	}
	
	entrada.close();
}

int main(){

	const string fich = "prueba.txt";
	
	leer_Grafo_Archivo(fich);

	system("PAUSE");
	return 0;
}