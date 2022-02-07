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

void generar_datos(int *array, int n, int orden);
void imprimir(int *array, int n);
void ordenar_quick(int *array, int primero, int ultimo, int orden);

int main()
{
	int vector[N];
	
	generar_datos(&vector[0], N, DESC);
	
	printf("\n\nArray desordenado");
	imprimir(&vector[0], N);
	
	ordenar_quick(&vector[0], 0, N-1, ASC);
	
	printf("\n\nArray ordenado");
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

// -------Método de ordenamiento QUICK SORT----------
void ordenar_quick(int *array, int primero, int ultimo, int orden)
{
	int i, j, central, pivote, aux;
	
	central = (primero+ultimo) / 2;
	pivote = *(array+central);					// Elemento central
	i = primero;
	j = ultimo;
	
	if (orden == 1)								// Ordenar de forma ascendente
		do
		{
			while (*(array+i) < pivote) i++;	// Cambio
			while (*(array+j) > pivote) j--;	// Cambio
			
			if (i <= j)
			{
				aux = *(array+i);
				*(array+i) = *(array+j);
				*(array+j) = aux;
				i++;
				j--;
			}
			
		}while (i <= j);
	else										// Ordenar de forma descendente
		do
		{
			while (*(array+i) > pivote) i++;		// Cambio
			while (*(array+j) < pivote) j--;		// Cambio
			
			if (i <= j)
			{
				aux = *(array+i);
				*(array+i) = *(array+j);
				*(array+j) = aux;
				i++;
				j--;
			}
			
		}while (i <= j);
	
	if (primero < j)
		ordenar_quick (array, primero, j, orden);
	
	if (i < ultimo)
		ordenar_quick (array, i, ultimo, orden);
}
// --------------------------------------------------
