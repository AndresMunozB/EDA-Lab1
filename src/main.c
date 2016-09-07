#include "estructuras.h"
#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


int main()
{
	// CARGAR LAS IMAGENES:
	//cargando imagen principal...
	imagen_t* imagenPrincipal;
	imagenPrincipal=cargarImagenPrincipal(imagenPrincipal);
	
	//cargando las imagenes a buscar..
	imagen_t** arregloImagenes;
	int cantidadImagenes=contarImagenes();
	arregloImagenes=cargarImagenesBuscar(arregloImagenes,cantidadImagenes);
	
	//TERMINO DE CARGAR LAS IMAGENES.





	// SIGUIETES COMENTARIOS SON UTILIZADOS PARA PROBAR LAS FUNCINOES:

	//imprimir Imagenes:
	//printf("imagen principal:\n");
	//imprimirImagen(imagenPrincipal);
	//printf("\n");
	//imprimirImagen(arregloImagenes[1]);
	//buscarImagen(imagenPrincipal,arregloImagenes[1]);
	//printf("\n");
	//imprimirImagenesArreglo(arregloImagenes,cantidadImagenes);
	//printf("\n");
	//rotar la imagen! e imprimirla :D 
	//imagenPrincipal= rotarImagen(imagenPrincipal);
	//imagenPrincipal= rotarImagen(imagenPrincipal);
	//imagenPrincipal= rotarImagen(imagenPrincipal);
	//printf("imagen principal:\n");
	//imprimirImagen(imagenPrincipal);
	

	//ALGORITMO DE BUSQUEDA DE LAS IMAGENES:

	FILE* archivo=fopen("resultado.txt","w");
	int i;
	for (i=0;i<cantidadImagenes;i++){

		int rotar=0;
		int buscar=0;
		while (rotar<4){ //mientras no se hagan todas las rotaciones;
			//printf("ROTAR!!! :%d\n",rotar );
			//imprimirImagen(arregloImagenes[i]);
			buscar=buscarImagen(imagenPrincipal,arregloImagenes[i]);
			if (buscar==1){// si se encuentra la imagen sale del buclei
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

	//LIBERAR EL ESPACIO UTILIZADO POR LAS IMAGENES CARGADAS:

	liberarImagen(imagenPrincipal);
	liberarImagenesArreglo(arregloImagenes,cantidadImagenes);
	//TERMINO DE LA LIBERACION DE LAS IMAGENES.
	return 0;
}