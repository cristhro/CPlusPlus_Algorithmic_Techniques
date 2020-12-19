// E51 Cristhian Rodríguez Gómez

#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include "bintree_eda.h"

using namespace std;

// O(n) respecto al numero de nodos que tiene el arbol
// Funcion que devuelve
// numEquipos: Numero de equipos necesarios para rescatar a los excursionistas
// numMaxRescatados: Numero maximos de excursionista rescatados en una ruta
void resuelve(bintree<int> const & arbol, int &numEquipos, int &numMaxRescatados ){

    if (arbol.empty()){
        numEquipos = 0; numMaxRescatados = 0;
    }else {

        int nEquiposI = 0, numMaxRescatadosI = 0, numEquiposD = 0, numMaxRescatadosD = 0;
        resuelve(arbol.right(), nEquiposI, numMaxRescatadosI);
        resuelve(arbol.left(), numEquiposD, numMaxRescatadosD);

        if (nEquiposI == 0 && numEquiposD == 0 && arbol.root() != 0) {
            numEquipos++;
            numMaxRescatados += arbol.root();
        }
        else {
            numEquipos = nEquiposI + numEquiposD;
            numMaxRescatados = std::max(numMaxRescatadosI, numMaxRescatadosD) + arbol.root();
        }
    }
}

void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);
    int numRescatadores = 0;
    int numRescatados = 0;

    resuelve(arbol, numRescatadores, numRescatados);

    cout << numRescatadores << " " << numRescatados << endl;
    // propiedades(arbol,numNodos,numHojas, altura);
    // La funcion getFrontera tiene un coste de complejidad O(n) don n es el numero de nodos del arbol.

}

int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i <numCasos ; ++i) {
        resuelveCaso();
    }
    //    while(resuelveCaso());


    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}