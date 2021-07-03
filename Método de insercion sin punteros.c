#include<stdio.h>

void metodoInsercion(long array[], int N){
	long aux;
	int i,j;	
	for(i=1;i<N;i++){
		j=i;
		aux=array[i];
		while(j>0 && aux>=array[j-1]){
			array[j]=array[j-1];
			j--;
		}
		array[j]=aux;
	}
	
	for(i=0;i<N;i++){
		printf("\n%d--->%ld",i,array[i]);
	}
}

int main(){
	int n=10;
	long vector[10]={-9,8,0,6,99,4,33,-2,1,0};
	metodoInsercion(vector,n);
	return 0;
}
