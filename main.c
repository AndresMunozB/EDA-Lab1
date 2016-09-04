#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

// abrir archivo imagenprincipal y guardar en memoria
// abrir archivo imagesBuscar y guardar en memoria separando cada imagenes distinta
// buscar las imagenes en el archivo de la imagen principal
// 

int main()
{
	FILE* archivo;
	archivo = fopen("imagesBuscar.txt","r");
	char cadena[18000];
	int contador=0;
	int contador2=0;
	//imagen_t imagen1=;
	//imagen1=crearImagen(2,3);
	//printf("%d\n",imagen1.fila );
	while (!feof(archivo)){
		fgets(cadena,18000,archivo);
		if (isdigit(cadena[0]) && cadena[1]==' ' && isdigit(cadena[2]) ){
			int a=atoi(&cadena[0]);
			int b=atoi(&cadena[2]);
			printf("entre al if cadena: %d %d\n",a,b );
			contador2++;
			scan(archivo);
			printf("fin del if\n");
			//imagen_t* imagen;
			//cargarImagen(imagen);
		}
		/*printf("linea %d: - largo:%d %s\n",contador,strlen(cadena),cadena );
		contador++;*/

	}
	printf("imagenes: %d\n",contador2 );

	/*pixel_t* pixel1=crearPixel();
	cargarPixel(0,100,200,pixel1);
	pixel_t* pixel2=crearPixel();
	cargarPixel(0,100,202,pixel2);
	printf("%d\n",comparaPixel(pixel1,pixel2) );
	imprimirPixel(pixel1);
	printf("\n");
	imprimirPixel(pixel2);
	imagen_t* imagen;
	imagen=crearImagen(5,5);
	imagen->matrizPixeles[0][0].r=0;*/

	//imagen_t* imagen= crearImagen(5,5);


/*	printf("%d\n",pixel->r );
	printf("%d\n",pixel->g );
	printf("%d\n",pixel->b );*/
	/*free(pixel1);
	free(pixel2);
*/

	//imagen_t* imagen;
	//cargarImagen(imagen);
	return 0;
}