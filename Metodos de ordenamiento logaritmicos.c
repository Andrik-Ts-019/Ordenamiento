/* PROGRAMA DE ORDENAMIENTOS LOGARITMICOS
 *
 * Programa que compara los tiempos de ejecución de los programa de ordenamiento
 * de tipo logaritmico en el mejor, peor y caso promedio.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30000

void proceso();

void ordenar_shell(long *);
void ordenar_heap(long *);
void Merge(long *, long *, long *, int);
int Mergesort(long *,int );
void ordenar_quick(long *, int, int);

void ingresar_datos(long *, long *, long *, long *);
void desordenar_datos(long *);


//void imprimir(long *,long *, long *, long *);

//Función principal
int main(){
	printf("\n\n\n\t\t\tProcesando....");
	proceso();
	printf("\n\n\n");
	return 0;
}

/**/
void proceso(){
	
	float tiempo[4][3];
	long array1[N];			//Arreglo para el método shell
	long array2[N];			//Arreglo para el método heap
	long array3[N];			//Arreglo para el método marge
	long array4[N];			//Arreglo para el método quick
	
	ingresar_datos(&array1[0],&array2[0],&array3[0],&array4[0]);
	
	/*Ordenamiento  shellsort*/
	//Caso promedio
	clock_t time1 = clock();
	ordenar_shell(&array1[0]);
	tiempo[0][0]=((double)clock() - time1) / CLOCKS_PER_SEC;
	
	//Mejor de los casos
	clock_t time2 = clock();
	ordenar_shell(&array1[0]);
	tiempo[0][1]=((double)clock() - time2) / CLOCKS_PER_SEC;
	
	//Peor de los casos
	desordenar_datos(&array1[0]);
	clock_t time3 = clock();
	ordenar_shell(&array1[0]);
	tiempo[0][2]=((double)clock() - time3) / CLOCKS_PER_SEC;
	

	/*Ordenamiento  heapsort*/
	//Caso promedio
	clock_t time4 = clock();
	ordenar_heap(&array2[0]);
	tiempo[1][0]=((double)clock() - time4) / CLOCKS_PER_SEC;
	
	//Mejor de los casos
	clock_t time5= clock();
	ordenar_heap(&array2[0]);
	tiempo[1][1]=((double)clock() - time5) / CLOCKS_PER_SEC;
	
	//Peor de los casos
	desordenar_datos(&array2[0]);
	clock_t time6 = clock();
	ordenar_heap(&array2[0]);
	tiempo[1][2]=((double)clock() - time6) / CLOCKS_PER_SEC;
	
	
	/*Ordenamiento  mergesort*/
	//Caso promedio
	clock_t time7 = clock();
	Mergesort(&array3[0],N);
	tiempo[2][0]=((double)clock() - time7) / CLOCKS_PER_SEC;
	
	//Mejor de los casos
	clock_t time8 = clock();
	Mergesort(&array3[0],N);
	tiempo[2][1]=((double)clock() - time8) / CLOCKS_PER_SEC;
	
	//Peor de los casos
	desordenar_datos(&array3[0]);
	clock_t time9 = clock();
	Mergesort(&array3[0],N);
	tiempo[2][2]=((double)clock() - time9) / CLOCKS_PER_SEC;
	
	
	/*Ordenamiento  quicksort*/
	//Caso promedio
	clock_t time10 = clock();
	ordenar_quick(&array4[0],0,N-1);
	tiempo[3][0]=((double)clock() - time10) / CLOCKS_PER_SEC;
	
	//Mejor de los casos
	clock_t time11 = clock();
	ordenar_quick(&array4[0],0,N-1);
	tiempo[3][1]=((double)clock() - time11) / CLOCKS_PER_SEC;
	
	//Peor de los casos
	desordenar_datos(&array4[0]);
	clock_t time12 = clock();
	ordenar_quick(&array4[0],0,N-1);
	tiempo[3][2]=((double)clock() - time12) / CLOCKS_PER_SEC;
	
	system("cls");
	
	printf("\n\n\t\t\t\tM%cTODOS DE ORDENAMIENTO LOGAR%cTMICOS (SEG)"
	
		   "\n\n\n\t\t\tM%ctodo Shellsort"
		   "\nMejor de los casos: %f"
		   "\nPeor de los casos: %f"
		   "\nCaso promedio: %f"
		   
		   "\n\n\n\t\t\tM%ctodo Heapsort"
		   "\nMejor de los casos: %f"
		   "\nPeor de los casos: %f"
		   "\nCaso promedio: %f"
		   
		   "\n\n\n\t\t\tM%ctodo Mergesort"
		   "\nMejor de los casos: %f"
		   "\nPeor de los casos: %f"
		   "\nCaso promedio: %f"
		   
		   "\n\n\n\t\t\tM%ctodo Quicksort"
		   "\nMejor de los casos: %f"
		   "\nPeor de los casos: %f"
		   "\nCaso promedio: %f"
		   
		   ,144,214,130,tiempo[0][1],tiempo[0][2],tiempo[0][0],
		   130,tiempo[1][1],tiempo[1][2],tiempo[1][0],130,tiempo[2][1],tiempo[2][2],tiempo[2][0],
		   130,tiempo[3][1],tiempo[3][2],tiempo[3][0]);
	/**/
}

