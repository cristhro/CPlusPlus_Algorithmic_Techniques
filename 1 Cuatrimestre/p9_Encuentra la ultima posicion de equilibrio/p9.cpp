// Cristhian Rodriguez Gomez
// E51
//  Coste de la funcion resolver O(n) respecto al numero de elementos que tenga el vector

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


// función que resuelve el problema
int resolver(vector<int> const  &v) {
    int tamV = v.size();
    int sumUnos = 0;
    int sumCeros = 0;
    int nUnosCeros=0;
    int pos = -1;
    bool enc =  false;

    if ( tamV == 0) {
        pos = -1;
    }
    else {
        for (int j = 0; j < v.size() ; ++j) {
            if (v[j] == 0) {
                ++ceros;
            } else if ( v[j] == 1) {
                ++unos;
            }

            if (unos != 0 && unos == ceros) {
                pos = j;
            }
        }
        if(ceros==0 && unos==0){
            pos=v.size()-1;
        }
        else {
            // Comprobación para evitar que pos no se salga de rango
            if (pos < v.size() - 1 ) {
                /// Si el siguiente elemento del vector no es uno ni cero
                if (v[pos + 1] != 0 && v[pos + 1] != 1) {
                    pos++;
                }
            }
        }
    }


    return pos;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nElems;

    cin >> nElems;
    vector<int> v(nElems);

    for (int i = 0; i < nElems; ++i) {
        cin >> v[i];
    }

    int sol = resolver(v);

    // escribir sol
    cout << sol << endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
