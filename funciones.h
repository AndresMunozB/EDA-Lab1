#include "estructuras.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

imagen_t* inicializarImagen(imagen_t* imagen,int fila, int columna);
void liberarImagen(imagen_t* imagen);
void imprimirPixel(pixel_t pixel);
void imprimirImagen(imagen_t* imagen);
void cargarPixel(int r,int g, int b, pixel_t* pixel);
void cargarImagen(imagen_t* imagen,FILE* archivo);
int compararPixel(pixel_t* pixel1,pixel_t* pixel2);
int contarImagenes();
imagen_t* cargarImagenPrincipal(imagen_t* imagen);
imagen_t** cargarImagenesBuscar(imagen_t** arreglo,int cantidadImagenes);
void liberarImagenesArreglo(imagen_t** arregloImagenes,int cantidadImagenes);
void imprimirImagenesArreglo(imagen_t** arregloImagenes,int cantidadImagenes);
imagen_t* rotarImagen(imagen_t* imagen);
int buscarImagen(imagen_t* imagenPrincipal, imagen_t* imagen);
