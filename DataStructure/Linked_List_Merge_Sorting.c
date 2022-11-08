#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// ������ ����Ʈ�� ũ��
#define LIST_SIZE 20

// ����Ʈ�� ���
typedef struct {
	int data;
	struct Node* next;
}Node;

Node* GetList();					// ������ 20���� ���� ����Ʈ�� �����Ͽ� ��ȯ�ϴ� �Լ�
void PrintList(Node* head);			// ����Ʈ�� ����ϴ� �Լ�
void SortList(Node** head);			// ����Ʈ�� ������������ �����ϴ� �Լ�
Node* MergeList(Node** A, Node** B);// ����Ʈ 2���� ���� ���ο� ��带 ��ȯ�ϴ� �Լ�. ������带 ������
void DeleteList(Node** head);		// ����Ʈ�� �����Ҵ��� �����ϴ� �Լ�

int main()
{
	srand((unsigned)time(NULL));	// ���� �õ尪 ����
	Node* A, * B, * D;				// ����Ʈ ���� ����
	
	// A����Ʈ ����, ���� �� ���
	A = GetList();
	SortList(&A);
	printf("List A : \n");
	PrintList(A);
	printf("\n");

	// B����Ʈ ����, ���� �� ���
	B = GetList();
	SortList(&B);
	printf("List B : \n");
	PrintList(B);
	printf("\n");

	// A, B�� ��ģ D����Ʈ ���� �� ���
	D = MergeList(&A, &B);
	SortList(&D);
	printf("List D : \n");
	PrintList(D);
	printf("\n");

	// �� ����Ʈ �����Ҵ� ����
	DeleteList(&A);
	DeleteList(&B);
	DeleteList(&D);
	return 0;
}

// ������ 20���� ���� ����Ʈ�� �����Ͽ� ��ȯ�ϴ� �Լ�
// Head��带 ������ ����Ʈ�� ��ȯ��
Node* GetList() {
	// ���ο� ����Ʈ�� �ص� ����
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = -1;
	head->next = NULL;

	// ����Ʈ�� ������ �߰�
	Node* ptr = head;
	Node* temp;
	for (int i = 0; i < LIST_SIZE; i++) {
		temp = (Node*)malloc(sizeof(Node));
		temp->data = (rand() % 1000) + 1;
		temp->next = NULL;
		ptr->next = temp;
		ptr = ptr->next;
	}
	return head;
}

// Head��带 ������ ����Ʈ�� ����ϴ� �Լ�
void PrintList(Node* head) {
	printf("[Head]->");
	for (Node* ptr = head->next; ptr != NULL; ptr = ptr->next) {
		printf("[%4d]->", ptr->data);
	}
	printf("[NULL]\n");
}

// ����Ʈ�� ������������ �����ϴ� �Լ�
void SortList(Node** head) {
	Node* temp;
	Node* min_node, *B_min_node;// B_min_node = Before min node
	Node* ptr, * B_ptr;			// B_ptr = Before ptr
	Node* CS_node, * BCS_node;	// Compare Start Node, Before Compare Start Node

	for (BCS_node = *head, CS_node = (*head)->next; CS_node->next != NULL; BCS_node = CS_node, CS_node = CS_node->next) {
		// ���� �ݺ��� ���� �ʱ�ȭ
		B_min_node = BCS_node;
		min_node = CS_node;
		B_ptr = min_node;
		ptr = min_node->next;
		// �� �κ�
		for (; ptr != NULL; ptr = ptr->next) {
			if (min_node->data > ptr->data) {
				B_min_node = B_ptr;
				min_node = ptr;
			}
			B_ptr = ptr;

		}
		// Swap
		// before node's next�� Change
		temp = BCS_node->next;
		BCS_node->next = B_min_node->next;
		B_min_node->next = temp;
		// node's next�� Change
		temp = CS_node->next;
		CS_node->next = min_node->next;
		min_node->next = temp;
		
		// CS_node�� ��ġ�� �� ����
		CS_node = min_node;
	}
}

// ����Ʈ 2���� ���� ���ο� ��带 ��ȯ�ϴ� �Լ�. ������带 ������
Node* MergeList(Node** A, Node** B) {
	// ���ο� ����Ʈ�� �ص� ����
	Node* merge_list = (Node*)malloc(sizeof(Node));
	merge_list->data = -1;
	// ���ο� ����Ʈ�� A����Ʈ �߰�
	merge_list->next = (* A)->next;
	// ���ο� ����Ʈ�� ���� B����Ʈ �߰�
	Node* ptr;
	for(ptr = merge_list; ptr->next != NULL; ptr = ptr->next){}
	ptr->next = (*B)->next;
	// ���� ����� �ص带 �����ϰ� ����
	(*A)->next = NULL;
	(*B)->next = NULL;
	return merge_list;
}

// ����Ʈ�� �����Ҵ��� �����ϴ� �Լ�, �ص��带 �����Ͽ� ����
void DeleteList(Node** head) {
	Node* ptr, * temp;
	for (temp = *head, ptr = (*head)->next; ptr != NULL; ptr = ptr->next) {
		free(temp);
		temp = ptr;
	}
	free(temp);
}