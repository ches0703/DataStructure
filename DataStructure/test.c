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
int delete(Node** Head, int data);
void print_list(Node* Head);
int search(Node* Head, int data);
void free_list(Node** Head);

int main()
{
	// List
	Node* List = (Node*)malloc(sizeof(Node)); // List's Num은 0
	List->next = NULL;
	
	// Stack
	Node* Stack = (Node*)malloc(sizeof(Node));
	Stack->next = NULL;

	// Queue
	Node* Queue = (Node*)malloc(sizeof(Node));
	Queue->next = NULL;

	int resulte;
	int input_data;

	// 기본 리스트 연산
	for (;;) {
		printf("List's Basic Process\n");
		printf("0. Print List\n");
		printf("1. Insert Front\n");
		printf("2. Insert Last\n");
		printf("3. Delete Front\n");
		printf("4. Delete\n");
		printf("5. Search\n");
		printf("-1. Exit\n");

		printf("Menu Select : ");
		scanf("%d", &input_data);
		if (input_data == -1) {
			printf("Basic List Process End...\n");
			free_list(&List);
			break;
		}
		switch (input_data){
		// 리스트 출력
		case 0 : 
			printf("List : ");
			print_list(List);
			break;

		// 리스트 입력 : Front
		case 1 : 
			printf("Enter Data : ");
			scanf("%d", &input_data);
			insert_front(&List, input_data);
			printf("List : ");
			print_list(List);
			break;

		// 리스트 입력 : Last
		case 2 : 
			printf("Enter Data : ");
			scanf("%d", &input_data);
			insert_last(&List, input_data);
			printf("List : ");
			print_list(List);
			break;

		// 노드 삭제 : Front
		case 3 : 
			resulte = delete_front(&List);
			if (resulte == -1) { // 리스트가 비어있는 경우
				printf("Lise is Empty...\n");
			}
			else { // 정상 작동 : 해당 노드의 data 출력
				printf("Deleted Node's Data : %d\n", resulte);
			}
			printf("List : ");
			print_list(List);
			break;

		// 노드 삭제 : Data에 의한 삭제
		case 4 : 
			printf("Enter Delete Data : ");
			scanf("%d", &input_data);
			resulte = delete(&List, input_data);
			if (resulte == -1) { // 리스트가 비어있는 경우
				printf("Lise is Empty...\n");
			}
			else if (resulte == -2) { // 입력 받은 데이터에 대해 해당하는 노드가 없는 경우
				printf("Not Found Node...\n");
			}
			else { // 정상 작동 : 해당 노드의 번호 출력
				printf("Deleted Node's Num : %d\n", resulte);
			}
			printf("List : ");
			print_list(List);
			break;

		// 노드 검섹 
		case 5 : 
			printf("Enter Search Data : ");
			scanf("%d", &input_data);
			resulte = search(List, input_data);
			if (resulte == -1) { // 입력 받은 데이터에 대해 해당하는 노드가 없는 경우
				printf("Not Found Node...\n");
			}
			else { // 정상 작동 : 해당 노드의 번호 출력
				printf("Searched Node's Num : %d\n", resulte);
			}
			printf("List : ");
			print_list(List);
			break;

		// 잘못된 값 입력
		default:
			getchar();
			printf("Enterd Worng Value!!!\n\n");
			break;
		}
	}
	
	printf("------------------------------------------------------\n");
	printf("------------------------------------------------------\n");

	// Stack의 기본연산
	for (;;) {
		printf("Stack's Basic Process\n");
		printf("0. Print Stack\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("-1. Exit\n");

		printf("Menu Select : ");
		scanf("%d", &input_data);
		if (input_data == -1) {
			printf("Basic Stack Process End...\n");
			free_list(&Stack);
			break;
		}
		switch (input_data) {
		// 스택 출력
		case 0:
			printf("Stack : ");
			print_list(Stack);
			break;

		// Stack's Process : Push -> Insert Front
		case 1:
			printf("Enter Data : ");
			scanf("%d", &input_data);
			insert_front(&Stack, input_data);
			printf("Stack : ");
			print_list(Stack);
			break;

		// Stack's Process : Pop -> Delete Front
		case 2:
			resulte = delete_front(&Stack);
			if (resulte == -1) { // Stack이 비어있는 경우
				printf("Lise is Empty...\n");
			}
			else { // 정상 작동 : 해당 노드의 data 출력
				printf("Deleted Node's Data : %d\n", resulte);
			}
			printf("Stack : ");
			print_list(Stack);
			break;
		// 잘못된 값 입력
		default:
			getchar();
			printf("Enterd Worng Value!!!\n\n");
			break;
		}
	}
	
	printf("------------------------------------------------------\n");
	printf("------------------------------------------------------\n");

	// Queue의 기본연산
	for (;;) {
		printf("Queue's Basic Process\n");
		printf("0. Print Queue\n");
		printf("1. Add\n");
		printf("2. Delete\n");
		printf("-1. Exit\n");

		printf("Menu Select : ");
		scanf("%d", &input_data);
		if (input_data == -1) {
			printf("Basic Queue Process End...\n");
			free_list(&Queue);
			break;
		}
		switch (input_data) {
		// 큐 출력
		case 0:
			printf("Queue : ");
			print_list(Queue);
			break;

		// Queue's Process : Add -> Insert Last
		case 1:
			printf("Enter Data : ");
			scanf("%d", &input_data);
			insert_last(&Queue, input_data);
			printf("Queue : ");
			print_list(Queue);
			break;

		// Queue's Process : Delete -> Delete Front
		case 2:
			resulte = delete_front(&Queue);
			if (resulte == -1) { // Queue이 비어있는 경우
				printf("Lise is Empty...\n");
			}
			else { // 정상 작동 : 해당 노드의 data 출력
				printf("Deleted Node's Data : %d\n", resulte);
			}
			printf("Queue : ");
			print_list(Queue);
			break;
			// 잘못된 값 입력
		default:
			getchar();
			printf("Enterd Worng Value!!!\n\n");
			break;
		}
	}

	printf("------------------------------------------------------\n");
	printf("------------------------------------------------------\n");


	return 0;

}

// 모든 리스트의 내용을 출력
void print_list(Node* Head) {
	printf("[ Head ] -> ");
	for (Node* temp = Head->next; temp != NULL; temp = temp->next) {
		printf("[ %d ] -> ", temp->data);
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
	Node* ptr, *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	for (ptr = *Head; ptr->next != NULL; ptr = ptr->next){}
	ptr->next = temp;
}

// 멘 앞의 노드를 삭제하고 그 값을 리턴
int delete_front(Node** Head) {
	// List가 이미 비어있는 경우 : -1 return
	if ((* Head)->next == NULL) {
		return -1;
	}
	Node* temp = (*Head)->next;
	int resulte = temp->data;
	(*Head)->next = temp->next;
	free(temp);
	return resulte;
}

// 값을 입력받아 해당하는 노드를 삭제 후 노드의 번호를 리턴
int delete(Node** Head, int data) {
	// List가 이미 비어있는 경우 : -1 return
	if ((*Head)->next == NULL) {
		return -1;
	}
	Node* ptr = (*Head)->next;
	Node* temp = (*Head);
	for (int Node_num = 1; ptr != NULL; ptr = ptr->next, Node_num++) {
		if (ptr->data == data) {
			temp->next = ptr->next;
			free(ptr);
			return Node_num; // 노드의 번호 리턴
		}
		temp = ptr;
	}
	// List에 입력받은 데이터가 없는 경우 : return -2
	return -2;
}

// 값을 입력받아 해당하는 노드의 번호를 리턴
int search(Node* Head, int data) {
	Node* ptr = Head->next;
	for (int Node_num = 1; ptr != NULL; ptr = ptr->next, Node_num++) {
		if (ptr->data == data) {
			return Node_num; // 노드의 번호 리턴
		}
	}
	// List에 입력받은 데이터가 없는 경우 : return -1
	return -1;
}

// List의 동적 할당 해제
void free_list(Node** Head) {
	Node* temp, *ptr;
	for (ptr = *Head; ptr != NULL; ptr = temp) {
		temp = ptr->next;
		free(ptr);
	}
}