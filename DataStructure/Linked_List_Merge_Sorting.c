#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 생성할 리스트의 크기
#define LIST_SIZE 20

// 리스트의 노드
typedef struct {
	int data;
	struct Node* next;
}Node;

Node* GetList();					// 랜덤값 20개를 가진 리스트를 생성하여 반환하는 함수
void PrintList(Node* head);			// 리스트를 출력하는 함수
void SortList(Node** head);			// 리스트를 오름차순으로 정렬하는 함수
Node* MergeList(Node** A, Node** B);// 리스트 2개를 분인 새로운 노드를 반환하는 함수. 기존노드를 제거함
void DeleteList(Node** head);		// 리스트의 동적할당을 해재하는 함수

int main()
{
	srand((unsigned)time(NULL));	// 랜덤 시드값 설정
	Node* A, * B, * D;				// 리스트 변수 선언
	
	// A리스트 생성, 정렬 후 출력
	A = GetList();
	SortList(&A);
	printf("List A : \n");
	PrintList(A);
	printf("\n");

	// B리스트 생성, 정렬 후 출력
	B = GetList();
	SortList(&B);
	printf("List B : \n");
	PrintList(B);
	printf("\n");

	// A, B를 합친 D리스트 생성 및 출력
	D = MergeList(&A, &B);
	SortList(&D);
	printf("List D : \n");
	PrintList(D);
	printf("\n");

	// 각 리스트 동적할당 해제
	DeleteList(&A);
	DeleteList(&B);
	DeleteList(&D);
	return 0;
}

// 랜덤값 20개를 가진 리스트를 생성하여 반환하는 함수
// Head노드를 포함한 리스트를 반환함
Node* GetList() {
	// 새로운 리스트의 해드 생성
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = -1;
	head->next = NULL;

	// 리스트에 랜덤값 추가
	Node* ptr = head;
	Node* temp;
	for (int i = 0; i < LIST_SIZE; i++) {
		temp = (Node*)malloc(sizeof(Node));
		temp->data = (rand() % 1000) + 1;
		temp->next = NULL;
		ptr->next = temp;
		ptr = ptr->next;
	}
	return head;
}

// Head노드를 포함한 리스트를 출력하는 함수
void PrintList(Node* head) {
	printf("[Head]->");
	for (Node* ptr = head->next; ptr != NULL; ptr = ptr->next) {
		printf("[%4d]->", ptr->data);
	}
	printf("[NULL]\n");
}

// 리스트를 오름차순으로 정렬하는 함수
void SortList(Node** head) {
	Node* temp;
	Node* min_node, *B_min_node;// B_min_node = Before min node
	Node* ptr, * B_ptr;			// B_ptr = Before ptr
	Node* CS_node, * BCS_node;	// Compare Start Node, Before Compare Start Node

	for (BCS_node = *head, CS_node = (*head)->next; CS_node->next != NULL; BCS_node = CS_node, CS_node = CS_node->next) {
		// 현재 반복에 대한 초기화
		B_min_node = BCS_node;
		min_node = CS_node;
		B_ptr = min_node;
		ptr = min_node->next;
		// 비교 부분
		for (; ptr != NULL; ptr = ptr->next) {
			if (min_node->data > ptr->data) {
				B_min_node = B_ptr;
				min_node = ptr;
			}
			B_ptr = ptr;

		}
		// Swap
		// before node's next를 Change
		temp = BCS_node->next;
		BCS_node->next = B_min_node->next;
		B_min_node->next = temp;
		// node's next를 Change
		temp = CS_node->next;
		CS_node->next = min_node->next;
		min_node->next = temp;
		
		// CS_node의 위치를 재 조정
		CS_node = min_node;
	}
}

// 리스트 2개를 분인 새로운 노드를 반환하는 함수. 기존노드를 제거함
Node* MergeList(Node** A, Node** B) {
	// 새로운 리스트의 해드 생성
	Node* merge_list = (Node*)malloc(sizeof(Node));
	merge_list->data = -1;
	// 새로운 리스트에 A리스트 추가
	merge_list->next = (* A)->next;
	// 새로운 리스트의 끝에 B리스트 추가
	Node* ptr;
	for(ptr = merge_list; ptr->next != NULL; ptr = ptr->next){}
	ptr->next = (*B)->next;
	// 기존 노드의 해드를 제외하고 제거
	(*A)->next = NULL;
	(*B)->next = NULL;
	return merge_list;
}

// 리스트의 동적할당을 해재하는 함수, 해드노드를 포함하여 해제
void DeleteList(Node** head) {
	Node* ptr, * temp;
	for (temp = *head, ptr = (*head)->next; ptr != NULL; ptr = ptr->next) {
		free(temp);
		temp = ptr;
	}
	free(temp);
}