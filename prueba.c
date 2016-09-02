#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "structs.h"

int main()

{
	FILE *iF;
	

		
		if ( (iF = fopen("imagenPrincipal.txt","r")) != NULL)
		{		
			int a, b;

			int c,d,e;
			fscanf(iF,"%d %d\n",&a,&b);
			printf("%d %d\n",a,b );
			imagen_t* imagen= crearImagen(a,b);
			int i,j;
			for (i=0;i<a;i++){
				for(j=0;j<b;j++){
					fflush(stdin);
					fscanf(iF,"%d,%d,%d",&c,&d,&e);
					//printf("%d,%d,%d",c,d,e);
					imagen->matrizPixeles[i][j].r=c;
					imagen->matrizPixeles[i][j].r=d;
					imagen->matrizPixeles[i][j].r=e;


					imprimirPixel(&imagen->matrizPixeles[i][j]);
					//cargarPixel(c,d,e,imagen->matrizPixeles[i][j]);
					//imprimirPixel(imagen->matrizPixeles[i][j]);
					
				}
				printf("\n");
			}
			printf("\n");
			/*for (i=0;i<imagen->fila;i++){
				for (j=0;j<imagen->columna;j++){
					imprimirPixel(&imagen->matrizPixeles[i][j]);
				}
				printf("s\n");
			
			}*/
			imprimirImagen(imagen);
			
			
		
			fclose(iF);			
		
		}
		else
			printf("Archivo no existe o no se pudo abrir\n");
	

	return 0;
}