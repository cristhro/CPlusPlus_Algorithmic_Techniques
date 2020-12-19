// Cristhian Rodriguez Gomez
// E51	


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
	predicate EstricCreciente ( s : seq <int >)
	ensures EstricCreciente ( s ) == forall u , w :: 0 <= u < w < | s | == > s [ u ] < s [ w ]
	method Problema02 ( v : array <int >)
	requires v != null
	requires forall k :: 0 <= k < v . Length == > v [ k ] > 0
	requires EstricCreciente ( v [..])
	
	ensures forall i ::0 <= i <old ( v . Length ) && old( v [ i ])%2 == 0 == > old( v [ i ]) in v [..]
	ensures 0 <= v . Length <= old ( v . Length )
	ensures forall i :: 0 <= i < v . Length == > v [ i ] in old( v [..])
	ensures EstricCreciente ( v [..])
	modifies v


*/
// función que resuelve el problema
void resolver(vector<int> &v) {
	
	int tamV = v.size();
	int ultPosPar = 0;
	for (int i = 0; i < tamV; i++) {
		if (v[i] % 2 == 0){
			v[ultPosPar] = v[i];
			ultPosPar++;
		}
	}
	v.resize(ultPosPar);
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

	resolver(v);

	int tamV = v.size();
	for (int i = 0; i < tamV; i++) {
		cout << v[i];
		if (i < tamV - 1) cout << " ";
	}
	cout << endl;
	
	// escribir sol


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