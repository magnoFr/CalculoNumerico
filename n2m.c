#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"



int main(int argc, char *argv[]){


	if(argc != 4)
		exit(-1);

	char out[100];

	long int base10;
	base10 = toBase10(argv[1], atoi(argv[2]));
	toBaseM(out, base10, atoi(argv[3]));	
	puts(out);

	return 0;
}