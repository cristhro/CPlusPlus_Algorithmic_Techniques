#include "ColaUrgencias.h"

bool operator>= (tPaciente a, tPaciente b) {
	if (a.gravedad > b.gravedad) return true;
	else if (a.gravedad == b.gravedad && a.orden < b.orden) return true;
	else return false;
}
void ColaUrgencias::insertar(std::string nombre, int gravedad){
	
	paciente.gravedad = gravedad;
	paciente.nombre = nombre;
	paciente.orden += 1;

	elementos.push(paciente);
}
bool ColaUrgencias::esVacia() const{

	return elementos.empty();
}

//Obtenemos el mas primero ,(el mas prioritario)
// O(1)
std::string  ColaUrgencias::nombrePrimero() const{
	tPaciente prioritario;

	prioritario = elementos.top();

	return prioritario.nombre;
}
void ColaUrgencias::quitarPrimero(){

	elementos.pop();
}
