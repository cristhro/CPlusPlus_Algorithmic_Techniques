#include "GrafoDirigido.h"

class Arborecencia
{
public:
	/* Constructor */
	Arborecencia(GrafoDirigido const& G, size_t &raiz);
	bool es_Arborecencia();

private:
	/*Atributos*/
	std :: vector<size_t> grado_de_entrada;
	std::vector<bool> visitado;
	bool esAr;

	/*Funciones*/
	void dfs_grado(GrafoDirigido const& G, size_t v);
	void obtener_grado_de_entrada(GrafoDirigido const& g);
	void dfs_arborecencia(GrafoDirigido const& G, size_t v, size_t &k);
};

