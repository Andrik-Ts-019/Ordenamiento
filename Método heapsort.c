/* PROGRAMA DE ORDENAMIENTO EMPLEANDO HEAP SORT
 *
 * Dado un arreglo de datos de tipo int, 
 * el programa ordena en el peor (o mejor de los casos).
 *
 * La salida debe ser el arreglo ya ordenado de forma ascendente o descendente
 * (según como se especifique)
 *
 * El método en promedio es tan bueno como el quick sort
 * No es estable y emplea un árbol binario.
 * 
 * Complejidad nlog(n)
 */

#include <stdio.h>

#define N 100				// Número de datos a generar
#define ASC 1
#define DESC 0

// Genera N datos que vamos a ordear
void generar_datos(int *p, int modo)
{
	int i;
	
	if(modo==1)				// Guarda los elementos de forma ascendente
	for(i=0; i<N; i++)
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
	for(i=0; i<N; i++)
	{
		printf("\n%ld--->%ld",i,*p);
		p++;
	}
}

// --------Método de ordenamiento HEAP SORT----------
void insertar_arbol(int *p, int modo)
{
	int i, k, bandera, aux;
	
	if(modo == 1)
	{
		for(i=1; i<N; i++)
		{
			k=i;
			bandera=1;
			while(k>0 && bandera==1)
			{
				bandera=0;
				if(*(p+k) > *(p+(k/2)))		// Cambio
				{
					aux=*(p+(k/2));
					*(p+(k/2))=*(p+k);
					*(p+k)=aux;
					k=k/2;
					bandera=1;
				}
			}
		}
	}
	else
	{
		for(i=1; i<N; i++)
		{
			k=i;
			bandera=1;
			while(k>0 && bandera==1)
			{
				bandera=0;
				if(*(p+k) < *(p+(k/2)))		// Cambio
				{
					aux=*(p+(k/2));
					*(p+(k/2))=*(p+k);
					*(p+k)=aux;
					k=k/2;
					bandera=1;
				}
			}
		}
	}
	
	
	
}

void eliminar_monticulo(int *p, int modo)
{
	int i, k, izq, der, ap, bandera, aux;
	
	if(modo==1)
	{
		int mayor;
		
		for(i=N-1; i>=1; i--)
		{
			aux=*(p+i);
			*(p+i)=*p;
			izq=1;
			der=2;
			k=0;
			bandera=1;
			while(izq<i && bandera==1)
			{
				mayor=*(p+izq);
				ap=izq;
				
				if(mayor<*(p+der) && der!=i)	// Cambio
				{
					mayor=*(p+der);
					ap=der;
				}
				
				if(aux<mayor)					// Cambio
				{
					*(p+k)=*(p+ap);
					k=ap;
				}
				else
				{
					bandera=0;
				}
				
				izq=k*2;
				der=izq+1;
			}
			*(p+k)=aux;
		}
	}
	else
	{
		int menor;
		
		for(i=N-1; i>=1; i--)
		{
			aux=*(p+i);
			*(p+i)=*p;
			izq=1;
			der=2;
			k=0;
			bandera=1;
			while(izq<i && bandera==1)
			{
				menor=*(p+izq);
				ap=izq;
				
				if(menor>*(p+der) && der!=i)	// Cambio
				{
					menor=*(p+der);
					ap=der;
				}
				
				if(aux>menor)					// Cambio
				{
					*(p+k)=*(p+ap);
					k=ap;
				}
				else
				{
					bandera=0;
				}
				
				izq=k*2;
				der=izq+1;
			}
			*(p+k)=aux;
		}
	}
}


void ordenar_heap(int *p, int modo)
{
	insertar_arbol(p, modo);
	eliminar_monticulo(p, modo);
}
// --------------------------------------------------

int main()
{
	int vector[N];
	
	generar_datos(&vector[0], DESC);
	
	/*
	 * insertar_arbol(&vector[0]);
	 * eliminar_monticulo(&vector[0]);
	 */
	ordenar_heap(&vector[0], ASC);
	
	imprimir(&vector[0]);
	
	return 0;
}
