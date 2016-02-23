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



int main(int argc, char *argv[]) {
	int sum = 0;

	int pid = (int)getpid();
	printf("This is: %d\n", pid);
	int j = 0;
	linkInsert(1);
	linkInsert(2);
	linkInsert(3);
	linkInsert(4);
	linkInsert(5);

// fork child process
	pid_t pid2 = fork();

	if(pid2 < 0 ){
		perror("Fork Error!");
	}else if (pid2 == 0){
		printf("I am Child: %d\n", (int) getpid());
		int i = 0;
		print();
		listRev();
		print();
		printf("Child %d Done task %d\n", (int) getpid(), i);

		exit(0);

	};
	printf("I'm a parent\n");
	wait(NULL);
	int x = retData(3);
		printf("return:%d\n", x);
	print();
	return 0;
}
