
#ifndef JUGADA_H_
#define JUGADA_H_

#include "Jugador.h"
#include "Lista.h"
#include "Coordenada.h"

class Jugada{
private:
	Jugador quienJugo;
	bool eliminado;
	Lista<Coordenada*>* casillerosModificados;
	bool fueronDestapados;

public:

	/*
	 * Post inicializa la jugada con datos nulos
	 */

	Jugada();

	/*
	 * Post Si el jugador no fue seteado devuelve un jugador inicializado vacio
	 * de otra forma devuelve el jugador que realizo la jugada
	 */
	Jugador obtenerJugadorQueJugo();

	/*
	 * Post devuelve si el jugador de la jugada fue eliminado
	 */
	bool fueEliminado();

	/*
	 * Post Devuelve el numero del jugador, correspondiente con el orden en la cola
	 */
	int obtenerPosicionDelEliminado();

	/*
	 * Post Devuelve las coordenadas en la cual fue se altero/alteraron el/los casilleros
	 */
	Lista<Coordenada*>* obtenerCasilleros();

	/*
	 * Post Indica si los casilleros fueron destapados o se coloco una bandera
	 */
	bool huboDestapados();

	/*
	 *
	 */
	unsigned int obtenerCantidadDeCasillerosModificados();

	/*
	 * Post establece el jugador que realizo la jugada
	 */
	void establecerQuienJugo(Jugador quienJugo);

	/*
	 * Post establece la condicion de si el jugador fue eliminado o no
	 */
	void establecerQueFueEliminado(bool eliminado);

	/*
	 * Post Agrega coordenada a la lista
	 */
	void agregarCasilleroModificado(Coordenada* casilleros);

	/*
	 * Post Establece si la jugada fue destapar casilleros o colocar bandera
	 */
	void establecerQueFueronDestapados(bool destapados);

	/*
	 *
	 */
	~Jugada();

};



#endif
