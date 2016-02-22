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




int main(int argc, char *argv[]) {
	int sum = 0;
	int pid = (int)getpid();
	printf("This is: %d\n", pid);
	int j = 0;
	for(; j<4; j++){

	pid_t pid2 = fork();


	if(pid2 < 0 ){
		perror("Fork Error!");
	}else if (pid2 == 0){
		printf("I am Child: %d\n", (int) getpid());
		int i = 0;
		for(; i < 4; i++){
			sleep(2);
			sum += 1;
			printf("Child %d Done task %d\n", (int) getpid(), i);
		}
		exit(0);
	}
	};
	printf("I'm a parent\n");
	int i = 0;
			for(; i < 4; i++){
				sleep(2);
				sum += 1;
				printf("Parent Done task %d\n", i);
			}
	wait(NULL);
	return 0;
}
