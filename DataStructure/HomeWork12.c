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
double quickSort(double* arr, int n, int left, int right);

int main()
{
	srand((unsigned)time(NULL));

	double duration;
	int n;
	n = 10;
	double* original_arr = makeRnadArray(n);
	double* copy_arr = copyArray(original_arr, n);

	printArray(original_arr, n);
	duration = quickSort(original_arr, n, 0, n - 1);

	printf("duration : %f\n", duration);
	printArray(original_arr, n);
	


}
void printArray(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("[%.3f]", arr[i]);
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

double quickSort(double* arr, int n, int left, int right) {
	if (left >= right) { printf("Return\n");  return 0; }
	printf("n = %d, left = %d, right = %d\n", n, left, right);
	clock_t start, end;
	double standard = arr[left + right / 2];
	double temp;
	start = clock();
	int l, r;
	int s;
	printf("stadard = %.3f\n", standard);
	for (l = left, r = right; (l < r) && (l < n);) {


		printf("left = %d, right = %d\n", l, r);
		printArray(arr, n);
		scanf("%d", &s);
		if (arr[l] < standard) {
			l++;
			continue;
		}
		if (arr[r] > standard) {
			r--;
			continue;
		}
		if (arr[l] >= standard) {
			printf("l[%.3f] <-> [%.3f]\n", arr[l], arr[r]);
			SWAP(arr[l], arr[r], temp);
			l++; r--;
		}

		

		/*
		if (arr[i] < arr[standard]) {
			
			printf("l[%.3f] <-> [%.3f]\n", arr[i], arr[l]);
			SWAP(arr[i], arr[l], temp);
			l++;

		}
		else {
			for (; arr[r] >= arr[standard]; r--) { ; }
			printf("r[%.3f] <-> [%.3f]\n", arr[i], arr[r]);
						r--;
		}
		*/
	}
	printf("Soting end\n");
	printArray(arr, n);

	printf("Left part : ");
	printf("n = %d, left = %d, right = %d\n", l, left, l - 1);

	printf("Right part : ");
	printf("n = %d, left = %d, right = %d\n", n - r, l, right);

	quickSort(arr, l, left, l - 1);
	quickSort(arr, n - r - 1, l, right);
	end = clock();
	return (double)(end - start) / 1000;
}