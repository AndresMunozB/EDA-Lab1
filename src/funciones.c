 #include "estructuras.h"
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
		//printf("hola: %d\n",i);
		free(imagen->pixeles[i]);
	}
	free(imagen->pixeles);
	free(imagen);
	/*if (imagen==NULL){
		printf("nulooooo\n");
	}*/
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


int compararPixel(pixel_t pixel1,pixel_t pixel2){
	if (pixel1.r==pixel2.r && pixel1.g==pixel2.g && pixel1.b==pixel2.b ){
		return 1;
	}
	else return 0;
}

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
									//printf("pixel1: \n");
									//imprimirPixel(imagenPrincipal->pixeles[a+i][b+j]);
									//printf("pixel1: \n");
									//imprimirPixel(imagen->pixeles[a][b]);
									//printf("no son iguales\n");
									contador+=1;
									//printf("es igual= i:%d,j:%d,a:%d,b:%d \n",i+a,j+b,a,b );
								}
							}

						}
					}
					if(contador==(imagen->fila*imagen->columna)){
						//printf("encontrada la igualdad de imagen\n");
						return 1;
					}
				}
			}
		}

	
	return 0;

}







