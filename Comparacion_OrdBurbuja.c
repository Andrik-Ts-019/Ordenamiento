#include <stdio.h>
#include<time.h>

#define N 3000

void generarDatos(long *lista1, long *lista2);
void desordenar(long *lista);
//void imprimir(long *lista);

void ordBurbujaSimple(long *lista);
void ordBurbuja(long *lista);

int main() {
	float tiempo[3][3];
	long array1[N];
	long array2[N];
	clock_t time;
	
	generarDatos(&array1[0],&array2[0]);
	
	/* Ordenamiento burbuja simple */
	//caso promedio
	time = clock();
	ordBurbujaSimple(&array1[0]);
	tiempo[0][1]=((double)clock() - time) / CLOCKS_PER_SEC;
	
	//caso peor
	desordenar(&array1[0]);
	time = clock();
	ordBurbujaSimple(&array1[0]);
	tiempo[0][2]=((double)clock() - time) / CLOCKS_PER_SEC;
	
	//caso mejor
	time = clock();
	ordBurbujaSimple(&array1[0]);
	tiempo[0][0]=((double)clock() - time) / CLOCKS_PER_SEC;
	
	generarDatos(&array1[0],&array2[0]);
	
	/* Ordenamiento burbuja mejorado */
	//caso promedio
	time = clock();
	ordBurbuja(&array1[0]);
	tiempo[1][1]=((double)clock() - time) / CLOCKS_PER_SEC;
	
	//caso peor
	desordenar(&array1[0]);
	time = clock();
	ordBurbuja(&array1[0]);
	tiempo[1][2]=((double)clock() - time) / CLOCKS_PER_SEC;
	
	//caso mejor
	time = clock();
	ordBurbuja(&array1[0]);
	tiempo[1][0]=((double)clock() - time) / CLOCKS_PER_SEC;
	
	printf("\nEFICIENCIA DE LOS M%cTODOS DE ORDENACI%cN (SEG)",144,224);
	
	printf("\n\n\nM%ctodo burbuja simple",130);
	printf("\n\nCaso mejor: %.5f", tiempo[0][0]);
	printf("\nCaso promedio: %.5f", tiempo[0][1]);
	printf("\nCaso peor: %.5f", tiempo[0][2]);

	printf("\n\n\nM%ctodo burbuja 2",130);
	printf("\n\nCaso mejor: %.5f", tiempo[1][0]);
	printf("\nCaso promedio: %.5f", tiempo[1][1]);
	printf("\nCaso peor: %.5f", tiempo[1][2]);
	
	return 0;
}

void generarDatos(long *p, long *p2){
	srand(time(NULL));
	int i;
	for(i=0;i<N;i++){
		*p=rand()%N+1;
		*p2=*p;
		p++;
		p2++;
	}
}

//Desordenar para elpeor de los casos (ordenar de forma descendente)
void desordenar(long *p){
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

void ordBurbujaSimple(long *p) {
	int i, j;
	long tmp;
	
	for(i=0;i<N;i++) {
		for(j=i+1;j<N;j++) {
			if(*(p+i)>*(p+j)) {			// Forma de ordenar ascendente
				tmp=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=tmp;
			}
		}
	}
}

void ordBurbuja(long *p) {
	int interruptor = 1, pasada, j;
	long aux;
	
	for(pasada = 0; pasada < N-1 && interruptor; pasada++) {
		interruptor = 0;
		for(j = 0; j < N-pasada-1; j++) {
			if(*(p+j) > *(p+j+1)) {	// Forma de ordenar ascendente
				interruptor = 1;
				aux = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = aux;
			}
		}
	}
}

/*
//Prueba de código
void imprimir(long *p){
	int i;
	for(i=0;i<N;i++){
		printf("\n%d_____*p=%ld",i,*p);
		p++;
	}
}/**/
