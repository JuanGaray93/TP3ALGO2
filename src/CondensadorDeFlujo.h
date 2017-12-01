/*
 * condensadorDeFlujo.h
 *
 *  Created on: Nov 28, 2017
 *      Author: juan
 */

#ifndef CONDENSADORDEFLUJO_H_
#define CONDENSADORDEFLUJO_H_

#ifndef NULL
#define NULL 0


#include "NodoDeArbol.h"
#include "Lista.h"
#include "Juego.h"
#include "Jugada.h"

class CondensadorDeFlujo{

private:
	NodoDeArbol<Jugada>* raiz;
	NodoDeArbol<Jugada>* cursor;
	NodoDeArbol<Jugada>* nodoActual;
	Juego* juego;
	bool sigueElJuego;
	Jugada jugadaActual;
	bool huboCambios;

public:

	/*
	 * Post:
	 */
	CondensadorDeFlujo();

	/*
	 * Pre: El condensador existe
	 * Post: El nodo
	 */
	void agregarNodo(NodoDeArbol<Jugada>* nodoNuevo);

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
	int devolverProfundidadActual();

	/*
	 *
	 */
	void ejecutarJuego(){

		juego->avanzarTurno();
		while(sigueElJuego){

			juego->declararTurno();
			juego->tomarJugada();
			juego->avanzarTurno();
			if(huboCambios){
				//Guardo en un nodo nuevo el estado actual de la partida
				NodoDeArbol<Jugada>* aGuardar = new NodoDeArbol<Jugada>(nodoActual, jugadaActual);
				agregarNodo(aGuardar);
			}

			avanzar(1);
			sigueElJuego = !(juego->terminoLaPartida());
		};

	}

	/*
	 *
	 */
	void inicializarJuego(int dificultad, int numeroDeJugadores, int filas, int columnas, std::string* nombresDeJugadores){
		juego = new Juego(dificultad, numeroDeJugadores, filas, columnas, nombresDeJugadores);
	}

	/*
	 *
	 */
	void preguntarQueHijoSeguir();


};


CondensadorDeFlujo::CondensadorDeFlujo(){
	raiz = NULL;
	cursor = raiz;
	nodoActual = raiz;
	juego = NULL;
	sigueElJuego = true;
	huboCambios = false;
}

void CondensadorDeFlujo::agregarNodo(NodoDeArbol<Jugada>* nodoNuevo){
	nodoActual->asignarNuevoHijo(nodoNuevo);
}


void CondensadorDeFlujo::retroceder(int cantidadDeNodos){


}


void CondensadorDeFlujo::avanzar(int cantidadDeNodos){

	int nodosPosibles = nodoActual->devolverCantidadDeHijos();

	/* Probablemente se pueda optimizar o emprolijar  */
	if(nodosPosibles != 0){
		/*SUMAR CAMBIOS SOBRE JUEGO*/
		int hijoASeguir;

		if( nodosPosibles > 1 ){

			hijoASeguir = preguntarQueHijoSeguir();
			nodoActual = nodoActual->devolverHijo(hijoASeguir);
			avanzar(cantidadDeNodos - 1);

		} else if (nodosPosibles == 1){
			nodoActual = nodoActual->devolverHijo(1);
		}
	}


}

void CondensadorDeFlujo::preguntarQueHijoSeguir(){
	//preguntar numero (copiar metodo)
}

int CondensadorDeFlujo::devolverProfundidadActual(){
	return nodoActual->devolverProfundidad();
}











#endif /* NULL */
#endif /* CONDENSADORDEFLUJO_H_ */
