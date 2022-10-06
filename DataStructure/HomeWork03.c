#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 
#define compare(x,y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)


// polynomal ����ü ����
typedef struct {
	float coef;
	int expon;
} polynomial;

// �Լ� ����
void PolymialArraySizeCheckAndIncrease(polynomial* P);
void GetPolynomial(polynomial* P);
void PrintPolynomial(polynomial* P);
void SortPolynomial(polynomial* P);
int CheckNotEnd(polynomial P);
int CheckNotDuplicate(polynomial* P, int get_expon, float get_coef);
polynomial* padd(polynomial* A, polynomial* B);
polynomial* single_mul(polynomial A, polynomial* B);
polynomial* pmul(polynomial* A, polynomial* B);

// ���� �Լ�
int main()
{
	// A, B �����Ҵ� �� ������ ���� D ����
	polynomial* A = (polynomial*)calloc(10, sizeof(polynomial));
	polynomial* B = (polynomial*)calloc(10, sizeof(polynomial));
	polynomial* D;


	// ���׽� ������
	printf("3.1. ���׽� ����\n");

	// A ����
	printf("���׽� A(x) �Է� : \n");
	GetPolynomial(A);

	printf("���׽� A(x)  ���� : ");
	SortPolynomial(A);
	printf("���� �Ϸ�\n");

	printf("���׽� A(x) ��� : \n");
	PrintPolynomial(A);
	printf("\n");

	// B ����
	printf("���׽� B(x) �Է� : \n");
	GetPolynomial(B);

	printf("���׽� B(x)  ���� : ");
	SortPolynomial(B);
	printf("���� �Ϸ�\n");

	printf("���׽� B(x) ��� : \n");
	PrintPolynomial(B);
	printf("\n");

	// A + B ����
	printf("3.2. ���׽� ����\n");
	D = padd(A, B);
	printf("A(x)�� B(x)�� �� D(x) ��� : \n");
	PrintPolynomial(D);
	printf("\n");
	free(D); // free�� ���� D�� �����Ҵ�� �迭�� ��ȯ

	// A * B ����
	printf("3.3. ���׽� ����\n");
	D = pmul(A, B);
	printf("A(x)�� B(x)�� �� D(x) ��� : \n");
	PrintPolynomial(D);
	printf("\n");


	// ���� �Ҵ� ����
	free(A);
	free(B);
	free(D);

}
// polynomial �迭 ũ�� Ȯ�� �� �� �Ҵ�
void PolymialArraySizeCheckAndIncrease(polynomial* P) {
	int p_size = (_msize(P) / sizeof(polynomial));
	if (P[p_size - 1].expon) {
		realloc(P, sizeof(polynomial) * (p_size + 1));
	}
}
// polynomial �迭 �Է�
void GetPolynomial(polynomial* P) {

	float get_coef = 0;
	int get_expon = 0;
	int check_duplicate_resulte = 0;

	for (int i = 0;; i++) {
		PolymialArraySizeCheckAndIncrease(P);
		printf("���� �Է��ϼ���. (coef expon) : ");
		scanf("%f %d", &get_coef, &get_expon);
		if (get_coef == 0) {
			printf("����� 0�� �Է��� �����մϴ�.	\n");
			i--;
			continue;
		}
		if (CheckNotDuplicate(P, get_expon, get_coef)) {
			P[i].coef = get_coef;
			P[i].expon = get_expon;
		}
		if ((get_coef == -1) && (get_expon == -1)) {
			break;
		}
	}

}
// polynomial �迭 ���
void PrintPolynomial(polynomial* P) {
	for (int i = 0; CheckNotEnd(P[i]); i++) {
		if (i) {
			if (P[i].expon) {
				printf("  %+.1fx^%d", P[i].coef, P[i].expon);
			}
			else {
				printf("  %+.1f", P[i].coef);
				break;
			}
		}
		else {
			printf("%.1fx^%d", P[i].coef, P[i].expon);
		}
	}
	printf("\n");
}
// polynomial �迭 ���� : ������ ������������
void SortPolynomial(polynomial* P) {
	polynomial temp;
	for (int i = 0; CheckNotEnd(P[i]); i++) {
		for (int j = i + 1; CheckNotEnd(P[j]); j++) {
			if (P[i].expon < P[j].expon) {
				SWAP(P[i], P[j], temp);
			}
		}
	}
}
// polynomial[i]�� �迭�� ���� �ƴ��� �Ǻ� : coef, expon�� �Ѵ� -1 �̸� ���̹Ƿ� 0 ��ȯ
int CheckNotEnd(polynomial P) {
	if (((P.coef == -1) && (P.expon == -1))) {
		return 0;
	}
	else {
		return 1;
	}
}
// polynomial�迭�� �� �߰��� �ش� ���� �ߺ� �˻�
// ���� expon�� ���� polynomial�� ������ �ش簪�� �����Ͽ� ����
int CheckNotDuplicate(polynomial* P, int get_expon, float get_coef) {
	for (int i = 0; P[i].coef; i++) {
		if (P[i].expon == get_expon) {
			P[i].coef += get_coef;
			return 0;
		}
	}
	return 1;
}
// polynomial�迭���� �� ����
polynomial* padd(polynomial* A, polynomial* B) {
	polynomial* D = (polynomial*)calloc(10, sizeof(polynomial));
	int D_index = 0;
	for (int i = 0; CheckNotEnd(A[i]); i++) {
		PolymialArraySizeCheckAndIncrease(D);
		D[D_index].coef = A[i].coef;
		D[D_index].expon = A[i].expon;
		D_index++;
	}
	for (int i = 0; CheckNotEnd(B[i]); i++) {
		PolymialArraySizeCheckAndIncrease(D);
		if (CheckNotDuplicate(D, B[i].expon, B[i].coef)) {
			D[D_index].expon = B[i].expon;
			D[D_index].coef = B[i].coef;
			D_index++;
		}
	};
	PolymialArraySizeCheckAndIncrease(D);
	D[D_index].expon = -1;
	D[D_index].coef = -1;
	SortPolynomial(D);
	return D;
}
// polynomial�迭�� polynomial���� �� ����
polynomial* single_mul(polynomial A, polynomial* B) {
	polynomial* D = (polynomial*)calloc(10, sizeof(polynomial));
	int D_index = 0;
	for (int i = 0; CheckNotEnd(B[i]); i++) {
		PolymialArraySizeCheckAndIncrease(D);
		D[D_index].coef = B[i].coef * A.coef;
		D[D_index].expon = B[i].expon + A.expon;
		D_index++;
	};
	PolymialArraySizeCheckAndIncrease(D);
	D[D_index].expon = -1;
	D[D_index].coef = -1;
	return D;
}
// polynomial�迭���� �� ����
polynomial* pmul(polynomial* A, polynomial* B) {
	polynomial* D = (polynomial*)calloc(1, sizeof(polynomial));
	D[0].expon = -1;
	D[0].coef = -1;
	polynomial* C;

	for (int i = 0; CheckNotEnd(A[i]); i++) {
		C = single_mul(A[i], B);
		printf("single_mul : C%d(x) : ", i);
		PrintPolynomial(C);
		D = padd(D, C);
		free(C);
	}

	return D;

}