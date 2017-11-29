
#ifndef JUGADA_H_
#define JUGADA_H_

#include <Jugador.h>;
#include <Lista.h>;
#include <Coordenada.h>;
#include <Bandera.h>;

class Jugada{
private:
	Jugador quienJugo;
	Jugador eliminado;
	int posicionDelEliminado;
	Lista<Coordenada> casillerosModificados;
	bool fueronDestapados;
	Bandera* banderaColocada;

public:

	/*
	 * Post inicializa la jugada con todo vacio
	 */

	Jugada();



	Jugador obtenerJugadorQueJugo();

	Jugador obtenerJugadorEliminado();

	int obtenerPosicionDelEliminado();

	Lista<Coordenada> obtenerCasilleros();

	bool casilleroDestapados();

	Bandera* obtenerBanderaColocada();

	void establecerQuienJugo(Jugador quienJugo);

	void establecerJugadorEliminado(Jugador eliminado);

	void establecerPosicionEliminado(int posicion);

	void agregarCasilleroModificado(Coordenada casilleros);

	void establecerFueronDestapados(bool destapados);

	void establecerBanderaColocada(Bandera* bandera);
};



#endif
