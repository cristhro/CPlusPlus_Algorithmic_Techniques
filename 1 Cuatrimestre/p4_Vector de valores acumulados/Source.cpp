// Cristhian Rodriguez
// E51


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

vector<int> problema1(vector<int> const &a)
// requires a != null && a.Length > 0
// ensures v != null &&  a.Length == v.Length
// ensures forall k:: 0 < k < v.Length == > v[..][k - 1] == (v[..][k] + a[..][k - 1])
{
	int i = a.size() - 1;
	vector<int> v(a.size());

	v[i] = a[i];
	while (i > 0)
		// invariant forall k::i <= k < v.Length ==> v[..][k - 1] == v[..][k] + a[..][k - 1]
	{
		v[i - 1] = v[i] + a[i - 1];
		i = i - 1;
	}

	return v;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int valor;
	vector<int> a;

	cin >> valor;
	if (valor == 0)
		return false;

	while (valor != 0)
	{
		a.push_back(valor);
		cin >> valor;
	}

	vector<int> sol = problema1(a);

	// escribir sol
	for (int i = 0; i < sol.size(); i++)
	{
		cout << sol[i];
		if (i < sol.size()- 1)
			cout << " ";
	}
	cout << endl;
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
