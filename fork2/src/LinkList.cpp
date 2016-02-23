/*
 * LinkList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: ubuntu
 */
/*
Meant for Practice/ Educational Purposes
Author: Siddharth Rajguru
Purpose: Linked List manipulation and creation
*/

#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
struct node* head = NULL;
struct node {
	int x = 0;
    struct node* next;
};

void linkInsert(long long val){									/*Insert a node object */
	struct node* temp;
	struct node* temp2;
	if (head != NULL){										/*If not the first node*/
		temp = new (struct node);
		temp->x = val;
		temp->next = head;
		head = temp;
		printf("\n");
	};
	if (head == NULL){										/*if the first node*/
		temp = new (struct node);
		temp->x = val;
		temp->next = NULL;
		head = temp;
		printf("\n");
	};
	};

void nInsert(int val, int n){							/*Insert a node at the Nth position in the list*/
	struct node* temp = head;
	struct node* temp2;
	struct node* temp3;
	temp2 = new (struct node);
	temp3 = new (struct node);
	temp = head;
	for (int i = 0; i < n; i++){
		temp = temp->next;
	};
	temp3 = temp;
	temp2->next = temp3->next;
	temp2->x = val;
	temp->next = temp2;


	printf("\n");
}

void listRev(){											/*Reverse List Head = Null and Null = Head*/
	struct node* temp = head;
	struct node* temp2 = NULL;
	while (head != NULL){
	head = temp->next;
	temp->next = temp2;
	temp2 = temp;
	temp = head;
	};
	head = temp2;
};

void print(){											/*Print list contents*/
	struct node* temp = head;
	printf("list is:");
	while (temp != NULL ){
	printf("%d\n", temp->x);
	temp = temp->next;
	};

};



int retData(int n){
	int val = 0;
	struct node* temp = head;
	for (int i = 0; i < n; i++){
			temp = temp->next;
		};
	val = temp->x;
	return val;

};


//int main(void){
//	linkInsert(1);
//	linkInsert(2);
//	linkInsert(3);
//	linkInsert(4);
//	linkInsert(5);
//	linkInsert(6);
//	listRev();
//	print();
//	nInsert(9, 2);
//	print();
//	return(0);
//
//}


