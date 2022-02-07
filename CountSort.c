#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define ASC 1
#define DESC 0

void generar_datos(int *array);
void imprimir(int *array);
int getMax(int *array);
void count_sort(int *array, int orden);

int main()
{
	int array[N+1];
	
	generar_datos(&array[0]);
	
	imprimir(&array[0]);
	
	count_sort(&array[0], DESC);
	
	printf("\n\nArray ordenado:");
	imprimir(&array[0]);
	
	return 0;
}

void generar_datos(int *array)
{
	int i;
	
	srand(time(NULL));
	
	for(i = 0; i < N+1; i++)
	{
		*array = rand()%(N+1);
		array++;
	}
}

void imprimir(int *array)
{
	int i;
	
	for (i = 0; i <= N; i++)
	{
		printf("\n%d--->%d",i,*array);
		array++;
	}
}

int getMax(int *array)
{
	int max = *array, i;
	
	for (i = 1; i <= N; i++)
		if(*(array+i) > max)
        	max = *(array+i);

	return max;
}

void count_sort(int *array, int orden)
{
	int max, i, posicion, output[N+1];
	
	max = getMax(array);
	int count[max+1];
	
	for (i = 0; i <= max; i++)
		count[i] = 0;
	
	for (i = 0; i <= N; i++)
		count[*(array+i)]++;
	
	for (i = 1; i <= max; i++)
		count[i] += count[i-1];
	
	for (i = N; i >= 0; i--)
	{
		count[*(array+i)] -= 1;
		posicion = count[*(array+i)];
		output[posicion] = *(array+i);
		
	}
	
	if (orden == 1)
	{
		for (i = 0; i <= N; i++)
			*(array+i) = output[i];
	}
	else
	{
		for (i = 0; i <= N; i++)
			*(array+i) = output[N-i];
	}
	
}
