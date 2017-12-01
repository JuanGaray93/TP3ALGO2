/*
 * ppal.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: juan
 */


#include "CondensadorDeFlujo.h"
#include "Presentador.h"


int main(){

	bool jugarDeNuevo = true;
	Presentador presentador;

	while(jugarDeNuevo){
		CondensadorDeFlujo condensador;
		presentador.pedirDatosDeJuego();
		condensador.inicializarJuego(	presentador.devolverDificultad(),
										presentador.devolverNumeroDeJugadores(),
										presentador.devolverFilas(),
										presentador.devolverColumnas(),
										presentador.devolverNombresDeLosJugadores() );
		condensador.ejecutarJuego();
		presentador.consultarSiJugarDeNuevo();
		jugarDeNuevo = presentador.devolverSiJugarDeNuevo();
	}
	return 0;
}

