#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LIST_SIZE 1000000
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 

void reverse_list_make(int list[], int n);
void print_list(int list[], int n);
void sort(int list[], int n, double* duration);
void is_sorted(int list[], int n);

int main()
{
	srand((unsigned)time(NULL));

	int list[LIST_SIZE];
	double duration;

	// 1.1 ������ 100,000�� ���� ���� �� ����, ���� �˻� ����
	/*printf("1.1. ���� ���� �迭(100,000 ~ 0) ���� �� ����, ���� �˻� ����\n");

	printf("1.1.1. ���� �迭 ���� : ");
	reverse_list_make(list, 100000);
	printf("���� �Ϸ�\n");

	printf("1.1.2. �迭 ���� : ");

	sort(list, 100000, &duration);

	printf("���Ŀ� �ɸ� �ð� : %f\n", duration);

	printf("1.1.3. ���� ���� : ");
	is_sorted(list, 100000);

	printf("�迭 ��� :\n");
	print_list(list, 100000);*/

	// 1.2 n�� ũ�⸦ 100���� 1,000,000���� �ٲٸ鼭 sort �Լ��� ���� �ð��� �����Ͽ� �������� ���

	// n = 100 ����
	printf("n\t time\t sort\n");
	for (int i = 0; i < 10; i++) {
		int n_size = 10;
		printf("%7d", i * n_size);
		reverse_list_make(list, i * n_size);
		sort(list, i * n_size, &duration);
		printf("   %7.2f\t", duration);
		is_sorted(list, i * n_size);
	}
	for (int i = 0; i < 10; i++) {
		int n_size = 100;
		printf("%7d", i * n_size);
		reverse_list_make(list, i * n_size);
		sort(list, i * n_size, &duration);
		printf("   %7.2f\t", duration);
		is_sorted(list, i * n_size);
	}
	for (int i = 0; i < 10; i++) {
		int n_size = 1000;
		printf("%7d", i * n_size);
		reverse_list_make(list, i * n_size);
		sort(list, i * n_size, &duration);
		printf("   %7.2f\t", duration);
		is_sorted(list, i * n_size);
	}
	for (int i = 0; i < 10; i++) {
		int n_size = 10000;
		printf("%7d", i * n_size);
		reverse_list_make(list, i * n_size);
		sort(list, i * n_size, &duration);
		printf("   %7.2f\t", duration);
		is_sorted(list, i * n_size);
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
	printf("\n-----�迭 ��� �Ϸ�------\n");
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
				printf("���� �ȵ�\n");
				return;
			}
		}
	}
	printf("���� ��\n");
	return;
}