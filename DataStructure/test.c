#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 

void printArr(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("[%2.2f] ", arr[i]);
	}
	printf("\n\n");
}

void adjust(double* arr, int root, int n) {
	int child = 2 * root;
	double temp;
	if (child >= n) {
		return;
	}
	if ((child + 1 < n) && (arr[child + 1] > arr[child])) {
		child++;
	}
	if (arr[child] > arr[root]) {
		SWAP(arr[child], arr[root], temp);
		adjust(arr, child, n);
	}

}

void heapSort(double* arr, int n) {
	int i, j;
	double temp;
	for (i = n / 2; i > 0; i--) {
		adjust(arr, i, n);
	}

	printf("Max Heap\n");
	printArr(arr, n);

	for (i = n - 1; i > 0; i--) {
		SWAP(arr[1], arr[i], temp);
		printf("last : %2.2f\n", arr[i]);
		adjust(arr, 1, i);
	}
}



double* makeRnadArray(int n) {
	double* arr = (double*)malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (rand() / (0x7fff * 1.0));
	}
	return arr;
}



int main()
{
	srand((unsigned)time(NULL));
	int n = 10;
	double* arr = makeRnadArray(10);
	arr[0] = 0;
	printf("Before Sorting\n");
	printArr(arr, n);

	heapSort(arr, n);

	printf("After Sorting\n");
	printArr(arr, n);
	return 0;

}
