/*
 * condensadorDeFlujo.h
 *
 *  Created on: Nov 28, 2017
 *      Author: juan
 */

#ifndef CONDENSADORDEFLUJO_H_
#define CONDENSADORDEFLUJO_H_

#ifndef NULL
#define NULL 0


#include "NodoDeArbol.h"
#include "Lista.h"
#include "Juego.h"
#include "Jugada.h"

class CondensadorDeFlujo{

private:
	NodoDeArbol<Jugada*>* raiz;
	NodoDeArbol<Jugada*>* cursor;
	NodoDeArbol<Jugada*>* nodoActual;
	Juego* juego;
	bool sigueElJuego;
	bool huboCambios;

public:

	/*
	 * Post: Se crea un condensador nuevo con un arbol de jugadas de solo un elemento vacio
	 */
	CondensadorDeFlujo();

	/*
	 * Pre: El condensador existe
	 * Post: Se suma un nuevo nodo al arbol, partiendo del nodo actual.
	 */
	void agregarNodo(NodoDeArbol<Jugada*>* nodoNuevo);

	/* Pre: La cantidad de nodos a retroceder es menos que devolverProfundidadActual()
	 *
	 */
	void retroceder(int cantidadDeNodos);

	/* Pre: El condensador existe.
	 * Post: Se rehacen las jugadas. Si la cantidad de jugadas pedida excede la cantidad de jugadas futuras hechas,
	 * 		 Se detiene el avance en la ultima jugada hecha. Se le pregunta al jugador cuando hay una bifurcacion
	 * 		 de posibles jugadas a repetir.
	 */
	void avanzar(int cantidadDeNodos);

	/* Pre: El condensador existe
	 * Post: Devuelve la cantidad de jjugadas que se hicieron desde la primera hasta la actual
	 */
	int devolverProfundidadActual();

	/* Pre: El condensador existe y se corrio inicializarJuego()
	 * Post: Inicia el ciclo de juego y sigue hasta que algun jugador gane
	 */
	void ejecutarJuego();

	/* Pre: el condensador existe
	 * Post: Se crea la instancia de juego. Se puede ejecutarJuego();
	 */
	void inicializarJuego(int dificultad, int numeroDeJugadores, int filas, int columnas, std::string* nombresDeJugadores);

	/* Pre: El condensador existe. Se inicio el juego. nodoActual->devolverCantidadDeHijos() > 1
	 * Post: Presenta un resumen de cada jugada futura elegible y pregunta que jugada repetir.
	 * 		 Devuelve el numero de la jugada elegida.
	 */
	int preguntarQueHijoSeguir();

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


};


CondensadorDeFlujo::CondensadorDeFlujo(){
	raiz = new NodoDeArbol<Jugada*>(NULL);
	cursor = raiz;
	nodoActual = raiz;
	juego = NULL;
	sigueElJuego = true;
	huboCambios = false;
}

void CondensadorDeFlujo::agregarNodo(NodoDeArbol<Jugada*>* nodoNuevo){
	nodoActual->asignarNuevoHijo(nodoNuevo);
}


void CondensadorDeFlujo::retroceder(int cantidadDeNodos){
	if(nodoActual->tienePadre() && cantidadDeNodos > 0){
		/*DESHACER CAMBIOS DE NODO ACTUAL*/
		nodoActual = nodoActual->devolverPadre();
		retroceder(cantidadDeNodos-1);
	}
}


void CondensadorDeFlujo::avanzar(int cantidadDeNodos){

	int nodosPosibles = nodoActual->devolverCantidadDeHijos();

	/* Probablemente se pueda optimizar o emprolijar  */
	if(nodosPosibles != 0 && cantidadDeNodos > 0){

		/*SUMAR CAMBIOS SOBRE JUEGO*/
		int hijoASeguir;

		if( nodosPosibles > 1 ){

			hijoASeguir = preguntarQueHijoSeguir();
			nodoActual = nodoActual->devolverHijo(hijoASeguir);
			avanzar(cantidadDeNodos - 1);

		} else if (nodosPosibles == 1){
			nodoActual = nodoActual->devolverHijo(1);
		}
	}


}

