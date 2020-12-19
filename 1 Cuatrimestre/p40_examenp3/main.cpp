// Cristhian Rodríguez Gómez
// E51

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

typedef struct tDatos {
    size_t numSoluciones = 0;
    size_t altura = 0;
    std::vector<std::string> colores = {"azul", "rojo", "verde"};
    std::vector<size_t> cubos = {0,0,0};
    std::vector<size_t> cubosTotales = {0,0,0};
};

void imprimir(std::vector<std::string> &sol){
    for (const std::string &color : sol) {
        std::cout << color << " ";
    }

    std::cout << std::endl;
}

void marcar( tDatos &datos, size_t const& color){
    datos.cubosTotales[color]++;
}

void desMarcar( tDatos &datos, size_t const& color){
    datos.cubosTotales[color]--;
}

bool esSolucion (tDatos & datos, std::vector<std::string> &sol, size_t k) {
    if (k == datos.altura - 1 && (datos.cubosTotales[0] + datos.cubosTotales[1] + datos.cubosTotales[2] == datos.altura)) {
        if (datos.cubosTotales[1] > datos.cubosTotales[0] + datos.cubosTotales[2]) {
            return true;
        }
    }

    return false;
}

bool esValida(tDatos const& datos, std::vector<std::string> &sol, size_t k, size_t i){
    if (datos.cubosTotales[i] > datos.cubos[i]) {
        return false;
    } else {
        if (sol[k] == datos.colores[2] && sol[k-1] == datos.colores[2]) {
            return false;
        } else if (datos.cubosTotales[2] > datos.cubosTotales[0]) {
            return false;
        }
    }

    return true;
}

void resolver(tDatos & datos, std::vector<std::string> &sol, size_t k){
    for (size_t i = 0; i < 3; ++i) {
        sol[k] = datos.colores[i];
        marcar(datos, i);
        if (esValida(datos,sol,k, i)){
            if (esSolucion(datos, sol,k)) {
                imprimir(sol);
                datos.numSoluciones ++;
            }else{
                resolver(datos, sol, k + 1);
            }
        }
        sol[k] = "";
        desMarcar(datos, i);
    }
}

void resolver (tDatos & datos){
    std::vector<std::string> sol(datos.altura);
    sol[0] = "rojo";
    datos.cubosTotales[1]++;
    resolver(datos, sol, 1);
}

bool resuelveCaso() {
    tDatos datos;
    std::cin >> datos.altura >> datos.cubos[0] >> datos.cubos[1] >> datos.cubos[2];

    if (datos.altura == 0 && datos.cubos[0] == 0 && datos.cubos[1] == 0 && datos.cubos[2] == 0){
        return false;
    }

    resolver(datos);

    if (datos.numSoluciones == 0) {
        std::cout << "SIN SOLUCION" <<std::endl;
    }
    std::cout << std::endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 

    while (resuelveCaso()) {}

    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     #endif
    
    return 0;
}