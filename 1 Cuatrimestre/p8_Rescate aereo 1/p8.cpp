// Cristhian Rodriguez
// E51

// El coste del algoritmo que resuelve el problema es Lineal respecto al numero de edificios

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
/*int resolver(int datos) {
cout << " Resolver datos" << endl;
return 1;
}*/

void rescate(std::vector<int> const  &alturaEdificios, int const &alturaTransporte, int &ini, int &fin){

		int i = 0; int iniUltSeg = 0; int maxLong = 0;
		int nEdificios = alturaEdificios.size();
		ini = 0, fin = 0;

		while (i < nEdificios)
		{
			if (alturaEdificios[i] > alturaTransporte) {
				if (maxLong < i - iniUltSeg + 1) {
                    ini = iniUltSeg;
                    maxLong = i - iniUltSeg + 1;
				}
			}
			else { iniUltSeg = i + 1; }
		i = i + 1;
		}
		fin = ini + maxLong - 1;

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	int nEdificios;
	int alturaTransporte;
	int ini, fin;
	std::cin >> nEdificios;
	std::cin >> alturaTransporte;

	std::vector<int> alturaEdificios(nEdificios);

	for (int i = 0; i < nEdificios; ++i) {
		std::cin >> alturaEdificios[i];
	}


	rescate(alturaEdificios, alturaTransporte, ini, fin);

	// escribir sol
	std::cout << ini << " " << fin << std::endl;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("08EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i){
		resuelveCaso();
	}


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
