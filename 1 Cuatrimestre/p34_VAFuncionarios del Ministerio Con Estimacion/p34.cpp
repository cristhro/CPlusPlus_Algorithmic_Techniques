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

int inicializarTiempo(std::vector<std::vector<int>> const& tiempos);

// función que resuelve el problema
void resolver(tDatos const& datos, int k,std::vector<bool> &marcas, int &tiempoActual, int &tiempoMejor, std::vector<int> const& vAcum) {
    for (int i = 0; i < datos.numFuncionario; ++i) {
        tiempoActual += datos.tiempos[k][i];
        if (!marcas[i]){ // es valida
            marcas[i] = true;
            if (k == datos.numFuncionario - 1){ // es solucion
                if (tiempoActual < tiempoMejor){
                    tiempoMejor = tiempoActual;
                }
            } else {
                if (tiempoActual + vAcum[k+1] < tiempoMejor) {
                    resolver(datos,k+1,marcas,tiempoActual,tiempoMejor,vAcum);
                }
            }
            marcas[i] = false;
        }
        tiempoActual -= datos.tiempos[k][i];
    }
}
std::vector<int> acumulada(std::vector<std::vector<int>> const& tiempos){
    std::vector<int> minimo(tiempos.size());

    for (int i = 0; i < tiempos.size(); ++i) {
        int min = tiempos[i][0];
        for (int j = 0; j < tiempos.size(); ++j) {
            if (tiempos[i][j] < min){
                min = tiempos[i][j];
            }
        }
        minimo[i]=min;
    }

    for (int i = tiempos.size() - 1; i > 0; --i) {
        minimo[i-1] += minimo[i];
    }
    return  minimo;
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
    std::vector<int> vAcum = acumulada(datos.tiempos);
    int tiempoMejor = inicializarTiempo(datos.tiempos);
    int tiempoActual = 0;


    resolver(datos,0,marcas,tiempoActual,tiempoMejor,vAcum);

    std::cout << tiempoMejor << std::endl;
    return true;
}

int inicializarTiempo(std::vector<std::vector<int>> const& tiempos) {
    int suma = 0;
    for (int i = 0; i < tiempos.size() ; ++i) {
        suma += tiempos[i][i];
    }
    return suma;
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