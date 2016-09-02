#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

// abrir archivo imagenprincipal y guardar en memoria
// abrir archivo imagesBuscar y guardar en memoria separando cada imagenes distinta
// buscar las imagenes en el archivo de la imagen principal
// 


int main()
{
	pixel_t* pixel1=crearPixel();
	cargarPixel(0,100,200,pixel1);
	pixel_t* pixel2=crearPixel();
	cargarPixel(0,100,202,pixel2);
	printf("%d\n",comparaPixel(pixel1,pixel2) );
	imprimirPixel(pixel1);
	printf("\n");
	imprimirPixel(pixel2);
	imagen_t* imagen;
	imagen=crearImagen(5,5);
	imagen->matrizPixeles[0][0].r=0;

	//imagen_t* imagen= crearImagen(5,5);


/*	printf("%d\n",pixel->r );
	printf("%d\n",pixel->g );
	printf("%d\n",pixel->b );*/
	free(pixel1);
	free(pixel2);

	return 0;
}