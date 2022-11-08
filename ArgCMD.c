#include <stdio.h>

int main (int argc, char *argv[], char *env[]) {

	int i;

	printf("\nLa cantidad de argumentos de linea de comando ingresados es: %d\n\n", argc);

	for(i = 0; i < argc; i++) 
		printf("El argumento %d es: %s\n", i, argv[i]);

	printf("\n");

	for(i = 0; env[i] != NULL; i++)
		printf("La variable de ambiente %d es: %s\n", i, env[i]);

	return 0;
}