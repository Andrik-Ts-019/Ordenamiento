/* PROGRAMA DE ORDENAMIENTO EMPLEANDO QUICK SORT
 *
 * Dado un arreglo de datos de tipo int, 
 * el programa ordena en el peor (o mejor de los casos).
 *
 * La salida debe ser el arreglo ya ordenado de forma ascendente o descendente
 * (según como se especifique)
 *
 * Se dice que es el más rápido.
 * Complejidad: nlog2(n)
 */

#include <stdio.h>

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
		printf("\n%ld--->%ld",i,*p);
		p++;
	}
}

// -------Método de ordenamiento QUICK SORT----------
void ordenar_quick(int *p, int primero, int ultimo, int modo)
{
	int i, j, central, pivote, aux;
	central=(primero+ultimo)/2;
	pivote=*(p+central);				// Elemento central
	i=primero;
	j=ultimo;
	
	if(modo==1)							// Ordenar de forma ascendente
	{
		do
		{
			while(*(p+i)<pivote) i++;	// Cambio
			while(*(p+j)>pivote) j--;	// Cambio
			if(i<=j)
			{
				aux=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=aux;
				i++;
				j--;
			}
		}while(i<=j);
	}
	else								// Ordenar de forma descendente
	{
		do
		{
			while(*(p+i)>pivote) i++;	// Cambio
			while(*(p+j)<pivote) j--;	// Cambio
			if(i<=j)
			{
				aux=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=aux;
				i++;
				j--;
			}
		}while(i<=j);
		
	}
	
	if(primero<j)
	{
		ordenar_quick(p, primero, j, modo);
	}
	
	if(i<ultimo)
	{
		ordenar_quick(p, i, ultimo, modo);
	}
}
// --------------------------------------------------

int main()
{
	int vector[N];
	
	generar_datos(&vector[0], ASC);
	
	ordenar_quick(&vector[0], 0, N-1, DESC);
	
	imprimir(&vector[0]);
	
	return 0;
}


