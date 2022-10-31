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
		printf("List�� �⺻ ����\n");
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

// ��� ����Ʈ�� ������ ���
void print_list(Node* Head) {
	Node* temp = Head->next;
	printf("[ Head ] -> ");
	while (temp != NULL) {
		printf("[ %d ] -> ", temp->data);
		temp = temp->next;
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
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	
	Node* ptr = (* Head)->next;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = temp;
	
}

// �� ���� ��带 �����ϰ� �� ���� ����
int delete_front(Node** Head) {
	// List�� �̹� ����ִ� ��� : -1 return
	if (*Head == NULL) {
		return -1;
	}
	Node* temp = *Head;
	int resulte = temp->data;
	*Head = temp->next;
	free(temp);
	return resulte;
}

// ���� �Է¹޾� �ش��ϴ� ��带 ���� �� ����� ��ȣ�� ����
int delete(Node** Head, int data) {
	// List�� �̹� ����ִ� ��� : -1 return
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
			return Node_num; // ����� ��ȣ ����
		}
		temp = ptr;
		ptr = ptr->next;
		Node_num++;
	}
	// List�� �Է¹��� �����Ͱ� ���� ��� : return -2
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