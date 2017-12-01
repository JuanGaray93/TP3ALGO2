
#include "Jugada.h"

Jugada::Jugada(){
	this->eliminado = false;
	this->posicionDelEliminado = 0;
	this->fueronDestapados = false;
}

Jugador Jugada::obtenerJugadorQueJugo(){
	return this->quienJugo;
}

bool Jugada::fueEliminado(){
	return this->eliminado;
}

int Jugada::obtenerPosicionDelEliminado(){
	return this->posicionDelEliminado;
}
Lista<Coordenada> Jugada::obtenerCasilleros(){
	return this->casillerosModificados;
}

bool Jugada::casilleroDestapados(){
	return this->fueronDestapados;
}


void Jugada::establecerQuienJugo(Jugador quienJugo){
	this->quienJugo = quienJugo;
}

void Jugada::establecerQueFueEliminado(bool eliminado){
	this->eliminado = eliminado;
}

void Jugada::establecerPosicionEliminado(int posicion){
	this->posicionDelEliminado = posicion;
}

void Jugada::agregarCasilleroModificado(Coordenada casillero){
	this->casillerosModificados.agregar(casillero);
}

void Jugada::establecerFueronDestapados(bool destapados){
	this->fueronDestapados = destapados;
}


