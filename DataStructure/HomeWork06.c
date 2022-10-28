#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node* Link;
typedef struct{
	int data;
	Link next;
}Node;

void print_list(Link A);
int search(Link A, int data);
void insert_front(Link* A, int data);
void insert_last(Link* A, int data);
int delete_front(Link** A);
int delete(Link* A, int data);
int main()
{
	Link* A = NULL;
	insert_front(&A, 3);
	insert_front(&A, 4);
	insert_front(&A, 5);
	insert_last(&A, 2);
	print_list(A);
	printf("serch(2) : %d\n", search(A, 2));

	int i = delete_front(&A);
	delete(&A, 3);
	printf("delete_front %d: ",i);
	print_list(A);
	

}

void print_list(Link A) {
	Node* temp = A;
	while (temp != NULL) {
		printf("[ %d ] -> ", temp->data);
		temp = temp->next;
	}
	printf("[ NULL ]\n");
}

int search(Link A, int data) {
	Node* temp = A;
	for (int i = 0; temp != NULL; temp = temp->next,i++) {
		if (temp->data == data) {
			return i;
		}
	}
	return -1;
}

void insert_front(Link* A, int data) {
	Node* temp = (Link)malloc(sizeof(Node));
	temp->data = data;
	if (*A == NULL) {
		temp->next = NULL;
		*A = temp;
	}
	else {
		temp->next = *A;
		*A = temp;
	}
}

void insert_last(Link* A, int data) {
	Node* temp = *A;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = (Link)malloc(sizeof(Node));
	temp = temp->next;
	temp->data = data;
	temp->next = NULL;
}

int delete_front(Link* A) {
	Node* temp = *A;
	int resulte = temp->data;
	*A = ((Node*)*A)->next;
	free(temp);
	return resulte;
}

int delete(Link* A,int data) {
	if (*A == NULL) {
		printf("List is empty...\n");
		return -1;
	}

	printf("...\n");
	Node* before = *A;
	Node* temp = before->next;
	while (temp != NULL){
		if (temp->data == data) {
			before->next = temp->next;
			free(temp);
			return 1;
		}
		temp = temp->next;
	}
	return -1;
}