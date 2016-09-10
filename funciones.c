#include "estructuras.h"
#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LARGOLINE 50000

imagen_t* inicializarImagen(imagen_t* imagen,int fila, int columna){
	imagen=(imagen_t*)malloc(sizeof(imagen_t));
	imagen->fila=fila;
	imagen->columna=columna;
	imagen->pixeles=(pixel_t**)malloc(sizeof(pixel_t*)*fila);
	if (imagen->pixeles!=NULL){
		int i;
		for (i=0;i<imagen->fila;i++){
			imagen->pixeles[i]=(pixel_t*)malloc(sizeof(pixel_t)*columna);
			if (imagen->pixeles[i]==NULL){
				printf("Error: memoria insuficiente\n");
			}
		}
	}
	else{
		printf("Error: memoria insuficiente\n");
	}
	return imagen;
}

void liberarImagen(imagen_t* imagen){
	int i;
	for (i=0;i<(imagen->fila);i++){
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
void cargarPixel(int r,int g, int b, pixel_t* pixel){
	pixel->r=r;
	pixel->g=g;
	pixel->b=b;

}
void cargarImagen(imagen_t* imagen,FILE* archivo){
	int c,d,e;
	int i,j;
	for (i=0;i<imagen->fila;i++){
		for(j=0;j<imagen->columna;j++){
			fscanf(archivo,"%d,%d,%d",&c,&d,&e);
			cargarPixel(c,d,e,&imagen->pixeles[i][j]);
		}
	}
}


int compararPixel(pixel_t pixel1,pixel_t pixel2){
	if (pixel1.r==pixel2.r && pixel1.g==pixel2.g && pixel1.b==pixel2.b ){
		return 1;
	}
	else return 0;
}

int contarImagenes(){
	FILE* archivo;
	archivo = fopen("Entrada/imagesBuscar.txt","r");
	char cadena[LARGOLINE];
	int contadorImagenes=0;
	while (!feof(archivo)){
		fgets(cadena,LARGOLINE,archivo);
		if (buscarLinea(cadena)){
			contadorImagenes++;
		}
	}
	fclose(archivo);
	return contadorImagenes;
}

int buscarLinea(char* cadena){
	int i,largo,contadorEspacios,contadorComas;
	largo= strlen(cadena);
	contadorEspacios=0;
	contadorComas=0;
	for (i=0;i<largo;i++){
		if (cadena[i]==' '){
			contadorEspacios+=1;
		}
		if (cadena[i]==','){
			contadorComas+=1;
		}
	}
	if(contadorComas==0 && contadorEspacios==1){
		return 1;
	}
	return 0;
}
void buscarDimensiones(char* cadena,int* fil,int*col){
	int i,largo,posicion;
	posicion=0;
	largo = strlen(cadena);
	for (i=0;i<largo;i++){
		if (cadena[i]==' '){
			posicion=i;
		}
	}
	char numero1[posicion];
	char numero2[largo-posicion+1];
	memset(numero1,0,sizeof(numero1));
	memset(numero2,0,sizeof(numero2));
	memcpy(numero1,cadena,posicion);
	memcpy(numero2,&cadena[posicion+1],(largo-posicion));
	int a,b;
	*fil=atoi(numero1);
	*col=atoi(numero2);

}
imagen_t* cargarImagenPrincipal(imagen_t* imagen){
	
	FILE* archivo;
	archivo = fopen("Entrada/imagenPrincipal.txt","r");
	char cadena[LARGOLINE];
	fgets(cadena,LARGOLINE,archivo);
	int fila,columna;
	if (buscarLinea(cadena)){
		buscarDimensiones(cadena,&fila,&columna);
		imagen=inicializarImagen(imagen,fila,columna);
		cargarImagen(imagen,archivo);
		
	}
	fclose(archivo);
	return imagen;
}


imagen_t** cargarImagenesBuscar(imagen_t** arreglo,int cantidadImagenes){
	arreglo=malloc(sizeof(imagen_t*)*cantidadImagenes);
	FILE* archivo;
	archivo = fopen("Entrada/imagesBuscar.txt","r");
	char cadena[LARGOLINE];
	int contadorImagenes=0;
	while (!feof(archivo)){
		fgets(cadena,LARGOLINE,archivo);
		int fila,columna;
		if (buscarLinea(cadena)){
			buscarDimensiones(cadena,&fila,&columna);
			imagen_t* imagen;
			imagen=inicializarImagen(imagen,fila,columna);
			cargarImagen(imagen,archivo);
			arreglo[contadorImagenes]=imagen;
			contadorImagenes++;
		}
	}
	fclose(archivo);
	return arreglo;
}

void liberarImagenesArreglo(imagen_t** arregloImagenes,int cantidadImagenes){
	int i;
	for (i=0;i<cantidadImagenes;i++){
		liberarImagen(arregloImagenes[i]);
	}
}

void imprimirImagenesArreglo(imagen_t** arregloImagenes,int cantidadImagenes){
	int i;
	for (i=0;i<cantidadImagenes;i++){
		printf("imagen: %d\n",i );
		imprimirImagen(arregloImagenes[i]);
		printf("\n");
	}
}

imagen_t* rotarImagen(imagen_t* imagen){
	imagen_t* imagenRotada;
	imagenRotada=inicializarImagen(imagenRotada,imagen->columna,imagen->fila);
	int i,j,h;
	for (i = 0; i < imagen->fila; i++){
		h=imagen->columna-1;
		for(j = 0; j < imagen->columna; j++){
			imagenRotada->pixeles[h][i] = imagen->pixeles[i][j];
			h--;
		}

		
	}
	liberarImagen(imagen);
	return imagenRotada;
}

int buscarImagen(imagen_t* imagenPrincipal, imagen_t* imagen){
	int i,j;
		for (i=0;i<imagenPrincipal->fila;i++){
			for (j=0;j<imagenPrincipal->columna;j++){
				if (compararPixel(imagenPrincipal->pixeles[i][j],imagen->pixeles[0][0])){
					//printf("pixel igual\n");
					int a,b,contador;
					contador=0;
					for (a=0;a<imagen->fila;a++){
						for (b=0;b<imagen->columna;b++){
							if (a+i<imagenPrincipal->fila && b+j<imagenPrincipal->columna){
								if (compararPixel(imagenPrincipal->pixeles[a+i][b+j],imagen->pixeles[a][b])){
									contador+=1;
								}
							}

						}
					}
					if(contador==(imagen->fila*imagen->columna)){
						return 1;
					}
				}
			}
		}
	return 0;
}

void BusquedaTotal(int cantidadImagenes,imagen_t** arregloImagenes,imagen_t* imagenPrincipal){

	FILE* archivo=fopen("Salida/resultado.txt","w");
	int i;
	for (i=0;i<cantidadImagenes;i++){
		int rotar=0;
		int buscar=0;
		while (rotar<4){ //mientras no se hagan todas las rotaciones;
			buscar=buscarImagen(imagenPrincipal,arregloImagenes[i]);
			if (buscar==1){// si se encuentra la imagen sale del bucle
				fprintf(archivo,"Imagen %d: Encontrada.\n",i+1 );
				break;
			}
			if(rotar==3){
				fprintf(archivo,"Imagen %d: No encontrada.\n",i+1 );
				break;
			}
			else{
				arregloImagenes[i]=rotarImagen(arregloImagenes[i]);
				rotar++;
			}
		}
	}
	fclose(archivo);
}

// int main(){
// 	char hola[100]="23 21";
// 	printf("%d\n",buscarLinea(hola) );
// 	int fil,col;
// 	buscarDimensiones(hola,&fil,&col);
// 	printf("%d,%d\n",fil,col );
// }







