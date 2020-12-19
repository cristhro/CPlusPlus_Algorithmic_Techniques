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

int solucion(vector<tIntervalo> & intervalos, tIntervalo &expuesto) {

	int num_min_trabajos = 0;
	int i = 0;
	int j = 1;							// siguiente
	bool ok = false;

	sort(intervalos.begin(), intervalos.end());
	
	int fin = intervalos[0].finalizacion;
	int comienzo = intervalos[0].comienzo;
	if (intervalos[0].comienzo > expuesto.comienzo){

		num_min_trabajos = -1;			// imposible
	}
	else{

		num_min_trabajos++;

		// recorrer todo el array hasta llegar el expuesto.finalizacion
		while (j < intervalos.size() && !ok){
			
			//// si no hay saltos
			//if (intervalos[j].comienzo <= fin){

			//	// si encuentra un elemento mas granque que fin
			//}
			//else 
			/*if (intervalos[j].comienzo <= fin && intervalos[j].comienzo >= comienzo){
			
			}*/
			if (intervalos[j].comienzo >= fin){

					fin = intervalos[j].finalizacion;
					comienzo = intervalos[j].comienzo;

					while (i < j){

						if (intervalos[i].finalizacion > fin)
						{
							fin = intervalos[i].finalizacion;

						}
						i++;
					}

					i = j;

					if (fin >= expuesto.finalizacion){
						ok = true;
					}

					num_min_trabajos++;
			}
			j++;
		}
	}
	
	

	return num_min_trabajos;
}
bool resuelveCaso() {

	int  N;		
	tIntervalo expuesto;// numero de conferencias
	cin >> expuesto.comienzo;
	cin >> expuesto.finalizacion;
	cin >> N;

	if (N == 0 && expuesto.comienzo == 0 && expuesto.finalizacion == 0) {
		return false;
	}
	vector<tIntervalo> intervalos(N);				 // vector de intervalos (comienzo, finalizacion)

	tIntervalo ;								 // leemos fechas

	for (int i = 0; i < N; i++)
	{
		cin >> intervalos[i].comienzo;
		cin >> intervalos[i].finalizacion;
	}

	cout << solucion(intervalos, expuesto) << endl;

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}