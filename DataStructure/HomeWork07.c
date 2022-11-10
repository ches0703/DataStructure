#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	float coef;
	int exp;
	struct PolyNode* next;
}PolyNode;

PolyNode* Avail = NULL;				// ���� ��� ����Ʈ
PolyNode* getNode();				// ��� ����
PolyNode* retNode(PolyNode** node); // ��� ��ȯ
void freeAvail();					// Avail ���� �Ҵ� ����

void printList(PolyNode* node);		// ȯ�� polyNode ����Ʈ ���
PolyNode* create_polynomial();		// ȯ�� polyNode ����Ʈ ����
void cerease(PolyNode** head);		// ����Ʈ�� node�� retNode�� ���� Avail�� ��ȯ
void attach(float coef, int exp, PolyNode** head);	// polyNode list�� ������������ polyNode �߰�
PolyNode* cpadd(PolyNode* A, PolyNode* B);	// polyNode ����Ʈ���� �� ����
PolyNode* cpmul(PolyNode* A, PolyNode* B);	// cpadd�� �̿��� polyNode ����Ʈ���� �� ����

int main()
{
	// 7.1 ���׽� ����
	printf("7.1 ���׽� ����\n");
	printf("\nEnter the A(x) : \n");
	PolyNode* A = create_polynomial();
	printList(A);


	printf("\nEnter the B(x) : \n");
	PolyNode* B = create_polynomial();
	printList(B);


	// 7.2 ���׽� ����
	printf("\n7.2 ���׽� ����\n");
	PolyNode* C = cpadd(A, B);
	printf("A(x) + B(x) = ");
	printList(C);


	// 7.3 ���׽� ����
	printf("\n7.3 ���׽� ����\n\n");
	PolyNode* D = cpmul(A, B);
	printf("A(x) * B(x) = ");
	printList(D);


	// ����Ʈ ��ȯ �� Avail ���� �Ҵ� ����
	cerease(&A);
	cerease(&B);
	cerease(&C);
	cerease(&D);
}

// ��� ����
PolyNode* getNode() {
	PolyNode* new_node;
	if (Avail != NULL) { // Avail�� ���������� ��尡 �ִ°��
		// Avail�� ó�� ��带 ��ȯ
		new_node = Avail;	 
		Avail = Avail->next;
	}
	else {
		// Avail�� ����ִ� ��� : �����Ҵ�
		new_node = (PolyNode*)malloc(sizeof(PolyNode));
	}
	new_node->next = NULL;
	return new_node;
}

// ��� ��ȯ : Avail�� ���ʿ� ���� 
PolyNode* retNode(PolyNode** node) {
	(*node)->next = Avail;
	Avail = *node;
}

// Avile�� �����Ҵ� ����
void freeAvail() {
	PolyNode* ptr;
	for (ptr = Avail; ptr != NULL; ptr = Avail) {
		Avail = Avail->next;
		free(ptr);
	}
}

// ȯ�� polyNode List ���
void printList(PolyNode* node) {
	for (PolyNode* ptr = node->next; ptr != node; ptr = ptr->next) {
		printf("%+.2fx^%d ", ptr->coef, ptr->exp);
	}
	printf("\n");
}


// ȯ�� polyNode ����Ʈ ����
PolyNode* create_polynomial() {
	// ���ο� ����Ʈ�� ��� ����
	PolyNode* new_list = getNode();
	new_list->coef = -1.0;
	new_list->exp = -1;
	new_list->next = new_list;
	float coef;
	int exp;
	for (;;) {
		printf("Enter polyNode Data(-1 -1 is end) : ");
		scanf("%f %d", &coef, &exp);
		if ((coef < 0) && (exp == -1)) {
			printf("End enter\n");
			return new_list;
		}
		attach(coef, exp, &new_list);
	}
}

