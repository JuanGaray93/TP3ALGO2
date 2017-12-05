
#include "Jugada.h"

Jugada::Jugada(){
	this->eliminado = false;
	this->fueronDestapados = false;
	this->casillerosModificados = new Lista<Coordenada*>;
	this->quienJugo = new Jugador;
}

//GET

Jugador* Jugada::obtenerQuienJugo(){
	return this->quienJugo;
}

bool Jugada::fueEliminado(){
	return this->eliminado;
}

int Jugada::obtenerPosicionDelEliminado(){
	return quienJugo->consultarNumero();
}

Lista<Coordenada*>* Jugada::obtenerCasilleros(){
	return this->casillerosModificados;
}

bool Jugada::huboDestapados(){
	return this->fueronDestapados;
}

unsigned int Jugada::obtenerCantidadDeCasillerosModificados(){
	return ( casillerosModificados->contarElementos() );
}


//SET

void Jugada::establecerQuienJugo(Jugador* aEstablecer){
	quienJugo = new Jugador(*aEstablecer);
}

void Jugada::establecerQueFueEliminado(bool eliminado){
	this->eliminado = eliminado;
}

void Jugada::agregarCasilleroModificado(Coordenada* casillero){
	this->casillerosModificados->agregar(casillero);
}

void Jugada::establecerQueFueronDestapados(bool destapados){
	this->fueronDestapados = destapados;
}

Jugada::~Jugada(){
	casillerosModificados->iniciarCursor();
	while(casillerosModificados->avanzarCursor()){
		Coordenada* coordAEliminar = casillerosModificados->obtenerCursor();
		delete coordAEliminar;
	}

	delete casillerosModificados;
	delete quienJugo;
}


