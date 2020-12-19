// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 27: Insercion de parentesis
	para resolver el porblema hemos rellenado la tabla por diagonales, empezando por la diagonal principal para el caso baasico.
	como tenemos tres funciones mutuamente recursivas, necesitamos tres matrices booleanas A, B, C que se rellenan simultaneamente.
	Vamos a completar el algoritmo de manera que tambien se devuelva una tabla de decisiones para cada predicado pa, pb, pc que nos permitiran 
	calcular la forma adecuada de insertar los parentesis. 
	Cada decision consistira en la posicion ken la que se divide, y los caracteres que hay que obtener en cada parte.
	
	Coste en tiempo: O(n^3) debido a los tres bucles anidados, donde n es el numero de caracteres.
	Coste en espacio: O(n^2) debido al manejo de matrices (nótese que el hecho de manejar tres matrices en vez de una
	no afecta al coste en espacio por tratarse de una constante).
	
	Llamada recursiva:
	
	A(i, j): para k = i hasta j - 1, ((A(i, k) && C k + 1, j)) || (B(i, k) && C(k + 1, j)) || (C(i, k) && A(k + 1, j)))
	B(i, j): para k = i hasta j - 1, ((A(i, k) && A(k + 1, j)) || (A(i, k) && B(k + 1, j)) || (B(i, k) && B(k + 1, j)))
	C(i, j): para k = i hasta j - 1, ((B(i, k) && A(k + 1, j)) || (C(i, k) && B(k + 1, j)) || (C(i, k) && C(k + 1, j)))
	
	Caso básico:
	
	A(i, i): (xi = a)
	B(i, i): (xi = b)
	C(i, i): (xi = c)
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm> // min
#include "Matriz.h"
#include <vector>
#include <string>

using namespace std;

typedef struct {
	int posicion;
	char resultado1, resultado2;

}tDecision;



void asignar(tDecision &d, int p, char r1, char r2) 
{
	d.posicion = p;
	d.resultado1 = r1; 
	d.resultado2 = r2;
}

bool parentesis(vector<char> const& X, Matriz<tDecision> &pa, Matriz<tDecision> &pb, Matriz<tDecision> &pc) {

	bool posible = false;
	int n = X.size();
	Matriz<bool>A(n , n);
	Matriz<bool>B(n , n );
	Matriz<bool>C(n , n);

	for (int i = 1; i < n; i++)
	{
		A[i][i] = (X[i] == 'a'); B[i][i] = (X[i] == 'b'); C[i][i] = (X[i] == 'c');
	}
	//recorre diagonales
	for (int d = 1; d < n - 1; d++)
	{
		//recorre elementos dentro de la diagonal
		for (int i = 1; i < n-d; i++)
		{
			int j = i + d;
			
			//calcula la disyuncion para A
			A[i][j] = false; int k = i;
			
			while (!A[i][j] && k < j)
			{
				if (A[i][k] && C[k + 1][j]) 
				{
					A[i][j] = true; asignar(pa[i][j], k, 'a', 'c');
				}
				else if(B[i][k] && C[k+1][j])
				{
					A[i][j] = true; asignar(pa[i][j], k, 'b', 'c');
				}
				else if (C[i][k] && A[k + 1][j]) 
				{
					A[i][j] = true; asignar(pa[i][j], k, 'c', 'a');
				}
				else 
				{
					k = k + 1;
				}
			}
			//calcula la disyuncion para B
			B[i][j] = false; k = i;
			while (!B[i][j] && k < j)
			{
				if (A[i][k] && A[k + 1][j])
				{
					B[i][j] = true; asignar(pb[i][j], k, 'a', 'a');
				}
				else if (A[i][k] && B[k + 1][j])
				{
					B[i][j] = true; asignar(pb[i][j], k, 'a', 'b');
				}
				else if (B[i][k] && B[k + 1][j])
				{
					B[i][j] = true; asignar(pb[i][j], k, 'b', 'b');
				}
				else
				{
					k = k + 1;
				}
			}
			//calcula la disyuncion para A
			C[i][j] = false; k = i;
			while (!C[i][j] && k < j)
			{
				if (B[i][k] && A[k + 1][j])
				{
					C[i][j] = true; asignar(pa[i][j], k, 'b', 'a');
				}
				else if (C[i][k] && B[k + 1][j])
				{
					C[i][j] = true; asignar(pa[i][j], k, 'c', 'b');
				}
				else if (C[i][k] && C[k + 1][j])
				{
					C[i][j] = true; asignar(pa[i][j], k, 'c', 'c');
				}
				else
				{
					k = k + 1;
				}
			}

		}
	}
	// fin recorrido diagonales
	posible = A[1][n - 1];
	return posible;
}
bool resuelveCaso() {

	
	string caracteres;
	
	cin >> caracteres;

	if (!cin) {
		return false;
	}
	// convertimos Striing a Vector de Char
	vector<char> X(caracteres.size() + 1);
	int i = 1;
	for (char k : caracteres) {
		X[i] = k;
		i++;
	}

	int n = X.size(); 
	Matriz<tDecision> pa(n , n);
	Matriz<tDecision> pb(n , n);
	Matriz<tDecision> pc(n , n);

	bool solucion =  parentesis(X, pa, pb, pc);

	// mostrar solucion
	if (solucion) cout << "SI" << endl;
	else cout << "NO" << endl;

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}



/*

Esquema de programación dinámica

Identificación
--------------
• Especificación de la función que representa el problema a	resolver.
• Determinación de las ecuaciones recurrentes para calcular dicha función.
• Comprobación del alto coste de cálculo de dicha función debidoa la repetición de subproblemas a resolver.

Construcción
-------------
• Sustitución de la función por una tabla.
• Inicialización de la tabla según los casos base de la definiciónrecursiva de la función.
• Sustitución, en las ecuaciones, de las llamadas recursivas porconsultas a la tabla.
• Planificación del orden de llenado de la tabla, de forma que serespeten las necesidades de cada entrada de la tabla.
• Posible optimización en espacio.

*/