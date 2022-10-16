#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int max_stack_size = 10;
int max_queue_size = 10;
int max_Cqueue_size = 10;

int* stack;
int top = -1;
void push(int item);
int pop();

int *queue;
int front = -1, rear = -1;
void add_q(int item);
int delete_q();

int* Cqueue = NULL;
int Cfront = 4, Crear = 4;
void add_Cq(int item);
int delete_Cq();
int Cqueue_is_empty = 1;
int Cqueue_is_full = 0;


int main()
{
	int menu;
	int item;

	// 3.1 Stack ----------------------------------------------
	printf("3.1 Stack \n");
	menu = 0;
	stack = (int*)calloc(max_stack_size, sizeof(int));
	for (;menu!=-1;) {
		printf("Select Menu(push = 1, pop = 2, end = -1) : ");
		scanf("%d", &menu);
		switch (menu)
		{
			case 1:
				printf("input integer : ");
				scanf("%d", &item);
				push(item);
				break;
			case 2:
				printf("pop() = %d\n", pop());
				break;
			case -1:
				printf("End...\n");
				break;
			default:
				printf("worng value!!!\n");
				break;
		}
		printf("\n");
		printf("Index : \n");
		for (int i = 0; i < max_stack_size; i++) {
			printf("[%3d]", i);
		}
		printf("\n");
		printf("vlaue : \n");
		for (int i = 0; i < max_stack_size; i++) {
			if (i <= top) {
				printf("[%3d]", stack[i]);
			}
			else {
				printf("[ x ]");
			}
		}
		printf("\n");
		printf("\n");
	}

	// 3.2 Queue ----------------------------------------------
	printf("3.2 Queue \n");
	menu = 0;
	queue = (int*)calloc(max_queue_size, sizeof(int));
	for (; menu != -1;) {
		printf("add_q = 1, delete_q = 2, end = -1 : ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("input integer : ");
			scanf("%d", &item);
			add_q(item);
			break;
		case 2:
			printf("delete_q() = %d\n", delete_q());
			break;
		case -1:
			printf("End...");
			break;
		default:
			printf("worng value!!!\n");
			break;
		}
		printf("\n");
		printf("Index : \n");
		for (int i = 0; i < max_queue_size; i++) {
			printf("[%3d]", i);
		}
		printf("\n");
		printf("vlaue : \n");
		for (int i = 0; i < max_queue_size; i++) {
			if (i <= rear) {
				if (i <= front) {
					printf("[ x ]");
				}
				else {
					printf("[%3d]", queue[i]);
				}
			}
			else {
				printf("[ x ]");
			}
		}
		printf("\n");
		printf("\n");
	}

	// 3.3 CQueue ---------------------------------------------
	printf("3.3 CQueue \n");
	menu = 0;
	for (; menu != -1;) {
		printf("add_Cq = 1, delete_Cq = 2, end = -1 : ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("input integer : ");
			scanf("%d", &item);
			add_Cq(item);
			break;
		case 2:
			printf("delete_q() = %d\n", delete_Cq());
			break;
		case -1:
			printf("End...");
			break;
		default:
			printf("worng value!!!\n");
			break;
		}
		printf("\n");
		printf("Index : \n");
		for (int i = 0; i < max_Cqueue_size; i++) {
			printf("[%3d]", i);
		}
		printf("\n");
		printf("vlaue : \n");
		for (int i = 0; i < max_Cqueue_size; i++) {
			if (Cfront < Crear) {
				if ((Cfront <= i) && (Crear > i)) {
					printf("[%3d]", Cqueue[i]);
				}
				else {
					printf("[ x ]");
				}
			}
			else if (Cfront > Crear) {
				if ((Cfront <= i) != (Crear > i)) {
					printf("[%3d]", Cqueue[i]);
				}
				else {
					printf("[ x ]");
				}
			}
			else {
				if (Cqueue_is_empty) {
					printf("[ x ]");
				}
				else {
					printf("[%3d]", Cqueue[i]);
				}
			}
		}
		printf("\n");
		for (int i = 0; i < max_Cqueue_size; i++) {
			if ((i == Crear) && (i == Cfront)) {
				printf("[f r]");
			}
			else if (i == Crear) {
				printf("[ r ]");
			}
			else if (i == Cfront) {
				printf("[ f ]");
			}
			else {
				printf("     ");
			}
		}
		printf("\n");
		printf("\n");
	}

	free(stack);
	free(queue);
	free(Cqueue);


}
// Stack
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
// Queue
void add_q(int item) {
	if (rear < max_queue_size - 1) {
		queue[++rear] = item;
	}
	else {
		printf("Queue is full... Retouch Queue size!\n");
		max_queue_size *= 2;
		queue = (int**)realloc(queue, sizeof(int) * max_queue_size);
		queue[++rear] = item;
	}
}
int delete_q() {
	if (front >= rear) {
		printf("It is empty...\n");
		return -1;
	}
	return queue[++front];
}
// CQueue
void add_Cq(int item) {
	if (Cqueue == NULL) {
		Cqueue = (int*)calloc(max_Cqueue_size, sizeof(int));
		Cqueue[Crear++] = item;
		Cqueue_is_empty = 0;
	}
	else if (Cqueue_is_full) {
		printf("CQueue is full... Retouch CQueue size!\n");
		int* temp = (int*)calloc(max_Cqueue_size * 2, sizeof(int));
		int i = 0;
		for (int j = Crear;j<max_Cqueue_size;j++) {
			temp[i++] = Cqueue[j];
		}
		for (int j = 0; j < Crear; j++) {
			temp[i++] = Cqueue[j];
		}
		free(Cqueue);
		Cqueue = temp;
		Cqueue_is_full = 0;
		Crear = max_Cqueue_size;
		Cfront = 0;
		max_Cqueue_size *= 2;
		add_Cq(item);
	}
	else {
		Cqueue_is_empty = 0;
		Cqueue[Crear++] = item;
	}
	Crear %= max_Cqueue_size;
	if ((Cfront == Crear) && (!Cqueue_is_empty)) {
		printf("CQueue is full...\n");
		Cqueue_is_full = 1;
	}
}
int delete_Cq() {
	int temp;
	if (Cqueue_is_empty) {
		printf("It is empty...\n");
		return -1;
	}
	temp = Cqueue[Cfront++];
	Cfront %= max_Cqueue_size;
	if (Cfront == Crear) {
		Cqueue_is_empty = 1;
	}
	return temp;
}