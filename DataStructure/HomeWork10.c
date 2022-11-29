#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

// 기본 스택 연산
int max_stack_size = 10;
int *stack;
int top = -1;
void push(int item) {
	if (top < max_stack_size - 1) {
		stack[++top] = item;
	}
	else {
		max_stack_size *= 2;
		stack = (int**)realloc(stack, sizeof(int) * max_stack_size);
		stack[++top] = item;
	}
}
int pop() {
	if (top < 0) {
		return -1;
	}
	return stack[top--];
}
void resetStack() {
	top = -1;
}

// 기본 큐 연산
int max_queue_size = 10;
int* queue;
int front = -1, rear = -1;
void add_q(int item) {
	if (rear < max_queue_size - 1) {
		queue[++rear] = item;
	}
	else {
		max_queue_size *= 2;
		queue = (int**)realloc(queue, sizeof(int) * max_queue_size);
		queue[++rear] = item;
	}
}
int delete_q() {
	if (front >= rear) {
		return -1;
	}
	return queue[++front];
}
void resetQueue() {
	front = -1, rear = -1;
}

// graph에 Edge 추가
void insertEdge(Node** graph, int start, int end);

// Graph 정보 출력
void printGraph(Node** graph, int n);	// Graph 출력
void higherDgree(Node** graph, int n);	// Graph의 degree가 가장 높은 리스트 출력

// Graph 탐색 알고리즘
void DFS(Node** graph, int n, int start);	// 깊이 우선, Stack사용
void BFS(Node** graph, int n, int start);	// 넓이 우선, Queue사용

// Graph 신장 트리 알고리즘
void spaningDFS(Node** graph, int n, int start);
void spaningBFS(Node** graph, int n, int start);

// Graph의 동적 할당 해제
void freeGraph(Node** graph, int n);

int main()
{
	// Stack 및 Queue 초기 동적 할당
	stack = (int*)calloc(max_stack_size, sizeof(int));
	queue = (int*)calloc(max_queue_size, sizeof(int));

	int n;
	Node** graph;
	for (;;) {
		// 10.1. 인접 리스트 형태의 무방향성 그래프 생성
		printf("10.1. 인접 리스트 형태의 무방향성 그래프 생성\n");
		printf("Enter the number of nodes (n) : ");
		scanf("%d", &n);
		if (n < 0) {
			break;
		}
		graph = (Node*)calloc(n, sizeof(Node));
		for (int i = 0; i < n; i++) {
			graph[i] = (Node*)malloc(sizeof(Node));
			graph[i]->data = i;
			graph[i]->next = NULL;
		}
		int start_node, end_node;
		for (;;) {
			printf("Enter the Edge : ");
			scanf("%d %d", &start_node, &end_node);
			if ((start_node < 0) || (end_node < 0)) { break; }
			insertEdge(graph, start_node, end_node);
		}

		// 그래프 출력 및 degree가 가장 높은 리스트 출력
		printGraph(graph, n);
		higherDgree(graph, n);

		// 10.2. 탐색 알고리즘(DFS, BFS)
		printf("10.2. 탐색 알고리즘(DFS, BFS)");
		printf("\nDFS : \n");
		for (int i = 0; i < n; i+=2) {
			DFS(graph, n, i);
		}

		printf("\nBFS : \n");
		for (int i = 1; i < n; i += 2) {
			BFS(graph, n, i);
		}

		// 10.3. 신장트리 알고리즘(DFS, BFS 기반)
		printf("10.3. 신장트리 알고리즘(DFS, BFS 기반)\n");
		printf("\nSpaning tree of DFS : \n");;
		for (int i = 0; i < n; i += 2) {
			spaningDFS(graph, n, i);
		}

		printf("\nSpaning tree of BFS : \n");
		for (int i = 1; i < n; i += 2) {
			spaningBFS(graph, n, i);
		}

		freeGraph(graph, n);
		printf("\n\n");
	}

	free(stack);
	free(queue);

	return 0;

}

// graph에 Edge 추가
void insertEdge(Node** graph, int start, int end) {
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->data = end;
	temp->next = graph[start]->next;
	graph[start]->next = temp;

	temp = (Node*)malloc(sizeof(Node));
	temp->data = start;
	temp->next = graph[end]->next;
	graph[end]->next = temp;
}

