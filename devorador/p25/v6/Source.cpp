#include<iostream>
#include <stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct {

	int comienzo;
	int finalizacion;

} tIntervalo;

bool operator < (tIntervalo a, tIntervalo b) {
	return a.comienzo < b.comienzo;
}

int solucion(vector<tIntervalo> intervalos, tIntervalo expuesto) {

	int num_min_trabajos = 1;
	int j = 1;							// siguiente
	bool ok = false;
	
	sort(intervalos.begin(), intervalos.end(), less<tIntervalo>());
	
	int  fin = intervalos[0].finalizacion;
	int  fin_mayor = fin;
	int  comienzo = intervalos[0].comienzo;

	if (comienzo > expuesto.comienzo){

		num_min_trabajos = -1;			// imposible
	}
	else{

		// tamaño vector
		int  tam = intervalos.size();

		//si es solucion el primer intervalo
		if (intervalos[0].finalizacion >= expuesto.finalizacion) {
				ok = true;
		}

		// recorrer todo el array hasta que ok sea igual a true
		while (j < tam && !ok ){

			// busca el intervalo de finalizacion mas grande
			if (intervalos[j].finalizacion > fin)
			{
				fin_mayor = intervalos[j].finalizacion;

			}
			// si hay un salto paramos
			if (intervalos[j].comienzo > fin) {
				ok = true;
				num_min_trabajos = -1;
			}

			//si siguiente es solucion paramos (llegamos al final del expuesto)
			else if (intervalos[j].finalizacion >= expuesto.finalizacion) {
				num_min_trabajos++;
				ok = true;
			}

			// si continua buscando por el siguiente Intervalo 
			if (intervalos[j].comienzo >= fin && !ok ){

					fin = fin_mayor;
					comienzo = intervalos[j].comienzo;

					if (fin >= expuesto.finalizacion){
						ok = true;
					}

					num_min_trabajos++;
			}

			j++;
		
		}

		if (fin_mayor < expuesto.finalizacion)
			num_min_trabajos = -1;
	}
	
	

	return num_min_trabajos;
}
bool resuelveCaso() {

	int   N;		
	tIntervalo expuesto;// numero de conferencias

	cin >> expuesto.comienzo;
	cin >> expuesto.finalizacion;
	cin >> N;

	if (N == 0 && expuesto.comienzo == 0 && expuesto.finalizacion == 0) {
		return false;
	}
	
	vector<tIntervalo> intervalos(N);				 // vector de intervalos (comienzo, finalizacion)

	for (int i = 0; i < N; i++)
	{
		cin >> intervalos[i].comienzo;
		cin >> intervalos[i].finalizacion;
	}

	int sol = solucion(intervalos, expuesto);

	if ( sol == -1){

		cout << "Imposible" << endl;
	}
	else{

		cout << sol << endl;
	}


	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}