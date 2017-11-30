
#include "Jugada.h"

Jugada::Jugada(){
	this->banderaColocada = 0;
	this->casillerosModificados = 0;
	this->eliminado = false;
	this->posicionDelEliminado = 0;
	this->fueronDestapados = 0;
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
Lista<Coordenada>* Jugada::obtenerCasilleros(){
	return this->casillerosModificados;
}

bool Jugada::casilleroDestapados(){
	return this->fueronDestapados;
}

Bandera* Jugada::obtenerBanderaColocada(){
	return this->banderaColocada;
}

void Jugada::establecerQuienJugo(Jugador quienJugo){
	this->quienJugo = quienJugo;
}

void Jugada::establecerQueFueEliminado(){
	this->eliminado =true;
}

void Jugada::establecerPosicionEliminado(int posicion){
	this->posicionDelEliminado = posicion;
}

void Jugada::agregarCasilleroModificado(Coordenada casillero){
	this->casillerosModificados->agregar(casillero);
}

void Jugada::establecerFueronDestapados(bool destapados){
	this->fueronDestapados = destapados;
}

void Jugada::establecerBanderaColocada(Bandera* bandera){
	this->banderaColocada = bandera;
}

