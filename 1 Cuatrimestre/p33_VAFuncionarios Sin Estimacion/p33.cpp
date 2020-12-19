// Cristhian Rodríguez Gómez
// E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

struct tDatos {
    int numFuncionario;
    std::vector<std::vector<int>> tiempos;
};
// función que resuelve el problema
void resolver(tDatos const& datos, int k,std::vector<bool> &marcas,int &tiempoActual, int &tiempoMejor) {
    for (int i = 0; i < datos.numFuncionario; ++i) {
        tiempoActual += datos.tiempos[k][i];
        if (!marcas[i]){ // es valida
            marcas[i] = true;
            if (k == datos.numFuncionario - 1){ // es solucion
                if (tiempoActual < tiempoMejor){
                    tiempoMejor = tiempoActual;
                }
            } else {
                resolver(datos,k+1,marcas,tiempoActual,tiempoMejor);
            }
            marcas[i] = false;
        }
        tiempoActual -= datos.tiempos[k][i];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    tDatos datos;
    std::cin >> datos.numFuncionario;

    if (datos.numFuncionario == 0) return false;

    for (int i = 0; i < datos.numFuncionario ; ++i) {
        std::vector<int> aux(datos.numFuncionario);
        for (int j = 0; j < datos.numFuncionario; ++j) {
            std::cin >> aux[j];
        }
        datos.tiempos.push_back(aux);
    }

    std::vector<bool> marcas(datos.numFuncionario);
    int tiempoActual = 0;
    int tiempoMejor = 99999999;

    resolver(datos,0,marcas,tiempoActual,tiempoMejor);

    std::cout << tiempoMejor << std::endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso());

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}