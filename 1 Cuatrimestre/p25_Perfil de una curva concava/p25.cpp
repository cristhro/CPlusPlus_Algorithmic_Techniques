// Cristhian Rodríguez Gómez
// E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
void resolver(std::vector<int> const& v, int ini, int fin, int &minimo) {
    if(ini + 1 == fin) {
        if(v[ini] < minimo){
            minimo = v[ini];
        }
    } else {
        int m = (ini + fin + 1) / 2;
        resolver(v,ini,m,minimo);
        resolver(v,m,fin,minimo);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nElems;
    std::cin >> nElems;

    if (! std::cin)
        return false;

    std::vector<int> v(nElems);
    for (int i = 0; i < nElems; ++i) {
        std::cin >> v[i];
    }

    int minimo = 99999999;
    resolver(v,0,v.size(),minimo);

    std::cout << minimo << std::endl;
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