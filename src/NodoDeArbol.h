/*
 * NodoDeArbol.h
 *
 *  Created on: Nov 27, 2017
 *      Author: juan
 */

#ifndef NODODEARBOL_H_
#define NODODEARBOL_H_
#include "Lista.h"

template <class T>
class NodoDeArbol{

private:
	Lista<NodoDeArbol>* hijos;
	T* contenido;
public:

	/*
	 * Post: Crea nuevo nodo sin hijos y sin contenido.
	 */
	NodoDeArbol();

	/*
	 * Post: Crea un nuevo nodo sin hijos con el contenido pasado
	 */
	NodoDeArbol(T nuevoContenido);

	/*
	 * Post: Crea un nuevo nodo con contenido e hijos dados.
	 */
	NodoDeArbol(T nuevoContenido, Lista<NodoDeArbol> nuevosHijos);

	/*
	 * Pre: El nodo existe
	 * Post: el nodo pasa a tener el contenido dado.
	 * 		 Si ya tenia contenido, se sobreescribe y se pierden los datos anteriores
	 */
	void asignarContenido(T nuevoContenido);

	/*
	 * Pre: El nodo existe
	 * Post: El nodo tiene de hijo el nodo pasado
	 */
	void asignarNuevoHijo(NodoDeArbol nuevoHijo);

	/*
	 * Pre: El nodo existe
	 * Post: devuelve la cantidad de hijos que tiene el nodo.
	 */
	int devolverCantidadDeHijos();

	/*
	 * Pre: Se le asigno contenido a traves del constructor o de asignarContenido.
	 * Post: Devuelve el contenido de este nodo.
	 */
	T devolverContenido();

	/*
	 * Pre: Existe el nodo.
	 * 		NumeroDeHijo esta entre 1 y devolverCantidadDeHijos()
	 * Post: Devuelve direccion del nodo del hijo pedido.
	 */
	NodoDeArbol* devolverHijo(int numeroDeHijo);


};

template <class T>
NodoDeArbol<T>::NodoDeArbol(){
	hijos = new Lista<NodoDeArbol>;
	contenido = 0;
}

template <class T>
NodoDeArbol<T>::NodoDeArbol(T nuevoContenido){
	hijos = new Lista<NodoDeArbol>;
	contenido = new T;
	*contenido = nuevoContenido;
}

template <class T>
NodoDeArbol<T>::NodoDeArbol(T nuevoContenido, Lista<NodoDeArbol> nuevosHijos){
	hijos = new Lista<NodoDeArbol>(nuevosHijos);
	contenido = new T;
	*contenido = nuevoContenido;
}

template <class T>
void NodoDeArbol<T>::asignarContenido(T nuevoContenido){
	if (contenido==0){
		contenido = new T;
	}
	*contenido = nuevoContenido;
}

template <class T>
void NodoDeArbol<T>::asignarNuevoHijo(NodoDeArbol nuevoHijo){
	hijos->agregar(nuevoHijo);
}

template <class T>
int NodoDeArbol<T>::devolverCantidadDeHijos(){
	return ( hijos->contarElementos() );
}

template <class T>
T NodoDeArbol<T>::devolverContenido(){
	return *contenido;
}

template <class T>
NodoDeArbol* NodoDeArbol<T>::devolverHijo(int numeroDeHijo){
	return &(hijos->obtener(numeroDeHijo));
}







#endif /* NODODEARBOL_H_ */