int CondensadorDeFlujo::preguntarQueHijoSeguir(){
	std::cout << "Hay varias opciones para avanzar!" << std::endl;

	Lista<NodoDeArbol<Jugada*>*>* hijosPosibles = nodoActual->devolverListaDeHijos();

	hijosPosibles->iniciarCursor();
	int numeroDeHijo = 1;
	Jugada* jugadaActual;
	NodoDeArbol<Jugada*>* nodoActual;
	while(hijosPosibles->avanzarCursor()){

		nodoActual =  hijosPosibles->obtenerCursor();
		jugadaActual = nodoActual->devolverContenido();
		Jugador quienJugo = jugadaActual->obtenerJugadorQueJugo();
		Coordenada* modificada = jugadaActual->obtenerCasilleros()->obtener(1);

		std::cout << std::endl << "La alternativa " << numeroDeHijo << " tiene:" << std::endl;

		if ( jugadaActual->huboDestapados() ) {

			if( jugadaActual->fueEliminado() ){

				std::cout 	<< "Eliminacion del jugador " << quienJugo.consultarNombre() << std::endl
							<< " por pisar la mina en columna " << modificada->obtenerCoordX()
							<< " y fila " << modificada->obtenerCoordY()
							<< "."
							<< std::endl;

			} else {
				std::cout 	<< jugadaActual->obtenerCantidadDeCasillerosModificados()
							<< " casilleros modificados por el jugador " << quienJugo.consultarNombre()
							<< "."
							<< std::endl;
			}
		} else {
				std::cout 	<< "Colocacion de bandera en columna " << modificada->obtenerCoordX()
							<< " y fila " << modificada->obtenerCoordY()
							<< " por el jugador " << quienJugo.consultarNombre()
							<< "."
							<< std::endl;
		}

		numeroDeHijo++;
	}

	return pedirNumero("Que camino desea seguir?");
}

int CondensadorDeFlujo::devolverProfundidadActual(){
	return nodoActual->devolverProfundidad();
}

void CondensadorDeFlujo::ejecutarJuego(){

	juego->avanzarTurno();
	while(sigueElJuego){

		juego->declararTurno();
		juego->tomarJugada();
		juego->avanzarTurno();
		if(huboCambios){
			//Guardo en un nodo nuevo el estado actual de la partida
			Jugada* jugadaActual = juego->devolverJugada();
			NodoDeArbol<Jugada*>* aGuardar = new NodoDeArbol<Jugada*>(nodoActual, jugadaActual);
			agregarNodo(aGuardar);
		}

		avanzar(1);
		sigueElJuego = !(juego->terminoLaPartida());
	};

}

void CondensadorDeFlujo::inicializarJuego(int dificultad, int numeroDeJugadores, int filas, int columnas, std::string* nombresDeJugadores){
		juego = new Juego(dificultad, numeroDeJugadores, filas, columnas, nombresDeJugadores);
	}


int CondensadorDeFlujo::pedirNumero(std::string mensaje){
	int numeroIngresado;
	std::cout << mensaje << std::endl;
	std::cin >> numeroIngresado;

	while (std::cin.fail()){
		std::cin.clear();
		std::cin.ignore();
		std::cin >> numeroIngresado;
	}

	if(numeroIngresado <= 0){

		std::cout << "El numero debe ser mayor a cero!" << std::endl;
		numeroIngresado =  pedirNumero(mensaje);
	}
	return numeroIngresado;
}

int CondensadorDeFlujo::pedirNumero(std::string mensaje, int numeroMaximo){
	int numeroIngresado = 0;
	std::cout << mensaje << std::endl;
	std::cin >> numeroIngresado;

	while (std::cin.fail()){
		std::cin.clear();
		std::cin.ignore();
		std::cin >> numeroIngresado;
	}

	if(numeroIngresado <= 0 || numeroIngresado > numeroMaximo){

		std::cout << "Numero no valido! " << std::endl;
		numeroIngresado = pedirNumero(mensaje, numeroMaximo);
	}
	return numeroIngresado;
}






#endif /* NULL */
#endif /* CONDENSADORDEFLUJO_H_ */
