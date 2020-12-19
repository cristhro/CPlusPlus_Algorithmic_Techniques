#include "ConjuntosDisjuntos_modificado.h"

ConjuntosDisjuntos::ConjuntosDisjuntos(size_t N) : numElemConj(N, 1), size(N), _count(size), id(size, -1) {}

size_t ConjuntosDisjuntos::buscar(size_t p) const {
	if (id[p] < 0) // es una raíz
		return p;
	else
		return id[p] = int(buscar(id[p]));
}

// unir los conjuntos que contengan a p y q
void ConjuntosDisjuntos::unir(size_t p, size_t q) {
	auto i = buscar(p);
	int Elem_i = numElemConj[i];
	auto j = buscar(q);
	int Elem_j = numElemConj[j];

	if (i == j) return;
	if (id[i] < id[j]) { // i es la raíz del mayor árbol
		id[i] += id[j]; id[j] = int(i);
		numElemConj[i] += Elem_j;

	}
	else {
		id[j] += id[i]; id[i] = int(j);

		numElemConj[j] += Elem_i;
	}

	_count--;
}

// muestra el array por la salida o
void ConjuntosDisjuntos::print(std::ostream& o) const {
	o << _count << ": ";
	for (auto i = 0; i < size; ++i)
		o << id[i] << " ";
}

size_t ConjuntosDisjuntos::num_elem_conjunto(size_t c){

	return numElemConj[c];
}
std::ostream& operator<<(std::ostream & o, ConjuntosDisjuntos const& a){
	a.print(o);
	return o;
}
