#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {

	FILE *fp;
	FILE *fp1;

	char ch;
	char Opt[1];
	char Name[50];
	int Age[2];

	printf("\nBIENVENID@S A LA FERIA!\n");

	printf("\nFavor ingresar nombre: ");
		scanf("%s", Name);

	printf("\nFavor ingresar edad: ");
		scanf("%d", Age);

	if(*Age > 90) {

		printf("\nFavor ver fichero con comentario en C:/Users/User/Desktop/INS-340/Err.txt");

		fp = fopen("C:/Users/User/Desktop/INS-340/Err.txt", "w+");
			 fprintf(fp, "Lo sentimos, su edad '%d' es muy elevada para entrar a la feria.\n", *Age);
			 fclose(fp);

		printf("\n\nDesea visualizar los contenidos del fichero Err.txt en la consola (S/N)? ");
			scanf("%s", Opt);

		if(*Opt == 's' || *Opt == 'S') {

			printf("\nEl contenido del fichero Err.txt es:");

			fp1 = fopen("C:/Users/User/Desktop/INS-340/Err.txt", "r");

			while(ch != EOF) {

				printf("%c", ch);
				ch = getc(fp1);
			}

			fclose(fp1);

		}

		else {

			printf("\nSaliendo del programa...\n");
			exit(0);
		}

	}


	else
		printf("\nBienvenid@ a la feria '%s' de %d!\n", Name, *Age);

}