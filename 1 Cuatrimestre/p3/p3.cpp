// Cristhian Rodriguez Gomez
// E51	


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
method problema3 ( a : array <int > , p : int) returns ( b : bool )
requires a != null
requires 0 <= p < a . Length
ensures b == forall u , w :: 0 <= u <= p < w < a . Length == > a [ u ] < a [ w ]
*/

// función que resuelve el problema
bool resolver(vector<int> &v, int p) {

    int tamV = v.size();
    bool ok = true;
    int valorMax = -99999999;

    for (int i = 0; i <= p; i++)
    {
        if (v[i] > valorMax) valorMax = v[i];

    }

    for (int i = p + 1; i < tamV; i++) {
        if (valorMax >= v[i]){
            ok = false;
        }
    }
    return ok;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nElems, p;
    cin >> nElems;
    cin >> p;

    vector<int> v(nElems);

    for (int i = 0; i < nElems; i++) {
        cin >> v[i];
    }

    bool sol = resolver(v, p);

    // escribir sol
    if (sol){
        cout << "SI" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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