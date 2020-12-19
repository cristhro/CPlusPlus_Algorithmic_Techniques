#include "ColaUrgencias.h"

bool operator>= (tPaciente a, tPaciente b) {
	if (a.gravedad > b.gravedad) return true;
	else if (a.gravedad == b.gravedad && a.orden < b.orden) return true;
	else return false;
}
// funcion que inserta en la cola de prioridad de macximos  
// O(log n) donde n es el numero de elementos que tiene la cola
void ColaUrgencias::insertar(std::string nombre, int gravedad){
	
	paciente.gravedad = gravedad;
	paciente.nombre = nombre;
	paciente.orden += 1;

	elementos.push(paciente);
}
//Funcion que devuelve si existen elementos en la cola.
//O(1)
bool ColaUrgencias::esVacia() const{

	return elementos.empty();
}

//Obtenemos el  primero (el mas prioritario)
// O(1)
std::string  ColaUrgencias::nombrePrimero() const{
	tPaciente prioritario;

	prioritario = elementos.top();

	return prioritario.nombre;
}
//Funcion que elimina el elemento mas prioritario
//O(n)  donde n es el numero de elementos que tiene la cola
void ColaUrgencias::quitarPrimero(){

	elementos.pop();
}
