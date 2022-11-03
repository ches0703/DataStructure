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
Node* invert(Node** lead);
Node* getSortingNode();
Node* merge(Node** A, Node** B);

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

	// Invert_List
	Node* Before_Invert_List = (Node*)malloc(sizeof(Node));
	Before_Invert_List->next = NULL;

	Node* After_Invert_List;

	// Merge
	Node* A, * B, * AB;

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
				printf("List is Empty...\n");
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
				printf("List is Empty...\n");
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
				printf("List is Empty...\n");
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
				printf("List is Empty...\n");
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

	// Invert
	printf("Invert Process\n");
	for (;;) {
		printf("Enter List Data ( -1 is End ) : ");
		scanf("%d", &input_data);
		if (input_data == -1) {
			printf("Before invert list : ");
			print_list(Before_Invert_List);
			After_Invert_List = invert(&Before_Invert_List);
			printf("After invert list : ");
			print_list(After_Invert_List);
			free_list(&After_Invert_List);
			free_list(&Before_Invert_List);
			break;
		}
		insert_last(&Before_Invert_List, input_data);
		print_list(Before_Invert_List);
	}

	printf("------------------------------------------------------\n");
	printf("------------------------------------------------------\n");

	// Merge

	// List A �Է�
	printf("Enter List A : \n");
	A = getSortingNode();
	printf("List A : ");
	print_list(A);
	printf("------------------------------------------------------\n");
	// List B �Է�
	printf("Enter List B : \n");
	B = getSortingNode();
	printf("List B : ");
	print_list(B);
	printf("------------------------------------------------------\n");
	// merge ����
	AB = merge(&A, &B);
	printf("List A + B ( Merge(A, B) ) : \n");
	print_list(AB);

	free(A); // A�� �ص������� �����Ҵ� ����
	free(B); // B�� �ص������� �����Ҵ� ����
	free_list(&AB); // ����Ʈ AB �����Ҵ� ����

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

// List Invert Process
Node* invert(Node **Head){
	//  lead�� ����Ű�� ����Ʈ�� ������ �ݴ�� ����/
	Node* lead = (*Head)->next;
	Node* middle, * trail;
	middle = NULL;
	while (lead) {
		trail = middle;
		middle = lead;
		lead = lead->next;
		middle->next = trail;
	}
	(*Head)->next = NULL; // ���� �ص����� link�� NULL�� ����
	Node* return_Head = (Node*)malloc(sizeof(Node)); // ����ִ� ��� ��� �߰�
	return_Head->next = middle;
	return return_Head;
}

// ����� �����͸� �Է¹޾� �����Ͽ� ��ȯ�ϴ� �Լ� 
Node* getSortingNode() {
	int input_data;
	Node* Head = (Node*)malloc(sizeof(Node));
	Head->next = NULL;
	Node* ptr, *temp;
	for (;;) {
		printf("Enter List Data ( -1 is End ) : ");
		scanf("%d", &input_data);
		if (input_data == -1) {
			return Head;
		}
		temp = Head;
		for (ptr = Head->next; ptr != NULL; ptr = ptr->next) {
			if (ptr->data > input_data) {
				break;
			}
			temp = ptr;
		}
		if (ptr == NULL) { // �Է� ���� �����Ͱ� ����Ʈ�� �����͵� ���� ū ���
			insert_last(&Head, input_data);
		}
		else { // �Է¹��� �����Ͱ� Ư����庸�� ���� ���
			insert_front(&temp, input_data); // Ư�� ����� �տ� ��� ����
		}
		print_list(Head);
	}
}

// ��带 �����Ͽ� ����
Node* merge(Node** A, Node** B) {
	Node* Head = (Node*)malloc(sizeof(Node));
	Head->next = NULL;
	Node* Hptr, *temp;
	Node* Aptr = (*A)->next;
	Node* Bptr = (*B)->next;
	int i = 0;
	for (; (Aptr != NULL) && (Bptr != NULL);) {
		if (Aptr->data < Bptr->data) {
			for (Hptr = Head; Hptr->next != NULL; Hptr = Hptr->next) {}
			temp = Hptr->next = Aptr;
			Aptr = Aptr->next;
		}
		else {
			for (Hptr = Head; Hptr->next != NULL; Hptr = Hptr->next) {}
			temp = Hptr->next = Bptr;
			Bptr = Bptr->next;
		}
		temp->next = NULL;
	}
	for (; Aptr != NULL;) {
		for (Hptr = Head; Hptr->next != NULL; Hptr = Hptr->next) {}
		temp = Hptr->next = Aptr;
		Aptr = Aptr->next;
		temp->next = NULL;
	}
	for (; Bptr != NULL;) {
		for (Hptr = Head; Hptr->next != NULL; Hptr = Hptr->next) {}
		temp = Hptr->next = Bptr;
		Bptr = Bptr->next;
		temp->next = NULL;
	}
	return Head;
}