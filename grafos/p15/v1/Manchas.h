#ifndef MANCHAS_H
#define MANCHAS_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

template <class T>
class Manchas {
public:
	/* constructor */
	Manchas(int rows, int cols) : num_max_mancha(0)
	{
		m_cols = cols;
		m_rows = rows;

		//creamos matrices dinamicas
		m_manchas = new T*[m_rows];
		m_marked = new bool*[m_rows];

		for (int i = 0; i < m_rows; i++) {
			m_manchas[i] = new T[m_cols];
		}
		for (int i = 0; i < m_rows; i++) {
			m_marked[i] = new bool[m_cols];
		}
	}
	void read_by_user() {
		// recorre las filas
		for (int i = 0; i < m_rows; i++) {
			// recorre las columnas
			for (int j = 0; j < m_cols; j++) {
				cin.get(m_ele);
				m_manchas[i][j] = m_ele;

				//  actualizamor el marcaje
				if (m_manchas[i][j] == ' ') {
					m_marked[i][j] = true;
				}
				else {
					m_marked[i][j] = false;
				}
			
			}
			cin.ignore();
		}
	}
	void pon_Pixel(int f, int c) {
		m_manchas[f][c] = '#';
		m_marked[f][c] = false;
		num_max_mancha = 0;
		
		actualizar_marked();
		
		dfs_mancha();
	}
	int mancha_mas_grande() {
		return num_max_mancha;
	}
	
private:
	T m_ele;
	T **m_manchas;
	bool **m_marked;
	int m_cols;
	int m_rows;
	int num_max_mancha;
	

	void dfs_mancha(){
		int cont = 0;   // contador = 0

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++)
			{
				if (!m_marked[i][j]) {	// si no esta marcado
					cont = 1;
					num_Connected(i, j, cont);	// contamos cuantas marcas tiene

					if (cont > num_max_mancha)
						num_max_mancha = cont;
				}
			}

		}
	}
	void num_Connected(int f, int c, int &cont) {
		// marcamos la casilla visitada
		m_marked[f][c] = true;

		// conectado a la izq
		if (connected_toWest(f, c - 1)) {
			cont++;
			num_Connected(f, c - 1, cont);
		}
		// conectado a la der 
		if (connected_toEst(f, c + 1))
		{
			cont++;
			num_Connected(f, c + 1, cont);
		}
		// conectado hacia arriba 
		if (connected_toNorth(f - 1, c))
		{
			cont++;
			num_Connected(f - 1, c, cont);
		}
		// conectado hacia abajo
		if (connected_toSouth(f + 1, c))
		{
			cont++;
			num_Connected(f + 1, c, cont);
		}



	}
	bool connected_toWest(int f, int c) {
		if (c >= 0 && c < m_cols) {
			if (m_marked[f][c])return false;
			else return true;
		}
		else return false;
	}
	bool connected_toEst(int f, int c) {
		if (c >= 0 && c < m_cols) {
			if (m_marked[f][c])return false;
			else return true;
		}
		else return false;
	}
	bool connected_toNorth(int f, int c) {
		if (f >= 0 && f < m_rows) {
			if (m_marked[f][c])return false;
			else return true;
		}
		else return false;
	}
	bool connected_toSouth(int f, int c) {
		if (f >= 0 && f < m_rows) {
			if (m_marked[f][c])return false;
			else return true;
		}
		else return false;
	}
	void delete_manchas()
	{
		for (int i = 0; i < m_rows; i++) {
			delete[] m_manchas[i];
		}
		delete[] m_manchas;
	}
	void delete_marked()
	{
		for (int i = 0; i < m_rows; i++) {
			delete[] m_marked[i];
		}
		delete[] m_marked;
	}
	void print_marked()
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++) {
				cout << m_marked[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	void print_Manchas()
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++) {
				cout << m_manchas[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	void actualizar_marked() {
		for (int i = 0; i < m_rows; i++) {
			// recorre las columnas
			for (int j = 0; j < m_cols; j++) {
				//  actualizamor el marcaje
				if (m_manchas[i][j] == ' ') {
					m_marked[i][j] = true;
				}
				else {
					m_marked[i][j] = false;
				}
			}
		}
	}
};

#endif  // MANCHAS_H