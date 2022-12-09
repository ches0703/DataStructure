#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrayShow(double arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%.4lf ", arr[i]);
    }
    printf("\n");
}
void swap(double* a, double* b) {
    double temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}
void idxSwap(int* a, int* b) {
    int temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}
void selectionSort(double arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        double min = INT_MAX;
        int idx;
        for (j = i; j < n; j++) {
            if (min > arr[j]) {
                min = arr[j];
                idx = j;
            }
        }
        swap(&arr[i], &arr[idx]);
    }
}
void insertionSort(double arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        j = i;
        while (j >= 0 && arr[j] > arr[j + 1]) {
            swap(&arr[j], &arr[j + 1]);
            j--;
        }
    }
}
void quickSort(double arr[], int left, int right) {
    int mid = (left + right) / 2;
    double pivot = arr[mid];
    int low = left;
    int high = right;

    while (low <= high) {
        while (pivot > arr[low] && low <= right) // pivot보다 작은 값 찾을 때까지. 
            low++;

        while (pivot < arr[high] && high >= (left + 1)) // pivot보다 큰 값 찾을 때까지. 
            high--;

        if (low <= high) {
            if (low != high)
                swap(&arr[low], &arr[high]);
            low++; high--;
        }
    }
    //   int i;
    //    for (i = 0; i < n; i++) { //데이터 확인 부분.
    //        printf("%.4lf ", arr[i]);
    //      }
    //      printf("\n");
    if (left < high)
        quickSort(arr, left, high);
    if (low < right)
        quickSort(arr, low, right);
}

int isSorted(double arr[], int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}
int main(void)
{
    double* arr, * copied;
    int i, n;
    printf("Input Number >>> ");
    scanf("%d", &n);

    arr = (double*)malloc(sizeof(double) * n);
    copied = (double*)malloc(sizeof(double) * n);

    srand((unsigned)time(NULL));
    for (i = 0; i < n; i++) {
        //      arr[i]=(rand()/(0x7fff*1.0))*100000000;
        arr[i] = rand() % 100;
    }
    clock_t start, end;

    /////////////////무작위의 데이터 대입(평균적인 경우)////////////////////////////////      
    for (i = 0; i < n; i++) {
        copied[i] = arr[i];
    }
    start = clock();
    selectionSort(copied, n);
    end = clock();
    printf("Selection Sort Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    if (isSorted(copied, n) == 1)
        printf("Selection Sort Done\n");
    else
        printf("Selection Sort Fail\n");
    printf("\n");

    for (i = 0; i < n; i++) {
        copied[i] = arr[i];
    }
    start = clock();
    insertionSort(copied, n);
    end = clock();
    printf("Insertion Sort Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    if (isSorted(copied, n) == 1)
        printf("Insertion Sort Done\n");
    else
        printf("Insertion Sort Fail\n");
    printf("\n");

    for (i = 0; i < n; i++) {
        copied[i] = arr[i];
    }
    start = clock();
    quickSort(copied, 0, n - 1);
    end = clock();
    printf("Quick Sort Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    if (isSorted(copied, n) == 1)
        printf("Quick Sort Done\n");
    else
        printf("Quick Sort Fail\n");
    printf("\n");
    ///////////////////오름차순된 데이터 대입(최선의 경우)////////////////////////////////      
    for (i = 0; i < n; i++) {
        arr[i] = i;
    }
    for (i = 0; i < n; i++) {
        copied[i] = arr[i];
    }
    start = clock();
    selectionSort(copied, n);
    end = clock();
    printf("Selection Sort Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    if (isSorted(copied, n) == 1)
        printf("Selection Sort Done\n");
    else
        printf("Selection Sort Fail\n");
    printf("\n");

    for (i = 0; i < n; i++) {
        copied[i] = arr[i];
    }
    start = clock();
    insertionSort(copied, n);
    end = clock();
    printf("Insertion Sort Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    if (isSorted(copied, n) == 1)
        printf("Insertion Sort Done\n");
    else
        printf("Insertion Sort Fail\n");
    printf("\n");

    for (i = 0; i < n; i++) {
        copied[i] = arr[i];
    }
    start = clock();
    quickSort(copied, 0, n - 1);
    end = clock();
    printf("Quick Sort Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    if (isSorted(copied, n) == 1)
        printf("Quick Sort Done\n");
    else
        printf("Quick Sort Fail\n");
    printf("\n");
    /////////////////////내림차순된 데이터 대입(최악의 경우)////////////////////////////////
    for (i = 0; i < n; i++) {
        arr[i] = n - i - 1;
    }
    for (i = 0; i < n; i++) {
        copied[i] = arr[i];
    }
    start = clock();
    selectionSort(copied, n);
    end = clock();
    printf("Selection Sort Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    if (isSorted(copied, n) == 1)
        printf("Selection Sort Done\n");
    else
        printf("Selection Sort Fail\n");
    printf("\n");

    for (i = 0; i < n; i++) {
        copied[i] = arr[i];
    }
    start = clock();
    insertionSort(copied, n);
    end = clock();
    printf("Insertion Sort Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    if (isSorted(copied, n) == 1)
        printf("Insertion Sort Done\n");
    else
        printf("Insertion Sort Fail\n");
    printf("\n");

    for (i = 0; i < n; i++) {
        copied[i] = arr[i];
    }
    start = clock();
    quickSort(copied, 0, n - 1);
    end = clock();
    printf("Quick Sort Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    if (isSorted(copied, n) == 1)
        printf("Quick Sort Done\n");
    else
        printf("Quick Sort Fail\n");
    printf("\n");

    system("pause");
}