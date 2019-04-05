// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <sys/ipc.h>
#include <sys/shm.h>
#define PORT 9090 

int main(int argc, char const *argv[]) 
{ 
    key_t key = 1234;
    int *value;

    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    value = shmat(shmid, NULL, 0);

    *value = 10;

    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
     
    char *hello = "Hello from server"; 
    
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    //valread = read( new_socket , buffer, 1024); 
    //printf("%s\n",buffer ); 
    //send(new_socket , hello , strlen(hello) , 0 ); 
    //printf("Hello message sent\n"); 

    while(1){
        char buffer[1024] = {0};
        valread = read( new_socket , buffer, 1024);
        //printf("%s\n",buffer ); 
        //send(new_socket , hello , strlen(hello) , 0 ); 
        //fflush(stdout);
        if(strcmp("beli", buffer) == 0){
            //printf("aaaa");
            if(*value == 0) //printf("transaksi gagal\n");
                send(new_socket , "Transaksi Gagal" , strlen("Transaksi Gagal") , 0 ); 
            else if(*value != 0){
                *value = *value-1;
                //printf("transaksi berhasil\n");
                send(new_socket , "Transaksi Sukses" , strlen("Transaksi Sukses") , 0 );
            }
        }
        else{
            send(new_socket , "Command Salah" , strlen("Command Salah") , 0 );
        }
    }
    shmdt(value);
    shmctl(shmid, IPC_RMID, NULL);

    return 0; 
} 
