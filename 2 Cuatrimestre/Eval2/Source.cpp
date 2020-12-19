// E51 Cristhian Rodríguez Gómez

#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include "bintree_eda.h"

using namespace std;


typedef  struct {
    int descendientes;
    bool esSurdo;
}tSol;

// O(n) respecto al numero de nodos que tiene el arbol
tSol esSurdo(bintree<char > const & arbol){
    tSol sol;
    sol.descendientes = 0;
    sol.esSurdo = false;

    if (arbol.empty()){
        sol.esSurdo = true;
        return  sol;
    }   // Si es una hoja
    else if(arbol.left().empty() && arbol.right().empty()){
        sol.descendientes = 1;
        sol.esSurdo = true;
        return sol;
    } else {
        tSol solIzq = esSurdo(arbol.left());
        tSol solDer = esSurdo(arbol.right());

        sol.descendientes = solIzq.descendientes + solDer.descendientes + 1;

        if (solIzq.descendientes > solDer.descendientes && solIzq.esSurdo && solDer.esSurdo) {
            sol.esSurdo = true;
        }
        return sol;
    }
}

void resuelveCaso() {

    bintree<char> arbol = leerArbol('.');
    tSol sol = esSurdo(arbol);

    if (sol.esSurdo) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }
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