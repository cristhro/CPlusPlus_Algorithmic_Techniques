// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 5: Referencias Cruzadas
	--------------------------------

*/

#include <iostream>
#include "TreeMap_RB.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/*
*	Procedimiento que muestra por pantalla La lista de palabras ordenadas,
	cada palabra con su respectiva lista de enteros.
*	Complejidad: O(n^2)
*/
void muestraTreeMapLista( TreeMap <string, vector<int> > &mapa){

	TreeMap <string, vector<int>>:: Iterator itMap = mapa.begin();

	while (itMap != mapa.end()){

		cout << itMap.clave() << " ";
		vector<int> lista = itMap.valor();

		for (size_t i = 0; i < lista.size(); i++)
		{
			cout << lista.at(i);
			if (i < lista.size() -1 )
			 cout << " "; 
		}
		cout << endl;
		itMap.operator++();
	}
}
/*
* Funcion que se encarga de leer las lineas de string
*
*/

 void Referenciascruzadas(int n, TreeMap<string, vector<int>> &lista_Sol) {


	string linea;
	int num_Linea = 1; 
	int i;
	string palabra;
		cin.get();
		while (num_Linea <= n) {

			getline(cin, linea); // Lee siguiente linea
			i = 0;
			while (i <= linea.size()) {

				if (isalpha(linea[i]) || (isalnum(linea[i]))) {		//mientras sea una letra o un numero

					palabra.push_back(tolower(linea[i]));

				}
				else {
					if (palabra.size() > 2) {
						// si la palabra esta en la Tabla

						if (lista_Sol.contains(palabra)){
							vector<int> listAux = lista_Sol.at(palabra);

							// ultimo elemento lista entero es igual que la linea
							if (listAux.back() != num_Linea){
								listAux.push_back(num_Linea);
								lista_Sol.insert(palabra, listAux);
							}

						}
						else{
							vector<int> listAux;
							listAux.push_back(num_Linea);
							lista_Sol.insert(palabra, listAux);

						}



					}
					palabra.clear();

				}
				i++;
			}

			num_Linea++;		
		}
}
void resuelveCaso(int numCasos){
	

	TreeMap<string, vector<int>> solucion;

	// Lee y 
	Referenciascruzadas(numCasos, solucion);
	
	// Muestra solucion
	muestraTreeMapLista(solucion);
	cout << "----" << endl;
}

int main(){

	int num_Casos ;
	cin >> num_Casos;

	while ( num_Casos != 0){

		resuelveCaso(num_Casos);
		cin >> num_Casos;
	}
	return 0;

}

