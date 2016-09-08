#include "estructuras.h"
#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


int main()
{
	// CARGAR LAS IMAGENES:
	//cargando imagen principal...
	imagen_t* imagenPrincipal;
	imagenPrincipal=cargarImagenPrincipal(imagenPrincipal);
	//cargando las imagenes a buscar..
	imagen_t** arregloImagenes;
	int cantidadImagenes=contarImagenes();
	arregloImagenes=cargarImagenesBuscar(arregloImagenes,cantidadImagenes);
	//TERMINO DE CARGAR LAS IMAGENES.

	//INICIO ALGORITMO DE BUSQUEDA DE LAS IMAGENES:
	BusquedaTotal(cantidadImagenes,arregloImagenes,imagenPrincipal);
	//TERMINO DE ALGORITMO DE BUSQUEDA DE LAS IMAGENES:

	//LIBERAR EL ESPACIO UTILIZADO POR LAS IMAGENES CARGADAS:
	liberarImagen(imagenPrincipal);
	liberarImagenesArreglo(arregloImagenes,cantidadImagenes);
	//TERMINO DE LA LIBERACION DE LAS IMAGENES.
	return 0;
}