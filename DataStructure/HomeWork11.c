#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_WEIGHT 99999


void printGrape(int** G, int n);

void allCosts(int** G, int n);

int main()
{

	int** G;
	int n;
	int start;
	int end;
	int cost;
	printf("Enter the num of node : ");
	scanf("%d", &n);

	G = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		G[i] = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) {
			G[i][j] = MAX_WEIGHT;
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


	printGrape(G, n);


	allCosts(G, n);


	printGrape(G, n);

}

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