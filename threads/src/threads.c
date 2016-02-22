/*
 ============================================================================
 Name        : threads.c
 Author      : Sid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <pthread.h>

long long sum = 0;

void* add_run(void* arg){

	long long *limit_ptr = (long long*) arg;
	long long limit = *limit_ptr;

	for (long long i = 0; i <= limit; i++){
		sum += i;
	}
	pthread_exit(0);
}

int main(int argc, char **argv) {

	if (argc < 2){
		printf("Not enought Arguments\n");
		exit(1);
	}
	long long limit = atoll(argv[1]);
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int t_create = pthread_create(&tid, &attr, add_run, &limit);
	if (t_create == 0){
		printf("thread created!");
	}
	pthread_join(tid, NULL);
	printf("Sum is: %lld\n", sum);
	return 0;
};
