// Grupo 21, CRISTHIAN RODRIGUEZ GOMEZ y JONATHAN CARRERO ARANDA

/*
				PRACTICA 8: Ordenando a los pacientes en urgencias
				---------------------------------------------------

		Para resolver este ejercicio hemos creado una estructura auxiliar Paciente que guarda
		la gravedad y su nombre, obtenemos la lista de pacientes curados con la funcion Pacientes_curados()
		luego lo mostramos con la funcion muestra_lista().
*/
#include <iostream>
#include <string>
#include "PriorityQueue.h"
using namespace std;

typedef struct {
	int gravedad; 
	int pos;
	string nombre;
}tPaciente;

bool operator< (tPaciente a, tPaciente b){
	return (a.gravedad < b.gravedad);
}
bool operator> (tPaciente a, tPaciente b){
	return (a.gravedad > b.gravedad );
}
bool operator>= (tPaciente a, tPaciente b) {
	if (a.gravedad > b.gravedad) return true;
	else if (a.gravedad == b.gravedad && a.pos < b.pos) return true;
	else return false;
}
/*
	Funcion que 
	si el evento es  "I",
		lee los pacientes de la entrada estandar y los inserta en la cola de prioridad
	si el evento es "A" 
		lo insera en una lista . 
	
	devuelve la lista.

	Complejidad O(n) segun el numero de elementos
*/

vector<string> Pacientes_Curados(int num_Elems){
	tPaciente paciente;

	PriorityQueue<tPaciente, greater_equal<tPaciente>> cola;
	string evento;

	vector<string> lista;
	int i = 0;

	while( i < num_Elems)
	{
		//LEER EVENTO
		cin >> evento;

		if (evento == "I"){
		

			cin >> paciente.nombre;
			cin >> paciente.gravedad;
			paciente.pos = i;
			cola.push(paciente);
			i++;

		}
		else if (evento == "A" && !cola.empty()){
			//PriorityQueue<tPaciente, greater_equal<tPaciente>> colaAux;
			tPaciente prioritario;
			tPaciente aux;

			prioritario = cola.top();
			cola.pop();
			
		/*	aux = cola.top(); cola.pop();
				cola.push(aux);*/

			lista.push_back(prioritario.nombre);
			i++;

		}

	}
	return lista;
}
/*
	muestra la lista

	Complejidad O(n) segun el numero de elementos que tiene la lista.
*/
void mostrar_lista(vector<string> lista){
	for (size_t i = 0; i < lista.size(); i++)
	{
		cout << lista.at(i) << endl;
	}
}

void resuelveCaso(int num_Elems){

	vector<string> lista;

	// FUNCION PACIENTES CURADOS
	lista = Pacientes_Curados(num_Elems);

	//MOSTRAR PACIENTES
	mostrar_lista(lista);

	cout << "----" << endl;
}

int main(){

	int numCasos;

	cin >> numCasos;

	while (numCasos != 0)
	{
		resuelveCaso(numCasos);
		cin >> numCasos;
	}

	return 0;
}