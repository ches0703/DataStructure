#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<time.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 

double perm(char* list, int i, int n);
void makeIntegerToStr(int n, char* str);

int main()
{
	// 2.1
	char A[][10] = { "GO", "BOY", "GIRL", "GIRLS" };
	char integer_str[11];
	double duration;
	double duration_data[10];

	for (int i = 0; i < 4; i++) {
		printf("제시 문자열 : %s\n", A[i]);
		perm(A[i], 0, strlen(A[i]) - 1);
		printf("\n\n");
	}



	// 2.2
	for (;;) {
		int n;
		printf("정수 입력 : ");
		scanf("%d", &n);
		if (n == -1) {
			printf("종료");
			break;
		}
		else if (n>32) {
			printf("입력 범위(1~32)를 벗어났습니다.\n");
			continue;
		}
		makeIntegerToStr(n, integer_str);
		printf("1 ~ %d 순열\n", n);
		duration = perm(integer_str, 0, strlen(integer_str)-1);
		printf("\n실행시간 : %5.3f\n\n",duration);
	}
	

	// 2.3
	for (int i = 0; i < 11; i++) {
		makeIntegerToStr(i+1, integer_str);
		duration = perm(integer_str, 0, strlen(integer_str) - 1);
		duration_data[i] = duration;
		printf("\n");
	}
	printf("  n     duration\n");
	for (int i = 0; i < 11; i++) {
		printf("%3d %12.3f\n", i, duration_data[i]);
	}

}
double perm(char* list, int i, int n) {
	clock_t start, stop;
	start = clock();
	int j, temp;
	if (i == n) {
		for (j = 0; j <= n; j++)
			printf("%c", list[j]);
		printf(" ");
	}

	else {
		for (j = i; j <= n; j++) {
			SWAP(list[i], list[j], temp);
			perm(list, i + 1, n);
			SWAP(list[i], list[j], temp);
		}
	}
	stop = clock();
	return (double)(stop - start)/1000;

}
void makeIntegerToStr(int n, char* str) {
	for (int i = 0; i < n; i++) {
		str[i] = i + 49;
	}
	str[n] = NULL;
}

