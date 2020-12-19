// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

// El problema se ha resuelto usando  la clase RepartiendoPaquetes,  
// con un nuevo método que devuelve el esfuerzo de un origen a todos sus posibles destinos.
// O (n + e*log v) donde n es el numero de paquetes, e numero de calles, v numero de casas .


#include <iostream>
#include <string>
#include "GrafoDirigidoValorado.h"
#include "RepartiendoPaquetes.h"
#include <limits>
using namespace std;



// lectura estandar de un grafo por consola
GrafoDirigidoValorado<double> leer_Grafo(size_t V)
{
	size_t num_Conexiones;
	cin >> num_Conexiones;
	 
	GrafoDirigidoValorado<double> g(V);
	
	size_t v, w, valor;

	for (size_t i = 0; i < num_Conexiones; i++)
	{
	
		cin >> v;
		cin >> w;
		cin >> valor;

		g.ponArista(AristaDirigida<double>(v, w, valor));
	}
	return g;
}


// resuelve un caso de prueva
bool resuelveCaso(){

	// leer grafo
	size_t numCasas;
	int solucion=0;
	cin >> numCasas;

	if (!cin){
		return false;
	}

	GrafoDirigidoValorado<double> G = leer_Grafo(numCasas+1);			//O(e + v  )
	
	int oficina;
	cin >> oficina;					// leemos la oficina
	
	int num_Paquetes;	
	cin >> num_Paquetes;			// leemos numero de paquetes
	
	vector<int> casas_destino;								

	for (size_t i = 0; i < num_Paquetes; i++)				
	{
		int a; cin >> a; casas_destino.push_back(a);
	}

	// calcula el esfuerzo desde la oficina a las demas casas 
	RepartiendoPaquetes Ida(G, oficina);								//O(e*log v  ) v numero de casas, e numero de calles
	vector<double> esfuerzo_Ida;
	esfuerzo_Ida = Ida.oficina_to_Home();

	// Invertimos el grafo
	GrafoDirigidoValorado<double> G2 =	G.reverse();					//O(e + v) donde v es el numero de casas y e numero de calles  

	// calcula el esfuerzo desde la oficina a las demas casas en sentido contrario
	RepartiendoPaquetes Vuelta(G2, oficina);							//O(e*log v  )	
	vector<double> esfuerzo_vuelta;	
	esfuerzo_vuelta = Vuelta.oficina_to_Home();

	// Calcular esfuerzo Total
	bool imposible = false;
	for (size_t i = 0; i < casas_destino.size() && !imposible; i++)								//O (n) n es numero de paquetes
	{
		solucion += esfuerzo_Ida[casas_destino.at(i)] + esfuerzo_vuelta[casas_destino.at(i)];

		if ((esfuerzo_Ida[casas_destino.at(i)] == numeric_limits<double>::infinity()) ||
			(esfuerzo_vuelta[casas_destino.at(i)] == numeric_limits<double>::infinity())){
			
			imposible = true;
		}
	}

	//Mostrar solucion
	if (imposible) {
		cout << "Imposible" << endl;
	}
	else{
		cout << solucion << endl;
	}
	

	
	return true;

}

int main(){

	// casos de prueba ilimitados
	while (resuelveCaso());
	return 0;
}