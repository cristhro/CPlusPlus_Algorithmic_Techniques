/*
*	------------------------------------------------------------
*	TAIS21 - CRISTHIAN RODRIGUEZ GÓMEZ y JONATHAN CARRERO ARANDA
*	------------------------------------------------------------
*	PRÁCTICA 2: ¿ES	UN ÁRBOL AVL?
*	------------------------------------------------------------
*
*	Para saber si un árbol AVL está equilibrado hemos usado dos funciones auxiliares
*	que nos dicen por un lado si está equilibrado y por otro si dicho árbol está ordenado.
*/

#include <math.h>
#include <iostream>
#include "Arbin.h"
#include <algorithm>

using namespace std;

Arbin<int> leeArbol();
int altura(Arbin<int> arbol);
void resuelveCaso(Arbin<int> arbol);
int diferencia(int n , int m);
bool esOrdenado(Arbin<int> arbol);
bool tiene_2_Hijos(Arbin<int> arbol);
bool tiene_Hijo_Izq(Arbin<int> arbol);
bool tiene_Hijo_Dr(Arbin<int> arbol);
bool esEquilibrado(Arbin<int> arbol);
bool recorre_Rama_Derecha(Arbin<int> arbol, int &max);
bool recorre_Rama_Izquierda(Arbin<int> arbol, int  &min);

/*
*	Función que lleva a cabo la lectura de un árbol binario haciendo
*	llamadas recursivas sobre sus hijos derecho e izquierdo.
*
*	Complejidad: O(n)
*/
Arbin<int> leeArbol(){
	int raiz;

	cin >> raiz;
	if(raiz==-1)
		return Arbin<int>();
	else
	{
		const Arbin<int> &iz = leeArbol();
		const Arbin<int> &dr = leeArbol();
		return Arbin<int>(iz, raiz, dr);
	}
}

/*
*	Función que dado un árbol (arbol) retorna true si el árbol está ordenado.
*	Un árbol está ordenado cuando el hijo izquierdo es menor que su padre
*	y el hijo derecho es mayor que su padre. Además, ambos hijos también están ordenados.
*
*	Complejidad: O(n)
*/
bool esOrdenado(Arbin<int> arbol){
	
	if(arbol.esVacio()){ 

		return true;
	// Si tiene dos hijos
	}else if( tiene_2_Hijos(arbol)){

		int max_hijo_Izq = arbol.hijoIz().raiz();
		int min_hijo_der = arbol.hijoDr().raiz();
		
		bool DR_IS_ORD = recorre_Rama_Derecha(arbol.hijoIz(), max_hijo_Izq);
		bool IZ_IS_ORD = recorre_Rama_Izquierda(arbol.hijoDr(), min_hijo_der);
	
		if ((arbol.raiz() > max_hijo_Izq)	&& 
			(arbol.raiz() < min_hijo_der)   && 
			DR_IS_ORD && DR_IS_ORD
			){

			return( esOrdenado(arbol.hijoIz()) &&			
			        esOrdenado(arbol.hijoDr()) 
				   );
		}else 
			return false;
	
	}else if(tiene_Hijo_Izq(arbol)){

		int max_hijo_Izq = arbol.hijoIz().raiz();
		bool DR_IS_ORD = recorre_Rama_Derecha(arbol.hijoIz(), max_hijo_Izq);
		
		if ((arbol.raiz() > max_hijo_Izq) && DR_IS_ORD){
			return (esOrdenado(arbol.hijoIz() ));
		}else 
			return false;

	}else if(tiene_Hijo_Dr(arbol)){

		int min_hijo_der = arbol.hijoDr().raiz();
		bool  IZ_IS_ORD = recorre_Rama_Izquierda(arbol.hijoDr(), min_hijo_der);

		if ((arbol.raiz() < min_hijo_der) && IZ_IS_ORD){
			return ( esOrdenado(arbol.hijoDr())  );
		}else 
			return false;
	}
	else return true;
}

/*
*	Función que recibe un árbol binario (arbol) y calcula si
*	o bien es vacío (en cuyo caso es equilibrado) o bien no es vacío pero aún así está
*	equilibrado.
*
*	Complejidad: O(n)
*/
bool esEquilibrado(Arbin<int> arbol){
	
	if(arbol.esVacio()) return true;
	else{
		return( esEquilibrado(arbol.hijoIz()) &&			
			    esEquilibrado(arbol.hijoDr()) && 
				diferencia(
						altura(arbol.hijoIz()),
						altura(arbol.hijoDr())
				) <=1
			  );
	}
}

/*
*	Función que lee de la entrada la configuración del árbol (arbol)
*	y devuelve el resultado de si está equilibrado o bien no lo está.
*
*	Complejidad: O(n)
*/
void resuelveCaso(){
	Arbin<int> arbol;

	arbol = leeArbol();

	if(esOrdenado(arbol) && esEquilibrado(arbol))
		cout <<"SI" << endl;
	else cout <<"NO" << endl;
} 


bool tiene_2_Hijos(Arbin<int> arbol){
	return (!arbol.hijoIz().esVacio() && !arbol.hijoDr().esVacio());
}
bool tiene_Hijo_Izq(Arbin<int> arbol){
	return (!arbol.hijoIz().esVacio());
}
bool tiene_Hijo_Dr(Arbin<int> arbol){
	return (!arbol.hijoDr().esVacio());
}

/*
*	Función que recibe un árbol binario (arbol) y devuelve su altura máxima.
*
*	Complejidad: O(n)
*/
int altura(Arbin<int> arbol){
	if (arbol.esVacio()){
		return 0;
	}else{
		return 1 + max(altura(arbol.hijoIz()),altura(arbol.hijoDr()));
	}
}

/*
*	Función que recibe dos enteros (n, m) y nos retorna la diferencia entre ambos.
*
*	Complejidad: O(1)
*/
int diferencia(int n , int m){

	if (n>=m)return n-m;
	else return m-n;
}

int main(){
	int numCasos;

	cin >>numCasos;
	
	for (int i = 0; i < numCasos; i++)
	{
		resuelveCaso();
	}

	return 0;
}

/*
*	Función que recorre los hijos derechos de la raíz (raiz)
*	y si no tiene hijo derecho devuelve false.
*
*	Complejidad: O(n)
*/
bool recorre_Rama_Derecha(Arbin<int> arbol ,int  &max){
	
	 if (!tiene_Hijo_Dr(arbol) ){
		  max = arbol.raiz();
		  return true;
	 }
	 else {
		 if (arbol.hijoDr().raiz()  > arbol.raiz()){
			 return recorre_Rama_Derecha(arbol.hijoDr(), max);
		 }
		 else{
			 return false;
		 }
	 }
}

/*
*	Función que recorre los hijos izquierdos de la raíz (raiz)
*	y si no tiene hijo izquierdo devuelve false.
*
*	Complejidad: O(n)
*/
bool recorre_Rama_Izquierda(Arbin<int> arbol, int  &min){

	if (!tiene_Hijo_Izq(arbol)){
		min = arbol.raiz();
		return true;
	}
	else {
		if (arbol.hijoIz().raiz()  < arbol.raiz()){
			return recorre_Rama_Izquierda(arbol.hijoIz(), min);
		}
		else{
			return false;
		}
	}
}
