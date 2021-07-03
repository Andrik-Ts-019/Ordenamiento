/* PROGRAMA DE ORDENAMIENTO EMPLEANDO SHELL SORT
 *
 * Dado un arreglo de datos de tipo long, 
 * el programa ordena en el peor (o mejor de los casos).
 *
 * La salida debe ser el arreglo ya ordenado de forma ascendente o descendente
 * (según como se especifique).
 *
 */

#include <stdio.h>

#define N 100
#define ASC 1
#define DESC 0

// Genera N datos que vamos a ordear
void generar_datos(long *p, int modo)
{
	long i;
	
	if(modo==1)						// Guarda los elementos de forma ascendente
	{
		for(i=0;i<N;i++)
		{
			*(p+i)=i+1;
		}
	}
	
	if(modo==0)						// Guarda los elementos de forma descendente
	{
		for(i=0;i<N;i++)
		{
			*(p+i)=N-i;
		}
	}
}

void imprimir(long *p)
{
	long i;
	for(i=0;i<N;i++)
	{
		printf("\n%ld--->%ld",i,*p);
		p++;
	}
}

// ---------Método de ordenamiento------------
void ordenar_shell(long *p, int mod)
{
	long i, j, k, intervalo, temp;
	intervalo=N/2;
	
	if(mod==0)						// Ordenar de forma descendente
	{
		while(intervalo>=1)
		{
			for(i=0;i+intervalo<N;i++)
			{
				j=i;
				while(j>=0)
				{
					k=j+intervalo;
					if(*(p+j)<*(p+k))	// Cambio
					{
						temp=*(p+j);
						*(p+j)=*(p+k);
						*(p+k)=temp;
						j-=intervalo;
					}
					else
					{
						j=-1;
					}
				}
			}
			intervalo=intervalo/2;
		}
	}
	else							// Ordenar de forma ascendente
	{
		while(intervalo>=1)
		{
			for(i=0;i+intervalo<N;i++)
			{
				j=i;
				while(j>=0)
				{
					k=j+intervalo;
					if(*(p+j)>*(p+k))	// Cambio
					{
						temp=*(p+j);
						*(p+j)=*(p+k);
						*(p+k)=temp;
						j-=intervalo;
					}
					else
					{
						j=-1;
					}
				}
			}
			intervalo=intervalo/2;
		}
	}
}
// -------------------------------------------

int main()
{
	long vector[N];
	
	generar_datos(&vector[0], DESC);
	
	ordenar_shell(&vector[0], ASC);
	
	imprimir(&vector[0]);
	
	return 0;
}
