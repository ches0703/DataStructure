#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
	int key;
	double value;
	struct Node* lchild, * rchild;
}Node;


void inorderPrint(Node* root);				// ���� Ž�� Ʈ�� ���
Node* modified_search(Node* tree, int key);	// Ư��Ű�� ���� ��� ��ȯ
void insert(Node** root, int key);			// Ʈ���� ��� ����
void search(Node* root, int key);			// Ʈ���� Ư�� Ű �� �˼�
Node* make_bst(int n);						// n���� ������ Ű�� ������ ���� Ž�� Ʈ�� ����
int count_node(Node* root);					// ����� �� ���� : ��� �Լ�, postoder ��
int count_depth(Node* root);				// Ʈ���� ���� ���� : ���, postoder 
int count_leaf(Node* root);

// ��� �����Ҵ� ���� �Լ�
Node* Avail = NULL;							// ���� ��� ����Ʈ
Node* getNode();							// ��� �Ҵ�
void retTreeNode(Node** root);				// ��� ��ȯ
void freeAvail();							// ���� ��� ���� �Ҵ� ����

int main()
{
	srand((unsigned)time(NULL));
	clock_t start, stop;
	double duration;
	int find_key, n;
	Node* A = NULL;
	Node* n_tree;
	
	// 9.1. 12���� (key, value)���� �����Ͽ� ���� Ž�� Ʈ�� ����
	printf("9.1. 12���� (key, value)���� �����Ͽ� ���� Ž�� Ʈ�� ����\n");
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
	printf("���� �Ϸ�.\n");
	printf("Print A(inorder) : \n");
	inorderPrint(A);
	printf("Num of A's node : %d\n", count_node(A));
	printf("A's depth : %d\n", count_depth(A));
	printf("Num of A's leaf node: %d\n", count_leaf(A));

	// 9.2. ������ ���� �˻� Ʈ������ key���� Ȱ���� �˻�
	printf("9.2. ������ ���� �˻� Ʈ������ key���� Ȱ���� �˻�\n");
	for (;;) {
		printf("Enter key to find : ");
		scanf("%d", &find_key);
		if (find_key == -1) { break; }
		search(A, find_key);
	}
	retTreeNode(&A);

	// 9.3. n���� ��带 ���� ����Ʈ�� �����ð� �� ��� ��, ����(����), �ܸ� ��� �� ����
	printf("9.3. n���� ��带 ���� ����Ʈ�� �����ð� �� ��� ��, ����(����), �ܸ� ��� �� ����\n");
	for (;;) {
		printf("Enter size for make tree : ");
		scanf("%d", &n);
		if (n == -1) { break; }
		start = clock();
		n_tree = make_bst(n);
		stop = clock();
		duration = (double)(stop - start);
		inorderPrint(n_tree);
		printf("duration = %.3f\n", duration / 1000);		// ��� �ð� ���
		printf("count node = %d\n", count_node(n_tree));	// ����� �� ���
		printf("depth node = %d\n", count_depth(n_tree));	// Ʈ���� ���� ���
		printf("leaf node = %d\n\n", count_leaf(n_tree));	// leaf����� �� ���
		retTreeNode(&n_tree);								// Ʈ���� ��带 Avail�� ��ȯ
	}

	freeAvail();
}

// Ʈ���� inoder������ ���
void inorderPrint(Node* root) {
	if (root) {
		inorderPrint(root->lchild);
		printf("(%4d, %4.4f)\n", root->key, root->value);
		inorderPrint(root->rchild);
	}
}

// key�� ���� ����� value ���
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

// �ش�Ű�� ���� ��带 ��ȯ, Ʈ���� key�� ���� ��� ���� �� NULL ����
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

// modified_search�� ���� key�� ���� ��带 Ʈ���� ����
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

// insert�� ���� ������ ���� key�� ������ Ʈ�� ����
Node* make_bst(int n) {
	Node* root = NULL;
	for (int i = 0; i < n; i++) {
		insert(&root, (rand() / (0x7fff * 1.0)) * 100000000);
	}
	return root;
}

// ����� �� ����
int count_node(Node* root) {
	int count = 0;
	if (root) {
		count += 1;							// �ڽ��� ��� ����
		count += count_node(root->lchild);	// + ���� �������� ���� 
		count += count_node(root->rchild);	// + ������ �������� ���� 
	}
	return count;
}

// Ʈ���� ���� ����
int count_depth(Node* root) {
	int count = 0;
	if (root) {
		count += 1;	// �ڽ��� ���� �߰�		
		int left_depth = count_depth(root->lchild);	// ���� ���� Ʈ���� ���� ���
		int right_depth = count_depth(root->rchild);// ������ ���� Ʈ���� ���� ���
		
		// �� ����Ʈ�� �� ���� ���̸� ī����� �ջ�
		if (left_depth > right_depth) { count += left_depth; }
		else { count += right_depth; }
	}
	return count;
}

// leaf����� �� ����
int count_leaf(Node* root) {
	int count = 0;
	if (!root) { return 0; }
	// lchild �� rchild�� NULL�̸� leaf node
	else if (!(root->lchild) && !(root->rchild)) { count = 1; }
	else {
		count += count_leaf(root->lchild);	// ���� ���� Ʈ���� leaf����� �� ���
		count += count_leaf(root->rchild);	// ������ ���� Ʈ���� leaf����� �� ���
	}
	return count;
}

// ��� ����
Node* getNode() {
	Node* new_node;
	if (Avail) { // Avail�� ���������� ��尡 �ִ°�� : Avail�� ó�� ��带 ��ȯ
		new_node = Avail;
		Avail = Avail->lchild;
	}
	// Avail�� ����ִ� ��� : �����Ҵ�
	else { new_node = (Node*)malloc(sizeof(Node)); }
	return new_node;
}

// Ʈ���� ��� ��ȯ : Postorder�� ���� ��ȯ, Avail�� ���ʿ� ���� 
void retTreeNode(Node** root) {
	if (*root) {
		retTreeNode(&((*root)->lchild));
		retTreeNode(&((*root)->rchild));
		(*root)->lchild = Avail;
		Avail = (*root);
	}
}

// Avile�� �����Ҵ� ����
void freeAvail() {
	Node* ptr;
	for (ptr = Avail; ptr != NULL; ptr = Avail) {
		Avail = Avail->lchild;
		free(ptr);
	}
}