// ����Ʈ�� node�� retNode�� ���� Avail�� ��ȯ
void cerease(PolyNode**head) {
	PolyNode* ptr = (*head)->next;
	PolyNode* temp;
	for (; ptr != *head;) {
		temp = ptr;
		ptr = ptr->next;
		retNode(&temp);
	}
	retNode(head);
}

// ȯ�� ����Ʈ�� �ŰԺ����� ���� ���� ������ ��带 ������������ �߰�
void attach(float coef, int exp, PolyNode** head) {
	PolyNode* prev_ptr = (*head);
	PolyNode* ptr = (*head)->next;
	PolyNode* new_node = getNode();	// list�� �� ���ο� ���
	new_node->coef = coef;
	new_node->exp = exp;
	// list�� ������������ �ֱ�
	for (; ptr != *head; prev_ptr = ptr, ptr = ptr->next) {
		if (ptr->exp == exp) {		// ������ ���� Node�� ����� : �տ���
			ptr->coef += coef;
			retNode(&new_node);		// ����� ���� ���� new_node ��ȯ�� �Լ� ����
			return;
		}
		else if (ptr->exp < exp) {	
			break;
		}
	}
	prev_ptr->next = new_node;
	new_node->next = ptr;
}

// ȯ�� PolyNode ����Ʈ���� �տ��� 
PolyNode* cpadd(PolyNode* A, PolyNode* B) {
	// �տ��� ����� ������ ���ο� ����Ʈ�� ��� ����
	PolyNode* resulte_list = getNode();
	resulte_list->coef = -1.0;
	resulte_list->exp = -1;
	resulte_list->next = resulte_list;
	// ���ο� ����Ʈ�� A, B�� ��� node�� �����͸� ����
	// ������ ���� ����� ��� attach���� �տ����� ����
	for (PolyNode* Aptr = A->next; Aptr != A; Aptr = Aptr->next) {
		attach(Aptr->coef, Aptr->exp, &resulte_list);
	}
	for (PolyNode* Bptr = B->next; Bptr != B; Bptr = Bptr->next) {
		attach(Bptr->coef, Bptr->exp, &resulte_list);
	}
	return resulte_list;
}

PolyNode* cpmul(PolyNode* A, PolyNode* B) {
	PolyNode* temp;	// �� ���� ��� ����Ʈ�� �ӽ������� ����ų ������
	// ������ ����� ������ ���ο� ����Ʈ�� ��� ����
	PolyNode* resulte_list = getNode();
	resulte_list->coef = -1.0;
	resulte_list->exp = -1;
	resulte_list->next = resulte_list;
	int C = 0;
	// ����Ʈ A�� ���� �ϳ��� ���� B ��ä�� ���� ���� mid_resulte_list�� 
	// ���� �� resulte_list �� �� ����
	for (PolyNode* Aptr = A->next; Aptr != A; Aptr = Aptr->next) {
		// �߰� ���� ������ mid_resulte ����Ʈ�� �ص� ����
		PolyNode* mid_resulte_list = getNode();
		mid_resulte_list->coef = -1.0;
		mid_resulte_list->exp = -1;
		mid_resulte_list->next = mid_resulte_list;
		for (PolyNode* Bptr = B->next; Bptr != B; Bptr = Bptr->next) {
			// �߰��ϴ� node�� �� ���� �� �߰�
			attach(Aptr->coef * Bptr->coef, Aptr->exp + Bptr->exp, &mid_resulte_list);
		}
		printf("single_mul : C%d(x) : ", ++C); 
		printList(mid_resulte_list);
		printf("\n");
		temp = cpadd(resulte_list, mid_resulte_list);	// �ӽ������� �տ��� ����� temp�� ����Ŵ
		cerease(&resulte_list);		// resulte �ʱ�ȭ
		cerease(&mid_resulte_list); // mid_resulte_list �ʱ�ȭ
		resulte_list = temp;		// �տ��� ����� resulte�� ����
	}
	return resulte_list;
}