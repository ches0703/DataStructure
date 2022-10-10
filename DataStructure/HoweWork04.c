#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int max_stack_size = 1;
int max_queue_size = 1;

int* stack;
int top = -1;
void push(int item);
int pop();

int *queue;
int front = -1, rear = -1;
void add_q(int item);
int delete_q();

int main()
{
	int menu;
	int item;

	stack = (int*)calloc(max_stack_size, sizeof(int));

	printf("***");
	for (int i = 1;i;) {
		printf("push = 0, pop = 1, end = -1 : ");
		scanf("%d", &menu);
		switch (menu)
		{
			case 0:
				printf("input integer : ");
				scanf("%d", &item);
				push(item);
				break;
			case 1:
				printf("pop() = %d\n", pop());
				break;
			case -1:
				printf("End...\n");
				i = 0;
				break;
			default:
				printf("worng value!!!\n");
				break;
		}
		printf("Index : \n");
		for (int i = 0; i < max_stack_size; i++) {
			printf("[%3d]", i);
		}
		printf("\n");
		printf("vlaue : \n");
		for (int i = 0; i <= top; i++) {
			printf("[%3d]", stack[i]);
		}
		printf("\n");
	}

	queue = (int*)calloc(max_queue_size, sizeof(int));

	for (int i = 1; i;) {
		printf("add_q = 0, delete_q = 1, end = -1 : ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 0:
			printf("input integer : ");
			scanf("%d", &item);
			add_q(item);
			break;
		case 1:
			printf("delete_q() = %d\n", delete_q());
			break;
		case -1:
			printf("End...");
			i = 0;
			break;
		default:
			printf("worng value!!!\n");
			break;
		}

		printf("Index : \n");
		for (int i = 0; i < max_queue_size; i++) {
			printf("[%3d]", i);
		}
		printf("\n");
		printf("vlaue : \n");
		for (int i = 0; i <= front; i++) {
			if (i <= rear) {
				printf("[ x ]");
			}
			else {
				printf("[%3d]", queue[i]);
			}
		}
		printf("\n");

	}

	free(stack);
	free(queue);
}

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
	if (top < 0 ) {
		printf("It is empty...\n");
		return -1;
	}
	return stack[top--];
}

void add_q(int item) {
	if (front < max_queue_size - 1) {
		queue[++front] = item;
	}
	else {
		printf("Queue is full... Retouch Queue size!\n");
		max_queue_size *= 2;
		queue = (int**)realloc(queue, sizeof(int) * max_queue_size);
		queue[++front] = item;
	}
}

int delete_q() {
	if (rear >= front) {
		printf("It is empty...\n");
		return -1;
	}
	return queue[++rear];
}