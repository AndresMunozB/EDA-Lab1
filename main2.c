#include "estructuras.h"
#include "funciones2.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


int main()
{
	//cargar imagenes:
	imagen_t* imagenPrincipal;
	imagenPrincipal=cargarImagenPrincipal(imagenPrincipal);
	
	imagen_t** arregloImagenes;
	int cantidadImagenes=contarImagenes();
	arregloImagenes=cargarImagenesBuscar(arregloImagenes,cantidadImagenes);
	
	
	//imprimir Imagenes:
	printf("imagen principal:\n");
	imprimirImagen(imagenPrincipal);
	printf("\n");
	imprimirImagenesArreglo(arregloImagenes,cantidadImagenes);
	
	
	
	//liberar imagenes:
	liberarImagen(imagenPrincipal);
	liberarImagenesArreglo(arregloImagenes,cantidadImagenes);
	return 0;
}