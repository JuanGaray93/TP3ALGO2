

#include "Juego.h"


Juego::Juego(int dificultad, int numeroDeJugadores, int filas, int columnas, std::string* nombresDeJugadores){

	bomba = "boom";
	bandera = "bandera";
	casilleroCubierto = "cubierto";
	margen = "margen";

	this->columnaDeJugada = 0;
	this->filaDeJugada = 0;
	this->seDebeEliminarJugador = false;

	this->dibujante = new Dibujante(columnas, filas, numeroDeJugadores, nombresDeJugadores);
	this->arbitro = new Arbitro(nombresDeJugadores, numeroDeJugadores, dificultad);

	tablero.asignarDimensionesYDificultad(columnas, filas, dificultad);

	this->dibujante->dibujarTablero();

	this->jugadaActual = NULL;


}

//UI y pedidos de datos

int Juego::pedirNumero(std::string mensaje){

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

int Juego::pedirNumero(std::string mensaje, int numeroMaximo){

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

int Juego::tomarTipoDeJugada(){

	std::string pedido = "Ingrese el numero de la opcion elegida: \n";
	std::string opcion1 = "1) Colocar / quitar bandera \n";
	std::string opcion2 = "2) Descubrir casillero \n";
	std::string mensajeDeOpciones = pedido + opcion1 + opcion2;

	int tipoDeJugada = pedirNumero(mensajeDeOpciones, 2);
	this->jugadaActual->establecerQueFueronDestapados(tipoDeJugada == 2);
	return tipoDeJugada;
}

void Juego::tomarUbicacionDeJugada(){
	filaDeJugada = pedirNumero("Por favor, ingrese la FILA donde desea realizar la jugada", tablero.obtenerFilaMaxima() ) - 1;
	columnaDeJugada = pedirNumero("Por favor, ingrese la COLUMNA donde desea realizar la jugada", tablero.obtenerColumnaMaxima() ) - 1;
}





void Juego::tomarJugada(){
	std::string queDibujar;
	bool haJugado = false;
	int opcionElegida;
	int jugadorActual;


	while (! haJugado){

		opcionElegida = tomarTipoDeJugada();
		jugadorActual = arbitro->devolverNumeroDeTurno();
		tomarUbicacionDeJugada();

		//Es colocar/quitar bandera:
		if ((opcionElegida == 1) && (! tablero.estaDescubierto(columnaDeJugada, filaDeJugada) )){

			cambiarBandera(jugadorActual);
			haJugado = true;

		//Es destapar
		} else if ( ! tablero.hayBanderaEn(columnaDeJugada, filaDeJugada) ) {

			descubrirCasillero(columnaDeJugada, filaDeJugada, jugadorActual);
			haJugado = true;

		} else {
			std::cout << "Esa jugada no es valida!" << std::endl;
		}
	}

	this->dibujante->dibujarTablero();
}

void Juego::tomarJugada(Jugada* jugada){
	std::string queDibujar;
	int opcionElegida;
	int jugadorActual;

	opcionElegida = (jugada->huboDestapados()) ? 1 : 2;
	jugadorActual = jugada->obtenerQuienJugo()->consultarNumero();
	Lista<Coordenada*>* coordenadasDeJugada = jugada->obtenerCasilleros();

	/* La primera coordenada de coordenadasDeJugada es aquella en la que se hizo la jugada.
	 * Solo hace falta esta coordenada, ya que otros casilleros afectados
	 * lo son por la recursividad en descubrirCasillero().
	 */

	Coordenada* coordDeJugada = coordenadasDeJugada->obtener(1);
	columnaDeJugada = coordDeJugada->obtenerCoordX();
	filaDeJugada = coordDeJugada->obtenerCoordY();

	//Es colocar/quitar bandera:
	if ((opcionElegida == 1) && (! tablero.estaDescubierto(columnaDeJugada, filaDeJugada) )){

		cambiarBandera(jugadorActual);

	//Es destapar
	} else {

		descubrirCasillero(columnaDeJugada, filaDeJugada, jugadorActual);
	}

	dibujante->dibujarTablero();
}






//Logica de juego

void Juego::avanzarTurno(){
	jugadaActual = new Jugada;
	if (seDebeEliminarJugador){
		std::cout << (arbitro->devolverJugador())->consultarNombre() << " fue eliminado!" << std::endl;
	}

	arbitro->avanzarTurno(seDebeEliminarJugador);
	this->jugadaActual->establecerQuienJugo(this->arbitro->devolverJugador());
	seDebeEliminarJugador = false;
}

void Juego::cambiarBandera(int jugadorActual){

	std::string queDibujar = "";

	//No hay bandera, la pone
	if ( ! tablero.hayBanderaEn(columnaDeJugada, filaDeJugada) ){

		bool pusoBien = tablero.colocarBandera(columnaDeJugada, filaDeJugada, jugadorActual);
		queDibujar = bandera;

		if (pusoBien){
			arbitro->sumarPuntaje(1);

		} else {
			arbitro->sumarPuntaje(-1);
		}

	//Hay bandera, saca
	} else {

		queDibujar = casilleroCubierto;
		int quienPuso = tablero.obtenerJugadorQueColocoBandera(columnaDeJugada, filaDeJugada);
		bool bienQuitada = tablero.quitarBandera(columnaDeJugada, filaDeJugada);
		this->dibujante->cambiarCuadrante(columnaDeJugada, filaDeJugada, queDibujar, jugadorActual, false);
		this->tomarUbicacionDeJugada();
		bool pusoBien = tablero.colocarBandera(columnaDeJugada, filaDeJugada, jugadorActual);
		int puntajeADevolver = 0;
		if( quienPuso != jugadorActual ){
			if (bienQuitada && pusoBien){
				puntajeADevolver = 2;
			} else{
				puntajeADevolver = -2;
			}
		}
		queDibujar = bandera;

		this->arbitro->sumarPuntaje(puntajeADevolver);
	}

	int puntaje = arbitro->devolverPuntaje();
	this->dibujante->cambiarPuntaje( puntaje, jugadorActual );
	this->dibujante->cambiarCuadrante(columnaDeJugada, filaDeJugada, queDibujar, jugadorActual, false);
	Coordenada* coordenada = new Coordenada(this->columnaDeJugada, this->filaDeJugada);
	this->jugadaActual->agregarCasilleroModificado(coordenada);
}

void Juego::descubrirCasillero(int columnaDeCasillero, int filaDeCasillero, int jugadorActual){

	std::string queDibujar = "";

	tablero.descubrirCasillero(columnaDeCasillero, filaDeCasillero);

	//Tiene bomba
	if (tablero.hayBombaEn(columnaDeCasillero, filaDeCasillero) ){

		queDibujar = bomba;
		seDebeEliminarJugador = true;
		dibujante->eliminarJugador(jugadorActual);

	//No tiene bomba
	} else {

		int numeroDeBombasCircundantes = tablero.obtenerNumeroDeBombasCircundantes(columnaDeCasillero, filaDeCasillero);
		queDibujar = hacerCadena(numeroDeBombasCircundantes);

		if (numeroDeBombasCircundantes == 0){
			descubrirCasillerosCircundantes(columnaDeCasillero, filaDeCasillero);
		}
	}
	Coordenada* descubierta = new Coordenada(columnaDeCasillero, filaDeCasillero);
	this->jugadaActual->establecerQueFueEliminado(seDebeEliminarJugador);
	this->jugadaActual->agregarCasilleroModificado(descubierta);
	this->dibujante->cambiarCuadrante(columnaDeCasillero, filaDeCasillero, queDibujar, jugadorActual, false);
}


void Juego::descubrirCasillerosCircundantes(int columnaDeCasillero, int filaDeCasillero){
	for(int dFila = -1; dFila < 2; dFila++){
		for(int dColumna = -1; dColumna < 2; dColumna++ ){

			int columnaAEvaluar = columnaDeCasillero + dColumna;
			int filaAEvaluar = filaDeCasillero + dFila;


			if ((tablero.esCoordenadaValida(columnaAEvaluar,filaAEvaluar)) && (! tablero.estaDescubierto(columnaAEvaluar, filaAEvaluar)) ){
				//Llamada recursiva entre el metodo actual y descubrirCasillero.
				descubrirCasillero(columnaAEvaluar, filaAEvaluar, 0);
			}
		}
	}
}

void Juego::declararTurno(){
	std::cout << "Es el turno de "<< (arbitro->devolverJugador())->consultarNombre() << std::endl;
}

bool Juego::terminoLaPartida(){
	bool termino = ( arbitro->quedaUno() || tablero.noQuedanCasilleros() );
	if ( termino ){
		arbitro->anunciarGanador();
	}
	return termino;
}

std::string Juego::hacerCadena(int numero){
	std::ostringstream ossnumero;
	ossnumero << numero;
	return ossnumero.str();
}

void Juego::revivirJugador(Jugador* jugadorARevivir){
		arbitro->revivirJugador(*jugadorARevivir);
		int nroJugador = jugadorARevivir->consultarNumero();
		dibujante->revivirJugador(nroJugador);
}

Jugada* Juego::devolverJugada(){
	return this->jugadaActual ;
}

void Juego::deshacerJugadaBandera(Coordenada* donde, Jugador* quien){

	int columna = donde->obtenerCoordX();
	int fila = donde->obtenerCoordY();

	if ( tablero.hayBanderaEn(columna, fila) ){
		tablero.quitarBandera(columna, fila);
		dibujante->cambiarCuadrante(columna, fila, "cubierto", quien->consultarNumero() , false);

	} else {
		int nroJugador = quien->consultarNumero();
		tablero.colocarBandera(columna, fila, nroJugador);
		dibujante->cambiarCuadrante(columna,fila,"bandera", quien->consultarNumero(), false);
	}
}

void Juego::taparCasilleros(Lista<Coordenada*>* casillerosAfectados){
	casillerosAfectados->iniciarCursor();
	while(casillerosAfectados->avanzarCursor()){

		Coordenada* casilleroActual = casillerosAfectados->obtenerCursor();
		tablero.taparCasillero( casilleroActual );

		int col = casilleroActual->obtenerCoordX();
		int fil = casilleroActual->obtenerCoordY();
		dibujante->cambiarCuadrante(col, fil, "cubierto", 0, false);
	}
}

void Juego::restablecerPuntaje(Jugador* quienJugo){
	arbitro->restablecerPuntaje(quienJugo);
}

void Juego::retrocederTurno(Jugador* quienJugo){
	arbitro->retomarPosicionDelCursor(quienJugo);
}

Juego::~Juego(){
	delete dibujante;
	delete arbitro;
}


