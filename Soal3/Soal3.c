#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int wus = 0, ss = 0;
int cntAgmal = 0, cntIraj = 0;
int kode = 0;
int wake_up_status = 0;
int spirit_status = 100;
char *msgAgmal = "Fitur Iraj Ayo Tidur disabled 10 s";
char *msgIraj = "Fitur Agmal Ayo Bangun disabled 10 s";

void *agmal(void *ptr) {
	while(1) {
		if(cntIraj == 3) {
			printf("%s\n", msgIraj);
			cntIraj = 0;
			wus = 10;
		}
		if(wus) {
			wus--;
			sleep(1);
			continue;
		}
		else if(kode == 1){
			wake_up_status += 15;
			cntAgmal++;
			kode = 0;
		}
	}
}

void *iraj(void *ptr) {
	while(1) {
		if(cntAgmal == 3) {
			printf("%s\n", msgAgmal);
			cntAgmal = 0;
			ss = 10;
		}
		if(ss) {
			ss--;
			sleep(1);
			continue;
		}
		else if(kode == 2){
			spirit_status -= 20;
			cntIraj++;
			kode = 0;
		}
	}
}

int main() {
	pthread_t Agmal, Iraj;
	pthread_create(&Agmal, NULL, agmal, NULL);
	pthread_create(&Iraj, NULL, iraj, NULL);
	while(wake_up_status < 100 && spirit_status > 0) {
		if(wake_up_status >= 100 || spirit_status <= 0) break;
		char *temp = (char *) malloc(50);
		scanf("%[^\n]%*c", temp); 
		if(strcmp(temp, "All Status") == 0) {
			printf("Agmal WakeUp_Status = %d\n", wake_up_status);
			printf("Iraj Spirit_Status = %d\n", spirit_status);
		}
		else if(strcmp(temp, "Agmal Ayo Bangun") == 0 && wus == 0) {
			kode = 1;
		}
		else if(strcmp(temp, "Iraj Ayo Tidur") == 0 && ss == 0) {
			kode = 2;
		}
	}
	if(wake_up_status >= 100) {
		puts("Agmal Terbangun,mereka bangun pagi dan berolahraga");
	}
	else {
		puts("Iraj ikut tidur, dan bangun kesiangan bersama Agmal");
	}
	return 0;
}