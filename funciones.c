#include "estructuras.h"
//#include "funciones2.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

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
			//fflush(stdin);
			fscanf(archivo,"%d,%d,%d",&c,&d,&e);
			//printf("%d,%d,%d\n",c,d,e );
			/*imagen->pixeles[i][j].r=c;
			imagen->pixeles[i][j].g=d;
			imagen->pixeles[i][j].b=e;*/
			cargarPixel(c,d,e,&imagen->pixeles[i][j]);
			//imprimirPixel(imagen->pixeles[i][j]);
			//printf("\n");

		}
		
	}

}


int compararPixel(pixel_t* pixel1,pixel_t* pixel2){
	if (pixel1->r==pixel2->r && pixel1->g==pixel2->g && pixel1->b==pixel2->b ){
		return 1;
	}
	else return 0;
}
/*int compararImagen(imagen_t* imagen1,imagen_t* imagen2){
	int i,j,bol;
	bol=1;
	for (i=0;i<imagen1->fila;i++){
		for(j=0;j<imagen1->columna;j++){
			if (!compararPixel(&imagen1->pixeles[i][j],&imagen2->pixeles[i][j])){
				bol=0;
			}
		}
	}
	return bol;
}*/
int contarImagenes(){
	FILE* archivo;
	archivo = fopen("imagesBuscar.txt","r");
	char cadena[18000];
	int contadorImagenes=0;
	while (!feof(archivo)){
		fgets(cadena,18000,archivo);
		if (isdigit(cadena[0]) && cadena[1]==' ' && isdigit(cadena[2]) ){
			contadorImagenes++;
		}
	}
	//printf("imagenes: %d\n",contadorImagenes );
	fclose(archivo);
	return contadorImagenes;
}
imagen_t* cargarImagenPrincipal(imagen_t* imagen){
	
	FILE* archivo;
	archivo = fopen("imagenPrincipal.txt","r");
	char cadena[18000];
	fgets(cadena,18000,archivo);
	if (isdigit(cadena[0]) && cadena[1]==' ' && isdigit(cadena[2]) ){
		int fila=atoi(&cadena[0]);
		int columna=atoi(&cadena[2]);
		imagen=inicializarImagen(imagen,fila,columna);
		cargarImagen(imagen,archivo);
		
	}
	fclose(archivo);
	return imagen;
}

imagen_t** cargarImagenesBuscar(imagen_t** arreglo,int cantidadImagenes){
	arreglo=malloc(sizeof(imagen_t*)*cantidadImagenes);
	FILE* archivo;
	archivo = fopen("imagesBuscar.txt","r");
	char cadena[18000];
	int contadorImagenes=0;
	while (!feof(archivo)){
		fgets(cadena,18000,archivo);
		if (isdigit(cadena[0]) && cadena[1]==' ' && isdigit(cadena[2]) ){
			int fila=atoi(&cadena[0]);
			int columna=atoi(&cadena[2]);
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
int buscarImagen(imagen_t* imagenPrincipal, imagen_t* imagen){

	int i,j;

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
// 







/*int main(){

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
}*/
