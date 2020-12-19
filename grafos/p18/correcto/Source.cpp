// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

// El problema se ha resuelto usando  la clase RepartiendoPaquetes,  
// un nuevo método que devuelve si un arbol es libre (previamente calculado en el constructor de la clase).
// claves dadas.

#include <iostream>
#include <string>
#include "GrafoValorado.h"
#include "dijkstra.h"
#include <limits>
using namespace std;



// lectura estandar de un grafo por consola
GrafoValorado<double> leer_Grafo(size_t V)
{
	size_t e;
	cin >> e;
	 
	GrafoValorado<double> g(V);
	
	size_t v, w, valor;

	for (size_t i = 0; i < e; i++)
	{
	
		cin >> v;
		cin >> w;
		cin >> valor;

		g.ponArista(Arista<double>(v, w, valor));
	}
	return g;
}


// resuelve un caso de prueva
bool resuelveCaso(){

	// leer grafo
	size_t v;
	cin >> v;

	if (!cin){
		return false;
	}

	GrafoValorado<double> G = leer_Grafo(v+1);			// O( e + v ) donde n es el numero de vertices del grafo.
	
	dijkstra a(G,1);

	cout << a.caminosCortos() << endl;
	//
	//int oficina;
	//cin >> oficina;					// leemos la oficina
	//
	//int num_Paquetes;	
	//cin >> num_Paquetes;			// leemos numero de paquetes
	//
	//vector<int> casas_destino;								

	//for (size_t i = 0; i < num_Paquetes; i++)				
	//{
	//	int a; cin >> a; casas_destino.push_back(a);
	//}

	//// calcula el esfuerzo desde la oficina a las demas casas 
	//RepartiendoPaquetes Ida(G, oficina);
	//vector<double> esfuerzo_Ida;
	//esfuerzo_Ida = Ida.oficina_to_Home();

	//// Invertimos el grafo
	//GrafoValorado<double> G2 =	G.reverse();

	//// calcula el esfuerzo desde la oficina a las demas casas en sentido contrario
	//RepartiendoPaquetes Vuelta(G2, oficina);
	//vector<double> esfuerzo_vuelta;	
	//esfuerzo_vuelta = Vuelta.oficina_to_Home();

	//
	//bool imposible = false;
	//int solucion = 0;
	//// Calcular esfuerzo Total de todas las casas visitadas
	//for (size_t i = 0; i < casas_destino.size() && !imposible; i++)
	//{
	//	solucion += esfuerzo_Ida[casas_destino.at(i)] + esfuerzo_vuelta[casas_destino.at(i)];
	//	
	//	// si una casa no ha sido visitada
	//	if ((esfuerzo_Ida[casas_destino.at(i)] == numeric_limits<double>::infinity()) ||
	//		(esfuerzo_vuelta[casas_destino.at(i)] == numeric_limits<double>::infinity())){
	//		
	//		imposible = true;
	//	}
	//}

	////Mostrar solucion
	//if (imposible) {
	//	cout << "Imposible" << endl;
	//}
	//else{
	//	cout << solucion << endl;
	//}
	
	return true;

}

int main(){

	// casos de prueba ilimitados
	while (resuelveCaso());

	return 0;
}