#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
	int key;
	double value;
	struct Node* lchild, * rchild;
}Node;

Node* Avail = NULL;
Node* getNode();
Node* retTreeNode(Node** root);
void freeAvail();

Node* modified_search(Node* tree, int key);
void insert(Node** root, int key);
void search(Node* root, int key);
void inorder(Node* ptr);
Node* make_bst(int n);
int count_node(Node* ptr);

int main()
{
	srand((unsigned)time(NULL));
	clock_t start, stop;
	double duration;
	int find_key, n;
	Node* A = NULL;
	Node* n_tree;
	insert(&A, 10);
	insert(&A, 6);
	insert(&A, 15);
	insert(&A, 8);
	insert(&A, 18);
	insert(&A, 12);
	insert(&A, 3);
	insert(&A, 14);
	insert(&A, 9);
	insert(&A, 20);
	insert(&A, 5);
	insert(&A, 2);

	inorder(A);
	printf("\n");

	for (;;) {
		printf("Enter key to find : ");
		scanf("%d", &find_key);
		if (find_key == -1) { break; }
		search(A, find_key);
	}
	retTreeNode(&A);

	for (;;) {
		printf("Enter size for make tree : ");
		scanf("%d", &n);
		if (n == -1) { break; }
		start = clock();
		n_tree = make_bst(n);
		stop = clock();
		duration = (double)(stop - start);
		printf("duration = %.3f\n", duration / 1000);
		printf("count node = %d\n", count_node(n_tree));
		retTreeNode(&n_tree);
	}

	

	freeAvail();
}

void inorder(Node* ptr) {
	if (ptr) {
		inorder(ptr->lchild);
		printf("%d ", ptr->key);
		inorder(ptr->rchild);
	}
}

Node* modified_search(Node* root, int key) {
	for (;root;) {
		if (key == root->key) { return NULL; }
		if (key < root->key) {
			if (root->lchild) { root = root->lchild; }
			else { return root; }
		}
		else {
			if (root->rchild) { root = root->rchild; }
			else { return root; }
		}
	}
	return NULL;
}

void insert(Node** root, int key) {
	double value = 1. / key;
	Node* temp = modified_search(*root, key);
	Node* newNode;
	if (temp || !(*root)) {
		newNode = getNode();
		newNode->key = key;
		newNode->value = value;
		newNode->lchild = NULL;
		newNode->rchild = NULL;
		if (* root) {
			if (temp->key > key) { temp->lchild = newNode; }
			else { temp->rchild = newNode; }
		}
		else { (*root) = newNode; }
	}
}

void search(Node* root , int key) {
	int count = 1;
	for (; root; count++) {
		if (key == root->key) { 
			printf("Count : %d, Key : %d, Value : %f\n", count, key, root->value);
			return;
		}
		if (key < root->key) { root = root->lchild; }
		else { root = root->rchild; }
	}
	printf("Key : %d, Not fount... \n", key);
}

Node* make_bst(int n) {
	Node* root = NULL;
	for (int i = 0; i < n; i++) {
		insert(&root, (rand() / (0x7fff * 1.0)) * 100000000);
	}
	return root;
}

int count_node(Node* ptr) {
	int count = 0;
	if (ptr) {
		count += 1;
		count += count_node(ptr->lchild);
		count += count_node(ptr->rchild);
	}
	return count;
}



// 노드 배포
Node* getNode() {
	Node* new_node;
	if (Avail) { // Avail에 배포가능한 노드가 있는경우 : Avail의 처음 노드를 반환
		new_node = Avail;
		Avail = Avail->lchild;
	}
	// Avail이 비어있는 경우 : 동적할당
	else { new_node = (Node*)malloc(sizeof(Node)); }
	return new_node;
}

// 트리의 노드 반환 : Postorder를 통한 반환, Avail의 앞쪽에 삽입 
Node* retTreeNode(Node** root) {
	if (*root) {
		retTreeNode(&((*root)->lchild));
		retTreeNode(&((*root)->rchild));
		(*root)->lchild = Avail;
		Avail = (*root);
	}
}

// Avile의 동적할당 해제
void freeAvail() {
	Node* ptr;
	for (ptr = Avail; ptr != NULL; ptr = Avail) {
		Avail = Avail->lchild;
		free(ptr);
	}
}