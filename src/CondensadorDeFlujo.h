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
	int profundidadTotal;
	Juego* juego;
	bool sigueElJuego;

public:

	/*
	 * Post:
	 */
	CondensadorDeFlujo();

	/*
	 * Pre: El condensador existe
	 * Post: El nodo
	 */
	void agregarNodo(NodoDeArbol<Jugada> nodoNuevo);

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

	void ejecutarJuego(){

		juego->avanzarTurno();
		//Guardo en un nodo nuevo el estado actual de la partida

		do{
			juego->declararTurno();
			juego->tomarJugada();
			juego->avanzarTurno();
			sigueElJuego = !(juego->terminoLaPartida());
		} while(sigueElJuego);

	}


	void inicializarJuego(int dificultad, int numeroDeJugadores, int filas, int columnas, std::string* nombresDeJugadores){
		juego = new Juego(dificultad, numeroDeJugadores, filas, columnas, nombresDeJugadores);
	}




};


CondensadorDeFlujo::CondensadorDeFlujo(){
	raiz = NULL;
	cursor = raiz;
	nodoActual = raiz;
	profundidadTotal = 1;
	juego = NULL;
	sigueElJuego = true;
}

void CondensadorDeFlujo::agregarNodo(NodoDeArbol<Jugada> nodoNuevo){
	nodoActual->asignarNuevoHijo(nodoNuevo);
}


void CondensadorDeFlujo::retroceder(int cantidadDeNodos){


}


void CondensadorDeFlujo::avanzar(int cantidadDeNodos){


}


int CondensadorDeFlujo::devolverProfundidadTotal(){
	return profundidadTotal;
}


int CondensadorDeFlujo::devolverProfundidadActual(){
	return nodoActual->devolverProfundidad();
}











#endif /* NULL */
#endif /* CONDENSADORDEFLUJO_H_ */
