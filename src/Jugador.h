#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>

class Jugador{

	private:

		int puntaje;
		std::string nombre;
		int numeroJugador;

	public:

		/*
		 * post: Crea un jugador con puntaje en cero
		 */
		Jugador(std::string nom, int numeroJugador);

		/*
		 * post: Crea un jugador con valores default: todos en cero y nombre "JUGADOR AUXILIAR"
		 */
		Jugador();

		/*
		 * post: Crea un jugador copia de otro jugador
		 */
		Jugador(const Jugador& otroJugador);

		//GET

		/*
		 * post: Devuelve el nombre del jugador
		 */
		std::string consultarNombre() const;

		/*
		 * post: Devuelve el puntaje del jugador
		 */
		int consultarPuntaje() const;

		/*
		 * post: Devuelve el numero del jugador
		 */
		int consultarNumero() const;

		//SET

		/*
		 * post: Suma a los puntos del jugador el numero pasado
		 */
		void sumarPuntaje(int puntos);

		/*
		 * post: Este jugador adquiere todos los atributos del jugador que se asigna.
		 */
		Jugador operator=(const Jugador& otroJugador);

		void establecerPuntaje(int puntos);



};


#endif
