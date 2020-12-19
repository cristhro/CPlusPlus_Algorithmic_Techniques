#include "PajarosEnVuelos.h"

//inserta la pareja en las colas de maximos o de minimos
// En el peor de los casos O(log N ) 
void PajarosEnVuelos::insertarPareja(int a, int b) {

	if (son_Menores_que_Lider(a, b)) {
		//metemos a y b en la cola maximos de los elementos mas pequeños 
		colaMaximos.push(a);
		colaMaximos.push(b);
		//metemos el lider en la cola de minimos de los elementos mas grandes
		colaMinimos.push(Lider);
		// quita el lider de la cola de de maximos 
		colaMaximos.pop(Lider);
	}
	else if (son_Mayores_que_Lider(a, b)) {
		//metemos a y b en la cola minimos de los elementos mas grandes 
		colaMinimos.push(a);
		colaMinimos.push(b);
		//metemos el lider en la cola de maximos de los elementos mas pequeños
		colaMaximos.push(Lider);
		// quita el lider de la cola de de minimos 
		colaMinimos.pop(Lider);
	}
	else if (a < Lider && b > Lider) {
		//metemos a en la cola maximos de los elementos mas pequeños 
		colaMaximos.push(a);
		//metemos b en la cola minimos de los elementos mas grande
		colaMinimos.push(b);
	}
	else if (a > Lider && b < Lider) {
		//metemos a en la cola minimos de los elementos mas grande
		colaMinimos.push(a);
		//metemos b en la cola maximos de los elementos mas pequeños 
		colaMaximos.push(b);
	}
}

// devuelve la edad del lider
int PajarosEnVuelos::edadLider() {
	return  Lider;
}
bool PajarosEnVuelos::son_Mayores_que_Lider(int a, int b) {
	return(a > Lider && b > Lider);
}
bool PajarosEnVuelos:: son_Menores_que_Lider(int a, int b) {
	return(a < Lider && b < Lider);
}