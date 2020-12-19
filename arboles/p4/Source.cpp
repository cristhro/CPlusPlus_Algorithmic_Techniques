// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 4: ENCONTRAR EL K- ESIMO ELEMENTO EN UN ARBOL AVL
	
	Construye un arbol a partir de la funcion isertar del tad luego calcula el k_esimo

	Para resolver el problema hemos modificado el tad treemap_avl
	y le hemos añadido una funcion que se encargara de buscar el elemento k_esimo.
	

*/
#include <math.h>
#include <algorithm>
#include "TreeMap_Modificado.h"
#include "Exceptions.h"

using namespace std;

TreeMap_Modificado<int, int>leeArbol(const int n);
void resuelveCaso(int n);

int main() {

	int n;
	cin >> n;

	while (n != 0) {

		resuelveCaso(n);
		cout << "----" << endl;
		cin >> n;
	}
	return 0;
}
/*
*	lee un arbol de busqueda mediante el metodo insertar del tad Treemap_modificado
*/
TreeMap_Modificado<int, int> leeArbol(const int n)
{
	TreeMap_Modificado<int, int> arbol;
	
	int clave = 0;
	int i = 1;
	
	 cin >> clave;
	 arbol.insert(clave, 0);
	
	 while (i < n){

		 cin >> clave;
		 arbol.insert(clave, 0);
	
		 i++;
	 }

	return arbol;
}
// Resuelve el caso de prueba leyendo la entrada, la configuracion 
// y escribiendo la respuesta
void resuelveCaso(int n ){
	
	TreeMap_Modificado<int, int> arbol;
	
	// LEER ARBOL 
	arbol = leeArbol(n);
	int sol;

	// LEER M
	int m = 0;
	cin >>m ;

	// ELEMENTO K
	int k;
	int i = 0;

	while (i < m) {

		//SIGUIENTE ELEMENTO K
		cin >> k;

		try
		{	//CALCULAR K_ESIMO
			 sol = arbol.k_esimo(k);

			//MOSTRAR PRIMER ELEMENTO K
			cout << sol << endl;
		}
		catch (NotExistException)
		{
			cout << "??" << endl;
		}
		i++;
	}
}
