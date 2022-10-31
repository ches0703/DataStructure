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
	Node* List = (Node*)malloc(sizeof(Node)); // List's Num�� 0
	List->next = NULL;
	
	// Stack
	Node* Stack = (Node*)malloc(sizeof(Node));
	Stack->next = NULL;

	// Queue
	Node* Queue = (Node*)malloc(sizeof(Node));
	Queue->next = NULL;

	int resulte;
	int input_data;

	// �⺻ ����Ʈ ����
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
		// ����Ʈ ���
		case 0 : 
			printf("List : ");
			print_list(List);
			break;

		// ����Ʈ �Է� : Front
		case 1 : 
			printf("Enter Data : ");
			scanf("%d", &input_data);
			insert_front(&List, input_data);
			printf("List : ");
			print_list(List);
			break;

		// ����Ʈ �Է� : Last
		case 2 : 
			printf("Enter Data : ");
			scanf("%d", &input_data);
			insert_last(&List, input_data);
			printf("List : ");
			print_list(List);
			break;

		// ��� ���� : Front
		case 3 : 
			resulte = delete_front(&List);
			if (resulte == -1) { // ����Ʈ�� ����ִ� ���
				printf("Lise is Empty...\n");
			}
			else { // ���� �۵� : �ش� ����� data ���
				printf("Deleted Node's Data : %d\n", resulte);
			}
			printf("List : ");
			print_list(List);
			break;

		// ��� ���� : Data�� ���� ����
		case 4 : 
			printf("Enter Delete Data : ");
			scanf("%d", &input_data);
			resulte = delete(&List, input_data);
			if (resulte == -1) { // ����Ʈ�� ����ִ� ���
				printf("Lise is Empty...\n");
			}
			else if (resulte == -2) { // �Է� ���� �����Ϳ� ���� �ش��ϴ� ��尡 ���� ���
				printf("Not Found Node...\n");
			}
			else { // ���� �۵� : �ش� ����� ��ȣ ���
				printf("Deleted Node's Num : %d\n", resulte);
			}
			printf("List : ");
			print_list(List);
			break;

		// ��� �˼� 
		case 5 : 
			printf("Enter Search Data : ");
			scanf("%d", &input_data);
			resulte = search(List, input_data);
			if (resulte == -1) { // �Է� ���� �����Ϳ� ���� �ش��ϴ� ��尡 ���� ���
				printf("Not Found Node...\n");
			}
			else { // ���� �۵� : �ش� ����� ��ȣ ���
				printf("Searched Node's Num : %d\n", resulte);
			}
			printf("List : ");
			print_list(List);
			break;

		// �߸��� �� �Է�
		default:
			getchar();
			printf("Enterd Worng Value!!!\n\n");
			break;
		}
	}
	
	printf("------------------------------------------------------\n");
	printf("------------------------------------------------------\n");

	// Stack�� �⺻����
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
		// ���� ���
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
			if (resulte == -1) { // Stack�� ����ִ� ���
				printf("Lise is Empty...\n");
			}
			else { // ���� �۵� : �ش� ����� data ���
				printf("Deleted Node's Data : %d\n", resulte);
			}
			printf("Stack : ");
			print_list(Stack);
			break;
		// �߸��� �� �Է�
		default:
			getchar();
			printf("Enterd Worng Value!!!\n\n");
			break;
		}
	}
	
	printf("------------------------------------------------------\n");
	printf("------------------------------------------------------\n");

	// Queue�� �⺻����
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
		// ť ���
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
			if (resulte == -1) { // Queue�� ����ִ� ���
				printf("Lise is Empty...\n");
			}
			else { // ���� �۵� : �ش� ����� data ���
				printf("Deleted Node's Data : %d\n", resulte);
			}
			printf("Queue : ");
			print_list(Queue);
			break;
			// �߸��� �� �Է�
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

// ��� ����Ʈ�� ������ ���
void print_list(Node* Head) {
	printf("[ Head ] -> ");
	for (Node* temp = Head->next; temp != NULL; temp = temp->next) {
		printf("[ %d ] -> ", temp->data);
	}
	printf("[ NULL ]\n\n");
}

// List�� �տ� �Է¹��� �����͸� �߰�
void insert_front(Node** Head, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = (* Head)->next;
	(*Head)->next = temp;
}

// List�� �������� �Է¹��� �����͸� �߰�
void insert_last(Node** Head, int data) {
	Node* ptr, *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	for (ptr = *Head; ptr->next != NULL; ptr = ptr->next){}
	ptr->next = temp;
}

// �� ���� ��带 �����ϰ� �� ���� ����
int delete_front(Node** Head) {
	// List�� �̹� ����ִ� ��� : -1 return
	if ((* Head)->next == NULL) {
		return -1;
	}
	Node* temp = (*Head)->next;
	int resulte = temp->data;
	(*Head)->next = temp->next;
	free(temp);
	return resulte;
}

// ���� �Է¹޾� �ش��ϴ� ��带 ���� �� ����� ��ȣ�� ����
int delete(Node** Head, int data) {
	// List�� �̹� ����ִ� ��� : -1 return
	if ((*Head)->next == NULL) {
		return -1;
	}
	Node* ptr = (*Head)->next;
	Node* temp = (*Head);
	for (int Node_num = 1; ptr != NULL; ptr = ptr->next, Node_num++) {
		if (ptr->data == data) {
			temp->next = ptr->next;
			free(ptr);
			return Node_num; // ����� ��ȣ ����
		}
		temp = ptr;
	}
	// List�� �Է¹��� �����Ͱ� ���� ��� : return -2
	return -2;
}

// ���� �Է¹޾� �ش��ϴ� ����� ��ȣ�� ����
int search(Node* Head, int data) {
	Node* ptr = Head->next;
	for (int Node_num = 1; ptr != NULL; ptr = ptr->next, Node_num++) {
		if (ptr->data == data) {
			return Node_num; // ����� ��ȣ ����
		}
	}
	// List�� �Է¹��� �����Ͱ� ���� ��� : return -1
	return -1;
}

// List�� ���� �Ҵ� ����
void free_list(Node** Head) {
	Node* temp, *ptr;
	for (ptr = *Head; ptr != NULL; ptr = temp) {
		temp = ptr->next;
		free(ptr);
	}
}