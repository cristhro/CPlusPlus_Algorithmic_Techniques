/*
*	------------------------------------------------------------
*	TAIS21 - CRISTHIAN RODRIGUEZ GÓMEZ y JONATHAN CARRERO ARANDA
*	------------------------------------------------------------
*	PRÁCTICA 6: ¿ES UN MONTÍCULO?
*	------------------------------------------------------------
*
*	El problema se resuelve ayudandonos de las funciones auxiliares (completo, semicompleto y altura),
*	ya que un montículo es semicompleto y cada elemento es menor o igual al resto de sus hijos.
*/
#include <math.h>
#include <iostream>
#include "BinTree.h"
#include <algorithm>

using namespace std;

BinTree<int> leeArbol();
int altura(BinTree<int> arbol);
void resuelveCaso(BinTree<int> arbol);
bool es_Completo(BinTree<int> arbol);
bool es_Semicompleto(BinTree<int> arbol);
bool es_Monticulo(BinTree<int> arbol);
bool menor_igual(BinTree<int> arbol, int padre);


/*
*	Resumen: lee un árbol binario de la entrada estandar.
*
*	Complejidad: tiene un coste O(n) en el caso peor, donde 'n' es el número de nodos leídos del árbol.
*/
BinTree<int> leeArbol()
{
	int root;

	cin >> root;
	if(root==-1)
		return BinTree<int>();
	else
	{
		const BinTree<int> &iz = leeArbol();
		const BinTree<int> &dr = leeArbol();
		return BinTree<int>(iz, root, dr);
	}
}

/*
*	Resumen: resuelve un caso de prueba, leyendo de la entrada y escribiendo la respuesta.
*
*	Complejidad: ¿  ?
*/
void resuelveCaso(){

	BinTree<int> arbol;

	arbol = leeArbol();

	if(es_Monticulo(arbol))
	cout <<"SI" << endl;
	else cout <<"NO" << endl;
} 

/*	
*	Resumen: dado un árbol binario calcula su altura.
*
*	Complejidad: comprobar la altura de un árbol binario semicompleto formado por N nodos es O(log n) + 1. 
*	Si el árbol es completo, la complejidad es la misma porque de un árbol semicompleto a uno completo
*	podemos pasar en un tiempo O(1).
*/
int altura(BinTree<int> arbol){
	if (arbol.empty()){
		return 0;
	}else{
		return 1 + max(altura(arbol.left()),altura(arbol.right()));
	}
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
*	Resumen: función que dado un arbol binario comprueba si es montículo. Dev bool.
*	
*	Complejidad: puesto que en un árbol binario la operación de búsqueda (en el caso peor) está en O(n), vamos a tener
*	una complejidad O(n) donde 'n' representa el número de nodos del árbol
*/
bool es_Monticulo(BinTree<int> arbol){
	if(arbol.empty()){ 

		return true;

	}else return (	es_Semicompleto(arbol) && 
					menor_igual( arbol.left(),arbol.root() ) &&
					menor_igual( arbol.right(),arbol.root() ) &&
					es_Monticulo( arbol.left() ) &&
					es_Monticulo( arbol.right()) );
}

/*
*	Resumen: función que dado un arbol binario comprueba si es Semicompleto: es semicompleto si o bien es completo
*	o tiene vacantes una serie de posiciones consecutivas del ultimo nivel empezando por la derecha, de tal manera 
*	que al rellenar dichas posiciones con nuevas hojas se obtiene un arbol completo.
*
*	Complejidad: para ver si un árbol es semicompleto hay que ver que sea completo. Ver si es completo tiene una complejidad
*	O(n) en el caso peor, pues hay que ver que TODOS los nodos tienen dos hijos (donde 'n' es el número de nodos). También puede
*	ser semicompleto, pero en ese caso también tendríamos un coste O(n), pues solo faltarían nodos pertenecientes al último
*	nivel del árbol.
*/
bool es_Semicompleto(BinTree<int> arbol){
	if(arbol.empty()) 
		return true;
	else if (es_Completo(arbol)) return true;
	else return (
					((altura(arbol.left())==altura(arbol.right())) && es_Completo(arbol.left()) && es_Semicompleto(arbol.right())) ||
				(   (altura(arbol.left())==altura(arbol.right())+1) && es_Completo(arbol.right()) && es_Semicompleto(arbol.left()))
				);
		
}

/*
*	Resumen: función que averigua si un arbol es completo: es completo cuando todos sus nodos internos tienen dos hijos 
*	no vacıos, y todas sus hojas estan al mismo nivel.
*
*	Complejidad: ver si es semicompleto o completo tiene la misma complejidad, pues la única diferencia se encuentra en el
*	número de nodos del último nivel (y esa diferencia es una constante). Es decir O(n) en el caso peor.
*/
bool es_Completo(BinTree<int> arbol){
	if(arbol.empty()) 
		return true;
	else 
		return (	es_Completo(arbol.left()) && 
					es_Completo(arbol.right()) && 
					 (altura(arbol.left()) == altura(arbol.right()))
			   );
}

/*
*	Resumen: función que nos sirve para determinar si un elemento es menor o igual que todos los elementos en un arbol binario.	
*
*	Complejidad: también tiene un coste O(n) pues hay que recorrer todo el árbol binario donde de nuevo, 'n' hace referencia
*	al número de nodos que tiene el árbol.
*/
bool menor_igual(BinTree<int> arbol, int padre){
	if(arbol.empty()) return true;
	else return (
					padre <= arbol.root() && 
					menor_igual(arbol.right(),arbol.root()) && 
					menor_igual(arbol.left(),arbol.root())
				);
}