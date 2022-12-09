#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 
int count = 0;

// Make Array
double* makeRnadArray(int n);
double* makeAscendingArray(int n);
double* makeDescendingArray(int n);

// Copy Array : return copy array
double* copyArray(double* arr, int n);

// Sort Check : Sorted -> return 1, Else -> return 0
int sortCheck(double* arr, int n);

// Sort Algorithm
double selectionSort(double* arr, int n);
double insertionSort(double* arr, int n);
double quickSort(double* arr, int left, int right);

int main()
{
	srand((unsigned)time(NULL));
	double* original_arr;
	double* copy_arr;
	double duration;
	int n;

	// Rand case
	printf("Rand Case\n");
	printf("========================================\n");
	for (;;) {
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
		duration = selectionSort(copy_arr, n);
		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Insertion Sort
		printf("Insertion Sort\n");
		copy_arr = copyArray(original_arr, n);
		duration = insertionSort(copy_arr, n);
		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Quick Sort
		printf("Quick Sort\n");
		copy_arr = copyArray(original_arr, n);
		duration = quickSort(copy_arr, 0, n - 1);
		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		free(original_arr);
		printf("========================================\n");
	}
	printf("\n\n\n");


	// Ascending Case
	printf("Ascending Case\n");
	printf("========================================\n");
	for (;;) {
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
		duration = selectionSort(copy_arr, n);
		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Insertion Sort
		printf("Insertion Sort\n");
		copy_arr = copyArray(original_arr, n);
		duration = insertionSort(copy_arr, n);
		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Quick Sort
		printf("Quick Sort\n");
		copy_arr = copyArray(original_arr, n);
		duration = quickSort(copy_arr, 0, n - 1);
		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		free(original_arr);
		printf("========================================\n");
	}
	printf("\n\n\n");

	
	// Descending Case
	printf("Descending Case\n");
	printf("========================================\n");
	for (;;) {
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
		duration = selectionSort(copy_arr, n);
		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Insertion Sort
		printf("Insertion Sort\n");
		copy_arr = copyArray(original_arr, n);
		duration = insertionSort(copy_arr, n);
		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Quick Sort
		printf("Quick Sort\n");
		copy_arr = copyArray(original_arr, n);
		duration = quickSort(copy_arr, 0, n - 1);
		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		free(original_arr);
		printf("========================================\n");
	}
	printf("\n");

	

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
		if (arr[i] > arr[i + 1]) { return 0; }
	}
	return 1;
}


double selectionSort(double* arr, int n) {
	clock_t start, end;
	start = clock();
	int min_index;
	double temp;
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
	start = clock();
	double insert_value;
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
	clock_t start, end;
	start = clock();
	if ((left >= right)) { return 0; }
	int l = left + 1, r = right;
	int pivot = left;
	int new_pivot = left;
	double temp;
	for (; l <= r;) {
		if (arr[pivot] > arr[l]) {
			l++;
			new_pivot++;
		}
		else {
			SWAP(arr[r], arr[l], temp);
			r--;
		}
	}
	SWAP(arr[pivot], arr[new_pivot], temp);
	quickSort(arr, left, new_pivot - 1);
	quickSort(arr, new_pivot + 1, right);
	end = clock();
	return (double)(end - start) / 1000;
}