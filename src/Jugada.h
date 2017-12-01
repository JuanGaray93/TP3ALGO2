
#ifndef JUGADA_H_
#define JUGADA_H_

#include "Jugador.h"
#include "Lista.h"
#include "Coordenada.h"

class Jugada{
private:
	Jugador quienJugo;
	bool eliminado;
	int posicionDelEliminado;
	Lista<Coordenada> casillerosModificados;
	bool fueronDestapados;

public:

	/*
	 * Post inicializa la jugada con todo vacio
	 */

	Jugada();

	Jugador obtenerJugadorQueJugo();

	bool fueEliminado();

	int obtenerPosicionDelEliminado();

	Lista<Coordenada> obtenerCasilleros();

	bool casilleroDestapados();


	void establecerQuienJugo(Jugador quienJugo);

	void establecerQueFueEliminado(bool eliminado);

	void establecerPosicionEliminado(int posicion);

	void agregarCasilleroModificado(Coordenada casilleros);

	void establecerFueronDestapados(bool destapados);

};



#endif
