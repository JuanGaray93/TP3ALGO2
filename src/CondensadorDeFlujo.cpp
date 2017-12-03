/*
 * CondensadorDeFlujo.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: juan
 */

#include "CondensadorDeFlujo.h"


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
	if(cantidadDeNodos >= this->devolverProfundidadActual()) throw ("No hay dicha cantidad de jugadas para deshacer");
	if(nodoActual->tienePadre() && cantidadDeNodos > 0){


		//DESHACER CAMBIOS DE NODO ACTUAL
		Jugada* jugadaADeshacer = nodoActual->devolverContenido();
		Jugador* quienJugo = jugadaADeshacer->obtenerQuienJugo();
		Lista<Coordenada*>* casillerosAfectados = jugadaADeshacer->obtenerCasilleros();

		//Si no se destapo ningun casillero es que se hizo una jugada de bandera.
		//DESHACER JUGADA DE BANDERA
		if ( ! jugadaADeshacer->huboDestapados() ){
			Coordenada* coordenadaDeJuego = casillerosAfectados->obtener(1);
			juego->deshacerJugadaBandera(coordenadaDeJuego, quienJugo);

		//DESHACER DESTAPE DE CASILLEROS
		} else {
			juego->taparCasilleros(casillerosAfectados);
			//REVIVIR
			if ( jugadaADeshacer->fueEliminado() ){
				juego->revivirJugador(quienJugo);
			}
		}

		//RESTAURO PUNTAJE
		juego->restablecerPuntaje(quienJugo);

		//DEJO EL CURSOR DE LA LISTA EN EL JUGADOR QUE LE TOCA JUGAR
		juego->retrocederTurno(quienJugo);


		nodoActual = nodoActual->devolverPadre();
		retroceder(cantidadDeNodos-1);
	}
}


void CondensadorDeFlujo::avanzar(int cantidadDeNodos){

	int nodosPosibles = nodoActual->devolverCantidadDeHijos();

	/* Probablemente se pueda optimizar o emprolijar  */
	if(nodosPosibles != 0 && cantidadDeNodos > 0){



		//SUMAR CAMBIOS SOBRE JUEGO ( TODO )
		//	juego->tomarJugada(nodoActual->devolverContenido());

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
		Jugador* quienJugo = jugadaActual->obtenerQuienJugo();
		Coordenada* modificada = jugadaActual->obtenerCasilleros()->obtener(1);

		std::cout << std::endl << "La alternativa " << numeroDeHijo << " tiene:" << std::endl;

		if ( jugadaActual->huboDestapados() ) {

			if( jugadaActual->fueEliminado() ){

				std::cout 	<< "Eliminacion del jugador " << quienJugo->consultarNombre() << std::endl
							<< " por pisar la mina en columna " << modificada->obtenerCoordX() + 1
							<< " y fila " << modificada->obtenerCoordY()+ 1
							<< "."
							<< std::endl;

			} else {
				std::cout 	<< jugadaActual->obtenerCantidadDeCasillerosModificados()
							<< " casilleros modificados por el jugador " << quienJugo->consultarNombre()
							<< "."
							<< std::endl;
			}
		} else {
				std::cout 	<< "Colocacion de bandera en columna " << modificada->obtenerCoordX()+ 1
							<< " y fila " << modificada->obtenerCoordY()+ 1
							<< " por el jugador " << quienJugo->consultarNombre()
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
		//Guardo en un nodo nuevo el estado actual de la partida
		Jugada* jugadaNueva = juego->devolverJugada();
		NodoDeArbol<Jugada*>* aGuardar = new NodoDeArbol<Jugada*>(nodoActual, jugadaNueva);
		agregarNodo(aGuardar);


		juego->avanzarTurno();

		int opcion = this->pedirNumero("Ingrese 1 para continuar con el flujo \n 2 para retroceder");
		if(opcion == 1)		avanzar(1);
		else{
			int cantJugadasARetroceder  = pedirNumero("Ingrese numero de jugadas a retroceder: ");
			retroceder(cantJugadasARetroceder);
		}
		sigueElJuego = !(juego->terminoLaPartida());
	}
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



