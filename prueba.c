#include <stdio.h>


int main()

{
	FILE *iF;
		
		if ( (iF = fopen("imagenPrincipal.txt","r")) != NULL)
		{		
			int a, b;
			fscanf(iF,"%d %d",&a,&b);
			printf("%d %d\n",a,b );
			fflush(stdin);
			fscanf(iF,"%d %d",&a,&b);
			printf("%d %d\n",a,b );
			fflush(stdin);
			fscanf(iF,"%d %d",&a,&b);
			printf("%d %d\n",a,b );
			fflush(stdin);
			fclose(iF);			
		
		}
		else
			printf("Archivo no existe o no se pudo abrir\n");
	return 0;
}