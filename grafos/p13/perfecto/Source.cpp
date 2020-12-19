// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

// El problema se ha resuelto usando  la clase SerpientesEscaleras,  
// con un nuevo método que devuelve el numero minimo de tiradas  (previamente calculado en el constructor de la clase).


#include <iostream>
#include <string>
#include "serpientesEscaleras.h"
#include "TreeMap_RB.h"
using namespace std;



TreeMap <size_t, size_t> leerDatos(size_t  S, size_t E)
{
	size_t  origen, destino;
	TreeMap <size_t, size_t> map;



	// insertamos las serpientes y las escaleras en el mapa
	for (size_t i = 0; i < S + E; i++)
	{
		cin >> origen;
		cin >> destino;
		map.insert(origen, destino);
	}

	return map;
}

// resuelve un caso de prueva

bool resuelveCaso(){

	 //leer grafo
	size_t N,K,S,E,V;
	TreeMap <size_t, size_t> map;

	cin >> N;		// dimension del tablero
	cin >> K;	    // numero de caras
	cin >> S;		// numero de serpientes
	cin >> E;		// numero de escaleras

	if (N== 0 && K == 0 && S == 0 && E == 0){
		return false;
	}

	map = leerDatos(S, E);

	//numero de vertices
	V = N*N;
										   // E = V*K  (numero de aristas * numero de caras del dado)
	serpientesEscaleras SE(V+1 , map,K);  // O(V + E ) donde V es el numero de vertices y E numero de aristas

	// mostrar solucion
	cout <<SE.obtener_menor_numero_movimientos() << endl;


	return true;
}

int main(){

	// casos de prueba ilimitados
	while (resuelveCaso());

	return 0;
}