#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 

// Make Array
double* makeRnadArray(int n);
double* makeAscendingArray(int n);
double* makeDescendingArray(int n);

// Copy Array : return copy array
double* copyArray(double* arr, int n);

// Sort Check : Sorted -> return 1, Else -> return 0
int sortCheck(double* arr, int n);

// Sort Algorithm
void selectionSort(double* arr, int n);
void insertionSort(double* arr, int n);
void quickSort(double* arr, int left, int right);


int main()
{
	srand((unsigned)time(NULL));
	double* original_arr;
	double* copy_arr;
	int n;
	clock_t start, end;
	double duration;

	// Rand case

	for (;;) {
		printf("Rand Case===============================\n");
		printf("Enter the array's size : ");
		scanf("%d", &n);
		if (n < 0) {
			break;
		}
		original_arr = makeRnadArray(n);
		printf("\n");

		// Seletion Sort
		printf("Seletion Sort\n");
		copy_arr = copyArray(original_arr, n);

		start = clock();
		selectionSort(copy_arr, n);
		end = clock();
		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Insertion Sort
		printf("Insertion Sort\n");
		copy_arr = copyArray(original_arr, n);

		start = clock();
		insertionSort(copy_arr, n);
		end = clock();
		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Quick Sort
		printf("Quick Sort\n");
		copy_arr = copyArray(original_arr, n);

		start = clock();
		quickSort(copy_arr, 0, n - 1);
		end = clock();
		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);


		// End
		free(original_arr);
	}
	printf("\n\n\n");


	// Ascending Case
	for (;;) {
		printf("Ascending Case==========================\n");
		printf("Enter the array's size : ");
		scanf("%d", &n);
		if (n < 0) {
			break;
		}
		original_arr = makeAscendingArray(n);
		printf("\n");

		// Seletion Sort
		printf("Seletion Sort\n");
		copy_arr = copyArray(original_arr, n);

		start = clock();
		selectionSort(copy_arr, n);
		end = clock();
		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Insertion Sort
		printf("Insertion Sort\n");
		copy_arr = copyArray(original_arr, n);

		start = clock();
		insertionSort(copy_arr, n);
		end = clock();
		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Quick Sort
		printf("Quick Sort\n");
		copy_arr = copyArray(original_arr, n);

		start = clock();
		quickSort(copy_arr, 0, n - 1);
		end = clock();
		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// End
		free(original_arr);
	}
	printf("\n\n\n");


	// Descending Case
	for (;;) {
		printf("Descending Case=========================\n");
		printf("Enter the array's size : ");
		scanf("%d", &n);
		if (n < 0) {
			break;
		}
		original_arr = makeDescendingArray(n);
		printf("\n");

		// Seletion Sort
		printf("Seletion Sort\n");
		copy_arr = copyArray(original_arr, n);

		start = clock();
		selectionSort(copy_arr, n);
		end = clock();
		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Insertion Sort
		printf("Insertion Sort\n");
		copy_arr = copyArray(original_arr, n);

		start = clock();
		insertionSort(copy_arr, n);
		end = clock();
		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Quick Sort
		printf("Quick Sort\n");
		copy_arr = copyArray(original_arr, n);

		start = clock();
		quickSort(copy_arr, 0, n - 1);
		end = clock();
		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);



		// End
		free(original_arr);
	}
	printf("\n");

	return(0);

}

double* makeRnadArray(int n) {
	double* arr = (double*)malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (rand() / (0x7fff * 1.0)) * 100000000;
	}
	return arr;
}

double* makeAscendingArray(int n) {
	double* arr = (double*)malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	return arr;
}

double* makeDescendingArray(int n) {
	double* arr = (double*)malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = n--;
	}
	return arr;
}

double* copyArray(double* arr, int n) {
	double* copy_arr = (double*)malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		copy_arr[i] = arr[i];
	}
	return copy_arr;
}

int sortCheck(double* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			printf("\n");
			printf("arr[%d] = %f arr[%d] = %f\n", i, arr[i], i + 1, arr[i + 1]);
			printf("List : ");
			for (int i = 0; i < n; i++) {
				printf("[%.0f]", arr[i]);
			}
			printf("\n");
			return 0;
		}
	}
	return 1;
}

void selectionSort(double* arr, int n) {
	int min_index;
	double temp;
	for (int i = 0; i < n; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[min_index] > arr[j]) { min_index = j; }
		}
		SWAP(arr[i], arr[min_index], temp);
	}
}

void insertionSort(double* arr, int n) {
	double insert_value;
	for (int i = 1, j; i < n; i++) {
		insert_value = arr[i];
		for (j = i - 1; (j >= 0) && (insert_value < arr[j]); j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = insert_value;
	}
}

void quickSort(double* arr, int left, int right) {

	int l = left + 1, r = right;
	double temp;
	SWAP(arr[left], arr[(left + right) / 2], temp);
	for (; l <= r; l++, r--) {
		for (; (arr[l] <= arr[left]) && (l <= r); l++) {}
		for (; (arr[r] >= arr[left]) && (l <= r); r--) {}
		if (l > r) { break; }
		SWAP(arr[l], arr[r], temp);
	}
	SWAP(arr[left], arr[r], temp);
	if (left < r - 1) { quickSort(arr, left, r - 1); }
	if (r + 1 < right) { quickSort(arr, r + 1, right); }

}
