/*
*	------------------------------------------------------------
*	TAIS21 - CRISTHIAN RODRIGUEZ G�MEZ y JONATHAN CARRERO ARANDA
*	------------------------------------------------------------
*	PR�CTICA 1: �EST� EL �RBOL EQUILIBRADO?
*	------------------------------------------------------------
*
*	Para resolver el problema del �rbol equilibrado hemos hecho uso de dos funciones auxiliares
*	(altura , diferencia) ya que un �rbol s�lo es equilibrado cuando la diferencia de las alturas 
*	de sus hijos es como mucho 1 y que ambos hijos esten equilibrados.
*/

#include <iostream>
#include <algorithm>
#include "Arbin.h"

using namespace std;

Arbin<char> leeArbol();
int altura(Arbin<char> arbol);
bool equilibrado(Arbin<char> arbol);
void resuelveCaso(Arbin<char> arbol);
int diferencia(int n , int m);

/*
*	Funci�n que lleva a cabo la lectura de un �rbol binario haciendo
*	llamadas recursivas sobre sus hijos derecho e izquierdo.
*
*	Complejidad: O(n)
*/
Arbin<char> leeArbol(){
	char raiz;

	cin >> raiz;
	if(raiz=='.')
		return Arbin<char>();
	else
	{
		const Arbin<char> &iz = leeArbol();
		const Arbin<char> &dr = leeArbol();
		return Arbin<char>(iz, raiz, dr);
	}
}

/*
*	Funci�n que recibe un �rbol binario (arbol) y devuelve su altura m�xima.
*
*	Complejidad: O(n)
*/
int altura(Arbin<char> arbol){

	if (arbol.esVacio()){
		return 0;
	}else{
		return 1 + max(altura(arbol.hijoIz()),altura(arbol.hijoDr()));
	}
}

/*
*	Funci�n que recibe un �rbol binario (arbol) y calcula si
*	o bien es vac�o (en cuyo caso es equilibrado) o bien no es vac�o pero a�n as� est�
*	equilibrado.
*
*	Complejidad: O(n)
*/
bool equilibrado(Arbin<char> arbol){
	
	if(arbol.esVacio()) return true;
	else{
		return( equilibrado(arbol.hijoIz()) &&			
			    equilibrado(arbol.hijoDr()) && 
				diferencia(altura(arbol.hijoIz()), altura(arbol.hijoDr())) <= 1 );
	}
}

/*
*	Funci�n que recibe dos enteros (n, m) y nos retorna la diferencia entre ambos.
*
*	Complejidad: O(1)
*/
int diferencia(int n , int m){

	if (n >= m)return n-m;
	else return m-n;
}

/*
*	Funci�n que lee de la entrada la configuraci�n del �rbol (arbol)
*	y devuelve el resultado de si est� equilibrado o bien no lo est�.
*
*	Complejidad: O(n)
*/
void resuelveCaso(){
	Arbin<char> arbol;

	arbol = leeArbol();
	if(equilibrado(arbol))
		cout <<"SI" << endl;
	else cout <<"NO" << endl;
} 


int main(){

	int numCasos;

	cin >>numCasos;
	for (int i = 0; i < numCasos; i++){
		resuelveCaso();
	}
	return 0;
}

