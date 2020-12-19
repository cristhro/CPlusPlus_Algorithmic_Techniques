/*
*	------------------------------------------------------------
*	TAIS21 - CRISTHIAN RODRIGUEZ GÓMEZ y JONATHAN CARRERO ARANDA
*	------------------------------------------------------------
*	PRÁCTICA 6: ¿ES UN MONTÍCULO?
*	------------------------------------------------------------
*
*	El problema se resuelve ayudandonos de las funciones auxiliares (completo, semicompleto y altura),
*	ya que un montículo es semicompleto y cada elemento es menor o igual al resto de sus hijos.
*   O(n) n 
*/
#include <math.h>
#include <iostream>
#include "BinTree.h"
#include <algorithm>

using namespace std;

const BinTree<int> leeArbol();
void resuelveCaso();
bool es_Monticulo(const BinTree<int> &arbol);
bool menor_igual(const BinTree<int> &arbol, int padre);
bool es__Monticulo(const BinTree<int> &arbol, int &altura, bool &esCompleto, bool &esSemicompleto);
/*
*	Resumen: lee un árbol binario de la entrada estandar.
*
*	Complejidad: tiene un coste O(n) en el caso peor, donde 'n' es el número de nodos leídos del árbol.
*/
const BinTree<int> leeArbol()
{
	int root;

	cin >> root;
	if(root == -1)
		return{};
	else
	{
		 const BinTree<int> &iz = leeArbol();
		 const BinTree<int> &dr = leeArbol();
		 return BinTree<int>{iz, root, dr};
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



int main(){
	int numCasos;

	cin >>numCasos;
	
	for (int i = 0; i < numCasos; i++)
	{
		resuelveCaso();
	}
	system("PAUSE");
	return 0;
}
/*	
*	Resumen: dado un árbol binario calcula su altura.
*
*	Complejidad: comprobar la altura de un árbol binario semicompleto formado por N nodos es O(log n) + 1. 
*	Si el árbol es completo, la complejidad es la misma porque de un árbol semicompleto a uno completo
*	podemos pasar en un tiempo O(1).
*/
/*
*	Resumen: función que dado un arbol binario comprueba si es montículo. Dev bool.
*	
*	Complejidad: puesto que en un árbol binario la operación de búsqueda (en el caso peor) está en O(n), vamos a tener
*	una complejidad O(n) donde 'n' representa el número de nodos del árbol
*/
bool es_Monticulo(const BinTree<int> &arbol){
	int altura;
	bool esCompleto;
	bool esSemicompleto;
	if (arbol.empty()){
		
		return true;
	}
	else{

		return es__Monticulo(arbol, altura, esCompleto, esSemicompleto);
	}
	
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
bool menor_igual(const BinTree<int> &arbol, int padre){
	if(arbol.empty()) return true;
	else return (
					padre <= arbol.root() && 
					menor_igual(arbol.right(),arbol.root()) && 
					menor_igual(arbol.left(),arbol.root())
				);
}

bool es__Monticulo(const BinTree<int> &arbol, int &altura, bool &esCompleto, bool &esSemicompleto){
	int  altura_IZ = 0 ,				 altura_DR = 0;
	bool esSemi_IZ = false,				 esSemi_DR = false;
	bool  esCom_IZ = false,				  esCom_DR = false;
	bool esMonticulo_IZ = false,	esMonticulo_DR = false;


	altura = 0;
	esCompleto = false;
	esSemicompleto = false;
	
	if (arbol.empty()){
		// actualizamos la altura

		altura = 0;
		esCompleto = true;
		esSemicompleto = true;
		return true;
	
	}
	else { //visitamos los dos hijos
	
		esMonticulo_IZ = es__Monticulo(arbol.left(), altura, esCompleto, esSemicompleto);
		altura_IZ = altura; esCom_IZ = esCompleto;  esSemi_IZ = esSemicompleto;

		esMonticulo_DR = es__Monticulo(arbol.right(), altura, esCompleto, esSemicompleto);
		altura_DR = altura; esCom_DR = esCompleto;  esSemi_DR = esSemicompleto;

	}
	
	// actualizamos la altura
	altura = 1 + max(altura_IZ, altura_DR);

	if (altura_IZ == altura_DR){

		esCompleto = true, esSemicompleto = true;

	}
	else {
		esCompleto = false, esSemicompleto = false;
	
	}
	//actualizamos esSemicompleto
	if (
		(altura_IZ == altura_DR && esCom_IZ && esSemi_DR) ||
		((altura_IZ == altura_DR + 1) && esCom_DR && esSemi_IZ)
		){

		esSemicompleto = true;
	}
	else esSemicompleto = false;

	//vemos si cumple los requisitos de monticulo
	if (
		esSemicompleto &&
		menor_igual(arbol.left(), arbol.root()) &&
		menor_igual(arbol.right(), arbol.root()) &&
		esMonticulo_IZ &&
		esMonticulo_DR
		) {

		return true;
	}
	else{
		return false;
	}
}