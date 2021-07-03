/* PROGRAMA DE ORDENAMIENTO EMPLEANDO SHELL SORT
 *
 * Dado un arreglo de datos de tipo long, 
 * el programa ordena en el peor (o mejor de los casos).
 *
 * La salida debe ser el arreglo ya ordenado de forma ascendente o descendente
 * (seg�n como se especifique)
 *
 */

#include <stdio.h>

#define N 101
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

// ---------M�todo de ordenamiento------------
void ordenar_shell(int *p, int mod)
{
	int intervalo, i, j, k, temp;
	intervalo=N/2;						// Divisi�n entera
	
	if(mod==0)							// Ordenar de forma descendente
	{
		while(intervalo>=1)
		{
			for(i=intervalo;i<N;i++)
			{
				j=i-intervalo;
				while(j>=0)
				{
					k=j+intervalo;
					if(*(p+j)>=*(p+k))	// Establece de que forma ordenar
					{
						j=-1;
					}
					else				// Cambio
					{
						temp=*(p+j);
						*(p+j)=*(p+k);
						*(p+k)=temp;
						j-=intervalo;
					}
				}
			}
			intervalo=intervalo/2;
		}
	}
	
	if(mod==1)							// Ordenar de forma ascendente
	{
		while(intervalo>=1){
			for(i=intervalo;i<N;i++){
				j=i-intervalo;
				while(j>=0){
					k=j+intervalo;
					if(*(p+j)<=*(p+k)){	// Cambio
						j=-1;
					}
					else{
						temp=*(p+j);
						*(p+j)=*(p+k);
						*(p+k)=temp;
						j-=intervalo;
					}
				}
			}
			intervalo=intervalo/2;
		}
	}
}
// -------------------------------------------

// Funci�n principal
int main()
{
	int vector[N];
	
	generar_datos(&vector[0], ASC);
	
	ordenar_shell(&vector[0], DESC);
	
	imprimir(&vector[0]);
	
	return 0;
}
