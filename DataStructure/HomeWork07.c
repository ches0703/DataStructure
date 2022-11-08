#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	float coef;
	int exp;
	struct PolyNode* next;
}PolyNode;

// 가용 노드 리스트
PolyNode* Avail = NULL;

PolyNode* getNode();
PolyNode* retNode(PolyNode** node);
void printList(PolyNode* node);

PolyNode* create_polynomial();
void attach(float coef, int exp, PolyNode** polynomial);

PolyNode* cpadd(PolyNode* A, PolyNode* B);

void cerase(PolyNode** List);
void freeAvail();

int checkCListNotEnd(PolyNode* node);

int main()
{
	PolyNode* A = create_polynomial();
	printList(A);
	PolyNode* B = create_polynomial();
	printList(B);
	PolyNode* A_B = cpadd(A, B);
	printList(A_B);


}

PolyNode* getNode() {
	PolyNode* node;
	if (Avail!=NULL) {
		node = Avail;
		Avail = Avail->next;
	}
	else {
		node = (PolyNode*)malloc(sizeof(PolyNode));
	}
	node->next = NULL;
	return node;
}

PolyNode* retNode(PolyNode** node) {
	(*node)->next = Avail;
	Avail = *node;
}

void printList(PolyNode* node) {
	PolyNode* ptr = node->next;
	for (;checkCListNotEnd(ptr);ptr = ptr->next) {
		printf("%f %d\n", ptr->coef, ptr->exp);
	}
}

PolyNode* create_polynomial() {
	PolyNode* polynomial = getNode();
	PolyNode* ptr;
	polynomial->coef = -1.0;
	polynomial->exp = -1;
	polynomial->next = NULL;
	float coef;
	int exp;
	for (;;) {
		printf("input(-1 -1 end) : ");
		scanf("%f %d", &coef, &exp);
		if ((coef < 0) && (exp == -1)) {
			printf("End enter");
			for (ptr = polynomial->next; ptr->next != NULL; ptr = ptr->next) {}
			ptr->next = polynomial;
			return polynomial;
		}
		attach(coef, exp, &polynomial);
	}

}

void attach(float coef, int exp, PolyNode** polynomial) {
	PolyNode* temp, * ptr, * insert_node;
	ptr = (*polynomial)->next;
	temp = ptr;
	if ((ptr==NULL) || (ptr->exp < exp)) {
		insert_node = getNode();
		insert_node->coef = coef;
		insert_node->exp = exp;
		insert_node->next = (*polynomial)->next;
		(*polynomial)->next = insert_node;
		return;
	}
	for (; ptr != NULL; ptr = ptr->next) {
		if (ptr->exp < exp) {
			insert_node = getNode();
			insert_node->coef = coef;
			insert_node->exp = exp;
			insert_node->next = ptr;
			temp->next = insert_node;
			return;
		}
		temp = ptr;
	}
	insert_node = getNode();
	insert_node->coef = coef;
	insert_node->exp = exp;
	insert_node->next = ptr;
	temp->next = insert_node;


}

PolyNode* cpadd(PolyNode* A, PolyNode * B) {
	A = A->next;
	B = B->next;
	PolyNode* resulte = getNode();
	PolyNode* ptr;
	resulte->coef = -1.0;
	resulte->exp = -1;
	for (; (checkCListNotEnd(A)) && (checkCListNotEnd(B));) {
		if (A->exp > B->exp) {
			attach(A->coef, A->exp, &resulte);
			A = A->next;
		}
		else if ((A->exp < B->exp)){
			attach(B->coef, B->exp, &resulte);
			B = B->next;
		}
		else{
			attach(A->coef + B->coef, A->exp, &resulte);
			A = A->next;
			B = B->next;
		}
	}
	for (; checkCListNotEnd(A); A = A->next) {
		attach(A->coef, A->exp, &resulte);
	}
	for (; checkCListNotEnd(B); B = B->next) {
		attach(B->coef, B->exp, &resulte);
	}
	for (ptr = resulte->next; ptr->next != NULL; ptr = ptr->next) {}
	ptr->next = resulte;
	return resulte;
}

void cerase(PolyNode** List) {
	for (PolyNode* temp = (* List)->next; checkCListNotEnd(temp); temp = *List) {
		*List = (*List)->next;
		free(temp);
	}
	free(*List);
}

void freeAvail() {
	for (PolyNode* temp = Avail; temp != NULL; temp = Avail) {
		Avail = Avail->next;
		free(temp);
	}
}

int checkCListNotEnd(PolyNode*node) {
	if ((node->coef < 0) && (node->exp == -1)) {
		return 0;
	}
	else {
		return 1;
	}
}