#include "funciones2.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	imagen_t* imagen1;
	imagen_t* imagen2;


	imagen1=(imagen_t*)inicializarImagen(imagen1,1800,800);
	imagen2=(imagen_t*)inicializarImagen(imagen2,2400,900);
	
	liberarImagen(imagen1);
	liberarImagen(imagen2);
	return 0;
}