#include "Arborecencia.h"


Arborecencia::Arborecencia(GrafoDirigido const& G, size_t &raiz) : grado_de_entrada(G.V()), esAr(false), visitado(G.V(), false)
{
	size_t r = 0;
	size_t k = 0;
	

	obtener_grado_de_entrada(G);

	for (size_t i = 0; i < G.V(); i++){

		if (grado_de_entrada.at(i) == 0){

			r++; raiz = i;
		}
	}

	if (r == 1){

		k = 0;
		esAr = true;

		dfs_arborecencia(G, raiz, k);

		esAr = (esAr && k == G.V());
	}
	else {
		esAr = false;
	}
	
}

void  Arborecencia:: obtener_grado_de_entrada(GrafoDirigido const& g){
	

	// INICIALIZAR LISTA GRADOS A CERO
	for (size_t i = 0; i < g.V(); i++)
	{
		grado_de_entrada.push_back(0);

	}
	// RECORRER DESDE TODOS LOS VERTICES 
	for (size_t i = 0; i < g.V(); i++)
	{
		dfs_grado(g, i);
	}

}
void Arborecencia:: dfs_grado(GrafoDirigido const& G, size_t v){


	for (size_t w : G.adj(v)) {

		if (grado_de_entrada[w] == 0)
		{
			grado_de_entrada[w] += 1;

			dfs_grado(G, w);
		}
	}

}
void Arborecencia:: dfs_arborecencia(GrafoDirigido const& G, size_t v, size_t &k) {

	std :: vector<size_t> lista;
	size_t w;
	++k;

	visitado[v] = true;
	lista = G.adj(v);

	while (!lista.empty()){

		w = lista.back();
		lista.pop_back();

		if (visitado[w]){

			esAr = false;

		}
		else {
			dfs_arborecencia(G, w, k);
		}
	}

}

bool Arborecencia:: es_Arborecencia(){

	return  esAr;

}