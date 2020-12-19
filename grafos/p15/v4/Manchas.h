#ifndef MANCHAS_H
#define MANCHAS_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "ConjuntosDisjuntos_modificado.h"
using namespace std;

template <class T>
class Manchas {
public:
	/* constructor */
	Manchas(int rows, int cols) :conjunto(rows*cols),  num_max_mancha(0)
	{
		m_cols = cols;
		m_rows = rows;

		//m_manchas[rows][cols];
		//casilla[rows][cols];
		//creamos matrices dinamicas
		m_manchas = new T*[m_rows];
		casilla = new int*[m_rows];
		
		for (int i = 0; i < m_rows; i++) 
		{
			m_manchas[i] = new T[m_cols];
			casilla[i] = new int[m_cols];
		}
	}
	void read_by_user() {

		int elemNumerico = 0;
		// recorre las filas
		for (int i = 0; i < m_rows; i++) 
		{
			// recorre las columnas
			for (int j = 0; j < m_cols; j++) 
			{
				cin.get(m_ele);
				m_manchas[i][j] = m_ele;
				casilla[i][j] = elemNumerico;
				elemNumerico++;

				if (m_manchas[i][j] == '#') 
				{
					//si es mancha puede conectarse...
					Connected(i, j);

					// averiguar el conjunto al que pertenece p
					int  conj = conjunto.buscar(casilla[i][j]);
					
					// recojer numero de elementos  del conjunto c
					int tam = conjunto.num_elem_conjunto(conj);
					
					if (tam > num_max_mancha)
						num_max_mancha = tam;
				}
			
			}
			cin.ignore();
		}
		//dfs_mancha();
	}
	
	void pon_Pixel(int f, int c) {
		
		m_manchas[f][c] = '#';
			
		    // conectar mancha individual
			conectarManchaNueva(f, c);
			
			// averiguar el conjunto al que pertenece p
			int conj = conjunto.buscar(casilla[f][c]);
				// recojer numero de elementos  del conjunto c
			int tam = conjunto.num_elem_conjunto(conj);

			if (tam > num_max_mancha)
			num_max_mancha = tam;
	}
	int mancha_mas_grande() {
		return num_max_mancha;
	}
	
private:
	T m_ele;
	T	 **m_manchas;
	int  **casilla;
	int m_cols;
	int m_rows;
	ConjuntosDisjuntos conjunto;
	int num_max_mancha;

	void Connected(int f, int c) {

		// conectado a la izq
		if (ConnectedTo(f, c - 1)) 
		{
			conjunto.unir(casilla[f][c], casilla[f][c - 1]);
		}
	
		// conectado hacia arriba 
		if (ConnectedTo(f - 1, c))
		{
			conjunto.unir(casilla[f][c], casilla[f-1][c ]);
		}
	
	}					
	bool ConnectedTo(int f, int c)
	{
		if ((c >= 0 && c < m_cols) && (f >= 0 && f < m_rows)) {
			if (m_manchas[f][c] == ' ') return false;
			else return true;
		}
		else return false;
	}
	void conectarManchaNueva(int f, int c) {
		// conectado a la izq
		if (ConnectedTo(f, c - 1))
		{
			conjunto.unir(casilla[f][c], casilla[f][c - 1]);
		}
		//// conectado a la der 
		if (ConnectedTo(f, c + 1))
		{
			conjunto.unir(casilla[f][c], casilla[f][c + 1]);
		}
		// conectado hacia arriba 
		if (ConnectedTo(f - 1, c))
		{
			conjunto.unir(casilla[f][c], casilla[f - 1][c]);
		}
		// conectado hacia abajo
		if (ConnectedTo(f + 1, c))
		{
			conjunto.unir(casilla[f][c], casilla[f + 1][c]);
		}
	}
	/*bool connected_toWest(int f, int c) 
	{
		if ((c >= 0 && c < m_cols) && (f >= 0 && f < m_rows)) 
		{
			if (m_marked[f][c] ) return false;
			else return true;
		}
		else return false;
	}
	bool connected_toEst(int f, int c) {
		if ((c >= 0 && c < m_cols) && (f >= 0 && f < m_rows)) {
			if (m_marked[f][c]) return false;
			else return true;
		}
		else return false;
	}
	bool connected_toNorth(int f, int c) {
		if ((c >= 0 && c < m_cols) && (f >= 0 && f < m_rows)) {
			if (m_marked[f][c]) return false;
			else return true;
		}
		else return false;
	}
	bool connected_toSouth(int f, int c) {
		if ((c >= 0 && c < m_cols) && (f >= 0 && f < m_rows)) {
			if (m_marked[f][c]) return false;
			else return true;
		}
		else return false;
	}*/
	//void delete_manchas()
	//{
	//	for (int i = 0; i < m_rows; i++) {
	//		delete[] m_manchas[i];
	//	}
	//	delete[] m_manchas;
	//}
	//void delete_marked()
	//{
	//	for (int i = 0; i < m_rows; i++) {
	//		delete[] m_marked[i];
	//	}
	//	delete[] m_marked;
	//}
	//void print_marked()
	//{
	//	for (int i = 0; i < m_rows; i++)
	//	{
	//		for (int j = 0; j < m_cols; j++) {
	//			cout << m_marked[i][j] << " ";
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//}
	//void print_Manchas()
	//{
	//	for (int i = 0; i < m_rows; i++)
	//	{
	//		for (int j = 0; j < m_cols; j++) {
	//			cout << m_manchas[i][j];
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//}
	//void actualizar_marked() {
	//	for (int i = 0; i < m_rows; i++) {
	//		// recorre las columnas
	//		for (int j = 0; j < m_cols; j++) {
	//			//  actualizamor el marcaje
	//			if (m_manchas[i][j] == ' ') {
	//				m_marked[i][j] = true;
	//			}
	//			else {
	//				m_marked[i][j] = false;
	//			}
	//		}
	//	}
	//}
};

#endif  // MANCHAS_H