#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;
struct tSol {
    int min = 99999999;
};

int minVectorRec(vector<int> const &v, int ini, int fin, tSol &sol){
    if (ini == fin){
        if(ini < v.size())
            return v[ini];
        else
            return 99999999;
    }
    else {
        int mitad = (ini + fin) / 2;
        int minI = minVectorRec(v, ini, mitad, sol);
        int minD = minVectorRec(v,mitad + 1, fin, sol);

        if(minI > minD){
            if (minD < sol.min) {
                sol.min= minD;
            }
            return minD;
        }else {
            if (minI < sol.min) {
                sol.min= minI;
            }
            return minI;
        }
    }
}
int minimoVecto(vector<int> const& v){
    int ini = 0;
    int fin = v.size();
    tSol sol;

    int min = minVectorRec(v,ini,fin,sol);
    
    return min;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nElems;
    cin >> nElems;

    if (! std::cin)
        return false;

    vector<int> v(nElems);
    for (int i = 0; i < nElems; ++i) {
        cin >> v[i];
    }

    int sol = minimoVecto(v);

    // escribir sol
    cout << sol << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
