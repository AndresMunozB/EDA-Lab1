#include <stdio.h>
#include <stdlib.h>


#include "structs.h"





imagen_t* crearImagen(int fila,int columna)
{
	imagen_t* imagen= malloc(sizeof(imagen_t));
	imagen->fila=fila;
	imagen->columna=columna;
	imagen->matrizPixeles=malloc(sizeof(pixel_t*)*(imagen->fila));
	if(imagen->matrizPixeles==NULL){
		printf("Error: memoria insuficiente\n");
	}
	int i,j;
	for (i=0;i<imagen->columna;i++){
		imagen->matrizPixeles[i]=malloc(sizeof(pixel_t)*(imagen->columna));
		if(imagen->matrizPixeles[i]==NULL){
			printf("Error: memoria insuficiente\n");
		}

	}
	return imagen;

	
}

void liberarImagen(imagen_t* imagen){
	int i;
	for (i=0;i<imagen->columna;i++){
		free(imagen->matrizPixeles[i]);
	}
	free(imagen->matrizPixeles);
	free(imagen);
		
}

void cargarPixel(int r,int g, int b, pixel_t* pixel){
	pixel->r=r;
	pixel->g=g;
	pixel->b=b;

}

int comparaPixel(pixel_t* pixel1,pixel_t* pixel2){
	if (pixel1->r==pixel2->r && pixel1->g==pixel2->g && pixel1->b==pixel2->b ){
		return 1;
	}
	else return 0;
}

void imprimirPixel(pixel_t* pixel){
	printf("%d,%d,%d ", pixel->r,pixel->g,pixel->b);
}

void imprimirImagen(imagen_t* imagen){
	int i,j;

	for (i=0;i<imagen->fila;i++){
		for (j=0;j<imagen->columna;j++){
			imprimirPixel(&imagen->matrizPixeles[i][j]);
		}
		printf("\n");
	}
}

void cargarImagen(){
	FILE *iF;
	

		
	if ( (iF = fopen("imagenPrincipal.txt","r")) != NULL)
	{		
		int a,b;
		int c,d,e;
		fscanf(iF,"%d %d\n",&a,&b);
		printf("%d %d\n",a,b );
		imagen_t* imagen= crearImagen(a,b);
		int i,j;
		for (i=0;i<a;i++){
			for(j=0;j<b;j++){
				fflush(stdin);
				fscanf(iF,"%d,%d,%d",&c,&d,&e);
				imagen->matrizPixeles[i][j].r=c;
				imagen->matrizPixeles[i][j].r=d;
				imagen->matrizPixeles[i][j].r=e;
				
			}
			
		}
		printf("\n");
		imprimirImagen(imagen);
		
		
	
		fclose(iF);			
	
	}
	else{
		printf("Archivo no existe o no se pudo abrir\n");
	}
}


/*
int main()
{
	pixel_t* pixel1=crearPixel();
	cargarPixel(0,100,200,pixel1);
	pixel_t* pixel2=crearPixel();
	cargarPixel(0,100,200,pixel2);
	printf("%d\n",comparaPixel(pixel1,pixel2) );

	printf("%d\n",pixel->r );
	printf("%d\n",pixel->g );
	printf("%d\n",pixel->b );
	free(pixel1);
	free(pixel2);

	return 0;
}*/
