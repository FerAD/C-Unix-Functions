#include "entsal.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char * parametros[] = {
		[0] = "entsal.txt",
		[1] = "O_WRONLY",
	};
	ARCHIVO *ar = malloc(sizeof(ARCHIVO));
	
	ar = abreArch(parametros[0], parametros[1]);
	char leido1c = AleeChar(ar);
	char leido2 = AleeChar(ar);
	printf("Caracter: %c\n",leido1c);
	printf("Caracter: %c\n",leido2);
	
	int leido1i = AleeInt(ar);
	printf("Numero int: %d\n",leido1i);
	int leido2i = AleeInt(ar);
	printf("Numero int: %d\n",leido2i);
	int leido3i = AleeInt(ar);
	printf("Numero int: %d\n",leido3i);
	int leido4i = AleeInt(ar);
	printf("Numero int: %d\n",leido4i);
	
	float leido1f = AleeFloat(ar);
	printf("Numero Float: %f\n",leido1f);
	float leido2f = AleeFloat(ar);
	printf("Numero Float: %f\n",leido2f);
	float leido3f = AleeFloat(ar);
	printf("Numero Float: %f\n",leido3f);
	
	char *str =malloc(sizeof(char));
	int st = AleeString(ar,str,4);
	printf("String leido: %s\n",str);
	
	printf("CHAR escrito : c\n");
	AescribeChar(ar,'c');

	st = AleeString(ar,str,4);
	printf("String leido: %s\n",str);

	printf("Escribe string: Fernando\n");
	st = AescribeString(ar,"Fernando");

	st = AleeString(ar,str,4);
	printf("String leido: %s\n",str);
	cierraArch(ar);

}