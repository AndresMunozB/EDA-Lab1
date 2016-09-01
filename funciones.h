
#ifndef _FUNCIONES_H
#define _FUNCIONES_H

typedef struct pixel pixel_t;
typedef struct imagen imagen_t;
imagen_t* crearImagen(int fila,int columna);
pixel_t* crearPixel();
void cargarPixel(int r,int g, int b, pixel_t* pixel);
int comparaPixel(pixel_t* pixel1,pixel_t* pixel2);

#endif