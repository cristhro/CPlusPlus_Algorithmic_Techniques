// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 12: Arborecencia
				-------------------------
		
*/
#include <iostream>
#include <string>
#include "GrafoDirigido.h"
#include<fstream>

using namespace std;



void dfs_grado(GrafoDirigido const& G, size_t v, std::vector<size_t>  &lista_grados, vector<bool> &marked){
	marked[v] = true;
	// recorre la lista de adyacencia

	for (size_t w : G.adj(v)) {

		if (!marked[w]) {

			lista_grados[w] += 1;

			
			dfs_grado(G, w, lista_grados, marked);
		}
	}

}
vector<size_t> obtener_grado_de_entrada(GrafoDirigido const& g) {
	vector<bool> marked;     // marked[v] = hay camino s-v?

	vector<size_t> lista_grados;

	// INICIALIZAR LISTA GRADOS A CERO
	for (size_t i = 0; i < g.V(); i++)
	{
		bool a = false;
		lista_grados.push_back(0);
		marked.push_back(a);

	}
	// RECORRER DESDE TODOS LOS VERTICES ## CORREGIR
	//for (size_t i = 0; i < g.V(); i++)
	//{
		dfs_grado(g, 0, lista_grados, marked);
	
	//}
	

	return lista_grados;
}

void dfs_arborecencia(GrafoDirigido const& G, size_t v, size_t &k, bool *visitado, bool &arb) {

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
bool es_Arborecencia(GrafoDirigido const& G, size_t &raiz){

	size_t r = 0; 
	size_t k = 0;
	vector<size_t> grado_de_entrada;


	

	bool *visitado = new bool[G.V()];
	bool b = false;

	grado_de_entrada = obtener_grado_de_entrada(G);
		
	
	for (size_t i = 0; i < G.V(); i++){

		if (grado_de_entrada.at(i)== 0){

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
	return b;
}




/*
*	Funcion estandar que lee un grafo
*/
GrafoDirigido leer_Grafo(size_t V){  

	size_t E;
	cin >> E;

	GrafoDirigido g(V);
	size_t v, w;

	for (size_t i = 0; i < E; i++)
	{
		cin >> v;
		cin >> w;
		g.ponArista(v, w);
	}
	
	return g;
}

bool resuelveCaso(){

	
	size_t V, raiz = 0;
	cin >> V;

	if (!cin){
		return false;
	}
	// leer grafo
	GrafoDirigido G = leer_Grafo(V);

	bool ok = es_Arborecencia(G, raiz);

	 //Mostrar solucion
	if (ok) cout << "SI " << raiz<<  endl;
	else cout << "NO" << endl;

	return true;

}

int main(){

	while (resuelveCaso());

	return 0;
}