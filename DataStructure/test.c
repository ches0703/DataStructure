#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int data;
	struct Node* next;
}Node;

void insert_front(Node* Head, int data);
void insert_last(Node** Head, int data);
int delete_front(Node* Head);
void print_list(Node* Head);
void free_list(Node** Head);

int main()
{
	Node* Head = (Node*)malloc(sizeof(Node));
	Head->next = NULL;
	for (int input_data;;) {
		printf("List의 기본 연산\n");
		printf("0. Print List\n");
		printf("1. Insert Front\n");
		printf("2. Insert Last\n");
		printf("3. Delete Front\n");
		printf("4. Delete\n");
		printf("5. Search\n");
		printf("-1. Exit\n");

		scanf("%d", &input_data);
		if (input_data == -1) {
			break;
		}
		switch (input_data){
		case 0 :
			print_list(Head);
			break;
		case 1 :
			printf("Enter Data : ");
			scanf("%d", &input_data);
			insert_front(&Head, input_data);
		default:
			break;
		}

	}
	free_list(Head);


}

// 모든 리스트의 내용을 출력
void print_list(Node* Head) {
	Node* temp = Head->next;
	printf("[ Head ] -> ");
	while (temp != NULL) {
		printf("[ %d ] -> ", temp->data);
		temp = temp->next;
	}
	printf("[ NULL ]\n\n");
}

// List의 앞에 입력받은 데이터를 추가
void insert_front(Node** Head, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = (* Head)->next;
	(*Head)->next = temp;
	
}

// List의 마지막에 입력받은 데이터를 추가
void insert_last(Node** Head, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	
	Node* ptr = (* Head)->next;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = temp;
	
}

// 멘 앞의 노드를 삭제하고 그 값을 리턴
int delete_front(Node** Head) {
	// List가 이미 비어있는 경우 : -1 return
	if (*Head == NULL) {
		return -1;
	}
	Node* temp = *Head;
	int resulte = temp->data;
	*Head = temp->next;
	free(temp);
	return resulte;
}

// 값을 입력받아 해당하는 노드를 삭제 후 노드의 번호를 리턴
int delete(Node** Head, int data) {
	// List가 이미 비어있는 경우 : -1 return
	if (*Head == NULL) {
		return -1;
	}
	int Node_num = 0;
	Node* ptr = *Head;
	Node* temp = *Head;
	while (ptr != NULL) {
		if (ptr->data == data) {
			temp->next = ptr->next;
			free(ptr);
			return Node_num; // 노드의 번호 리턴
		}
		temp = ptr;
		ptr = ptr->next;
		Node_num++;
	}
	// List에 입력받은 데이터가 없는 경우 : return -2
	return -2;
}

void free_list(Node** Head) {
	Node* ptr = *Head;
	Node* temp = ptr;
	*Head = NULL;
	while (ptr != NULL){
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
}