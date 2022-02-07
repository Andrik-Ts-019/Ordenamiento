#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define RANGO 500
#define ASC 1
#define DESC 0

void generar_datos(int *array, int rango, int n);
void imprimir(int *array, int n);
void intercambio(int *a, int *b);
void heapify(int *array, int n, int indiceNodo, int maxHeap);
void heapSort(int *array, int n, int orden);

int main ()
{
	int array[N];
	
	generar_datos(&array[0], RANGO, N);
	
	printf("\n\nArray desordenado:");
	imprimir(&array[0], N);
	
	heapSort(&array[0], N, ASC);
	
	printf("\n\nArray ordenado:");
	imprimir(&array[0], N);
	
	return 0;
}


/* Genera n números aleatorios, cuyos valores sean
 * entre 0 y rango. Los números se guardan en un array 
 * de enteros.
 */
void generar_datos(int *array, int rango, int n)
{
	int i;
	
	srand(time(NULL));
	
	for(i = 0; i < n; i++)
	{
		*array = rand()%(rango+1);
		array++;
	}
}

// Muestra en consola los elementos de un array de enteros
void imprimir(int *array, int n)
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		printf("\n%d--->%d",i,*array);
		array++;
	}
}

/* Dados dos punteros que apuntan a dos espacios de un mismo
 * array, se realiza un intercambio de valores entre los
 * espacios del array.
 */
void intercambio(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

/* Dado un array que represente a un árbol binario completo,
 * que contenga n cantidad de nodos,y dado también el
 * subíndice donde se ubica un nodo padre (con respecto al
 * array), la función se encarga de que el nodo padre sea
 * mayor o igual a sus nodos hijos (si maxHeap==1), o bien,
 * la función se encarga de que el nodo padre sea menor o
 * igual que sus hijos (si maxHeap=0).
 */
void heapify(int *array, int n, int indiceNodo, int maxHeap)
{
    int izquierda = 2 * indiceNodo + 1;
    int derecha = 2 * indiceNodo + 2;
    
    
    if (maxHeap == 1)
    {
    	int mayor = indiceNodo;
    	
    	if (izquierda < n && *(array+izquierda) > *(array+mayor))
	    	mayor = izquierda;
	    	
	    if (derecha < n && *(array+derecha) > *(array+mayor))
	    	mayor = derecha;
	  
	    if (mayor != indiceNodo)
		{
	      intercambio(array+indiceNodo, array+mayor);
	      heapify(array, n, mayor, maxHeap);
    	}
	}
	else
	{
		int menor = indiceNodo;
    	
    	if (izquierda < n && *(array+izquierda) < *(array+menor))
	    	menor = izquierda;
	    	
	    if (derecha < n && *(array+derecha) < *(array+menor))
	    	menor = derecha;
	  
	    if (menor != indiceNodo)
		{
	      intercambio(array+indiceNodo, array+menor);
	      heapify(array, n, menor, maxHeap);
    	}
	}
}

/* Método de ordenamiento heap sort, si orden=1 entonces se
 * ordena de forma ascendente y se realiza max heap, si
 * orden=0 entonces ordenamos de forma descendente y se
 * realiza min heap.
 */
void heapSort(int *array, int n, int orden)
{
	int indiceNodo;
	
	// Creación del montículo de abajo hacia arriba
	for (indiceNodo = n / 2 - 1; indiceNodo >= 0; indiceNodo--)
	    heapify(array, n, indiceNodo, orden);
		
	// Heap sort
	for (indiceNodo = n - 1; indiceNodo >= 0; indiceNodo--)
	{
	    intercambio(array, array+indiceNodo);
	    // Heapify root element to get highest element at root again
	    heapify(array, indiceNodo, 0, orden);
	}
}
