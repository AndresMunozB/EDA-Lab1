#include "estructuras.h"
#include "funciones.h"
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
	printf("\n");
	
	//rotar la imagen! e imprimirla :D 
	imagenPrincipal= rotarImagen(imagenPrincipal);
	printf("imagen principal:\n");
	imprimirImagen(imagenPrincipal);
	printf("girar!\n");
	arregloImagenes[1]=rotarImagen(arregloImagenes[1]);
	imprimirImagen(arregloImagenes[1]);
	printf("girar!\n");
	arregloImagenes[1]=rotarImagen(arregloImagenes[1]);
	imprimirImagen(arregloImagenes[1]);
	printf("girar!\n");
	arregloImagenes[1]=rotarImagen(arregloImagenes[1]);
	imprimirImagen(arregloImagenes[1]);
	printf("girar!\n");
	printf("valor: %d\n", buscarImagen(imagenPrincipal,arregloImagenes[1]));
	printf("valor: %d\n", buscarImagen(imagenPrincipal,arregloImagenes[0]));
	printf("valor: %d\n", buscarImagen(imagenPrincipal,arregloImagenes[2]));
	
	
	//liberar imagenes:
	liberarImagen(imagenPrincipal);
	liberarImagenesArreglo(arregloImagenes,cantidadImagenes);
	return 0;
}