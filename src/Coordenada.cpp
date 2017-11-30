#include "Coordenada.h"

Coordenada::Coordenada(){
	this->coordenadaX = 0;
	this->coordenadaY = 0;
}

Coordenada::Coordenada(int coordenadaX, int coordenadaY){
	this->coordenadaX = coordenadaX;
	this->coordenadaY = coordenadaY;
}

int Coordenada::obtenerCoordX() const{
	return this->coordenadaX;
}

int Coordenada::obtenerCoordY() const{
	return this->coordenadaY;
}

void Coordenada::cambiarCoordX(int coordenadaX){
	this->coordenadaX = coordenadaX;
}

void Coordenada::cambiarCoordY(int coordenadaY){
	this->coordenadaY = coordenadaY;
}

Coordenada Coordenada::operator=(const Coordenada& otraCoordenada){
	this->coordenadaX = otraCoordenada.obtenerCoordX();
	this->coordenadaY = otraCoordenada.obtenerCoordY();
	return *this;
}

