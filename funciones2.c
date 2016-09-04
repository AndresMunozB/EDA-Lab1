#include "estructuras.h"
#include <stdlib.h>
#include <stdio.h>

imagen_t* inicializarImagen(imagen_t* imagen,int fila, int columna){
	imagen=(imagen_t*)malloc(sizeof(imagen_t));
	imagen->fila=fila;
	//printf("fila: %d\n",imagen->fila );
	imagen->columna=columna;
	imagen->pixeles=(pixel_t**)malloc(sizeof(pixel_t*)*fila);
	if (imagen->pixeles!=NULL){
		int i;
		for (i=0;i<imagen->fila;i++){
			imagen->pixeles[i]=(pixel_t*)malloc(sizeof(pixel_t)*columna);
			if (imagen->pixeles[i]!=NULL){
				//status code OK

			}
			else{
				printf("Error: memoria insuficiente\n");
				//return NULL;
			}
		}


	}
	else{
		printf("Error: memoria insuficiente\n");
		//return NULL;
	}
	return imagen;



}
void liberarImagen(imagen_t* imagen){
	int i;

	for (i=0;i<(imagen->fila);i++){
		//printf("hola: %d\n",i);
		free(imagen->pixeles[i]);
	}
	free(imagen->pixeles);
	free(imagen);
}

void imprimirPixel(pixel_t pixel){
	printf("%d,%d,%d ", pixel.r,pixel.g,pixel.b);
}

void imprimirImagen(imagen_t* imagen){
	int i,j;

	for (i=0;i<imagen->fila;i++){
		for (j=0;j<imagen->columna;j++){
			imprimirPixel(imagen->pixeles[i][j]);
		}
		printf("\n");
	}
}
void cargarImagen(imagen_t* imagen,FILE* archivo){
	int c,d,e;
	int i,j;
	for (i=0;i<imagen->fila;i++){
		for(j=0;j<imagen->columna;j++){
			//fflush(stdin);
			fscanf(archivo,"%d,%d,%d",&c,&d,&e);
			//printf("%d,%d,%d\n",c,d,e );
			imagen->pixeles[i][j].r=c;
			imagen->pixeles[i][j].g=d;
			imagen->pixeles[i][j].b=e;
			//imprimirPixel(imagen->pixeles[i][j]);
			//printf("\n");

		}
		
	}

}

int main(){
	imagen_t* imagen1;
	FILE* archivo;
	archivo = fopen("imagenPrincipal.txt","r");
	char cadena[18000];
	fgets(cadena,18000,archivo);

	if (isdigit(cadena[0]) && cadena[1]==' ' && isdigit(cadena[2]) ){
		int fila=atoi(&cadena[0]);
		int columna=atoi(&cadena[2]);
		printf("entre al if cadena: %d %d\n",fila,columna );
		imagen1=inicializarImagen(imagen1,fila,columna);
		cargarImagen(imagen1,archivo);
	}
	imprimirImagen(imagen1);
	liberarImagen(imagen1);




	return 0;
}
