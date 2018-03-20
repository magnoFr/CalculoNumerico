#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

char *totalBase = "0123456789ABCDEFGHIJKLMNOPQRSTUVXWYZ";


void inverterVetor(char *elemento){
	long int i = strlen(elemento) - 1;
	long int j = 0;
	char aux;

	while (j <= i/2){
		aux = elemento[i - j];
		elemento[i - j] = elemento[j];
		elemento[j++] = aux;
	}
}

long int valorAbsoluto (char elemento){
	char *p;

	//acha a primeira ocorrência de um caractere em um string
	if((p = strchr(totalBase, elemento))){
		//Como p e totalBase sao negativos na memoria e totalBase eh menor
		//que p, basta subtrair p e TotalBase para achar o inderexamento
		return  (p - totalBase);
	}
	else{
		return 1;
		}
}



int toBase10 (char *valor, int primeiraBase){
	long int i = strlen(valor) - 1;
	long int expoente = 1;
	long int Soma = 0;

	while(i >=0){
		Soma += valorAbsoluto(valor[i]) * expoente;
		i--;
		expoente *= primeiraBase;
	}
	return Soma;
}


void toBaseM (char *valor, long int base10, int base){
	//int i = strlen(base10 + "0") - 1;
	long int i = 0;

	if(base10 == 0) {
        valor[0]='0'; i=1;
    }

	while(base10){
		valor[i++] = totalBase[base10%base];
		base10 /= base;
	}

	

	if(i >= 0)
		inverterVetor(valor);
}