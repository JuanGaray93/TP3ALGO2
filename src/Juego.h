/*
 * Arbitro.h
 *
 *  Created on: Oct 19, 2017
 *      Author: juan
 */
#ifndef JUEGO_H_
#define JUEGO_H_

#include <sstream>
#include <iostream>
#include <time.h>

#include "Arbitro.h"
#include "Casillero.h"
#include "Dibujante.h"
#include "Jugador.h"
#include "Tablero.h"
#include "Jugada.h"
#include "Coordenada.h"

class Juego{

  private:

	std::string bomba;
	std::string bandera;
	std::string casilleroCubierto;
	std::string margen;

	Tablero tablero;

	Dibujante* dibujante;

	Arbitro* arbitro;

	int filaDeJugada;
	int columnaDeJugada;
	bool seDebeEliminarJugador;

	Jugada* jugadaActual;





  public:

	/*
	 * Post:
	 */
	Juego(int dificultadPedida, int numeroDeJugadores, int filas, int columnas, std::string* listaDeNombresDeJugadores);


	//LOGICA DE JUEGO


	/*
	 * Post: El jugador actual es el siguiente en la lista
	 */
	void avanzarTurno();

	/*
	 * Post si el casillero seleccionado es 0 descubre los circundantes que tambien tengan cero
	 * hasta encontrar casilleros con bombas cercanas
	 */
	void descubrirCasillerosCircundantes(int fila, int columna);

	/* Pre: 	El casillero esta dentro del tablero
	 * Post: 	Si tiene una bomba se elimina al jugador,
	 * 			si no, revisa si tiene bombas al rededor.
	 * 			si tiene, muestra el numero de bombas
	 * 			si no tiene, actúa también sobre los casilleros de alrededor
	 */
	void descubrirCasillero(int columnaDeCasillero, int filaDeCasillero, int jugadorActual);


	/* Pre: 	El casillero de jugada existe
	 * Post: 	Si no hay una bandera la coloca,
	 * 			si hay y era del mismo jugador la saca sin que pase nada,
	 * 			si es de otro, se toma como corregir a otro jugador y se puntua.
	 */
	void cambiarBandera(int jugadorActual);

	//UI

	/*
	 * Post: Pide que el usuario ingrese un numero hasta recibir uno mayor a cero.
	 * 		 Devuelve el numero ingresado.
	 */
	int pedirNumero(std::string mensaje);

	/*
	 * Post: Pide que el usuario ingrese un numero hasta recibir uno mayor a cero y menor o igual al numero maximo
	 * 		 Devuelve el numero ingresado.
	 */
	int pedirNumero(std::string mensaje, int numeroMaximo);

	/*
	 * Post: Le toma la jugada al usuario.
	 * 		 Decide el resultado de la jugada.
	 */
	void tomarJugada();

	/*  Overload de tomarJugada()
	 *  repite las acciones realizadas en la jugada pasada.
	 */
	void tomarJugada(Jugada* jugada);

	/*
	 *Post: Recibe el input de que tipo de jugada va a realizar, "Poner/quitar bandera", "descubrir un casillero"
	 */
	int tomarTipoDeJugada();

	/*
	 *Post Toma las coordenadas en la que se realizara la jugada
	 */
	void tomarUbicacionDeJugada();

	/*
	 *Post: indica a que jugador le corresponde hacer su jugada
	 */
	void declararTurno();

	/*
	 * Post: devuelve true si termino la partida
	 */
	bool terminoLaPartida();

	/*
	 * Post devuelve la jugada creada, y inicializa nuevamente la jugada
	 */
	Jugada* devolverJugada();

	/*
	 * Post: Devuelve una std::string con el numero que se le paso
	 */
	std::string hacerCadena(int numero);


	/*
	 * Pre: El jugador que se le pasa fue previamente eliminado
	 * Post: Se borra la indicacion en la imagen de que el jugador fue eliminado
	 * 		 Se restaura el jugador a su lugar en la ronda
	 */
	void revivirJugador(Jugador* jugadorARevivir);

	/* Pre: Las coordenadas pasadas son validas
	 * Post: Los casilleros en esas coordenadas se tapan.
	 *
	 */
	void taparCasilleros(Lista<Coordenada*>* casillerosAfectados);

	/* Pre: La coordenada es valida en un casillero cubierto
	 * Post: Si no habia bandera ahi, se coloca. De lo contrario se quita.
	 * 		 No se afecta el puntaje del jugador.
	 */
	void deshacerJugadaBandera(Coordenada* donde, Jugador* quien);

	/*
	 * Post: El jugador pasa a tener el puntaje almacenado en "quien"
	 */
	void restablecerPuntaje(Jugador* quien);

	/*
	 * post
	 */
	void retrocederTurno(Jugador* jugada);
	/*
	 * Libera la memoria pedida para el DIBUJANTE y el ARBITRO.
	 *
	 */
	~Juego();

};



#endif /* JUEGO_H_ */
