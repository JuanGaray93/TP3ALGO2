/*
 * ppal.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: juan
 */


#include "src/Dibujante.h"
#include "src/Juego.h"
#include "src/Presentador.h"


int main(){

	bool jugarDeNuevo = true;
	bool finDeLaPartida;
	Presentador presentador;

	while(jugarDeNuevo){

		finDeLaPartida = false;

		presentador.pedirDatosDeJuego();

		Juego juego( 	 presentador.devolverDificultad(),
						 presentador.devolverNumeroDeJugadores(),
						 presentador.devolverFilas(),
						 presentador.devolverColumnas(),
			       		 presentador.devolverNombresDeLosJugadores() );

		juego.avanzarTurno();
		do{
			juego.declararTurno();
			juego.tomarJugada();
			juego.avanzarTurno();
			finDeLaPartida = juego.terminoLaPartida();
		}while(! finDeLaPartida);
		presentador.consultarSiJugarDeNuevo();
		jugarDeNuevo = presentador.devolverSiJugarDeNuevo();
	}
	return 0;
}

