/* PROGRAMA DE ORDENAMIENTO EMPLEANDO MERGE SORT
 *
 * Dado un arreglo de datos de tipo int, 
 * el programa ordena en el peor (o mejor de los casos).
 *
 * La salida debe ser el arreglo ya ordenado de forma ascendente o descendente
 * (según como se especifique)
 *
 * También se le llama: Ordenamiento por mezcla
 * 
 * Complejidad nlog(n)
 */

#include <stdio.h>

#define N 100				// Número de datos a generar
#define ASC 1
#define DESC 0

// Genera N datos que vamos a ordear
void generar_datos(int *p, int modo)
{
	int i;
	
	if(modo==1)				// Guarda los elementos de forma ascendente
	for(i=0; i<N; i++)
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
	for(i=0; i<N; i++)
	{
		printf("\n%ld--->%ld",i,*p);
		p++;
	}
}

// -------Método de ordenamiento MERGE SORT----------
void Merge(int *p, int *L, int *R, int n, int ml, int mr, int modo)
{
	int i=0,k=0,j=0;
	
	if(modo==1)
	{
		while(i<ml && j<mr)
		{
			if(*(L+i)<*(R+j))		// Cambio
			{
				*(p+k)=*(L+i);
				i++;
			}
			else
			{
				*(p+k)=*(R+j);
				j++;
			}
			k++;
		}
	}
	else
	{
		while(i<ml && j<mr)
		{
			if(*(L+i)>*(R+j))		// Cambio
			{
				*(p+k)=*(L+i);
				i++;
			}
			else
			{
				*(p+k)=*(R+j);
				j++;
			}
			k++;
		}
	}
	
	while(i<ml)
	{
		*(p+k)=*(L+i);
		i++;
		k++;
	}
	
	while(j<mr)
	{
		*(p+k)=*(R+j);
		j++;
		k++;
	}
}

int Mergesort(int *p, int n, int modo)
{	
	if(n<2)
	{
		return -1;
	}
	else
	{
		int medio=0, i=0;
		medio=n/2;
		
		int L[medio], R[n-medio];
		
		for(i=0;i<medio;i++)
		{
			L[i]=*(p+i);
		}
			
		for(i=medio;i<n;i++)
		{
			R[i-medio]=*(p+i);
		}
		
		Mergesort(&L[0], medio, modo);
		Mergesort(&R[0], n-medio, modo);
		Merge(p, &L[0], &R[0], n, medio, n-medio, modo);
	}
}
// --------------------------------------------------

/*
 * void Mergesort(long *,int);
 * void ordenar_merge(long *);
 * void Merge(long*,long*,long*);
 */

int main()
{
	int vector[N];
	
	generar_datos(&vector[0], ASC);
	
	Mergesort(&vector[0], N, DESC);
	
	imprimir(&vector[0]);
	
	return 0;
}


