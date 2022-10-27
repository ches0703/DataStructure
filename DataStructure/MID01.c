#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 
#define compare(x,y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)


// polynomal 구조체 선언
typedef struct {
	float coef;
	int expon;
} polynomial;

// 함수 원형
void PolymialArraySizeCheckAndIncrease(polynomial* P);
void GetPolynomial(polynomial* P);
void PrintPolynomial(polynomial* P);
void SortPolynomial(polynomial* P);
int CheckNotEnd(polynomial P);
int CheckNotDuplicate(polynomial* P, int get_expon, float get_coef);
polynomial* padd(polynomial* A, polynomial* B);


// MID -------------------------------------------------------------------
polynomial* psub(polynomial* A, polynomial* B);
double peval(polynomial *D, double b);
// MID -------------------------------------------------------------------



// 메인 함수
int main()
{
	// A, B 동적할당 및 포인터 변수 D 선언
	polynomial* A = (polynomial*)calloc(10, sizeof(polynomial));
	polynomial* B = (polynomial*)calloc(10, sizeof(polynomial));
	polynomial* D;
	double b;

	// 다항식 생성부
	printf("다항식 생성\n");

	// A 생성
	printf("다항식 A(x) 입력 : \n");
	GetPolynomial(A);

	printf("다항식 A(x)  정렬 : ");
	SortPolynomial(A);
	printf("정렬 완료\n");

	printf("다항식 A(x) 출력 : \n");
	PrintPolynomial(A);
	printf("\n");

	// B 생성
	printf("다항식 B(x) 입력 : \n");
	GetPolynomial(B);

	printf("다항식 B(x)  정렬 : ");
	SortPolynomial(B);
	printf("정렬 완료\n");

	printf("다항식 B(x) 출력 : \n");
	PrintPolynomial(B);
	printf("\n");

	// A - B 수행
	printf("\n");
	D = psub(A, B);
	printf("A(x) - B(x) = D(x) 출력 : \n");
	PrintPolynomial(D);
	printf("\n");


	// D(b) 행
	printf("D(x)의 미지수(x)의 값 입력 : ");
	scanf("%lf", &b);
	printf("D(%.2f)의 계산 결과 : %.2f\n",b, peval(D, b));


	// 동적 할당 해제
	free(A);
	free(B);
	free(D);

	return 0;
}
// polynomial 배열 크기 확인 및 재 할당
void PolymialArraySizeCheckAndIncrease(polynomial* P) {
	int p_size = (_msize(P) / sizeof(polynomial));
	if (P[p_size - 1].expon) {
		P = (polynomial*)realloc(P, sizeof(polynomial) * (p_size + 1));
	}
}
// polynomial 배열 입력
void GetPolynomial(polynomial* P) {

	float get_coef = 0;
	int get_expon = 0;
	int check_duplicate_resulte = 0;

	for (int i = 0;; i++) {
		PolymialArraySizeCheckAndIncrease(P);
		printf("항을 입력하세요. (coef expon) : ");
		scanf("%f %d", &get_coef, &get_expon);
		if (get_coef == 0) {
			printf("계수가 0인 입력은 무시합니다.	\n");
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
// polynomial 배열 출력
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
// polynomial 배열 정렬 : 지수의 내림차순으로
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
// polynomial[i]가 배열의 끝이 아닌지 판별 : coef, expon이 둘다 -1 이면 끝이므로 0 반환
int CheckNotEnd(polynomial P) {
	if (((P.coef == -1) && (P.expon == -1))) {
		return 0;
	}
	else {
		return 1;
	}
}
// polynomial배열에 값 추가시 해당 값의 중복 검사
// 같은 expon을 가진 polynomial가 잇을시 해당값에 가산하여 저장
int CheckNotDuplicate(polynomial* P, int get_expon, float get_coef) {
	for (int i = 0; P[i].coef; i++) {
		if (P[i].expon == get_expon) {
			P[i].coef += get_coef;
			return 0;
		}
	}
	return 1;
}
// polynomial배열간의 합 연산
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

// MID ---------------------------------------------------
// psub --------------------------------------------------
// B의 모든항의 계수에 -1을 곱한 값을 저장하는 T를 만들고 이후 padd(A,T) 실행하고,
// 그 결과를 D에 저장한 후 D를 리턴
polynomial* psub(polynomial* A, polynomial* B) {
	polynomial* T = (polynomial*)calloc(10, sizeof(polynomial));
	int T_index = 0;
	for (; CheckNotEnd(B[T_index]); T_index++) {
		PolymialArraySizeCheckAndIncrease(T);
		T[T_index].coef = -1 * B[T_index].coef; // 계수에 * -1
		T[T_index].expon = B[T_index].expon;
	}
	T[T_index].expon = -1;
	T[T_index].coef = -1;
	polynomial* D = padd(A, T);
	free(T);
	return D;
}
// peval --------------------------------------------------
double peval(polynomial *D, double b) {
	double resulte = 0;
	for (int i = 0; CheckNotEnd(D[i]); i++) {
		resulte += D[i].coef * pow(b, D[i].expon);
	}
	return resulte;
}