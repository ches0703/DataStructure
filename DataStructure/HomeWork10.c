#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

int max_stack_size = 10;
int *stack;
int top = -1;
void push(int item) {
	if (top < max_stack_size - 1) {
		stack[++top] = item;
	}
	else {
		printf("Stack is full... Retouch Stack size!\n");
		max_stack_size *= 2;
		stack = (int**)realloc(stack, sizeof(int) * max_stack_size);
		stack[++top] = item;
	}
}
int pop() {
	if (top < 0) {
		printf("It is empty...\n");
		return -1;
	}
	return stack[top--];
}

void insertEdge(Node** head, int data);
void printList(Node** head, int size);
void higherDgree(Node** graph, int n);

void DFS(Node** graph, int n, int start);

int main()
{
	stack = (int*)calloc(max_stack_size, sizeof(int));
	int n;
	printf("n : ");
	scanf("%d", &n);
	Node** graph = (Node*)calloc(n, sizeof(Node));
	for (int i = 0; i < n; i++) {
		graph[i] = (Node*)malloc(sizeof(Node));
		graph[i]->data = i;
		graph[i]->next = NULL;
	}
	int start_node, end_node;
	for (;;) {
		printf("inset Edge : ");
		scanf("%d %d", &start_node, &end_node);
		if ((start_node < 0) || (end_node < 0)) {
			break;
		}
		insertEdge(graph, start_node, end_node);
	}

	printList(graph, n);
	higherDgree(graph, n);

	printf("DFS : \n");
	DFS(graph, n, 0);
}

void insertEdge(Node** graph, int start, int end) {
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->data = end;
	temp->next = NULL;
	temp->next = graph[start]->next;
	graph[start]->next = temp;

	temp = (Node*)malloc(sizeof(Node));
	temp->data = start;
	temp->next = NULL;
	temp->next = graph[end]->next;
	graph[end]->next = temp;

}

void printList(Node** graph, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d : ", graph[i]->data);
		for (Node* ptr = graph[i]->next; ptr; ptr = ptr->next) {
			printf("%d -> ",ptr->data);
		}
		printf("end\n");
	}
}

void higherDgree(Node** graph, int n) {

	int higher_dgree_node = 0;
	int higher_degree = 0;
	int now_node_dgree = 0;

	for (int i = 0; i < n; i++) {
		now_node_dgree = 0;
		for (Node* ptr = graph[i]->next; ptr; ptr = ptr->next) {
			now_node_dgree++;
		}
		if (higher_degree < now_node_dgree) {
			higher_dgree_node = i;
			higher_degree = now_node_dgree;
		}
	}

	printf("Higher dgree Node's num : %d, Node's dgree : %d\n", higher_dgree_node, higher_degree);
	printf("Conection od Node(%d) : ", higher_dgree_node);
	for (Node* ptr = graph[higher_dgree_node]->next; ptr; ptr = ptr->next) {
		printf("%d -> ", ptr->data);
	}
	printf("end\n");

}


void DFS(Node** graph, int n, int start) {
	int* visited = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}
	Node* ptr = graph[start];
	while (1) {
		if (visited[ptr->data] == 0) {
			printf("%d - ", ptr->data);
			push(ptr->data);
			visited[ptr->data] = 1;
			ptr = ptr->next;
			ptr = graph[ptr->data];
		}
		else {
			ptr = ptr->next;
		}
		if (ptr == NULL) {
			ptr = graph[pop()];
			continue;
		}
		if (top == -1) {
			break;
		}
	}


	printf("end\n");
}