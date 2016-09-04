#include "estructuras.h"
#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


int main()
{
	//cargar imagenes:
	imagen_t* imagenPrincipal;
	imagenPrincipal=cargarImagenPrincipal(imagenPrincipal);
	
	imagen_t** arregloImagenes;
	int cantidadImagenes=contarImagenes();
	arregloImagenes=cargarImagenesBuscar(arregloImagenes,cantidadImagenes);
	
	
	//imprimir Imagenes:
	//printf("imagen principal:\n");
	//imprimirImagen(imagenPrincipal);
	//printf("\n");
	//imprimirImagenesArreglo(arregloImagenes,cantidadImagenes);
	//printf("\n");
	
	//rotar la imagen! e imprimirla :D 
	//imagenPrincipal= rotarImagen(imagenPrincipal);
	//imagenPrincipal= rotarImagen(imagenPrincipal);
	//imagenPrincipal= rotarImagen(imagenPrincipal);
	//printf("imagen principal:\n");
	//imprimirImagen(imagenPrincipal);
	
	
	int i;
	for (i=0;i<cantidadImagenes;i++){

		int rotar=0;
		int buscar=0;
		while (rotar<4){ //mientras no se hagan todas las rotaciones;
			//printf("ROTAR!!! :%d\n",rotar );
			//imprimirImagen(arregloImagenes[i]);
			buscar=buscarImagen(imagenPrincipal,arregloImagenes[i]);
			if (buscar==1){// si se encuentra la imagen sale del buclei
				printf("Imagen %d: Encontrada.\n",i+1 );
				break;
			}
			if(rotar==3){
				printf("Imagen %d: No encontrada.\n",i+1 );
				break;
			}
			else{
				arregloImagenes[i]=rotarImagen(arregloImagenes[i]);
				rotar++;
			}
			
		}
	}

	
	
	

	//printf("VALOR!!!!!: %d\n", buscarImagen(imagenPrincipal,arregloImagenes[1]));
	//rotar+=1;
	//liberar imagenes:
	liberarImagen(imagenPrincipal);
	liberarImagenesArreglo(arregloImagenes,cantidadImagenes);
	return 0;
}