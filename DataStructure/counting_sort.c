#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_VALUE 100
#define ARRAY_SIZE 100

// �迭 ��� ���� �Լ�
void printArray(int* arr, int size);

int main()
{
	// rand seed�� ����
	srand((unsigned)time(NULL));
	
	// ���� �� �迭 ����
	int a[ARRAY_SIZE];
	int row_terms[ARRAY_SIZE] = { 0 };
	int starting_pos[ARRAY_SIZE] = { 0 };
	int sorted[ARRAY_SIZE];
	int setting_pos = 0;
	int temp;


	// 100���� ������ �������� ������ �迭 a ����
	printf("100���� ������ ���� �迭 a ���� : ");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		a[i] = rand() % 100;
	}
	printf("���� �Ϸ�.\n");

	printf("a ��� ( index : a[index] ): \n");
	printArray(a, ARRAY_SIZE);
	printf("\n");


	// row_terms ���
	printf("row_terms ��� : ");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		row_terms[a[i]]++;
	}
	printf("��� �Ϸ�\n");

	printf("row_terms ��� ( index : row_terms[index] ) : \n");
	printArray(row_terms, ARRAY_SIZE);
	printf("\n");


	// starting_pos ���
	printf("starting_pos ��� : ");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		starting_pos[i] = setting_pos;
		if (row_terms[i]) {
			setting_pos += row_terms[i];
		}
	}
	printf("��� �Ϸ�\n");

	printf("starting_pos ��� ( index : starting_pos[index] ) : \n");
	printArray(starting_pos, ARRAY_SIZE);
	printf("\n");


	// counting sort ����
	printf("���� ���� ( sorted�� ���� ) : ");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		sorted[starting_pos[a[i]]++] = a[i];
	}
	printf("���� �Ϸ�\n");

	printf("sorted ��� ( index : sorted[index] ) : \n");
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