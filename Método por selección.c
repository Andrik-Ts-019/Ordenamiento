#include<stdio.h>

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

void ord_seleccion(int *p, int modo)
{
	int aux;
	int i, j;
	
	if(modo==1)							// Ordenar de forma ascendente
	{
		int minimo;
		for(i=0;i<N-1;i++)
		{
			minimo=i;
			for(j=i+1;j<N;j++)
			{
				if(*(p+j)<*(p+minimo))	// Determinación de orden
				{
					minimo=j;
				}
			}
			if(i!=minimo)
			{
				aux=*(p+i);
				*(p+i)=*(p+minimo);
				*(p+minimo)=aux;
			}
		}
	}
	else								// Ordenar de forma descendente
	{
		int maximo;
		for(i=0;i<N-1;i++)
		{
			maximo=i;
			for(j=i+1;j<N;j++)
			{
				if(*(p+j)>=*(p+maximo))	// Determinación de orden
				{
					maximo=j;
				}
			}
			if(i!=maximo)
			{
				aux=*(p+i);
				*(p+i)=*(p+maximo);
				*(p+maximo)=aux;
			}
		}
	}
}

int main()
{
	int vector[N];
	
	generar_datos(&vector[0], ASC);
	
	ord_seleccion(&vector[0], DESC);
	
	imprimir(&vector[0]);
	
	return 0;
}
