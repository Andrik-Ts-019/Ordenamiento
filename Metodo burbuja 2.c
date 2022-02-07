#include <stdio.h>

#define N 100
#define ASC 1
#define DESC 0

void generar_datos (int *p, int modo)
{
	int i;
	
	if (modo==1)				// Guarda los elementos de forma ascendente
	for (i=0;i<N;i++)
	{
		*(p+i)=i+1;
	}
	
	if (modo==0)				// Guarda los elementos de forma descendente
	for (i=0;i<N;i++)
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

void ordenar_burbuja ( int *p, int modo) {
	int interruptor = 1;
	int pasada, j;
	if(modo==1) {
		// Controla la cantidad de pasadas
		for ( pasada = 0; pasada < N-1 && interruptor; pasada++) {
			interruptor = 0;
			for ( j = 0; j < N-pasada-1; j++) {
				if (*(p+j) > *(p+j+1)) {			//Determina el orden
					int aux;
					interruptor = 1;
					aux = *(p+j);
					*(p+j) = *(p+j+1);
					*(p+j+1) = aux;
				}
			}
		}
	}
	else {
		// Controla la cantidad de pasadas
		for ( pasada = 0; pasada < N-1 && interruptor; pasada++) {
			interruptor = 0;
			for ( j = 0; j < N-pasada-1; j++) {
				if (*(p+j) < *(p+j+1)) {			//Determina el orden
					int aux;
					interruptor = 1;
					aux = *(p+j);
					*(p+j) = *(p+j+1);
					*(p+j+1) = aux;
				}
			}
		}
	}
}


int main () {
	
	int vec[N];
	
	generar_datos(&vec[0], ASC);
	
	ordenar_burbuja(&vec[0], DESC);
	
	imprimir(&vec[0]);
	
	return 0;
}
