#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define RANGO 200
#define ASC 1
#define DESC 0

void generar_datos(int *array);
void imprimir(int *array);
int getMax(int *array);
void count_sort(int *array, int orden, int exponente);
void radix_sort(int *array, int orden);

int main()
{
	int array[N];
	
	generar_datos(&array[0]);
	
	imprimir(&array[0]);
	
	radix_sort(&array[0], DESC);
	
	printf("\n\nArray ordenado:");
	imprimir(&array[0]);
	
	return 0;
}

void generar_datos(int *array)
{
	int i;
	
	srand(time(NULL));
	
	for(i = 0; i < N; i++)
	{
		*array = rand()%(RANGO+1);
		array++;
	}
}

void imprimir(int *array)
{
	int i;
	
	for (i = 0; i < N; i++)
	{
		printf("\n%d--->%d",i,*array);
		array++;
	}
}

int getMax(int *array)
{
	int max = *array, i;
	
	for (i = 1; i < N; i++)
		if(*(array+i) > max)
        	max = *(array+i);

	return max;
}

void count_sort(int *array, int orden, int exponente)
{
	int i, max, posicion, output[N];
	
	max = (*array/exponente) % 10;
	
	for (i = 1; i < N; i++)
		if (((*(array+i)/exponente) % 10) > max)
      		max = array[i];
	
	int count[max+1];
	
	for (i = 0; i <= max; i++)
		count[i] = 0;
	
	for (i = 0; i < N; i++)
		count[(*(array+i)/exponente)%10]++;
	
	if (orden == 1)
		for (i = 1; i <= max; i++)			// Cambio de orden
			count[i] += count[i-1];			// Cambio de orden
	else
		for (i = max; i > 0; i--)				// Cambio de orden
			count[i-1] += count[i];			// Cambio de orden
		
	for (i = N-1; i >= 0; i--)
	{
		posicion = count[(*(array+i)/exponente)%10]-1;
		output[posicion] = *(array+i);
		count[(*(array+i)/exponente)%10] -= 1;
	}
		
	for (i = 0; i < N; i++)
		*(array+i) = output[i];
	
}

void radix_sort(int *array, int orden)
{
	int max, exp;
	max = getMax(array);
	
	for (exp = 1; (max/exp) > 0; exp *= 10)
		count_sort(array, orden, exp);
}
