#include "estructuras.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_
/*
	Funciones iniciarImagen
	recibe de argumento un puntero de la estructura imagen_t y dos enteros
	@param imagen_t* imagen corresponde a un puntero a la estructura imagen_t
	@param int fila corresponde al numero de filas que va a contener la matriz de pixeles dentro de imagen
	@param int columna corresponde al numero de columas que va a contener la matriz de pixeles dentro de la imagen
	@return imagen_t* retorna un puntero de una estructura imagen con memoria reservada por malloc

*/
imagen_t* inicializarImagen(imagen_t* imagen,int fila, int columna);

/*
	Procedimiento liberarImagen
	@param imagen_t* imagen
*/
void liberarImagen(imagen_t* imagen);
/*
	Procedimiento imprimirPixel
	@param pixel_t pixel
*/
void imprimirPixel(pixel_t pixel);
/*
	Procedimiento imprimirImagen
	@param imagen_t* imagen
*/
void imprimirImagen(imagen_t* imagen);
/*
	Procedimiento hola
	@param asd
*/
void cargarPixel(int r,int g, int b, pixel_t* pixel);
/*
	Procedimiento hola
	@param asd
*/
void cargarImagen(imagen_t* imagen,FILE* archivo);
/*
	Funcion iniciarImagen
	@param
	@return
*/
int compararPixel(pixel_t pixel1,pixel_t pixel2);
/*
	Funcion iniciarImagen
	@param
	@return
*/
int contarImagenes();
/*
	Funcion iniciarImagen
	@param
	@return
*/
imagen_t* cargarImagenPrincipal(imagen_t* imagen);
/*
	Funcion iniciarImagen
	@param
	@return
*/
imagen_t** cargarImagenesBuscar(imagen_t** arreglo,int cantidadImagenes);
/*
	Procedimiento hola
	@param asd
*/
void liberarImagenesArreglo(imagen_t** arregloImagenes,int cantidadImagenes);
/*
	Procedimiento hola
	@param asd
*/
void imprimirImagenesArreglo(imagen_t** arregloImagenes,int cantidadImagenes);
/*
	Funcion iniciarImagen
	@param
	@return
*/
imagen_t* rotarImagen(imagen_t* imagen);
/*
	Funcion iniciarImagen
	@param
	@return
*/
int buscarImagen(imagen_t* imagenPrincipal, imagen_t* imagen);

void BusquedaTotal(int cantidadImagenes,imagen_t** arregloImagenes,imagen_t* imagenPrincipal);
#endif