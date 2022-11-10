#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	float coef;
	int exp;
	struct PolyNode* next;
}PolyNode;

PolyNode* Avail = NULL;				// 가용 노드 리스트
PolyNode* getNode();				// 노드 배포
PolyNode* retNode(PolyNode** node); // 노드 반환
void freeAvail();					// Avail 동적 할당 해제

void printList(PolyNode* node);		// 환형 polyNode 리스트 출력
PolyNode* create_polynomial();		// 환형 polyNode 리스트 생성
void cerease(PolyNode** head);		// 리스트의 node를 retNode를 통해 Avail로 반환
void attach(float coef, int exp, PolyNode** head);	// polyNode list에 내림차순으로 polyNode 추가
PolyNode* cpadd(PolyNode* A, PolyNode* B);	// polyNode 리스트간의 합 연산
PolyNode* cpmul(PolyNode* A, PolyNode* B);	// cpadd를 이용한 polyNode 리스트간의 곱 연산

int main()
{
	// 7.1 다항식 생성
	printf("7.1 다항식 생성\n");
	printf("\nEnter the A(x) : \n");
	PolyNode* A = create_polynomial();
	printList(A);


	printf("\nEnter the B(x) : \n");
	PolyNode* B = create_polynomial();
	printList(B);


	// 7.2 다항식 덧샘
	printf("\n7.2 다항식 덧샘\n");
	PolyNode* C = cpadd(A, B);
	printf("A(x) + B(x) = ");
	printList(C);


	// 7.3 다항식 곱샘
	printf("\n7.3 다항식 곱샘\n\n");
	PolyNode* D = cpmul(A, B);
	printf("A(x) * B(x) = ");
	printList(D);


	// 리스트 반환 및 Avail 동적 할당 해제
	cerease(&A);
	cerease(&B);
	cerease(&C);
	cerease(&D);
}

// 노드 배포
PolyNode* getNode() {
	PolyNode* new_node;
	if (Avail != NULL) { // Avail에 배포가능한 노드가 있는경우
		// Avail의 처음 노드를 반환
		new_node = Avail;	 
		Avail = Avail->next;
	}
	else {
		// Avail이 비어있는 경우 : 동적할당
		new_node = (PolyNode*)malloc(sizeof(PolyNode));
	}
	new_node->next = NULL;
	return new_node;
}

// 노드 반환 : Avail의 앞쪽에 삽입 
PolyNode* retNode(PolyNode** node) {
	(*node)->next = Avail;
	Avail = *node;
}

// Avile의 동적할당 해제
void freeAvail() {
	PolyNode* ptr;
	for (ptr = Avail; ptr != NULL; ptr = Avail) {
		Avail = Avail->next;
		free(ptr);
	}
}

// 환형 polyNode List 출력
void printList(PolyNode* node) {
	for (PolyNode* ptr = node->next; ptr != node; ptr = ptr->next) {
		printf("%+.2fx^%d ", ptr->coef, ptr->exp);
	}
	printf("\n");
}


// 환형 polyNode 리스트 생성
PolyNode* create_polynomial() {
	// 새로운 리스트의 헤드 생성
	PolyNode* new_list = getNode();
	new_list->coef = -1.0;
	new_list->exp = -1;
	new_list->next = new_list;
	float coef;
	int exp;
	for (;;) {
		printf("Enter polyNode Data(-1 -1 is end) : ");
		scanf("%f %d", &coef, &exp);
		if ((coef < 0) && (exp == -1)) {
			printf("End enter\n");
			return new_list;
		}
		attach(coef, exp, &new_list);
	}
}

// 리스트의 node를 retNode를 통해 Avail로 반환
void cerease(PolyNode**head) {
	PolyNode* ptr = (*head)->next;
	PolyNode* temp;
	for (; ptr != *head;) {
		temp = ptr;
		ptr = ptr->next;
		retNode(&temp);
	}
	retNode(head);
}

// 환형 리스트에 매게변수로 받은 값을 가지는 노드를 내림차순으로 추가
void attach(float coef, int exp, PolyNode** head) {
	PolyNode* prev_ptr = (*head);
	PolyNode* ptr = (*head)->next;
	PolyNode* new_node = getNode();	// list에 들어갈 새로운 노드
	new_node->coef = coef;
	new_node->exp = exp;
	// list에 내림차순으로 넣기
	for (; ptr != *head; prev_ptr = ptr, ptr = ptr->next) {
		if (ptr->exp == exp) {		// 지수가 같은 Node가 존재시 : 합연산
			ptr->coef += coef;
			retNode(&new_node);		// 실재로 쓰지 않은 new_node 반환후 함수 종료
			return;
		}
		else if (ptr->exp < exp) {	
			break;
		}
	}
	prev_ptr->next = new_node;
	new_node->next = ptr;
}

// 환형 PolyNode 리스트간의 합연산 
PolyNode* cpadd(PolyNode* A, PolyNode* B) {
	// 합연산 결과를 저장할 새로운 리스트의 헤드 생성
	PolyNode* resulte_list = getNode();
	resulte_list->coef = -1.0;
	resulte_list->exp = -1;
	resulte_list->next = resulte_list;
	// 새로운 리스트에 A, B의 모든 node의 데이터를 넣음
	// 지수가 같은 노드의 경우 attach에서 합연산을 실행
	for (PolyNode* Aptr = A->next; Aptr != A; Aptr = Aptr->next) {
		attach(Aptr->coef, Aptr->exp, &resulte_list);
	}
	for (PolyNode* Bptr = B->next; Bptr != B; Bptr = Bptr->next) {
		attach(Bptr->coef, Bptr->exp, &resulte_list);
	}
	return resulte_list;
}

PolyNode* cpmul(PolyNode* A, PolyNode* B) {
	PolyNode* temp;	// 합 연산 결과 리스트를 임시적으로 가르킬 포인터
	// 곱연산 결과를 저장할 새로운 리스트의 헤드 생성
	PolyNode* resulte_list = getNode();
	resulte_list->coef = -1.0;
	resulte_list->exp = -1;
	resulte_list->next = resulte_list;
	int C = 0;
	// 리스트 A의 원소 하나에 대해 B 전채를 곱한 값을 mid_resulte_list에 
	// 저장 후 resulte_list 와 합 연산
	for (PolyNode* Aptr = A->next; Aptr != A; Aptr = Aptr->next) {
		// 중간 값을 저장할 mid_resulte 리스트의 해드 생성
		PolyNode* mid_resulte_list = getNode();
		mid_resulte_list->coef = -1.0;
		mid_resulte_list->exp = -1;
		mid_resulte_list->next = mid_resulte_list;
		for (PolyNode* Bptr = B->next; Bptr != B; Bptr = Bptr->next) {
			// 추가하는 node의 값 연산 후 추가
			attach(Aptr->coef * Bptr->coef, Aptr->exp + Bptr->exp, &mid_resulte_list);
		}
		printf("single_mul : C%d(x) : ", ++C); 
		printList(mid_resulte_list);
		printf("\n");
		temp = cpadd(resulte_list, mid_resulte_list);	// 임시적으로 합연산 결과를 temp로 가리킴
		cerease(&resulte_list);		// resulte 초기화
		cerease(&mid_resulte_list); // mid_resulte_list 초기화
		resulte_list = temp;		// 합연산 결과를 resulte로 저장
	}
	return resulte_list;
}