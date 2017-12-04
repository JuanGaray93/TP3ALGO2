
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
	 * Post: Devuelve la cantidad de jugadas que se hicieron desde la primera hasta la actual
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


	//	UI

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

	void asignarPadre(NodoDeArbol<Jugada*>* nodoNuevo);




};



#endif /* NULL */
#endif /* CONDENSADORDEFLUJO_H_ */
