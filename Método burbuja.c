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

#include "stdio.h"

#define N 100
#define ASC 1
#define DESC 0

// Genera N datos que vamos a ordear
void generar_datos(int *p, int modo)
{
	int i;
	
	if(modo==1)				// Guarda los elementos de forma ascendente
	for(i=0;i<N;i++)
	{
		*(p+i)=i+1;
	}
	
	if(modo==0)				// Guarda los elementos de forma descendente
	for(i=0;i<N;i++)
	{
		*(p+i)=N-i;
	}
}

void imprimir(int *p)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("\n%d--->%d",i,*p);
		p++;
	}
} 


// ------- Método de ordenamiento burbuja -------
void ordenar_burbuja(int *p, int modo)
{
	int tmp, i, j;
	
	if(modo==1)
	{
		for(i=0;i<N;i++)
		{
			for(j=i;j<N;j++)
			{
				if(*(p+i)>*(p+j))		// Forma de ordenar
				{
					tmp=*(p+i);
					*(p+i)=*(p+j);
					*(p+j)=tmp;
				}
			}
		}
	}
	else
	{
		for(i=0;i<N;i++)
		{
			for(j=i;j<N;j++)
			{
				if(*(p+i)<=*(p+j))		// Forma de ordenar
				{
					tmp=*(p+i);
					*(p+i)=*(p+j);
					*(p+j)=tmp;
				}
			}
		}
	}
}
/* ---------------------------------------------- */

int main()
{
	int vec[N];
	
	generar_datos(&vec[0], DESC);
	
	ordenar_burbuja(&vec[0], ASC);
	
	imprimir(&vec[0]);
	
	return 0;
}
