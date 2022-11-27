#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
	int key;
	double value;
	struct Node* lchild, * rchild;
}Node;


void inorderPrint(Node* root);				// 이진 탐색 트리 출력
Node* modified_search(Node* tree, int key);	// 특정키의 이전 노드 반환
void insert(Node** root, int key);			// 트리에 노드 삽입
void search(Node* root, int key);			// 트리에 특정 키 값 검섹
Node* make_bst(int n);						// n개의 랜텀한 키를 가지는 이진 탐색 트리 생성
int count_node(Node* root);					// 노드의 수 측정 : 재귀 함수, postoder 순
int count_depth(Node* root);				// 트리의 깊이 측정 : 재귀, postoder 
int count_leaf(Node* root);

// 노드 동적할당 관련 함수
Node* Avail = NULL;							// 공동 노드 리스트
Node* getNode();							// 노드 할당
void retTreeNode(Node** root);				// 노드 반환
void freeAvail();							// 공동 노드 동적 할당 해제

int main()
{
	srand((unsigned)time(NULL));
	clock_t start, stop;
	double duration;
	int find_key, n;
	Node* A = NULL;
	Node* n_tree;
	
	// 9.1. 12개의 (key, value)쌍을 생성하여 이진 탐색 트리 생성
	printf("9.1. 12개의 (key, value)쌍을 생성하여 이진 탐색 트리 생성\n");
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
	printf("생성 완료.\n");
	printf("Print A(inorder) : \n");
	inorderPrint(A);
	printf("Num of A's node : %d\n", count_node(A));
	printf("A's depth : %d\n", count_depth(A));
	printf("Num of A's leaf node: %d\n", count_leaf(A));

	// 9.2. 생성된 이진 검색 트리에서 key값을 활용한 검색
	printf("9.2. 생성된 이진 검색 트리에서 key값을 활용한 검색\n");
	for (;;) {
		printf("Enter key to find : ");
		scanf("%d", &find_key);
		if (find_key == -1) { break; }
		search(A, find_key);
	}
	retTreeNode(&A);

	// 9.3. n개의 노드를 가진 이진트리 생성시간 및 노드 수, 높이(깊이), 단말 노드 수 관찰
	printf("9.3. n개의 노드를 가진 이진트리 생성시간 및 노드 수, 높이(깊이), 단말 노드 수 관찰\n");
	for (;;) {
		printf("Enter size for make tree : ");
		scanf("%d", &n);
		if (n == -1) { break; }
		start = clock();
		n_tree = make_bst(n);
		stop = clock();
		duration = (double)(stop - start);
		inorderPrint(n_tree);
		printf("duration = %.3f\n", duration / 1000);		// 경과 시간 출력
		printf("count node = %d\n", count_node(n_tree));	// 노드의 수 출력
		printf("depth node = %d\n", count_depth(n_tree));	// 트리의 깊이 출력
		printf("leaf node = %d\n\n", count_leaf(n_tree));	// leaf노드의 수 출력
		retTreeNode(&n_tree);								// 트리의 노드를 Avail에 반환
	}

	freeAvail();
}

// 트리를 inoder순으로 출력
void inorderPrint(Node* root) {
	if (root) {
		inorderPrint(root->lchild);
		printf("(%4d, %4.4f)\n", root->key, root->value);
		inorderPrint(root->rchild);
	}
}

// key에 대한 노드의 value 출력
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

// 해당키의 이전 노드를 반환, 트리에 key에 대한 노드 존재 시 NULL 리턴
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

// modified_search를 통해 key에 대한 노드를 트리에 삽입
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

// insert를 통한 랜덤한 값을 key로 가지는 트리 생성
Node* make_bst(int n) {
	Node* root = NULL;
	for (int i = 0; i < n; i++) {
		insert(&root, (rand() / (0x7fff * 1.0)) * 100000000);
	}
	return root;
}

// 노드의 수 측정
int count_node(Node* root) {
	int count = 0;
	if (root) {
		count += 1;							// 자신의 노드 포함
		count += count_node(root->lchild);	// + 왼족 서브노드의 갯수 
		count += count_node(root->rchild);	// + 오른족 서브노드의 갯수 
	}
	return count;
}

// 트리의 깊이 측정
int count_depth(Node* root) {
	int count = 0;
	if (root) {
		count += 1;	// 자신의 높이 추가		
		int left_depth = count_depth(root->lchild);	// 왼쪽 서브 트리의 높이 계산
		int right_depth = count_depth(root->rchild);// 오른족 서브 트리의 높이 계산
		
		// 두 서브트리 중 높은 깊이를 카운더에 합산
		if (left_depth > right_depth) { count += left_depth; }
		else { count += right_depth; }
	}
	return count;
}

// leaf노드의 수 측정
int count_leaf(Node* root) {
	int count = 0;
	if (!root) { return 0; }
	// lchild 와 rchild가 NULL이면 leaf node
	else if (!(root->lchild) && !(root->rchild)) { count = 1; }
	else {
		count += count_leaf(root->lchild);	// 왼쪽 서브 트리의 leaf노드의 수 계산
		count += count_leaf(root->rchild);	// 오른족 서브 트리의 leaf노드의 수 계산
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
void retTreeNode(Node** root) {
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