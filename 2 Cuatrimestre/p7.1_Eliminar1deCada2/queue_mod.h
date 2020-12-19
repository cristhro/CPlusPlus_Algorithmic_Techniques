//
// Created by cristhian rodriguez on 05/03/2018.
//

#ifndef EDA_QUEUE_MOD_H
#define EDA_QUEUE_MOD_H
#include "queue_eda.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

template <class T>

class Lista : public queue<T> {

    using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí

public:

    void print(std::ostream & o = std::cout) const {
        Nodo * aux = this->prim;

        while (aux != NULL){
            o << aux->elem<< " ";
            aux = aux->sig;
        }
    }


    void BorrarUnaDeCada2() {
        if (this->empty())
            throw std::domain_error("eliminando de una cola vacia");

        Nodo * aux = this->prim;

        while (aux != NULL) {

            if (aux->sig != NULL) {
                Nodo *a_borrar = aux->sig;
                aux->sig = aux->sig->sig;
                delete a_borrar;
                --this->nelems;
            }
            aux = aux->sig;
        }

    }
};
template <class T>
inline std::ostream & operator<<(std::ostream & salida, Lista<T> const& l) {
    l.print(salida);
    return salida;
}
#endif //EDA_QUEUE_MOD_H
