/*
 * Arbitro.cpp
 *
 *  Created on: Nov 7, 2017
 *      Author: juan
 */

#include "Arbitro.h"


Arbitro::Arbitro(std::string* nombresDeJugadores, int numeroDeJugadores, int dificultadPedida){
	this->dificultad = dificultadPedida;
	this->inicializarListaDeJugadores(nombresDeJugadores, numeroDeJugadores);
	posicionCursor = 0;
}

Jugador Arbitro::devolverJugador(){
	return actual;
}

void Arbitro::sumarPuntaje(int puntos){
	actual.sumarPuntaje(puntos);
}

int Arbitro::devolverPuntaje(){
	return devolverJugador().consultarPuntaje();
}

void Arbitro::avanzarTurno(bool fueEliminado){
	if (fueEliminado){
		Jugador posicionDelCursor = listaDeJugadores.obtenerCursor();
		listaDeJugadores.remover(posicionCursor);
		retomarPosicionDelCursor(posicionDelCursor);
	}
	posicionCursor++;
	if(!listaDeJugadores.avanzarCursor()) inicializarCursor();
	actual = listaDeJugadores.obtenerCursor();
}

void Arbitro::inicializarListaDeJugadores(std::string* nombres, int cantidadJugadores){
	for(int i = 0; i < cantidadJugadores; i++){
        Jugador jugador(nombres[i], i + 1);
        listaDeJugadores.agregar(jugador);
	}
}

int Arbitro::devolverNumeroDeTurno(){
	int nroJugador = actual.consultarNumero();
	return nroJugador;
}

bool Arbitro::quedaUno(){
	return (listaDeJugadores.estaVacia());
}

void Arbitro::anunciarGanador(){
	int puntajeMaximo = 0;
	Jugador ganador = actual;
	Jugador posibleGanador;

	while(! listaDeJugadores.avanzarCursor() ){

		posibleGanador = listaDeJugadores.obtenerCursor();

		if (posibleGanador.consultarPuntaje() > puntajeMaximo ){
			ganador = posibleGanador;
			puntajeMaximo = posibleGanador.consultarPuntaje();
		}
	}

	std::cout << "El ganador es "
			  << ganador.consultarNombre()
			  << " con "
			  << ganador.consultarPuntaje()
			  << " puntos!"
			  << std::endl;
}

void Arbitro::inicializarCursor(){
	listaDeJugadores.iniciarCursor();
	listaDeJugadores.avanzarCursor();
	posicionCursor = 1;
}

void Arbitro::revivirJugador(Jugador jugadorARevivir){

	Jugador siguienteAJugar = listaDeJugadores.obtenerCursor();
	listaDeJugadores.iniciarCursor();
	bool seRevivioJugador = false;
	int posicion = 1;
	while(listaDeJugadores.avanzarCursor()){
		Jugador jugadorAComparar = listaDeJugadores.obtenerCursor();
		if(jugadorARevivir.consultarNumero() < jugadorAComparar.consultarNumero()){
			listaDeJugadores.agregar(jugadorARevivir, posicion);
			seRevivioJugador = true;
		}
		posicion++;
	}
	if(!seRevivioJugador) listaDeJugadores.agregar(jugadorARevivir);

	retomarPosicionDelCursor(siguienteAJugar);

}

void Arbitro::retomarPosicionDelCursor(Jugador posicionDelCursor){
	bool encontrado = false;
	listaDeJugadores.iniciarCursor();
	posicionCursor = 1;
	while(listaDeJugadores.avanzarCursor() && ! encontrado){
		encontrado = posicionDelCursor.consultarNumero() == listaDeJugadores.obtenerCursor().consultarNumero();
		posicionCursor++;
	}
}

void Arbitro::restablecerPuntaje(Jugador* quien){
	/*
	 *
	 */
}











