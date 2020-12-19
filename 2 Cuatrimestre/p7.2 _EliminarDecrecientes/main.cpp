// Cristhian Rodriguez
// E51

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_mod.h"
#include "horas.h"

using namespace std;

bool resuelveCaso() {

    int nElems;
    cin>>nElems;

    if (nElems == 0)
        return false;

    Lista<horas> lista;

    for (int i = 0; i < nElems; ++i) {
        horas hora;
        cin >> hora;
        lista.push(hora);
    }

    lista.eliminarDecrecientes();

    lista.print();
    cout << endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
