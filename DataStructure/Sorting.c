#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 

double temp;

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
void mergeSort(double* arr, int n);
void merge(double* arr, double* extra_arr, int l_start, int l_end, int r_end);
void heapSort(double* arr, int n);
void adjust(double* arr, int root, int n);

void printArr(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("[%2.2f] ", arr[i]);
	}
	printf("\n\n");
}

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

		// Merge Sort
		printf("Merge Sort\n");
		copy_arr = copyArray(original_arr, n);

		start = clock();
		mergeSort(copy_arr, n);
		end = clock();
		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Heap sort
		printf("Heap sort\n");
		copy_arr = copyArray(original_arr, n);
		copy_arr[0] = 0;

		start = clock();
		heapSort(copy_arr, n);
		end = clock();
		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));


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

		// Merge Sort
		printf("Merge Sort\n");
		copy_arr = copyArray(original_arr, n);

		start = clock();
		mergeSort(copy_arr, n);
		end = clock();
		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Heap sort
		printf("Heap sort\n");
		copy_arr = copyArray(original_arr, n);
		copy_arr[0] = 0;

		start = clock();
		heapSort(copy_arr, n);
		end = clock();
		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));

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

		// Merge Sort
		printf("Merge Sort\n");
		copy_arr = copyArray(original_arr, n);

		start = clock();
		mergeSort(copy_arr, n);
		end = clock();
		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));
		free(copy_arr);

		// Heap sort
		
		printf("Heap sort\n");
		copy_arr = copyArray(original_arr, n);
		copy_arr[0] = 0;

		start = clock();
		heapSort(copy_arr, n);
		end = clock();

		duration = (double)(end - start) / 1000;

		printf("duration : %10.3f, ", duration);
		printf("Is Sorted? : %s\n\n", (sortCheck(copy_arr, n) ? "True" : "False"));

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
	int j = n;
	double* arr = (double*)malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = j--;
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
			return 0; }
	}
	return 1;
}

void selectionSort(double* arr, int n) {
	int min_index;
	
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

void mergeSort(double* arr, int n) {
	double* temp;
	double* before = arr;
	double* after = (double*)malloc(sizeof(double) * n);
	int part_size, l_start, l_end, r_end;
	for (part_size = 1; part_size < n; part_size *= 2) {
		for (l_start = 0;; l_start += part_size * 2) {
			l_end = l_start + part_size - 1;
			r_end = l_end + part_size;
			if (l_end > n - 1) { l_end = n - 1; }
			if (r_end > n - 1) { r_end = n - 1; }
			merge(before, after, l_start, l_end, r_end);
			if (r_end == n - 1) { break; }
		}
		SWAP(before, after, temp);
	}
	SWAP(before, after, temp);
	if (after != arr) { 
		for (int i = 0; i < n; i++) { arr[i] = after[i]; }
		free(after);
	}
	else { free(before); }
}

void merge(double* arr, double* extra_arr, int l_start, int l_end, int r_end) {
	int r_start = l_end + 1;
	int l = l_start, r = r_start;
	int i = l_start;
	for (; (l <= l_end) && (r <= r_end); i++) {
		if (arr[l] < arr[r]) { extra_arr[i] = arr[l++]; }
		else { extra_arr[i] = arr[r++]; }
	}
	for (; l <= l_end; i++) { extra_arr[i] = arr[l++]; }
	for (; r <= r_end; i++) { extra_arr[i] = arr[r++]; }
}

void heapSort(double* arr, int n) {
	int i, j;
	
	for (i = n / 2; i > 0; i--) {
		adjust(arr, i, n);
	}
	for (i = n - 1; i > 0; i--) {
		SWAP(arr[1], arr[i], temp);
		adjust(arr, 1, i);
	}
}

void adjust(double *arr, int root, int n){	
	int child = 2 * root;
	
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