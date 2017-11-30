/*
 * condensadorDeFlujo.h
 *
 *  Created on: Nov 28, 2017
 *      Author: juan
 */

#ifndef CONDENSADORDEFLUJO_H_
#define CONDENSADORDEFLUJO_H_


#include "NodoDeArbol.h"
#include "Lista.h"

template <class T>
class CondensadorDeFlujo{

private:
	NodoDeArbol<T>* raiz;
	NodoDeArbol<T>* cursor;
	NodoDeArbol<T>* jugadaActual;

public:

	/*
	 * Post:
	 */
	CondensadorDeFlujo(T jugadaInicial);

	/*
	 * Pre: El condensador existe
	 * Post:
	 */
	void agregarNodo(T jugadaNueva){
		jugadaActual->asignarNuevoHijo(jugadaNueva);
	}


};


template <class T>
CondensadorDeFlujo<T>::CondensadorDeFlujo(T jugadaInicial){
	raiz = new NodoDeArbol<T>(jugadaInicial);
	cursor = raiz;
	jugadaActual = raiz;
}






#endif /* CONDENSADORDEFLUJO_H_ */
