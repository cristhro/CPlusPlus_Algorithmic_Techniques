// Cristhian Rodriguez Gomez
// E51
// Coste total = O(nlogn) + O(n) = O(nlogn)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    function  posMaximo (s : seq <int >) : nat
    ensures 0 <= posMaximo(s) < |s|
    ensures  forall k :: 0 <= k < |s| ==> s[k]  <= s[posMaximo(s)]

    function  SumSinMaximo(s:seq <int >):int
        ensures s==[] ==>  SumSinMaximo(s)==0
        ensures s!=[] &&  posMaximo(s) != 0 ==>
            SumSinMaximo(s)==s[0]+ SumSinMaximo(s[1..])
        ensures s!=[] &&  posMaximo(s) == 0 ==>
            SumSinMaximo(s)== SumSinMaximo(s[1..])

    method  SumaValores (v : array <int >)  returns (s : int)
    requires v != null && v.Length  > 0
    ensures s ==  SumSinMaximo(v[..])
 
    maximo -
    vecesMaximo
    suma {
        Sin maximo
        Con maximo
    }
    al final desoues del buble restar maximo*-simMaximo
 
 
*/

// función que resuelve el problema
int resolver(vector<int> const& v) {

    sort(v.begin(),v.end());  // Coste de ordenar O(nlogn)

    int tamV = v.size();
    int maxElem = v[tamV -1];
    bool enc = false;
    int posMax = 0;
    int sumSinMax = 0;

    // Coste O(n)
    for (int i = tamV - 1; i>=0 && !enc; i--) {
        if (v[i] < maxElem){
            posMax = i+1;
            enc = true;
        }
    }

    for (int i = 0; i < posMax; i++) {
       sumSinMax = sumSinMax + v[i];
    }
    return sumSinMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nElems;
    cin >> nElems;
    vector<int> v(nElems);

    for (int i = 0; i < nElems; i++) {
        cin >> v[i];
    }

    int sol = resolver(v);

    // escribir sol
    cout << sol << endl;

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
