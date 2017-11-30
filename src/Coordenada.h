#ifndef COORDENADA_H_
#define COORDENADA_H_


class Coordenada{

 private:

	 int coordenadaX;
	 int coordenadaY;

 public:

	 /*
	  * Post: Las coordenadas son ambas cero
	  */
	 Coordenada();

	 /*
	  * Post: Crea coordenadas
	  */
	 Coordenada(int coordenadaX, int coordenadaY);

	 /*
	  * Post devuelve la coordenada x
	  */

	 int obtenerCoordX() const;

	 /*
	  * Posts devuelve la coordenada y
	  */


	 int obtenerCoordY() const;

	 /*
	  * Post cambia la coordenada x
	  */

	 void cambiarCoordX(int coordX);

	 /*
	  * Post Cambia la coordenada y
	  */

	 void cambiarCoordY(int coordY);

	 /*
	  *
	  */
	 Coordenada operator=(const Coordenada& otraCoordenada);

 };



#endif /* COORDENADA_H_ */
