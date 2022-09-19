#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LIST_SIZE 1000000
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 
#define compare(x,y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)


void reverse_list_make(int list[], int n);
void print_list(int list[], int n);
void sort(int list[], int n, double* duration);
void is_sorted(int list[], int n);
int binsearch(int list[], int searchnum, int left, int right, int *search_count);
int main()
{

	srand((unsigned)time(NULL));

	int list[LIST_SIZE];
	double duration;
	int search_data;
	int search_count = 0;

	// 1.1 1 ~ 100,000의 정수로 이루어진 역순정렬된 배열 생성 및 정렬, 정렬 검사 수행

	//printf("1.1. 역순 정렬 배열(100,000 ~ 0) 생성 및 정렬, 정렬 검사 수행\n");

	//printf("1.1.1. 역순 배열 생성 : ");
	//reverse_list_make(list, 100000);
	//printf("생성 완료\n");

	//printf("1.1.2. 배열 정렬 : ");
	//sort(list, 100000, &duration);
	//printf("정렬 완료\n");

	//printf("정렬에 걸린 시간 : %.4fs\n", duration/1000);

	//printf("1.1.3. 정렬 상태 : ");
	//is_sorted(list, 100000);

	//printf("배열 출력 :\n");
	//print_list(list, 100000);

	// 1.2 역순 정렬된 배열의 크기를 100부터 1,000,000까지 바꾸면서 sort 함수의 실행 시간을 측정하여 관찰지에 기록
	
	/*printf("1.2 역순 정렬된 배열의 크기를 100부터 1,000,000까지 바꾸면서 sort 함수의 실행 시간을 측정하여 관찰지에 기록\n");
	printf("      n        time\t   sort\n");
	for (int i = 0; i < 6;i++) {
		int n;
		switch (i)
		{
		case 0:
			reverse_list_make(list, 0);
			sort(list, 0, &duration);
			printf("%7d %10.4fs     ", 0, duration/1000);
			is_sorted(list, 0);
			n = 10;
			break;
		case 1:
			n = 100;
			break;
		case 2:
			n = 1000;
			break;
		case 3:
			n = 10000;
			break;
		case 4:
			n = 100000;
			break;
		case 5:
			n = 1000000;
			break;
		default:
			return 0;
		}
		if (i != 5){
			for (int j = 1; j < 10; j++) {
				reverse_list_make(list, n * j);
				sort(list, n * j, &duration);
				printf("%7d %10.4fs     ", n * j, duration/1000);
				is_sorted(list, n * j);
			}
		}
		else {
			reverse_list_make(list, n);
			sort(list, n, &duration);
			printf("%7d %10.4fs     ", n, duration / 1000);
			is_sorted(list, n);
		}
		
	}*/

	// 1.3 역순 정렬 배열(100,000 ~ 0) 생성 및 정렬, 이진검색 수행

	printf("1.3. 역순 정렬 배열(100,000 ~ 0) 생성 및 정렬, 이진검색 수행\n");

	printf("1.3.1. 역순 배열 생성 : ");
	reverse_list_make(list, 100000);
	printf("생성 완료\n");

	printf("1.3.2. 배열 정렬 : ");
	sort(list, 100000, &duration);
	printf("정렬 완료\n");

	printf("정렬에 걸린 시간 : %.4fs\n", duration/1000);

	printf("1.3.3. 정렬 상태 : ");
	is_sorted(list, 100000);
	


	for (;;){
		printf("검색 데이터( 1 ~ 100000 ) : ");
		scanf("%d", &search_data);
		if (search_data == -1) {
			printf("검색 종료");
			break;
		}
		printf("검색 데이터 : %6d\t Counter : %d\n",list[binsearch(list, search_data, 0, 100000-1, &search_count)],search_count);
	}

	return 0;


}
void reverse_list_make(int list[], int n) {
	for (int i = 0; i < n; i++) {
		list[i] = n - i;
	}
}
void print_list(int list[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%7d ", list[i]);
	}
	printf("\n-----배열 출력 완료------\n");
}
void sort(int list[], int n, double* duration) {
	int i, j, min, temp;
	clock_t start, stop;
	start = clock();
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);

	}
	stop = clock();
	*duration = (double)(stop - start);
}
void is_sorted(int list[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (list[i] > list[j]) {
				printf("정렬 안됨\n");
				return;
			}
		}
	}
	printf("정렬 됨\n");
	return;
}
int binsearch(int list[], int searchnum, int left, int right, int *search_count) {
	int middle;
	*search_count = 0;
	while (left <= right) {
		(*search_count)++;
		middle = (left + right) / 2;
		switch (compare(list[middle], searchnum)) {
		case  -1: left = middle + 1;
			break;
		case   0: return middle;
		case   1: right = middle - 1;
		}
	}
	return -1;
}

