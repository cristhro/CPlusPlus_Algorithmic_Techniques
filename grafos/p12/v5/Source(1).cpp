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


/*
	Funcion que ejecuta una busqueda de profundidad en el Grafo dirijido G buscando el grado de entrada del vertice v.
	Para saber el grado de entrada de un vertice bastara con contar si el vertice aparece en la lista de adyacentes de alguno de los vertices.

	Complejidad O(n + m) segun del numero de vertices y de aristas
*/
void dfs_grado(GrafoDirigido const& G, size_t v, std::vector<size_t>  &lista_grados, vector<bool> &marked){
	
	

	for (size_t w : G.adj(v)) {

		if(lista_grados[w] == 0)
		{
			lista_grados[w] += 1;

			dfs_grado(G, w, lista_grados, marked);
		}
	}

}

/*
Funcion que busca el grado de entrada  de todos los vertices, 
Usara la funcion dfs_grado para realizar la busqueda en cada uno de los vertices

Complejidad O(n^2) segun del numero de vertices 
*/
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
	// RECORRER DESDE TODOS LOS VERTICES 
	for (size_t i = 0; i < g.V(); i++)
	{
		dfs_grado(g,i, lista_grados, marked);
	}

	return lista_grados;
}

/*
	Funcion que realiza una busqueda en profundidad desde el vertice v.
	devuelve true si se han visitado todos los vertices si repetir.
	false en otro caso.

Complejidad O(n +  m) segun del numero de vertices

*/
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
Funcion que comprueba si un grafo es Arborecente.
Un grafo es arborecente  si existe el vertice desde el cual se puede alcanzar
cualquier otro veertice a traves de un camino unico. Es decir.
Dado una lista de grado de entrada existe solo un vertice cuyo grado de entrada sea cero.

Complejidad O(n^2) segun del numero de vertices

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