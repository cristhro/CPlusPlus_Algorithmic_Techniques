#include "Arborecencia.h"


Arborecencia::Arborecencia(GrafoDirigido const& G, size_t &raiz) : esAr(false), visitado(G.V(), false)
{
	size_t r = 0;
	size_t k = 0;

	GrafoDirigido g2(G.V());

	//invertimos el grafo 
	g2 = G.reverse();

	for (size_t i = 0; i < G.V(); i++){

		g2.adj(i).size();
			if (g2.adj(i).size() == 0){

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