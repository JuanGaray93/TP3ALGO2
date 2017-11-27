/*
 * Dibujante.h
 *
 *  Created on: Oct 18, 2017
 *      Author: juan
 */

#ifndef DIBUJANTE_H_
#define DIBUJANTE_H_

#include "EasyBMP/EasyBMP.h"
#include <sstream>
#include <algorithm>

class Dibujante{

  private:

	std::string directorioDeImagenesFuente;
	std::string directorioDeCasilleros;
	std::string directorioDeMargenes;
	std::string directorioDePuntajes;
	std::string bomba;
	std::string bandera;
	std::string casilleroCubierto;
	std::string margen;

	int columnasMinimasImagen;

	int numeroDeDibujo;
	int alturaDeCuadrante;
	int anchoDeCuadrante;
	int columnasDelTablero;
	int filasDelTablero;
	int columnasTotalesImagen;
	int filasTotalesImagen;

	int columnasMargenLateral;
	int filasMargenSuperior;


	BMP imagen;

	/* Pre: Es usado por el constructor. Se le pasan dos nros naturales.
	 * Post:
	 */
	void inicializarCasilleros();

	/*
	 * Post: Se muestran todos los jugadores con sus puntajes en 0.
	 */
	void inicializarPuntajes(int cantidadDeJugadores, std::string* nombres);

	/*
	 * Post: El tableroo tiene un margen inferior donde se van a dibujar los puntajes.
	 */
	void inicializarMargen(int cantidadDeJugadores, std::string* nombres);

	/*
	 * Post: La imagen tiene todos sus casilleros dibujados como cubiertos.
	 * 		 Se crean los margenes de la imagen con lugar para anotar los puntajes de los jugadores.
	 */
	void inicializarImagen(int cantidadDeJugadores, std::string* nombres);

  public:

	/*
	 * Post: El dibujante crea su imagen lista para ser dibujada y modificada
	 *		 Crea el espacio donde poner los puntajes de los jugadores.
	 */
	Dibujante(int cantidadDeColumnas, int cantidadDeFilas, int cantidadDeJugadores, std::string* nombres);

	/*
	 * Post: Devuelve el numero correspondiente al dibujo que se esta preparando.
	 */
	int informarNumeroDeDibujo();

	/* Pre: el numero de fila (o columna) esta dentro del rango [0 .. filas (o columnas) del tablero - 1 ]
	 * 	    queDibujar es un string con el nombre del archivo fuente sin ".bmp".
	 * 		Por default, se aceptan los numeros del cero al ocho, "boom", "cubierto" y "bandera".
	 *
	 * Post: Se superpone el cuadrante en la posicion indicada con el tipo de casillero pedido.
	 *
	 */
	void cambiarCuadrante(int fila, int columna, std::string queDibujar, int jugador, bool esMargen);

	/* Pre: El nroJugador esta entre 1 y el nro de jugadores pasados al crear el tablero.
	 * Post: Dibuja el puntaje pasado a la derecha del numero de jugador.
	 */
	void cambiarPuntaje(int puntaje, int nroJugador);

	/* Post:	Guarda una nueva imagen BMP con los cambios aplicados al tablero.
	 * 			El nombre de la imagen se crea de acuerdo a cuantas veces se llamo este metodo.
	 */
	void dibujarTablero();

	/*
	 *Post elimina el jugador le dibuja una raya roja
	 */
	void eliminarJugador(int nroJugador);

	/*
	 *Post convierte en string un tipo de dato int
	 */
	std::string hacerCadena(int numero);

};

#endif /* DIBUJANTE_H_ */
