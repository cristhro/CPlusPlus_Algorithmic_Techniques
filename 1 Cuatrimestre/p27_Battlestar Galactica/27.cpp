// Cristhian Rodríguez Gómez
// E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
int resolver(std::vector<int> &v, int ini, int fin) {
    
    if ( ini + 1 == fin) {
        return 0;
    } else {
        int m = ( ini + fin + 1) / 2;
        int invIz = resolver(v, ini, m);
        int invDer = resolver(v, m, fin);
        int inv = 0, i = ini, j = m;

        while (i < m && j < fin){
            if (v[i] > v[j]){
                inv += m-i;
                ++j;
            } else {
                ++i;
            }
        }
        std::vector<char > aux(fin-ini);
        std::sort(v.begin()+ini,v.begin()+fin);
        std::merge(v.begin()+ini, v.begin()+m,v.begin()+m,v.begin()+fin,aux.begin());

        for (int k = 0; k < aux.size(); ++k) {
            v[m+i] = aux[i];
        }

        return inv + invIz + invDer;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int  nNaves;

    std::cin >> nNaves;

    if (! std::cin)
        return false;

    std::vector<int> naves(nNaves);
    for (int i = 0; i < nNaves; ++i) {
        std::cin >> naves[i];
    }

    int sol = resolver(naves,0,naves.size());
    
    // escribir sol
    std::cout << sol << std::endl;
    
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