// Graph 출력
void printGraph(Node** graph, int n) {
	printf("\nGraph : \n");
	for (int i = 0; i < n; i++) {
		printf("  %d : ", graph[i]->data);
		for (Node* ptr = graph[i]->next; ptr; ptr = ptr->next) {
			printf("%d -> ",ptr->data);
		}
		printf("end\n");
	}
	printf("\n");
}

// Graph의 degree가 가장 높은 리스트 출력
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
	printf("Conection of Node(%d) : ", higher_dgree_node);
	for (Node* ptr = graph[higher_dgree_node]->next; ptr; ptr = ptr->next) {
		printf("%d -> ", ptr->data);
	}
	printf("end\n");

}

// Graph 탐색 알고리즘 : 깊이 우선 탐색
void DFS(Node** graph, int n, int start) {
	int* visited = (int*)calloc(n, sizeof(int));
	printf("  start node = %d : ", start);
	for (Node* ptr = graph[start];;) {
		if (!ptr) {
			int pop_resulte = pop();
			if (pop_resulte == -1) { break; }
			ptr = graph[pop_resulte];
		}
		if (!visited[ptr->data]) {
			printf("%d  ", ptr->data);
			push(ptr->data);
			visited[ptr->data] = 1;
			for (ptr = ptr->next; (ptr) && (visited[ptr->data]); ptr = ptr->next) {}
			if (ptr == NULL) { continue; }
			ptr = graph[ptr->data];
		}
		else {
			ptr = ptr->next;
		}
	}
	printf("\n");
	resetStack();
	free(visited);
}

// Graph 탐색 알고리즘 : 넓이 우선 탐색
void BFS(Node** graph, int n, int start) {
	int* visited = (int*)calloc(n, sizeof(int));
	printf("  start node = %d : ", start);
	for (Node* ptr = graph[start];;) {
		if(!ptr){
			int delete_resulte = delete_q();
			if (delete_resulte == -1) { break; }
			ptr = graph[delete_resulte];
		}
		if (!visited[ptr->data]) {
			printf("%d  ", ptr->data);
			add_q(ptr->data);
			visited[ptr->data] = 1;
		}
		else {
			ptr = ptr->next;
		}
	}
	printf("\n");
	resetQueue();
	free(visited);
}

// Graph 신장 트리 알고리즘 : DFS
void spaningDFS(Node** graph, int n, int start) {
	int* visited = (int*)calloc(n, sizeof(int));
	Node* prev_ptr = graph[start];
	push(start);
	visited[start] = 1;
	printf("  start node = %d : ", start);
	for (Node* ptr = graph[(graph[start]->next)->data];;) {
		if (!ptr) {
			int pop_resulte = pop();
			if (pop_resulte == -1) { break; }
			ptr = graph[pop_resulte];
			prev_ptr = ptr;
		}
		if (!visited[ptr->data]) {
			printf("(%d, %d) ", prev_ptr->data, ptr->data);
			prev_ptr = ptr;
			push(ptr->data);
			visited[ptr->data] = 1;
			for (ptr = ptr->next; (ptr) && (visited[ptr->data]); ptr = ptr->next) {}
			if (ptr == NULL) { prev_ptr = NULL; continue; }
			ptr = graph[ptr->data];
		}
		else {
			ptr = ptr->next;
		}
	}
	printf("\n");
	resetStack();
	free(visited);
}

// Graph 신장 트리 알고리즘 : BFS
void spaningBFS(Node** graph, int n, int start) {
	int* visited = (int*)calloc(n, sizeof(int));
	Node* prev_ptr = graph[start];
	push(start);
	visited[start] = 1;
	printf("  start node = %d : ", start);
	for (Node* ptr = graph[start]->next;;) {
		if (!ptr) {
			int delete_resulte = delete_q();
			if (delete_resulte == -1) { break; }
			prev_ptr = graph[delete_resulte];
			ptr = prev_ptr->next;
		}
		if (!visited[ptr->data]) {
			printf("(%d, %d) ", prev_ptr->data, ptr->data);
			add_q(ptr->data);
			visited[ptr->data] = 1;
		}
		else {
			ptr = ptr->next;
		}
	}
	printf("\n");
	resetQueue();
	free(visited);
}

// Graph의 동적 할당 해제
void freeGraph(Node** graph, int n) {
	for (int i = 0; i < n; i++) {
		Node* ptr = graph[i];
		for (Node* sub_ptr = ptr->next; sub_ptr; sub_ptr = ptr->next) {
			ptr->next = sub_ptr->next;
			free(sub_ptr);
		}
	}
	free(graph);
}