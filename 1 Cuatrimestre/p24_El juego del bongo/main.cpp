// Cristhian Rodriguez
// E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSolucion {
    bool ok = false;
    int suma = 0;
};

void bongoRec(vector<int> const&numeros, int numCantado, int ini, int fin, tSolucion &sol) {
    if(ini == fin ){
        return;
    }
    else {
        int posMitad = (fin + ini ) / 2;
        int sumaMitad = posMitad + numCantado;

        if (sumaMitad < numeros[posMitad]) {
            bongoRec(numeros, numCantado,  ini, posMitad, sol);
        }
        else if (sumaMitad == numeros[posMitad]){
            sol.ok = true;
            sol.suma = sumaMitad;
        }
        else{
            bongoRec(numeros, numCantado,  posMitad + 1, fin, sol);
        }
    }
}
tSolucion bongo (vector<int> const&numeros, int numCantado){
    int ini = 0;
    int fin = numeros.size() ;
    tSolucion sol;

    bongoRec( numeros,  numCantado,  ini,  fin, sol);

    return sol;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numCantado;
    int nNumeros;

    cin >> nNumeros;
    cin >> numCantado;

    vector<int> numeros(nNumeros);
    for (int i = 0; i < nNumeros ; ++i) {
        cin >> numeros[i];
    }
    // escribir sol
    tSolucion sol = bongo(numeros, numCantado);

    if(sol.ok)
        cout << sol.suma << endl;
    else
        cout << "NO" << endl;
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