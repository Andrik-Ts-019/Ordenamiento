/* PROGRAMA DE ORDENAMIENTO EMPLEANDO INSERCIÓN
 *
 * Dado un arreglo de datos de tipo long, 
 * el programa ordena en el peor (o mejor de los casos).
 *
 * La salida debe ser el arreglo ya ordenado de forma ascendente o descendente
 * (según como se especifique).
 *
 */

#include<stdio.h>

#define N 100
#define ASC 1
#define DESC 0

// Genera N datos que vamos a ordear
void generar_datos(int *p, int modo)
{
	int i;
	
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

void imprimir(int *p)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("\n%ld--->%ld",i,*p);
		p++;
	}
}

// ---------Método de ordenamiento------------
void ordenar_insercion(int *p, int modo)
{
	int i, pos, aux;
	
	if(modo==1)									// Ordenar ascendentemente
	{
		for(i=1;i<N;i++)
		{
			pos=i;
			aux=*(p+i);
			while(pos>0 && *(p+pos-1)>aux)		// Cambio de ordenamiento
			{
				*(p+pos)=*(p+pos-1);
				pos--;
			}
			*(p+pos)=aux;
		}
	}
	else										// Ordenar descendentemente
	{
		for(i=1;i<N;i++)
		{
			pos=i;
			aux=*(p+i);
			while(pos>0 && *(p+pos-1)<=aux)		// Cambio de ordenamiento
			{
				*(p+pos)=*(p+pos-1);
				pos--;
			}
			*(p+pos)=aux;
		}
	}
}
// -------------------------------------------

int main(){
	int vector[N];
	
	generar_datos(&vector[0], DESC);
	
	ordenar_insercion(&vector[0], DESC);
	
	imprimir(&vector[0]);
	
	return 0;
}
