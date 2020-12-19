// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
	PRACTICA 6
	¿Es un Monticulo ?
	El problema se resuelve ayudandonos de las funciones auxiliares, ( completo, semicompleto, altura)
	ya que un monticulo es semicompleto y cada elemento es menor o igual al resto de sus hijos.

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

// lee un árbol binariio de la entrada estandar
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


//Resuelve un cado de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
void resuelveCaso(){

	BinTree<int> arbol;

	arbol = leeArbol();

	if(es_Monticulo(arbol))
	cout <<"SI" << endl;
	else cout <<"NO" << endl;
} 



// dado un árbol binario, calcula su altura.
// coste lineal en el número N de nodos del árbol, O(N)
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
	Funcion que dado un arbol binario comprueba si es Monticulo. dev bool.

	Monticulo es  un arbol binario semicompleto donde cada elemento es menor o igual
	que sus hijos.

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
	Funcion que dado un arbol binario comprueba si es Semicompleto. 

	es semicompleto si o bien es completo o tiene vacantes una serie de
	posiciones consecutivas del ultimo nivel empezando por la derecha, de tal manera que al rellenar dichas
	posiciones con nuevas hojas se obtiene un arbol completo.
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
	funcion que averigua si un arbol es completo: 

	es completo cuando todos sus nodos internos tienen dos hijos no vacıos, y todas
	sus hojas estan al mismo nivel.
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
	Funcion que nos sirve para determinar si un elemento es menor o igual que todos los elementos en un arbol binario	
*/
bool menor_igual(BinTree<int> arbol, int padre){
	if(arbol.empty()) return true;
	else return (
					padre <= arbol.root() && 
					menor_igual(arbol.right(),arbol.root()) && 
					menor_igual(arbol.left(),arbol.root())
				);
}