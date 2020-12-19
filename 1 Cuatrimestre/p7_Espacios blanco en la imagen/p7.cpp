// Cristhian Rodriguez Gomez
// E51
//  Coste de la funcion resolver O(n) respecto al numero de pixeles

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


// función que resuelve el problema
void resolver(vector<string> const  &pixeles, int &posIni, int &posFin) {

    int i = 0, iniUltSeg = 0, maxLong = 0;
    posIni = 0; int numPixeles = pixeles.size();
    while(i < numPixeles)
    {
        if (pixeles[i] == "FFFFFF") {
            if (maxLong < i-iniUltSeg+1) {
                posIni = iniUltSeg;
                maxLong = i-iniUltSeg+1;
            }
        }
        else {iniUltSeg=i+1;}
        i=i+1;
    }
    posFin = posIni + maxLong -1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
    // leer los datos de la entrada
    int mFilas, nPixeles, posIni, posFin;
    cin >> mFilas;
    cin >> nPixeles;

    if (! std::cin)
        return false;

    vector<string> pixeles(nPixeles);
    for (int j = 0; j < mFilas; ++j) {
        for (int i = 0; i < nPixeles; ++i) {
            cin >> pixeles[i];
        }
        resolver(pixeles, posIni, posFin);

        // Mostrar sol
        cout << posIni << " " << posFin << endl;

    }
    cout << endl;
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
