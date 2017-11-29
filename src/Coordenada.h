#ifndef COORDENADA_H_
#define COORDENADA_H_


class Coordenada{

 private:

	 int coordenadaX;
	 int coordenadaY;

 public:

	 /*
	  * Post: Crea coordenadas
	  */
	 Coordenada(int coordenadaX, int coordenadaY);

	 /*
	  * Post devuelve la coordenada x
	  */

	 int obtenerCoordX();

	 /*
	  * Posts devuelve la coordenada y
	  */


	 int obtenerCoordY();

	 /*
	  * Post cambia la coordenada x
	  */

	 void cambiarCoordX(int coordX);

	 /*
	  * Post Cambia la coordenada y
	  */

	 void cambiarCoordY(int coordY);

 };



#endif /* COORDENADA_H_ */
