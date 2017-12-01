/*
 * NodoDeArbol.h
 *
 *  Created on: Nov 27, 2NULL17
 *      Author: juan
 */

#ifndef NODODEARBOL_H_
#define NODODEARBOL_H_
#include "Lista.h"

template <class T>
class NodoDeArbol{

private:
	Lista<NodoDeArbol>* hijos;
	NodoDeArbol* padre;
	T* contenido;
	int profundidad;


public:

	/*
	 * Post: Crea nuevo nodo sin hijos y sin contenido.
	 */
	NodoDeArbol(NodoDeArbol* padreNuevo);

	/*
	 * Post: Crea un nuevo nodo sin hijos con el contenido pasado
	 */
	NodoDeArbol(NodoDeArbol* padreNuevo, T nuevoContenido);

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
	NodoDeArbol<T>* devolverHijo(int numeroDeHijo);

	/*
	 * Post: informa si el nodo de arbol tiene padre (si no lo tiene, es raiz)
	 */
	bool tienePadre();

	/*
	 *
	 */
	int devolverProfundidad();

};

template <class T>
NodoDeArbol<T>::NodoDeArbol(NodoDeArbol* padreNuevo){
	hijos = new Lista<NodoDeArbol>;
	padre = padreNuevo;
	contenido = NULL;
	if (padre != NULL){
		profundidad = padre->devolverProfundidad();
	} else {
		profundidad = 1;
	}
}

template <class T>
NodoDeArbol<T>::NodoDeArbol(NodoDeArbol* padreNuevo, T nuevoContenido){
	hijos = new Lista<NodoDeArbol>;
	padre = padreNuevo;
	contenido = new T;
	*contenido = nuevoContenido;
	if (padre != NULL){
			profundidad = padre->devolverProfundidad();
	} else {
		profundidad = 1;
	}
}

template <class T>
void NodoDeArbol<T>::asignarContenido(T nuevoContenido){
	if (contenido == NULL){
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
NodoDeArbol<T>* NodoDeArbol<T>::devolverHijo(int numeroDeHijo){
	return &(hijos->obtener(numeroDeHijo));
}

template <class T>
bool NodoDeArbol<T>::tienePadre(){
	return (padre == NULL);
}

template <class T>
int NodoDeArbol<T>::devolverProfundidad(){
	return profundidad;
}




#endif /* NODODEARBOL_H_ */
