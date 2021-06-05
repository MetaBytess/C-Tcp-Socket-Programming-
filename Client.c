#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {

    //create a socket
	int client_socket;
	client_socket = socket(AF_INET, SOCK_STREAM, 0);

    //specify the sockets address 
	struct sockaddr_in server_addresss;
	server_addresss.sin_family = AF_INET;
	server_addresss.sin_port = htons(9966);
	server_addresss.sin_addr.s_addr = INADDR_ANY;


	int connection_status = connect(client_socket, (struct sockaddr *) &server_addresss, sizeof(server_addresss));
	//check for error with the connection
	if (connection_status == -1){
		    printf("There was an error attempting to connect to the socket");
	}

	//recieve data from the server
	char server_response[256];
	recv(client_socket, &server_response, sizeof(server_response), 0);

	//print tyhe servers response
	printf("The server sent the data: %s\n", server_response);

    //close the socket
	close(socket);

	return 0:


}