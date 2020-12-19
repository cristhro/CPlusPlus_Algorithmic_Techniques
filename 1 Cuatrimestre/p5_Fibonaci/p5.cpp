// Cristhian
// Rodriguez Gomez

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
// requires n >= 0
// ensures f == Fib(n)
long long int Fibonacci(int n) {
	long long int f, l, m;

	if (n < 2) {
		f = n;
	}
	else {
		f = 1, l  = 1,  m  = 0;
		int i  = 1;

		while (i < n)
			// invariant 2 <= i <= n
			// invariant  f == Fib(i)
			// invariant  l == Fib(i-1)
			// invariant  m == Fib(i-2)
		{
			f = l + m;
			m = l;
			l = f;

			i = i + 1;
		}
	}
	return f;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (n == -1)
		return false;

	long long int sol = Fibonacci(n);

	// escribir sol
	cout << sol << endl;
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
