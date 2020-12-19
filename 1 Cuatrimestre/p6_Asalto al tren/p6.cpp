// Cristhian Rodriguez Gomez
// E51
//  Coste de la funcion resolver O(n) respecto al numero de vagones

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


// función que resuelve el problema
void resolver(vector<int> &vagones, int &nVagonesAsaltar, int &vagonEmpezar, int &ganancia) {

    int tamV = vagones.size();
    int sumMax = 0;
    int sumParcial = 0;
    vagonEmpezar = 0;
    ganancia = 0;

    for (int j = 0; j < nVagonesAsaltar; ++j) {
        sumParcial = sumParcial + vagones[j];
    }
    sumMax = sumParcial;

    // Coste O(n)
    for (int i = nVagonesAsaltar ; i < tamV; i++) {

        sumParcial = sumParcial - vagones[i-nVagonesAsaltar];
        sumParcial = sumParcial + vagones[i];

        if (sumParcial >= sumMax){
            vagonEmpezar = i - nVagonesAsaltar + 1;
            sumMax = sumParcial;
        }
    }
    ganancia = sumMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nVagones, nVagonesAsaltar, vagonEmpezar, ganancia;
    cin >> nVagones;
    cin >> nVagonesAsaltar;

    vector<int> vagones(nVagones);

    for (int i = 0; i < nVagones; i++) {
        cin >> vagones[i];
    }

    resolver(vagones, nVagonesAsaltar, vagonEmpezar, ganancia);

    // escribir sol
    cout << vagonEmpezar << " " << ganancia << endl;

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
