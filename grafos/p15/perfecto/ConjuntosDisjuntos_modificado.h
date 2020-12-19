#ifndef CONJUNTOSDISJUNTOS_MODIFICADO_H_
#define CONJUNTOSDISJUNTOS_MODIFICADO_H_

#include <vector>
#include <iostream>

class ConjuntosDisjuntos {
public:

	// crea una estructura de partición con los elementos 0..N-1, cada uno en un conjunto
	ConjuntosDisjuntos(size_t N);

	// devuelve el número de conjuntos disjuntos
	size_t count() const { return _count; }

	//  devuelve el identificador del conjunto que contiene a p
	size_t buscar(size_t p) const;

	// unir los conjuntos que contengan a p y q
	void unir(size_t p, size_t q);

	// muestra el array por la salida o 
	void print(std::ostream& o = std::cout) const;

	//devuelve el numero de elementos que tiene el conjunto
	size_t num_elem_conjunto(size_t c);

protected:
	size_t size;             // los elementos son 0 .. size-1
	size_t _count;           // número de conjuntos disjuntos
	std::vector<int> numElemConj;
	mutable std::vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tamaño del conjunto de i

};

std::ostream& operator<<(std::ostream & o, ConjuntosDisjuntos const& a);
#endif