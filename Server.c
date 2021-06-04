#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){

	char server_message[256] = "You have arrived!";

    //create the server socket
	int server_socket
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	//define the server address
	struct sockaddr_in server_addresss;
	server_addresss.sin_faamily = AF_INET;
	server_addresss.sin_port = htons(9966);
	server_addresss.sin_addr.s_addr = INADDR_ANY;

	//bind the socket to the specified ip and port
	bind(server_socket, (struct sockaddr*), &server_addresss, sizeof(server_addresss));

	listen(server_socket, 6);


	int client_socket
	client_socket = accept(server_socket, NULL, NULL);


	send(client_socket, server_message, sizeof(server_message), 0);

	close(server_socket);





}