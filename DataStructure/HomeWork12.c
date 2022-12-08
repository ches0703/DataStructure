#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 

void printArray(double* arr, int n);
double* makeRnadArray(int n);
double* copyArray(double* arr, int n);
int sortCheck(double* arr, int n);
double selectionSort(double* arr, int n);
double insertionSort(double* arr, int n);

int main()
{
	srand((unsigned)time(NULL));

	double duration;
	int n;
	n = 100;
	double* original_arr = makeRnadArray(n);
	double* copy_arr = copyArray(original_arr, n);

	printArray(original_arr, n);
	duration = insertionSort(original_arr, n);

	printf("duration : %f\n", duration);
	printArray(original_arr, n);
	


}
void printArray(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("[%.3f]", arr[i]);
		if ((i) && (i % 9 == 0)) {
			printf("\n");
		}
	}
	printf("\n\n");
}

double* copyArray(double* arr, int n) {
	double* copy_arr = (double*)malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		copy_arr[i] = arr[i];
	}
	return copy_arr;
}

double* makeRnadArray(int n) {
	double* arr = (double*)malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (rand() / (0x7fff * 1.0)) * 10;
	}
	return arr;
}

int sortCheck(double* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) { return 0; }
	}
	return 1;
}


double selectionSort(double* arr, int n) {
	clock_t start, end;
	int min_index;
	double temp;
	start = clock();
	for (int i = 0; i < n; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[min_index] > arr[j]) { min_index = j; }
		}
		SWAP(arr[i], arr[min_index], temp);
	}
	end = clock();
	return (double)(end - start) / 1000;
}

double insertionSort(double* arr, int n) {
	clock_t start, end;
	double insert_value;
	start = clock();
	for (int i = 1, j; i < n; i++) {
		insert_value = arr[i];
		for (j = i - 1; (j >= 0) && (insert_value < arr[j]); j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = insert_value;
	}
	end = clock();
	return (double)(end - start) / 1000;
}

double quickSort(double* arr, int left, int right) {
	if (left >= right) { return 0; }
	clock_t start, end;
	double standard = arr[(left + right) / 2];
	start = clock();
	for (int index = 0, l = left, r = right; l < r; index++) {

	}
	end = clock();
	return (double)(end - start) / 1000;
}