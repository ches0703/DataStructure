#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
	int data;
	struct Node* lchild, * rchild;
}Node;
Node* make_tree_by_code();
Node* make_tree_by_rand(int max_n);
Node* copy(Node* ptr);
int equal(Node* A, Node* B);
Node* swap(Node* ptr);

void inorder(Node* ptr);
void preorder(Node* ptr);\
void postorder(Node* ptr);

int main()
{
	srand((unsigned)time(NULL));

	// 8.1.1. 트리 구성 (A = make_tree_by_code())
	Node* A = make_tree_by_code();
	printf("8.1.1. 트리 구성 (A = make_tree_by_code())\n");
	// 8.1.2. 트리 순회 (A)
	printf("8.1.2. 트리 순회 (A)\n");
	printf("Inorder : ");
	inorder(A);
	printf("\n");
	printf("Preorder : ");
	preorder(A);
	printf("\n");
	printf("Postorder : ");
	postorder(A);
	printf("\n\n");

	// 8.2.1. 트리 복사 (B = copy(A))
	printf("8.2.1. 트리 복사 (B = copy(A))\n");
	Node* B = copy(A);
	// 8.2.2. 트리 순회 (B)
	printf("8.2.1.트리 복사(B = copy(A))\n");
	printf("Inorder : ");
	inorder(B);
	printf("\n");
	printf("Preorder : ");
	preorder(B);
	printf("\n");
	printf("Postorder : ");
	postorder(B);
	printf("\n\n");

	// 8.2.3. 트리 동질성 검사 (equal(A,B))
	printf("8.2.3. 트리 동질성 검사 (equal(A,B))\n");
	printf("equal(A, B) : ");
	if (equal(A, B)) {
		printf("True\n");
	}
	else {
		printf("False\n");
	}
	printf("\n");

	// 8.2.4. 트리 swap (C = swap(A))
	printf("8.2.4. 트리 swap (C = swap(A))\n");
	Node* C = swap(A);
	// 8.2.5. 트리 순회 (C)
	printf("8.2.5. 트리 순회 (C)\n");
	printf("Inorder : ");
	inorder(C);
	printf("\n");
	printf("Preorder : ");
	preorder(C);
	printf("\n");
	printf("Postorder : ");
	postorder(C);
	printf("\n\n");

	

	// 8.3.1. 랜덤 트리 자동 생성 (D)
	int n;
	printf("Input n : ");
	scanf("%d", &n);
	Node* D = make_tree_by_rand(n);
	printf("D = make_tree_by_rand(9) : \n");
	// 8.3.2. 트리 순회 (D)
	printf("Inorder : ");
	inorder(D);
	printf("\n");
	printf("Preorder : ");
	preorder(D);
	printf("\n");
	printf("Postorder : ");
	postorder(D);
	printf("\n\n");

	return 0;

}

Node* make_tree_by_code() {
	Node* root = (Node*)malloc(sizeof(Node));
	Node* temp;
	root->data = 5;

	temp = (Node*)malloc(sizeof(Node));
	temp->data = 3;
	root->lchild = temp;

	temp = (Node*)malloc(sizeof(Node));
	temp->data = 1;
	temp->lchild = NULL;
	temp->rchild = NULL;
	(root->lchild)->lchild = temp;

	temp = (Node*)malloc(sizeof(Node));
	temp->data = 4;
	temp->lchild = NULL;
	temp->rchild = NULL;
	(root->lchild)->rchild = temp;

	temp = (Node*)malloc(sizeof(Node));
	temp->data = 8;
	temp->lchild = NULL;
	temp->rchild = NULL;
	root->rchild = temp;

	return root;
}

Node* make_tree_by_rand(int max_n) {
	int n = 0;
	Node * root = (Node*)malloc(sizeof(Node));
	root->data = n++;
	root->lchild = NULL;
	root->rchild = NULL;

	for (Node* ptr; n < max_n; n++) {
		ptr = root;
		for (; ptr ;) {
			int rand_value = rand() % 2;
			if (rand_value == 0) {
				if (ptr->lchild == NULL) {
					ptr = ptr->lchild = (Node*)malloc(sizeof(Node));
					ptr->data = n;
					ptr->lchild = NULL;
					ptr->rchild = NULL;
				}
				ptr = ptr->lchild;
			}
			else{
				if (ptr->rchild == NULL) {
					ptr = ptr->rchild = (Node*)malloc(sizeof(Node));
					ptr->data = n;
					ptr->lchild = NULL;
					ptr->rchild = NULL;
				}
				ptr = ptr->rchild;
			}
		}
	}
	return root;
}

Node* copy(Node* ptr) {
	if (ptr) {
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->data = ptr->data;
		temp->lchild = copy(ptr->lchild);
		temp->rchild = copy(ptr->rchild);
		return temp;
	}
	return NULL;
}



int equal(Node* A, Node* B) {
	if (A == NULL, B == NULL) {
		return 1;
	}
	else if ((A->data == B->data) && equal(A->lchild, B->lchild) && equal(A->rchild, B->rchild)) {
		return 1;
	}
	else {
		return 0;
	}
}

Node* swap(Node* ptr) {
	if (ptr) {
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->data = ptr->data;
		temp->rchild = copy(ptr->lchild);
		temp->lchild = copy(ptr->rchild);
		return temp;
	}
	return NULL;
}


// Travel

void inorder(Node* ptr) {
	if (ptr) {
		inorder(ptr->lchild);
		printf("%d ", ptr->data);
		inorder(ptr->rchild);
	}
}

void preorder(Node* ptr) {
	if (ptr) {
		printf("%d ", ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

void postorder(Node* ptr) {
	if (ptr) {
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d ", ptr->data);
	}
}