#include "entsal.h"
#import <unistd.h>
#import <fcntl.h>
#include <stdlib.h>
#import <stdio.h>
#import <string.h>

ARCHIVO* abreArch(char *nombre, char *permisos)
{
	ARCHIVO *ar = (ARCHIVO*)malloc(1*sizeof(ARCHIVO));
	ar->descriptor = open(nombre, O_RDONLY);
	ar->nombre = nombre;
	ar->permisos = permisos;
	ar->contadorBufer = -1;
	

	if((ar->descriptor)<0)
		printf("Error no se puede abrir el archivo\n");
	else{
		printf("El archivo se abrio exitosamente\n");
		return ar;
	}


}

void cierraArch(ARCHIVO *ar){
	int cerrar = close(ar->descriptor);

	if(cerrar == 0)
		printf("El archvio se cerro exitosamente\n");
	else if(cerrar < 0) 
		printf("Error al cerrar el archivo\n");

}

char AleeChar(ARCHIVO *ar){
	ar->contadorBufer++;
	read(ar->descriptor,ar->bufer,2048);
	return ar->bufer[ar->contadorBufer];
}

int contadorINT = 0; //contador para que cada ves que se llame la funcion el bufer del ARCHIVO este en la posicion en que se dejo por ultima ves
int contador = 0; 	//se le asigna el valor de contadorINT, esta es la que se usa en bufer 
int AleeInt(ARCHIVO *ar){
	int contador2 = 0;//se utiliza para manejar el indice de daux para asignar al num que se retorna
	int bandera = 0;	//bandera que nos ayuda a saltarnos las letras y tomar en cuenta solo los digitos
	int i = 0;	//inicio del for siempre en 0
	int num;	//el numero que se retorna. 
	char *d = (char*)malloc(sizeof(char));	//variable en la que se guarda lo que se va leyendo tomando en cuenta nuemros y letras
	char *daux = (char*)malloc(sizeof(char));	//variable en la que se guarda unicamente los digitos no las letras y esta se asigna a el numero que se va a retornar
	
	while (bandera < 2){ 	//inicia si la bandera es menor que 2
		for(i; i<=2048; i++)	//ciclo for que recorre el archivo
		{
			d[i] = ar->bufer[i+contador];	//guardo el primer caracter leeido del bufer
			//si es un digito segun ascii y la bandera es igual a 0 (o sea que es el primer digito que se encuentra)
			if((int)d[i] == 48 && bandera == 0||(int)d[i] == 49 && bandera == 0||(int)d[i] == 50 && bandera == 0||(int)d[i] == 51 && bandera == 0||(int)d[i] == 52 && bandera == 0||(int)d[i] == 53 && bandera == 0||(int)d[i] == 54 && bandera == 0||(int)d[i] == 55 && bandera == 0||(int)d[i] == 56 && bandera == 0||(int)d[i] == 57 && bandera == 0) 
			{	
				*daux = d[i];	//asigno el valor de ese digito a la primera posicion del apuntador
				contador2 = 1;	//sumo uno al indice para manejar la variable que se asignara al numero a retornar
				bandera = 1;	//sumo uno a mi bandera que indica que ya encontre el primer digito
				num = atoi(daux);	//asigno lo leido a una variable int que es la que voy a retornar
			}
			//si leeo otro digito y ya lei uno anteriormente
			else if((int)d[i] == 48 && bandera == 1||(int)d[i] == 49 && bandera == 1||(int)d[i] == 50 && bandera == 1||(int)d[i] == 51 && bandera == 1||(int)d[i] == 52 && bandera == 1||(int)d[i] == 53 && bandera == 1||(int)d[i] == 54 && bandera == 1||(int)d[i] == 55 && bandera == 1||(int)d[i] == 56 && bandera == 1||(int)d[i] == 57 && bandera == 1)
			{	
				daux[contador2] = ar->bufer[i+contador]; //guardo el digito leido en daux
				num = atoi(daux);	//asigno el numero leido a num que es la variable que voy a retornar
				contador2++;	// agrego 1 al contador de la variable daux
			}
			else{	//si leo cualquier cosa que no sea un numero
				if(bandera == 1){	//si leo cualquier cosa que no sea un numero y ya habia leido un digito 
					bandera = 2;	//agrego uno a mi bandera 
					contador = contadorINT;	//igualo contador y contadorINT para poder guardar la posicion del bufer para que la prox llamada a esta funcion sea desde esa posicion del bufer
					free(daux);
					daux = NULL;
					free(d);
					d = NULL;
					return num;
				}
				if(ar->bufer[i+contador] == '\0'){
					return 0;
				}
			}
			contadorINT++;
		}
	}
}

