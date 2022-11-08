#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h> // APIs para sockets.
#include <netinet/in.h> // Estructura para almacenar la informacion de la direccion. 

int main(int argc, char const* argv[]) {

	/*Creamos un socket de servidor similar 
	  al creado en el cliente */

	int servSockD = socket(AF_INET, SOCK_STREAM, 0);

	// String para almacenar la data que sera enviada al cliente. 

	char serMsg[255] = "Mensaje desde el servidor hacia el cliente \'Hola CLiente!\'";

	// Definimos la direccion del cliente. 

	struct sockaddr_in servAddr;

	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(9001); // Uso de un puerto no usado. 
	servAddr.sin_addr.s_addr = INADDR_ANY;

	// Enlazamos el socket a la IP y puerto especificado.

	bind(servSockD, (struct sockaddr*)&servAddr, sizeof(servAddr));

	// Escucha las conexiones. 

	listen(servSockD, 1);

	// Mantener el enlace con el cliente. 

	int clientSocket = accept(servSockD, NULL, NULL);

	// Enviamos el mensaje al socket del cliente. 

	send(clientSocket, serMsg, sizeof(serMsg), 0);

	return 0;
}