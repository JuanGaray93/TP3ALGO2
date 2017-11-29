#include "Coordenada.h"


Coordenada::Coordenada(int coordenadaX, int coordenadaY){
	this->coordenadaX = coordenadaX;
	this->coordenadaY = coordenadaY;
}

int Coordenada::obtenerCoordX(){
	return this->coordenadaX;
}

int Coordenada::obtenerCoordY(){
	return this->coordenadaY;
}

void Coordenada::cambiarCoordX(int coordenadaX){
	this->coordenadaX = coordenadaX;
}

void Coordenada::cambiarCoordY(int coordenadaY){
	this->coordenadaY = coordenadaY;
}

