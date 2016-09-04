#ifndef _STRUCTS_H_
#define _STRUCTS_H_

struct pixel{
	int r;
	int g;
	int b;
};
typedef struct pixel pixel_t;


struct imagen{
	int fila;
	int columna;
	pixel_t **pixeles;
};
typedef struct imagen imagen_t;


#endif


