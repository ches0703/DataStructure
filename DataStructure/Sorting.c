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

double mergeSort(double* arr, int n);

void merge(double* arr, double* extra_arr, int l_start, int l_end, int r_end);
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

		// Merge Sort
		printf("Merge Sort\n");
		copy_arr = copyArray(original_arr, n);
		duration = mergeSort(copy_arr, n);
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
	if ((left >= right)) { return 0; }
	clock_t start, end;
	start = clock();
	int l = left + 1, r = right;
	int pivot = left;
	double temp;
	SWAP(arr[left], arr[(left + right) / 2], temp);
	for (; l <= r;) {
		if (arr[pivot] > arr[l]) {
			l++;
		}
		else {
			SWAP(arr[r], arr[l], temp);
			r--;
		}
	}
	SWAP(arr[pivot], arr[r], temp);
	quickSort(arr, left, r - 1);
	quickSort(arr, r + 1, right);
	end = clock();
	return (double)(end - start) / 1000;
}

double mergeSort(double* arr, int n) {
	clock_t start, end;
	start = clock();
	double* extra_arr = (int*)malloc(sizeof(int) * n);
	double* temp;
	int part_size = 2;
	int l_start;
	int l_end;
	int r_end;
	for (; part_size < n; part_size *= 2) {
		for (l_start = 0; l_start + (part_size * 2) - 1 < n; l_start += part_size * 2) {
			printf("/");
			l_end = l_start + part_size - 1;
			r_end = l_end + part_size;
			merge(arr, extra_arr, l_start, l_end, r_end);
		}
		merge(arr, extra_arr, l_start, l_end, n - 1);
		SWAP(arr, extra_arr, temp);
	}
	free(extra_arr);
	end = clock();
	return (double)(end - start) / 1000;
}

void merge(double* arr, double* extra_arr, int l_start, int l_end, int r_end) {
	int r_start = l_end + 1;
	int l = l_start, r = r_start;
	for (int i = l_start; (l <= l_end) && (r <= r_end); i++) {
		if (arr[l] < arr[r]) {
			extra_arr[i] = arr[l++];
		}
		else {
			extra_arr[i] = arr[r++];
		}
	}
	for (int i = l; i <= l_end; i++) {
		extra_arr[i] = arr[l++];
	}
	for (int i = r; i <= r_end; i++) {
		extra_arr[i] = arr[r++];
	}
}