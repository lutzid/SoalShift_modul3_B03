#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h> 

//inisialisasi array untuk menampung thread 
pthread_t tid[6];
int runsave1, runsave2, runzip1, runzip2;

void* Simpan1(){
	//mengecek apakah direktori sudah ada atau belum
	
	if (0 != access("/home/zidan/Documents/FolderProses1/", F_OK))
		system("mkdir /home/zidan/Documents/FolderProses1/");
	if (0 == access("/home/zidan/Documents/FolderProses1/SimpanProses1.txt", F_OK))
		system("rm /home/zidan/Documents/FolderProses1/SimpanProses1.txt");
	system("ps -aux | tail -n 10 >> /home/zidan/Documents/FolderProses1/SimpanProses1.txt");
}

void* Simpan2(){
	//mengecek apakah direktori sudah ada atau belum
	if (0 != access("/home/zidan/Documents/FolderProses2/", F_OK))
		system("mkdir /home/zidan/Documents/FolderProses2/");
	if (0 == access("/home/zidan/Documents/FolderProses2/SimpanProses2.txt", F_OK))
		system("rm /home/zidan/Documents/FolderProses2/SimpanProses2.txt");
	system("ps -aux | tail -n 10 >> /home/zidan/Documents/FolderProses2/SimpanProses2.txt");
}

void* Zip1(){
	// -j (junk) dimana ketika melakukan kompres tidak akan mengkompres directory dari file yang akan dikompres
	system("zip -j /home/zidan/Documents/FolderProses1/KompresProses1.zip /home/zidan/Documents/FolderProses1/SimpanProses1.txt");
	system("rm /home/zidan/Documents/FolderProses1/SimpanProses1.txt");
}

void* Zip2(){
	// -j (junk) dimana ketika melakukan kompres tidak akan mengkompres directory dari file yang akan dikompres
	system("zip -j /home/zidan/Documents/FolderProses2/KompresProses2.zip /home/zidan/Documents/FolderProses2/SimpanProses2.txt");
	system("rm /home/zidan/Documents/FolderProses2/SimpanProses2.txt");
}
void* Unzip1(){
	// -d direktori mana yang akan menjadi tujuan ekstrak
	system("unzip /home/zidan/Documents/FolderProses1/KompresProses1.zip -d /home/zidan/Documents/FolderProses1/");
	system("rm /home/zidan/Documents/FolderProses1/KompresProses1.zip");
}
void* Unzip2(){
	// -d (delete entries in zipfile)
	system("unzip /home/zidan/Documents/FolderProses2/KompresProses2.zip -d /home/zidan/Documents/FolderProses2/");
	system("rm /home/zidan/Documents/FolderProses2/KompresProses2.zip");
}
																																			//Created By: Kelompok Sisop B3

int main(){
	int err;
	//err=pthread_create(&(tid[0]),NULL,&Proses1,NULL);
	// if(err!=0) //cek error
	// 	{
	// 		printf("\n can't create thread : [%s]",strerror(err));
	// 	}
	// 	else
	// 	{
	// 		printf("\n create thread success\n");
	// 	}
	//err=pthread_create(&(tid[1]),NULL,&Proses2,NULL);
	// if(err!=0) //cek error
	// 	{
	// 		printf("\n can't create thread : [%s]",strerror(err));
	// 	}
	// 	else
	// 	{
	// 		printf("\n create thread success\n");
	// 	}
	pthread_create(&(tid[0]),NULL,&Simpan1,NULL);
	pthread_create(&(tid[1]),NULL,&Simpan2,NULL);
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);

	pthread_create(&(tid[2]),NULL,&Zip1,NULL);
	pthread_create(&(tid[3]),NULL,&Zip2,NULL);
	pthread_join(tid[2],NULL);
	pthread_join(tid[3],NULL);

	printf("Menunggu 15 detik untuk mengekstrak kembali\n");
	sleep(15);

	pthread_create(&(tid[4]),NULL,&Unzip1,NULL);
	pthread_create(&(tid[5]),NULL,&Unzip2,NULL);
	pthread_join(tid[4],NULL);
	pthread_join(tid[5],NULL);

	exit(0);
	return 0;
}