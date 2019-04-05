#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
int hunger_status = 200, hygiene_status = 100, health_status = 300, food_stock = 3, bath_status = 0;
int perintah1 = 0, perintah2 = 0, perintah3 = 0;
int *value;
int keluar = 0, enemyHealth = 100, pindah = 1, cnt = 10;
int cntHunger = 0, cntHealth = 0, cntHygiene = 0, kode = 0;
char nama_monster[100];

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

void* standbyCommand(void *arg) {
	while(1) {
		if(kode == 1) {
			if(pindah > 0 || cnt == 10 || bath_status > 0) {
				if(cnt == 10)
					cnt = 0;
				system("clear");
				printf("Standby Mode\n");
				printf("Health Status 	: %d\n", health_status);
				printf("Hunger Status 	: %d\n", hunger_status);
				printf("Hygiene Status 	: %d\n", hygiene_status);
				printf("Food Left 	: %d\n", food_stock);
				pindah = 0;
				if(cntHunger == 10) {
					if(hunger_status - 5 <= 0) hunger_status = 0;
					else hunger_status -= 5;
					cntHunger = 0;
				}
				if(cntHealth == 10) {
					health_status += 5;
					cntHealth = 0;
				}
				if(cntHygiene == 30) {
					if(hygiene_status - 10 <= 0) hygiene_status = 0;
					else hygiene_status -= 10;
					cntHygiene = 0;
				}
				if(bath_status > 0) {
					printf("Bath will be ready in %ds\n", bath_status--);
					pindah = 1;
				}
				else printf("Bath is ready\n");
				printf("Choices\n");
				printf("1. Eat\n2. Bath\n3. Battle\n4. Shop\n5. Exit\n");
				if(perintah1 == 1 && food_stock > 0) {
					if(hunger_status + 15 <= 200)
						hunger_status += 15;
					else hunger_status = 200;
					food_stock -= 1;
					pindah = 1;
				}
				else if(perintah1 == 2 && bath_status == 0) {
					hygiene_status += 30;
					bath_status = 20;
					pindah = 1;
				}
				else if(perintah1 == 3) {
					kode = 2;
					pindah = 1;
					enemyHealth = 100;
				}
				else if(perintah1 == 4) {
					kode = 3;
					pindah = 1;
				}
				else if(perintah1 == 5) {
					keluar = 1;
					pindah = 1;
				}
				perintah1 = 0;
			}
			cnt++;
			cntHunger++;
			cntHealth++;
			cntHygiene++;
			sleep(1);
		}
	}
}

void* battleCommand(void *arg) {
	while(1) {
		if(kode == 2) {
			if(pindah > 0) {
				system("clear");
				printf("Battle Mode\n%s’s Health : %d\nEnemy’s Health : %d\nChoices\n1. Attack\n2. Run\n", nama_monster, health_status, enemyHealth);
				pindah = 0;
				if(perintah2 == 1) {
					health_status -= 20;
					enemyHealth -= 20;
					if(enemyHealth == 0 || health_status <= 0) {
						kode = 1;
						health_status = 0;
					}
					pindah = 1;
				}
				else if(perintah2 == 2) {
					kode = 1;
					pindah = 1;
				}
				perintah2 = 0;
			}
		}
	}
}

void* shopCommand(void *arg) {
	while(1) {
		if(kode == 3) {
			if(pindah > 0) {
				system("clear");
				printf("Shop Mode\nShop food stock : %d\nYour food stock : %d\nChoices\n1. Buy\n2. Back\n", *value, food_stock);
				pindah = 0;
				if(perintah3 == 1) {
					if(*value > 0) {
						food_stock += 1;
						*value -= 1;
					}
					pindah = 1;
				}
				else if(perintah3 == 2) {
					kode = 1;
					pindah = 1;
				}
				perintah3 = 0;
			}
		}
	}
}

int main () {
	key_t key = 1234;
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    value = shmat(shmid, NULL, 0);
	pthread_t standby, battle, shop;
	pthread_create(&standby, NULL, &standbyCommand, NULL);
	pthread_create(&battle, NULL, &battleCommand, NULL);
	pthread_create(&shop, NULL, &shopCommand, NULL);
	printf("Pet's Name : ");
	scanf("%[^\n]%*c", nama_monster);
	kode = 1;
	while(1) {
		if(keluar == 1) {
			system("clear");
			break;
		}
		if(kode == 1) {
			perintah1  = getch();
			perintah1 -= '0';
		}
		else if(kode == 2) {
			perintah2 = getch();
			perintah2 -= '0';
		}
		else if(kode == 3) {
			perintah3 = getch();
			perintah3 -= '0';
		}
		if(perintah1 > 0 || perintah2 > 0 || perintah3 > 0) pindah = 1;
	}
	return 0;
}