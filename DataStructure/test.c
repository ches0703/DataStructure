#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 

int main()
{
	int* temp;

	int* arr1 = (int*)malloc(sizeof(int) * 3);
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;

	int* arr2 = (int*)malloc(sizeof(int) * 3);
	arr2[0] = 4;
	arr2[1] = 5;
	arr2[2] = 6;
	printf("before SWAP\n");
	for (int i = 0; i < 3; i++) {
		printf("%d -> ", arr1[i]);
	}
	printf("\n");
	for (int i = 0; i < 3; i++) {
		printf("%d -> ", arr2[i]);
	}
	printf("\nafter SWAP\n");
	SWAP(arr1, arr2, temp);
	for (int i = 0; i < 3; i++) {
		printf("%d -> ", arr1[i]);
	}
	printf("\n");
	for (int i = 0; i < 3; i++) {
		printf("%d -> ", arr2[i]);
	}

}