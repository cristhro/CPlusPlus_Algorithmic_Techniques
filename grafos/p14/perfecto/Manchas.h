#ifndef MANCHAS_H
#define MANCHAS_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "ConjuntosDisjuntos_modificado.h"
#include "Matriz.h"
using namespace std;

template <class T>
class Manchas {
public:
	/* constructor */
	Manchas(int rows, int cols) :m_manchas (rows,cols), casilla(rows, cols), conjunto(rows*cols), num_max_mancha(0)
	{
		m_cols = cols;
		m_rows = rows;

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
	}

	int mancha_mas_grande() {
		return num_max_mancha;
	}

private:
	T m_ele;
	Matriz<T>m_manchas;
	Matriz<int>  casilla;
	int m_cols;
	int m_rows;
	ConjuntosDisjuntos conjunto;
	int num_max_mancha;

	void Connected(int f, int c) {

		// conectado a la izq
		if (esta_en_el_Rango(f, c - 1))
		{
			conjunto.unir(casilla[f][c], casilla[f][c - 1]);
		}

		// conectado hacia arriba 
		if (esta_en_el_Rango(f - 1, c))
		{
			conjunto.unir(casilla[f][c], casilla[f - 1][c]);
		}

	}
	bool esta_en_el_Rango(int f, int c)
	{
		if ((c >= 0 && c < m_cols) && (f >= 0 && f < m_rows)) {
			if (m_manchas[f][c] == ' ') return false;
			else return true;
		}
		else return false;
	}
	

};

#endif  // MANCHAS_H