#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_VALUE 100
#define ARRAY_SIZE 100

// 배열 출력 전용 함수
void printArray(int* arr, int size);

int main()
{
	// rand seed값 설정
	srand((unsigned)time(NULL));
	
	// 변수 및 배열 선언
	int a[ARRAY_SIZE];
	int row_terms[ARRAY_SIZE] = { 0 };
	int starting_pos[ARRAY_SIZE] = { 0 };
	int sorted[ARRAY_SIZE];
	int setting_pos = 0;
	int temp;


	// 100이하 정수를 랜덤으로 가지는 배열 a 설정
	printf("100이하 정수의 랜덤 배열 a 설정 : ");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		a[i] = rand() % 100;
	}
	printf("설정 완료.\n");

	printf("a 출력 ( index : a[index] ): \n");
	printArray(a, ARRAY_SIZE);
	printf("\n");


	// row_terms 계산
	printf("row_terms 계산 : ");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		row_terms[a[i]]++;
	}
	printf("계산 완료\n");

	printf("row_terms 출력 ( index : row_terms[index] ) : \n");
	printArray(row_terms, ARRAY_SIZE);
	printf("\n");


	// starting_pos 계산
	printf("starting_pos 계산 : ");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		starting_pos[i] = setting_pos;
		if (row_terms[i]) {
			setting_pos += row_terms[i];
		}
	}
	printf("계산 완료\n");

	printf("starting_pos 출력 ( index : starting_pos[index] ) : \n");
	printArray(starting_pos, ARRAY_SIZE);
	printf("\n");


	// counting sort 수행
	printf("정렬 수행 ( sorted에 저장 ) : ");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		sorted[starting_pos[a[i]]++] = a[i];
	}
	printf("정렬 완료\n");

	printf("sorted 출력 ( index : sorted[index] ) : \n");
	printArray(sorted, ARRAY_SIZE);
	printf("\n");

	return 0;

}
void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("| %2d :%3d |", i, arr[i]);
		if (i % 10 == 9)
		{
			printf("\n");
		}
	}
	printf("\n");
}