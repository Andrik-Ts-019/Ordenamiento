/* PROGRAMA DE ORDENAMIENTO EMPLEANDO BURBUJA
 *
 * Dado un arreglo de datos de tipo int, 
 * el programa ordena en el peor (o mejor de los casos).
 *
 * La salida debe ser el arreglo ya ordenado de forma ascendente o descendente
 * (según como se especifique)
 *
 * En este ejemplo se usa punteros para modificar el arreglo por medio del paso
 * por referencia.
 *
 */

#include<stdio.h>

// ------- Método de ordenamiento burbuja -------
void metodoBurbuja(long array[], int N)
{
	long aux;
	int i,j;	
	for(i=0; i<N; i++)
	{
		for(j=i; j<N; j++)
		{
			if(array[i]<array[j])				// Ordenar descedente "<".
			{									// Ordenar ascendente ">".
				aux=array[i];
				array[i]=array[j];
				array[j]=aux;
			}			
		}
	}
	
	for(i=0;i<N;i++)
	{
		printf("\n%d--->%ld", i, array[i]);
	}
}

int main()
{
	int n=10;
	long vector[10]={-9,8,0,6,99,4,33,-2,1,0};
	metodoBurbuja(vector,n);
	return 0;
}
