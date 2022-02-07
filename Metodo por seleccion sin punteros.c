#include<stdio.h>

void metodoSeleccion(long array[], int N){
	long aux;
	int i,j,minimo;
	for(i=0;i<N-1;i++){
		minimo=i;
		for(j=i+1;j<N;j++){
			if(array[j]<array[minimo]){				//cambio de signo lo hace descendente
				minimo=j;
			}
		}
		if(i!=minimo){
			aux=array[i];
			array[i]=array[minimo];
			array[minimo]=aux;
		}
	}
	
	for(i=0;i<N;i++){
		printf("\n%d--->%ld",i,array[i]);
	}
}

int main(){
	int n=10;
	long vector[10]={-9,8,0,6,99,4,33,-2,1,0};
	metodoSeleccion(vector,n);
	return 0;
}
