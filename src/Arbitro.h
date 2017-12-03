/*
 * Arbitro.h
 *
 *  Created on: Nov 7, 2017
 *      Author: juan
 */

#ifndef ARBITRO_H_
#define ARBITRO_H_

#include "Lista.h"
#include "Jugador.h"

class Arbitro{

private:

	int dificultad;

	Lista<Jugador*>* listaDeJugadores;
	Jugador* actual;
	int posicionCursor;

	/*
	 * Post: inicializa la lista de jugadores con los jugadores creados
	 */
	void inicializarListaDeJugadores(std::string* nombres, int cantidadJugadores);


public:

	/*
	 * Pre la lista fue inicializada durante el juego
	 * Post deja el cursor apuntando al jugador que le corresponde jugar
	 */
	void retomarPosicionDelCursor(Jugador* posicionDelCursor);

	Arbitro(std::string* nombres, int cantidadJugadores, int dificultadPedida);

	/* Pre: La lista debe estar iniciada con el cursor iniciado
	 * Post: Devuelve puntero al jugador al que le toca jugar.
	 */
	Jugador* devolverJugador();

	/*
	 * Elimina al jugador de la listaDeJugadores
	 * lo agrega a la listaDeJugadoresEliminados
	 */
	void eliminarJugador();

	/* Pre: No fueron eliminados todos los jugadores
	 * Post: Se suma el numero pasado al puntaje del jugador actual
	 *
	 */
	void sumarPuntaje(int puntos);

	/* Pre: No fueron eliminados todos los jugadores
	 * Post: Devuelve el puntaje del jugador actual
	 *		 Si es menor que 0, devuelve 0.
	 */
	int devolverPuntaje();

	/*
	 * Pre: La lista debe estar iniciada con el cursor iniciado
	 * Post: Devuelve el numero de jugador que realizo la ultima jugada.
	 * No avanza el cursor
	 */
	int devolverNumeroDeTurno();

	/* Pre: Se pasa por parametro si quien acaba de jugar perdio
	 * Post: Es turno del jugador siguiente.
	 * 		 Si se termina la ronda, vuelve a empezar
	 * 		 Si no hay más jugadores, no hace nada
	 *
	 */
	void avanzarTurno(bool fueEliminado);

	/*
	 *Post Devuelve si queda un jugador (Este jugador queda almacenado en la variable "actual")
	 */
	bool quedaUno();

	/*
	 *Post Anuncia el ganador de la partida
	 */
	void anunciarGanador();

	/*
	 * Pre la lista de jugadores no fue iniciada previamente
	 * Post inicia el cursor y lo deja sobre el primero de la lista
	 */
	void inicializarCursor();

	/*
	 * Pre: Se volvio al pasado y un jugador fue eliminado
	 * Post: Revive al jugador eliminado, usando memoria a liberar
	 */
	void revivirJugador(Jugador jugadorARevivir);

	/*
	 *Post setea al jugador el puntaje que tenia en la jugada
	 *Post deja el cursor de la lista donde estaba
	 */
	void restablecerPuntaje(Jugador* quien);

	/*
	 *Post Libera los recursos asociados
	 */
	~Arbitro();
};



#endif /* ARBITRO_H_ */
