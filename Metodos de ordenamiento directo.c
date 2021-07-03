/*
Nombre: Adrik de la Cruz Martínez			Matrícula: 1863369				Grupo: 006
*/

#include<windows.h>
#include<stdio.h>
#include<time.h>

#define N 30000

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}

void proceso();

void ordenamiento_burbuja(long *);
void ordenamiento_seleccion(long *);
void ordenamiento_insercion(long *);

void ingresar_datos(long *,long *,long *);
void desordenar(long *);

//void imprimir(long *,long *, long *);

//Función principal
int main(){
	printf("\n\n\nProcesando...");
	proceso();
	return 0;
}

void proceso(){
	float tiempo[3][3];
	long array1[N];
	long array2[N];
	long array3[N];
	
	ingresar_datos(&array1[0],&array2[0],&array3[0]);
	//imprimir(&array1[0],&array2[0],&array3[0]);
	
	/**/
	//caso promedio
	clock_t time3 = clock();
		ordenamiento_burbuja(&array1[0]);
	tiempo[0][2]=((double)clock() - time3) / CLOCKS_PER_SEC;

	//caso peor
	desordenar(&array1[0]);
	clock_t time2 = clock();
		ordenamiento_burbuja(&array1[0]);
	tiempo[0][1]=((double)clock() - time2) / CLOCKS_PER_SEC;

	//caso mejor
	clock_t time1 = clock();
		ordenamiento_burbuja(&array1[0]);
	tiempo[0][0]=((double)clock() - time1) / CLOCKS_PER_SEC;
	
	
	/**/
	//caso promedio
	clock_t time6 = clock();
		ordenamiento_insercion(&array2[0]);
	tiempo[1][2]=((double)clock() - time6) / CLOCKS_PER_SEC;
	
	//caso peor
	desordenar(&array2[0]);
	clock_t time5 = clock();
		ordenamiento_insercion(&array2[0]);
	tiempo[1][1]=((double)clock() - time5) / CLOCKS_PER_SEC;
	
	//caso mejor
	clock_t time4 = clock();
		ordenamiento_insercion(&array2[0]);
	tiempo[1][0]=((double)clock() - time4) / CLOCKS_PER_SEC;
	
	
	/**/
	//caso promedio
	clock_t time9 = clock();
		ordenamiento_seleccion(&array3[0]);
	tiempo[2][2]=((double)clock() - time9) / CLOCKS_PER_SEC;
	
	//caso peor
	desordenar(&array3[0]);
	clock_t time8 = clock();
		ordenamiento_seleccion(&array3[0]);
	tiempo[2][1]=((double)clock() - time8) / CLOCKS_PER_SEC;
	
	//caso mejor
	clock_t time7 = clock();
		ordenamiento_seleccion(&array3[0]);
	tiempo[2][0]=((double)clock() - time7) / CLOCKS_PER_SEC;
	
	system("cls");
	
	
	/**/
	gotoxy(30,4);printf("EFICIENCIA DE LOS M%cTODOS DE ORDENACI%cN (SEG)",144,224);
	
	gotoxy(30,8);printf("Caso mejor");
	gotoxy(55,8);printf("Caso peor");
	gotoxy(80,8);printf("Caso promedio");
	
	gotoxy(5,11);printf("M%ctodo burbuja",130);
	gotoxy(32,11);printf("%.5f",tiempo[0][0]);
	gotoxy(57,11);printf("%.5f",tiempo[0][1]);
	gotoxy(82,11);printf("%.5f",tiempo[0][2]);
	
	gotoxy(5,14);printf("M%ctodo de inserci%cn",130,162);
	gotoxy(32,14);printf("%.5f",tiempo[1][0]);
	gotoxy(57,14);printf("%.5f",tiempo[1][1]);
	gotoxy(82,14);printf("%.5f",tiempo[1][2]);
	
	gotoxy(5,17);printf("M%ctodo de selecci%cn",130,162);
	gotoxy(32,17);printf("%.5f",tiempo[2][0]);
	gotoxy(57,17);printf("%.5f",tiempo[2][1]);
	gotoxy(82,17);printf("%.5f",tiempo[2][2]);
	/**/
	
	printf("\n\n\n");
}


//ingreso de datos--------------------------------------------

void ingresar_datos(long *p, long *p2, long *p3){
	srand(time(NULL));
	int i;
	for(i=0;i<N;i++){
		*p=rand()%N+1;
		*p2=*p;
		*p3=*p;
		p++;
		p2++;
		p3++;
	}
}

//Desordenar para elpeor de los casos (ordenar de forma descendente)

void desordenar(long *p){
	long pos,aux;
	int i;
	//---------------------------------------------
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

//Métodos deordenación---------------------------------------

void ordenamiento_burbuja(long *p){
	int i,j;
	long aux, *p2;
	for(i=0;i<N;i++){
		p2=p;
		for(j=i;j<N;j++){
			if(*p>*p2){
				aux=*p;
				*p=*p2;
				*p2=aux;
			}
			p2++;
		}
		p++;
	}
}

void ordenamiento_seleccion(long *p){
	int i,j,minimo;
	long aux;
	for(i=0;i<N-1;i++){
		minimo=i;
		for(j=i+1;j<N;j++){
			if(*(p+j)<*(p+minimo)){
				minimo=j;
			}
		}
		if(i!=minimo){
			aux=*(p+i);
			*(p+i)=*(p+minimo);
			*(p+minimo)=aux;
		}
	}
}

void ordenamiento_insercion(long *p){
	long pos,aux;
	int i;
	for(i=1;i<N;i++){
		pos=i;
		aux=*(p+i);
		while(pos>0 && *(p+pos-1)>aux){
			*(p+pos)=*(p+pos-1);
			pos--;
		}
		*(p+pos)=aux;
	}
}

/*
//Prueba de código
void imprimir(long *p,long *p2, long *p3){
	int i;
	for(i=0;i<N;i++){
		printf("\n%d_____*p=%ld_____*p2=%ld_____*p3=%ld",i,*p,*p2,*p3);
		p++;
		p2++;
		p3++;
	}
}/**/

