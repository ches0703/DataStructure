#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 
#define compare(x,y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)



typedef struct {
	float coef;
	int expon;
} polynomial;

void GetPolynomial(polynomial* P);
void PrintPolynomial(polynomial* P);
void SortPolynomial(polynomial* P);
int CheckNotEnd(polynomial P);
int CheckDuplicate(polynomial* P, int get_expon, int input_adress);
void padd(polynomial* A, polynomial* B, polynomial* D);

int main()
{
	polynomial* A = (polynomial*)calloc(10, sizeof(polynomial));
	polynomial* B = (polynomial*)calloc(10, sizeof(polynomial));
	polynomial* D = (polynomial*)calloc(10, sizeof(polynomial));

	printf("3.1. ���׽� ����\n");

	printf("���׽� A(x) �Է� : \n");
	GetPolynomial(A);

	printf("���׽� A(x)  ���� : ");
	SortPolynomial(A);
	printf("���� �Ϸ�\n");

	printf("���׽� A(x) ��� : \n");
	PrintPolynomial(A);


	printf("���׽� B(x) �Է� : \n");
	GetPolynomial(B);

	printf("���׽� B(x)  ���� : ");
	SortPolynomial(B);
	printf("���� �Ϸ�\n");

	printf("���׽� B(x) ��� : \n");
	PrintPolynomial(B);



	printf("3.2. ���׽� ����\n");
	padd(A, B, D);
	printf("A(x)�� B(x)�� �� D(x) ��� : \n");
	PrintPolynomial(D);


	free(A);
	free(B);
	free(D);

}
void GetPolynomial(polynomial* P) {

	double get_coef = 0;
	int get_expon = 0;
	int check_duplicate_resulte = 0;

	for (int i = 0;; i++) {

		if ((sizeof(P) / sizeof(polynomial)) <= i) {
			realloc(P, sizeof(polynomial) * (i + 1));
		}
		printf("���� �Է��ϼ���. (coef expon) : ");
		scanf("%lf %d", &get_coef, &get_expon);
		if (get_coef == 0) {
			printf("����� 0�� �Է��� �����մϴ�.	\n");
			continue;
		}
		check_duplicate_resulte = CheckDuplicate(P, get_expon, i);
			if (check_duplicate_resulte != -1) {
				P[check_duplicate_resulte].coef += get_coef;
				i--;
			}
			else {
				P[i].coef = get_coef;
				P[i].expon = get_expon;
			}
		if ((get_coef == -1) && (get_expon == -1)) {
			break;
		}
	}
}
void PrintPolynomial(polynomial* P) {
	for (int i = 0; CheckNotEnd(P[i]); i++) {
		if (i) {
			printf(" + ");
		}
		if (P[i].coef) {
			if (P[i].expon) {
				printf("%.1fx^%d", P[i].coef, P[i].expon);
			}
			else {
				printf("%.1f", P[i].coef);
				break;
			}
		}
	}
	printf("\n\n");
}
void SortPolynomial(polynomial* P) {
	polynomial temp;
	for (int i = 0; CheckNotEnd(P[i]); i++) {
		for (int j = i + 1; CheckNotEnd(P[j]); j++) {
			if (P[j].expon > P[i].expon) {
				SWAP(P[i], P[j], temp);
			}
		}
	}
}
int CheckNotEnd(polynomial P) {
	if (((P.coef == -1) && (P.expon == -1))) {
		return 0;
	}
	else {
		return 1;
	}
}
int CheckDuplicate(polynomial* P, int get_expon, int input_adress) {
	for (int i = 0; i < input_adress; i++) {
		if (P[i].expon == get_expon) {
			return i;
		}
	}
	return -1;
}
void padd(polynomial* A, polynomial* B, polynomial* D) {
	int check_duplicate_resulte = 0;
	int D_size = 0;
	for (int i = 0; CheckNotEnd(A[i]); i++) {
		if ((sizeof(D) / sizeof(polynomial)) <= i) {
			realloc(D, sizeof(polynomial) * (i + 1));
		}
		printf("%d", D_size);
		D[D_size].coef = A[i].coef;
		D[D_size].expon = A[i].expon;
		D_size++;
	}
	for (int i = 0; CheckNotEnd(B[i]); i++) {
		if ((sizeof(D) / sizeof(polynomial)) <= D_size) {
			realloc(D, sizeof(polynomial) * (D_size + 1));
		}
		check_duplicate_resulte = CheckDuplicate(D, B[i].expon, D_size+1);
		if (check_duplicate_resulte != -1) {
			D[check_duplicate_resulte].coef += B[i].coef;
		}
		else {
			D[D_size].expon = B[i].expon;
			D[D_size].coef = B[i].coef;
			D_size++;
		}
	}
	D[D_size].expon = -1;
	D[D_size].coef = -1;
	SortPolynomial(D);
}