int contadorINT2 = 0; //contador2 para que cada ves que se llame la funcion el bufer del ARCHIVO este en la posicion en que se dejo por ultima ves
int contador2 = 0; 	//se le asigna el valor de contadorINT2, esta es la que se usa en bufer 
float AleeFloat(ARCHIVO *ar){
	int contador3 = 0;//se utiliza para manejar el indice de daux para asignar al num que se retorna
	int bandera = 0;	//bandera que nos ayuda a saltarnos las letras y tomar en cuenta solo los digitos
	int i = 0;	//inicio del for siempre en 0
	float num;	//el numero que se retorna. 
	char *d2 = (char*)malloc(sizeof(char));	//variable en la que se guarda lo que se va leyendo tomando en cuenta nuemros y letras
	char *daux2 = (char*)malloc(sizeof(char));	//variable en la que se guarda unicamente los digitos no las letras y esta se asigna a el numero que se va a retornar
	while (bandera < 2){ 	//inicia si la bandera es menor que 2
		for(i; i<=2048; i++)	//ciclo for que recorre el archivo
		{	
			d2[i] = ar->bufer[i+contador2];	//guardo el primer caracter leeido del bufer
			//si es un digito segun ascii y la bandera es igual a 0 (o sea que es el primer digito que se encuentra)
			if((int)d2[i] == 48 && bandera == 0 && (int)ar->bufer[(i+contador2)+1] == 46 || (int)d2[i] == 49 && bandera == 0 && (int)ar->bufer[(i+contador2)+1] == 46 || (int)d2[i] == 50 && bandera == 0 && (int)ar->bufer[(i+contador2)+1] == 46 || (int)d2[i] == 51 && bandera == 0 && (int)ar->bufer[(i+contador2)+1] == 46 || (int)d2[i] == 52 && bandera == 0 && (int)ar->bufer[(i+contador2)+1] == 46 || (int)d2[i] == 53 && bandera == 0 && (int)ar->bufer[(i+contador2)+1] == 46 || (int)d2[i] == 54 && bandera == 0 && (int)ar->bufer[(i+contador2)+1] == 46 || (int)d2[i] == 55 && bandera == 0 && (int)ar->bufer[(i+contador2)+1] == 46 || (int)d2[i] == 56 && bandera == 0 && (int)ar->bufer[(i+contador2)+1] == 46 || (int)d2[i] == 57 && bandera == 0 && (int)ar->bufer[(i+contador2)+1] == 46) 
			{	
				*daux2 = d2[i];	//asigno el valor de ese digito a la primera posicion del apuntador
				contador3 = 1;	//sumo uno al indice para manejar la variable que se asignara al numero a retornar
				bandera = 1;	//sumo uno a mi bandera que indica que ya encontre el primer digito
				num = atof(daux2);	//asigno lo leido a una variable int que es la que voy a retornar
			}
			else if(((int)d2[i]) == 46)
			{
				daux2[contador3] = ar->bufer[i+contador2];
				num = atof(daux2);	//asigno el numero leido a num que es la variable que voy a retornar
				contador3++;	// agrego 1 al contador2 de la variable daux
			}
			//si leeo otro digito y ya lei uno anteriormente
			else if((int)d2[i] == 48 && bandera == 1||(int)d2[i] == 49 && bandera == 1||(int)d2[i] == 50 && bandera == 1||(int)d2[i] == 51 && bandera == 1||(int)d2[i] == 52 && bandera == 1||(int)d2[i] == 53 && bandera == 1||(int)d2[i] == 54 && bandera == 1||(int)d2[i] == 55 && bandera == 1||(int)d2[i] == 56 && bandera == 1||(int)d2[i] == 57 && bandera == 1)
			{	
				daux2[contador3] = ar->bufer[i+contador2]; //guardo el digito leido en daux
				num = atof(daux2);	//asigno el numero leido a num que es la variable que voy a retornar
				contador3++;	// agrego 1 al contador2 de la variable daux
			}
			else
			{	//si leo cualquier cosa que no sea un numero
				if(bandera == 1)	//si leo cualquier cosa que no sea un numero y ya habia leido un digito 
				{	
					bandera = 2;	//agrego uno a mi bandera 
					contador2 = contadorINT2;	//igualo contador2 y contadorINT2 para poder guardar la posicion del bufer para que la prox llamada a esta funcion sea desde esa posicion del bufer
					free(daux2);
					daux2 = NULL;
					free(d2);
					d2 = NULL;
					return num;
				}
				if(ar->bufer[i+contador2] == '\0'){
					return 0;
				}
				
			}
			contadorINT2++;
		}
	}
}

int AleeString(ARCHIVO *ar, char *str, int x){
	
	int i = 0;
	for(i;i<x;i++)
	{
		if(ar->bufer[i] != '\n')
		{
			if(i==0){
				str[i] = ar->bufer[i];
			}else{
				str[i] = ar->bufer[i];
			}
		}else{
			return 1;
		}
	}
	return 1;
}

int con = 0;
int AescribeChar(ARCHIVO *ar,char c){
	int i;
	
	ar->bufer[con] = c;
	con++;
}

int AescribeString(ARCHIVO *ar, char *cadena){
	int i;
	for(i = 0;i< strlen(cadena); i++){
 			AescribeChar(ar, cadena[i]);
 		}
}
