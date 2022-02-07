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


void generar_datos(int *array, int n, int orden);
void imprimir(int *array, int n);
int Mergesort(int *array, int n, int orden);
void Merge(int *array, int *izquierda, int *derecha, int n, int rangoIzq, int rangoDer, int orden);


int main()
{
	int vector[N];
	
	generar_datos(&vector[0], N, DESC);
	
	imprimir(&vector[0], N);
	
	Mergesort(&vector[0], N, ASC);
	
	printf("\n\nArreglo ordenado");
	imprimir(&vector[0], N);
	
	return 0;
}

/* Genera números enteros entre 1 y n (incluyendo los límites)
 * de forma secuencial (ascendente si orden=1 o descendente sí
 * orden=0). Guarda los números generados en un array para su
 * posterior uso.
 */
void generar_datos(int *array, int n, int orden)
{
	int i;
	
	if (orden==1)
		for (i = 0; i < n; i++)
			*(array+i)=i+1;
	
	if (orden == 0)
		for (i = 0; i < n; i++)
			*(array+i) = n - i;
}

// Imprime los n primeros elementos de un array.
void imprimir(int *array, int n)
{
	int i;
	for(i=0; i<N; i++)
	{
		printf("\n%ld--->%ld",i,*array);
		array++;
	}
}

// -------Método de ordenamiento MERGE SORT----------
int Mergesort(int *array, int n, int orden)
{	
	if (n < 2)
		return -1;
	else
	{
		int medio = 0, i = 0;
		medio = n / 2;
		
		int izquierda[medio], derecha[n-medio];
		
		for (i = 0; i < medio; i++)
			izquierda[i] = *(array+i);
			
		for (i = medio; i < n; i++)
			derecha[i-medio] = *(array+i);
		
		Mergesort (&izquierda[0], medio, orden);
		Mergesort (&derecha[0], n-medio, orden);
		Merge (array, &izquierda[0], &derecha[0], n, medio, n-medio, orden);
	}
}

void Merge(int *array, int *izquierda, int *derecha, int n, int rangoIzq, int rangoDer, int orden)
{
	int i = 0, k = 0, j = 0;
	
	if (orden == 1)
	{
		while (i < rangoIzq && j < rangoDer)
		{
			if (*(izquierda+i) < *(derecha+j))		// Cambio
			{
				*(array+k) = *(izquierda+i);
				i++;
			}
			else
			{
				*(array+k) = *(derecha+j);
				j++;
			}
			k++;
		}
	}
	else
	{
		while (i < rangoIzq && j < rangoDer)
		{
			if (*(izquierda+i) > *(derecha+j))		// Cambio
			{
				*(array+k) = *(derecha+j);
				j++;
			}
			else
			{
				*(array+k)=*(izquierda+i);
				i++;
			}
			k++;
		}
	}
	
	while (i < rangoIzq)
	{
		*(array+k) = *(izquierda+i);
		i++;
		k++;
	}
	
	while (j < rangoDer)
	{
		*(array+k) = *(derecha+j);
		j++;
		k++;
	}
}
// --------------------------------------------------
