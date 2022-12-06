#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_COST 99999


void printGrape(int** G, int n);				// Graph�� cost�� ���� ������ ǥ ���·� ���
void shortestPath(int** G, int n, int node);	// Ư�� ����� �� ��尣�� �ּ� cost���� ���
void allCosts(int** G, int n);					// ��� ����� �ּ� cost ���

int main()
{

	int** G;	// Graph
	int n;		// ����� ��
	int start;	// start vertex's num
	int end;	// end vertex's num
	int cost;	// Edge's cost(weight)

	for (;;) {
		// 11.1. ���� ��� ������ ���⼺ �׷��� ����
		printf("11.1. ���� ��� ������ ���⼺ �׷��� ����\n");
		printf("Enter the num of node : ");
		scanf("%d", &n);
		if (n < 0) { break; }

		G = (int**)malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++) {
			G[i] = (int*)malloc(sizeof(int) * n);
			for (int j = 0; j < n; j++) {
				G[i][j] = MAX_COST;
			}
			G[i][i] = 0;
		}

		for (;;) {
			printf("Enter the Edge's data : ");
			scanf("%d %d %d", &start, &end, &cost);
			if ((start < 0) || (end < 0) || (cost < 0)) {
				break;
			}
			G[start][end] = cost;
		}

		// ���� ����� �̿��� �׷����� ���� :
		printf("\n���� ����� �̿��� �׷����� ���� :\n");
		printGrape(G, n);

		// 11.2. �ִ� ��� (���� �����) :
		printf("\n11.2. �ִ� ��� (���� �����)\n");
		for (;;) {
			printf("Enter the start node : ");
			scanf("%d", &start);
			if (start < 0) {
				break;
			}
			shortestPath(G, n, start);
		}

		// 11.3. �ִ� ��� (��� ���)
		printf("\n11.3. �ִ� ��� (��� ���)\n");
		allCosts(G, n);
		printGrape(G, n);

		// Graph ���� �Ҵ� ����
		for (int i = 0; i < n; i++) {
			free(G[i]);
		}
		free(G);
	}
}

// Graph�� cost�� ���� ������ ǥ ���·� ���
void printGrape(int**G, int n) {
	printf("Graph : \n");
	printf("        | ");
	for (int i = 0; i < n; i++) {
		printf("[%5d] ", i);
	}
	printf("\n---------");
	for (int i = 0; i < n; i++) {
		printf("--------", i);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("[%5d] | ", i);
		for (int j = 0; j < n; j++) {
			printf("[%5d] ", G[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// Ư�� ����� �� ��尣�� �ּ� cost���� ���
void shortestPath(int** G, int n, int node) {

	int* found = (int*)malloc(sizeof(int) * n);
	int* distance = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		found[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		distance[i] = G[node][i];
	}
	found[node] = 1;
	distance[node] = 0;

	for (int i = 0; i < n; i++) {
		int min = MAX_COST;
		int min_pos = -1;
		for (int j = 0; j < n; j++) {
			if (distance[j] < min && !found[j]) {
				min = distance[j];
				min_pos = j;
			}
		}
		if (min_pos < 0) { continue; }
		found[min_pos] = 1;
		for (int k = 0; k < n; k++) {
			if (!found[k]) {
				if (distance[min_pos] + G[min_pos][k] < distance[k]) {
					distance[k] = distance[min_pos] + G[min_pos][k];
				}
			}
		}
	}
	printf("Distance : ");
	for (int i = 0; i < n; i++) {
		printf("[%5d] ", distance[i]);
	}
	printf("\n");
	free(found);
	free(distance);
}

// ��� ����� �ּ� cost ���
void allCosts(int** G, int n) {
	// All costs
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (G[j][i] + G[i][k] < G[j][k]) {
					G[j][k] = G[j][i] + G[i][k];
				}
			}
		}
	}
}