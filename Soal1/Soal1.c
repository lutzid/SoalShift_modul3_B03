#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#define debug(x) printf("%d\n", x);
pthread_t tid[15];
int cnt[15];
long long arr[15];
void precompute() {
	int i;
	arr[0] = 1;
	for(i = 1; i <= 15; i++) {
		arr[i] = arr[i - 1] * i;
	}
	return;
}

void *factorial(void *argv) {
	int fact = 1, j, i;
	int panjang = strlen((char *) argv);
	char *urutan = (char *) argv;
	int angka = 0;
	for(j = 0; j < panjang; j++) {
		angka = angka * 10 + (urutan[j] - '0');
	}
	// debug(angka);
	cnt[angka]++;
}

int main(int argc, char** argv) {
	precompute();
	memset(cnt, 0 ,sizeof(cnt));
	int i = 1, j;
	int err;
	i = 1;
	while(i < argc) {
		pthread_create(&(tid[i]), NULL, &factorial, (void *)argv[i]);
		i++;
	}
	for(i = 1; i < argc; i++) {
		pthread_join((tid[i]), NULL);
	}
	for(i = 0; i <= 15; i++) {
		while(cnt[i]--) {
			printf("%d! = %lld\n", i, arr[i]);
		}
	}
	exit(0);
	return 0;
}