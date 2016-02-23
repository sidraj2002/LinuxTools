/*
 ============================================================================
 Name        : fork2.c
 Author      : 
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
#include <iostream>
#include <iomanip>
#include "Linkedlist.h"
#include <pthread.h>
#include <string.h>


using namespace std;
long long sum = 0;
long long sum0 = 0;
long long sum1 = 0;
void* add_run0(void* arg){

	long long *limit_ptr = (long long*) arg;
	long long limit = *limit_ptr;

	for (long long i = 0; i < limit/2; i++){
		sum0 += retData(i);
	}
	pthread_exit(0);
}
void* add_run1(void* arg){

	long long *limit_ptr = (long long*) arg;
	long long limit = *limit_ptr;

	for (long long i = limit/2; i < limit; i++){
		sum1 += retData(i);
	}
	pthread_exit(0);
}

int main(int argc, char *argv[]) {
													// Common work

	long long nLinks = atoi(argv[1]);
	long long linkData = atoll(argv[2]);
	for(int i = 0; i < nLinks; i++ ){
	linkInsert(linkData);
	linkData = linkData + 10;
	};

													// fork child process
	pid_t pid2 = fork(); 							// fork to create child

	if(pid2 < 0 ){
		perror("Fork Error!");
	}else if (pid2 == 0){
		long long sum = 0;											// Child process work
		printf("I'm a Child: %d\n", (int) getpid());

		for (long long i = 0; i < nLinks; i++){
			sum += retData(i);
			}

		printf("Child %d Sum is: %lld \n", (int) getpid(), sum);

		exit(0);
	};

	wait(NULL);
// Parent process work
	printf("I'm a parent: %d\n", (int) getpid());


		pthread_t tid0;
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		int t_create0 = pthread_create(&tid0, &attr, add_run0, &nLinks);
		if (t_create0 == 0){
				printf("thread created!\n");
			}

				pthread_t tid1;

				int t_create1 = pthread_create(&tid1, &attr, add_run1, &nLinks);
				if (t_create1 == 0){
						printf("thread created!\n");
					}
				pthread_join(tid0, NULL);
				pthread_join(tid1, NULL);
				sum = sum0 + sum1;

	printf("Parent %d Sum is: %lld \n", (int) getpid(), sum);

	return 0;
}
