#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <termios.h>
int *value;
int perintah = 0;
int keluar = 0;
int pindah = 1;

char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

void *shop(void *arg) {
	while(1) {
		if(pindah > 0) {
			system("clear");
			printf("Shop\nFood stock : %d\nChoices\n1. Restock\n2. Exit\n", *value);
			pindah = 0;
			if(perintah == 1) {
				*value += 1;
				perintah = 0;
				pindah = 1;
			}
			else if(perintah == 2) {
				keluar = 1;
				pindah = 1;
			}
			perintah = 0;
		}
	}
}

int main() {
	key_t key = 1234;
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    value = shmat(shmid, NULL, 0);
    *value = 10;
    pthread_t shopThread;
    pthread_create(&shopThread, NULL, &shop, NULL);
	while(1) {
		if(keluar == 1) {
			system("clear");
			break;
		}
		perintah = getch();
		perintah -= '0';
		if(perintah > 0) pindah = 1;
	}
	return 0;
}