#include<iostream>
#include <stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct {
	long long inicio;
	long long fin;
} tFecha;


struct myclass {
	bool operator() (tFecha i, tFecha j) { return (i.inicio>j.inicio); }
} myobject;

bool resuelveCaso() {

	int  N;							// numero de conferencias
	cin >> N;

	if (!cin) {
		return false;
	}
	vector<tFecha> vectorFechas(N);	// vector de fechas (inicio, fin)

	tFecha fecha;								 //leemos fechas
	
	for (int  i = 0; i < N; i++)
	{
		cin >> fecha.inicio;
		cin >> fecha.fin;
		vectorFechas.push_back(fecha);
	}
												 // ordenamos fecha inicio mayor								
	sort(vectorFechas.begin(), vectorFechas.end(), myobject);

	int num_Min_Salas = 1;
	tFecha  actual = vectorFechas[N - 1];

	for (int i = N-1; i >  0 ; i--){
		
		tFecha  siguiente = vectorFechas[i - 1];
		if (actual.fin <= siguiente.inicio) {
			
			actual = siguiente;
		}
		else {
			num_Min_Salas++;
		}
	}

	cout << num_Min_Salas << endl;
	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}