#include<iostream>
#include <stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct {

	long long inicio;
	long long fin;

} tFecha;



bool operator < (tFecha a, tFecha b) {
	return a.inicio < b.inicio;
}

int solucion(	const vector<tFecha> & pareja_horas) {
	int min_num_salas_ocupadas = 0;			// k =0
	vector <int> tiempo(pareja_horas.size()+ 1);
	
	// ordenamos fecha inicio mayor								
	sort(pareja_horas.begin(), pareja_horas.end(), less<tFecha>());
	
	
	// INICIALIZA EL TIEMPO
	for (size_t i = 0; i < pareja_horas.size() + 1; i++)
	{
		tiempo[i] = 0;
	}

	for (int i = 0; i < pareja_horas.size(); i++)
	{
		int j = 1;

		while (j<= min_num_salas_ocupadas && tiempo[j] > pareja_horas[i].inicio)
		{
			j++;
		}

		if (j <= min_num_salas_ocupadas) {

			tiempo[j] = pareja_horas[i].fin;
		}
		else {	// SE OCUPA UNA NUEVA SALA

			min_num_salas_ocupadas++;
			tiempo[min_num_salas_ocupadas] = pareja_horas[i].fin;
		}
	}




	return min_num_salas_ocupadas;
}
bool resuelveCaso() {

	int  N;									   	 // numero de conferencias
	cin >> N;

	if (N == 0) {
		return false;
	}
	vector<tFecha> vectorFechas(N);				 // vector de fechas (inicio, fin)

	tFecha fecha;								 // leemos fechas
	
	for (int  i = 0; i < N; i++)
	{
		cin >> fecha.inicio;
		cin >> fecha.fin;
		vectorFechas[i]=fecha;
	}

	//int num_Min_Salas = 1;
	//tFecha  actual = vectorFechas[N - 1];
	//for (int i = N-1; i >  0 ; i--){
	//	
	//	tFecha  siguiente = vectorFechas[i - 1];
	//	if (actual.fin <= siguiente.inicio) {
	//		
	//		actual = siguiente;
	//	}
	//	else {
	//		num_Min_Salas++;
	//	}
	//}

	cout << solucion(vectorFechas) << endl;
	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}