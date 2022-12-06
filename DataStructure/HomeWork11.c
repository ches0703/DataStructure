#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_COST 99999


void printGrape(int** G, int n);				// Graph의 cost에 대한 정보를 표 형태로 출력
void shortestPath(int** G, int n, int node);	// 특정 노드의 각 노드간의 최소 cost들을 출력
void allCosts(int** G, int n);					// 모든 노드의 최소 cost 계산

int main()
{

	int** G;	// Graph
	int n;		// 노드의 수
	int start;	// start vertex's num
	int end;	// end vertex's num
	int cost;	// Edge's cost(weight)

	for (;;) {
		// 11.1. 인접 행렬 형태의 방향성 그래프 생성
		printf("11.1. 인접 행렬 형태의 방향성 그래프 생성\n");
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

		// 인접 행렬을 이용한 그래프의 구성 :
		printf("\n인접 행렬을 이용한 그래프의 구성 :\n");
		printGrape(G, n);

		// 11.2. 최단 경로 (단일 출발점) :
		printf("\n11.2. 최단 경로 (단일 출발점)\n");
		for (;;) {
			printf("Enter the start node : ");
			scanf("%d", &start);
			if (start < 0) {
				break;
			}
			shortestPath(G, n, start);
		}

		// 11.3. 최단 경로 (모든 경로)
		printf("\n11.3. 최단 경로 (모든 경로)\n");
		allCosts(G, n);
		printGrape(G, n);

		// Graph 동적 할당 해제
		for (int i = 0; i < n; i++) {
			free(G[i]);
		}
		free(G);
	}
}

// Graph의 cost에 대한 정보를 표 형태로 출력
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

// 특정 노드의 각 노드간의 최소 cost들을 출력
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

// 모든 노드의 최소 cost 계산
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