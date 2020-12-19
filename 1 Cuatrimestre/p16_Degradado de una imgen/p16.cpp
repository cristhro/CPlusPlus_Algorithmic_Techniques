// Cristhian Rodríguez Gómez
// E51

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>

typedef struct  {
    bool sol;
    size_t suma;
} tSolucion;

tSolucion resolver( std::vector<size_t> const &imagen, size_t ini, size_t fin) {
    size_t mitad = (fin + ini + 1) / 2;
    tSolucion solIzq{};
    tSolucion solDch{};
    tSolucion solucion{};

    if (ini + 1 == fin) {
        solucion.suma += imagen[ini];
        solucion.sol = true;

        return solucion;
    } else {
        solIzq = resolver(imagen, ini, mitad);
        solDch = resolver(imagen, mitad, fin);
        solucion.suma = solIzq.suma + solDch.suma;
        solucion.sol = solIzq.suma <= solDch.suma && solIzq.sol && solDch.sol;

        return solucion;
    }
}

bool resolver( std::vector< std::vector<size_t>> const &imagen) {
    tSolucion sol{};
    bool result = true;

    for (const auto &i : imagen) {
        if (!resolver(i, 0, i.size()).sol) {
            result = false;
        }
    }

    return result;
}

bool resuelveCaso() {
    size_t filas;
    size_t columnas;

    std::cin >> filas >> columnas;

    if (! std::cin)
        return false;

    std::vector< std::vector<size_t>> imagen(filas, std::vector<size_t>(columnas));

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            std::cin >> imagen[i][j];
        }

    }

    bool sol = resolver(imagen);

    if (sol) {
        std::cout << "SI" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while(resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}