//Genera datos aleatorios del 1 a 30000 y los guarda en array1, array2, array3, array4
void ingresar_datos(long *p,long *p2,long *p3, long *p4){
	srand(time(NULL));
	int i;
	for(i=0;i<N;i++){
		*p=rand()%N+1;
		*p2=*p;
		*p3=*p;
		*p4=*p;
		p++;
		p2++;
		p3++;
		p4++;
	}
}


//Desordenar para elpeor de los casos (ordenar de forma descendente)
void desordenar_datos(long *p){
	long pos,aux;
	int i;

	for(i=1;i<N;i++){
		pos=i;
		aux=*(p+i);
		while(pos>0 && *(p+pos-1)<aux){
			*(p+pos)=*(p+pos-1);
			pos--;
		}
		*(p+pos)=aux;
	}
}


void ordenar_shell(long *p){
	int i,j,k, intervalo=N/2;
	long temp;
	while(intervalo>=1){
		for(i=0;i+intervalo<N;i++){
			j=i;
			while(j>=0){
				k=j+intervalo;
				if(*(p+j)>*(p+k)){
					temp=*(p+j);
					*(p+j)=*(p+k);
					*(p+k)=temp;
					j-=intervalo;
				}
				else{
					j=-1;
				}
			}
		}
		intervalo=intervalo/2;
	}
}


void insertar_arbol(long *p){
	int i,k,bandera;
	long aux;
	for(i=1;i<N;i++){
		k=i;
		bandera=1;
		while(k>0 && bandera==1){
			bandera=0;
			if(*(p+k)>*(p+(k/2))){
				aux=*(p+(k/2));
				*(p+(k/2))=*(p+k);
				*(p+k)=aux;
				k=k/2;
				bandera=1;
			}
		}
	}
}

void eliminar_monticulo(long *p){
	int i,k,izq,der,ap,bandera;
	long aux,mayor;
	for(i=N-1;i>=1;i--){
		aux=*(p+i);
		*(p+i)=*p;
		izq=1;
		der=2;
		k=0;
		bandera=1;
		while(izq<i && bandera==1){
			mayor=*(p+izq);
			ap=izq;
			if(mayor<*(p+der) && der!=i){
				mayor=*(p+der);
				ap=der;
			}
			if(aux<mayor){
				*(p+k)=*(p+ap);
				k=ap;
			}else{
				bandera=0;
			}
			izq=k*2;
			der=izq+1;
		}
		*(p+k)=aux;
	}
}


void ordenar_heap(long *p){
	long *p_aux;
	p_aux=p;
	insertar_arbol(p_aux);
	eliminar_monticulo(p_aux);
}


void Merge(long *p,long *L,long *R,int n){
	int i=0,k=0,j=0,ml=0,mr=0;
	ml=n/2;
	mr=n-ml;
	while(i<ml && j<mr){
		if(*(L+i)<*(R+j)){
			*(p+k)=*(L+i);
			i++;
		}else{
			*(p+k)=*(R+j);
			j++;
		}
		k++;
	}
	while(i<ml){
		*(p+k)=*(L+i);
		i++;
		k++;
	}
	while(j<mr){
		*(p+k)=*(R+j);
		j++;
		k++;
	}
}

int Mergesort(long *p,int n){
	long *p_aux;
	p_aux=p;
	int medio=0,i=0;
	medio=n/2;
	if(n<2){
		return -1;
	}else{
		long R[medio],L[n-medio];
		for(i=0;i<medio;i++){
			L[i]=*(p+i);
		}
		for(i=medio;i<n;i++){
			R[i-medio]=*(p+i);
		}
		Mergesort(&L[0],medio);
		Mergesort(&R[0],n-medio);
		Merge(p_aux,&L[0],&R[0],n);
	}
}

void ordenar_quick(long *p,int primero, int ultimo){
	long *p_aux;
	p_aux=p;
	int i,j,central;
	long pivote, aux;
	central=(primero+ultimo)/2;
	pivote=*(p+central);
	i=primero;
	j=ultimo;
	do{
		while(*(p+i)<pivote) 
			i++;
		while(*(p+j)>pivote)
			j--;
		if(i<=j){
			aux=*(p+i);
			*(p+i)=*(p+j);
			*(p+j)=aux;
			i++;
			j--;
		}
	}while(i<=j);
	if(primero<j){
		ordenar_quick(p_aux,primero, j);
	}
	if(i<ultimo){
		ordenar_quick(p_aux,i,ultimo);
	}
}

/*
//Prueba de los datos en array1, array2, array3, array4
void imprimir(long *p,long *p2, long *p3, long *p4){
	int i;
	for(i=0;i<N;i++){
		printf("\n%d___*p=%ld___*p2=%ld___*p3=%ld___*p4=%ld",i,*p,*p2,*p3,*p4);
		p++;
		p2++;
		p3++;
		p4++;
	}
}
/**/
