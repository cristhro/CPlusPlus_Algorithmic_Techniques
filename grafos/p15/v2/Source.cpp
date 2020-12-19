// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

// El problema se ha resuelto usando  la clase Manchas,  
// con un nuevo método que devuelve el numero mayor de manchas  ( calculado despues de la lectura del bitmap).
// o(n^2) donde n es el numero de casillas del bitmap

#include <iostream>
#include <string>
#include "Manchas.h"
#include <vector>
using namespace std;


// resuelve un caso de prueva
bool resuelveCaso(){

	int F,C;
	vector <int> sol;
	cin >> F;
	cin >> C;
	
	cin.ignore();
	if (!cin){
		return false;
	}

	Manchas<char> manchas(F, C);
	// leemos matriz
	manchas.read_by_user();

	int N, f,c;
	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		cin >> f >> c;
		manchas.pon_Pixel(f-1, c-1);
		
		// guardamos solucion
		sol.push_back(manchas.mancha_mas_grande()) ;
	}
	
	// mostrar solucion
	for (size_t i = 0; i < sol.size(); i++)
	{
		cout << sol.at(i);
		if (i < sol.size()-1) cout << " ";
	}

	return true;
}

int main(){

	// casos de prueba ilimitados
	while (resuelveCaso());
	
	return 0;
}