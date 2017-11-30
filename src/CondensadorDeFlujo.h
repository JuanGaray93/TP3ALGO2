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
	NodoDeArbol<T>* nodoActual;
	int profundidadTotal;

public:

	/*
	 * Post:
	 */
	CondensadorDeFlujo(T nodoInicial);

	/*
	 * Pre: El condensador existe
	 * Post: El nodo
	 */
	void agregarNodo(T nodoNuevo);

	/* Pre: La cantidad de nodos a retroceder son menos que devolverProfundidadActual()
	 *
	 */
	void retroceder(int cantidadDeNodos);
	/*
	 *
	 */
	void avanzar(int cantidadDeNodos);

	/*
	 *
	 */
	int devolverProfundidadTotal();

	/*
	 *
	 */
	int devolverProfundidadActual();




};


template <class T>
CondensadorDeFlujo<T>::CondensadorDeFlujo(T nodoInicial){
	raiz = new NodoDeArbol<T>(nodoInicial);
	cursor = raiz;
	nodoActual = raiz;
	profundidadTotal = 1;
}

template <class T>
void CondensadorDeFlujo<T>::agregarNodo(T nodoNuevo){
	nodoActual->asignarNuevoHijo(nodoNuevo);
}

template <class T>
void CondensadorDeFlujo<T>::retroceder(int cantidadDeNodos){


}

template <class T>
void CondensadorDeFlujo<T>::avanzar(int cantidadDeNodos){


}

template <class T>
int CondensadorDeFlujo<T>::devolverProfundidadTotal(){
	return profundidadTotal;
}

template <class T>
int CondensadorDeFlujo<T>::devolverProfundidadActual(){
	return nodoActual->devolverProfundidad();
}










#endif /* CONDENSADORDEFLUJO_H_ */
