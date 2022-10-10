#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COL  50         /*  maximum number of column + 1 */
#define MAX_TERMS 101
#define COMPARE(x, y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)

typedef struct {
	int	row;
	int	col;
	int	value;
} term;
typedef enum shape { SPARSE, MATRIX } printShape;

void printMatrix(term t[], printShape shape, char* title)
{
	int n = t[0].value;
	int i, len;
	char* line = "---------------", tLine[32];

	len = strlen(line);
	sprintf(tLine, "%s: %s", title, line);

	if (shape == SPARSE)	// 희소행렬 형태로 출력
	{
		printf("%.*s\n", len, tLine);
		for (i = 0; i <= n; i++)
			printf("%2d | %d, %d, %d\n", i, t[i].row, t[i].col, t[i].value);
		printf("%s\n", line);
	}
	else if (shape == MATRIX)  // 일반 행렬 형태로 출력
	{
		int j, p = 1;
		printf("%s:\n", title);
		for (i = 0; i < t[0].row; i++)
		{
			for (j = 0; j < t[0].col; j++)
				if (t[p].row == i && t[p].col == j)
					printf("%4d", t[p++].value);
				else
					printf("%4d", 0);
			printf("\n");
		}
		printf("\n");
	}
}

void fast_transpose(term a[], term b[])
{
	/*  the transpose of a is placed in b */
	int  row_terms[MAX_COL], starting_pos[MAX_COL];
	int  i, j, num_cols = a[0].col, num_terms = a[0].value;
	b[0].row = num_cols; b[0].col = a[0].row;
	b[0].value = num_terms;
	if (num_terms > 0)     /*  nonzero matrix  */
	{
		for (i = 0; i < num_cols; i++)
			row_terms[i] = 0;
		for (i = 1; i <= num_terms; i++)
			row_terms[a[i].col]++;
		starting_pos[0] = 1;
		for (i = 1; i < num_cols; i++)
			starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
		for (i = 1; i <= num_terms; i++)
		{
			j = starting_pos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}

void storesum(term d[], int* totald, int row, int column, int* sum)
{
	/* if *sum != 0, then it along with its row and column
	position is stored as the *totald+1 entry in d */
	if (*sum)
		if (*totald < MAX_TERMS)
		{
			d[++ * totald].row = row;
			d[*totald].col = column;
			d[*totald].value = *sum;
			*sum = 0;
		}
		else
		{
			fprintf(stderr, "Numbers of terms in product exceeds %d\n", MAX_TERMS);
			return;
		}
}

void mMult(term a[], term b[], term d[])
{	// multiply two sparse matrics
	int i, j, column, totald = 0;
	int rows_a = a[0].row, cols_a = a[0].col, totala = a[0].value;
	int cols_b = b[0].col, totalb = b[0].value;
	int row_begin = 1, row = a[1].row, sum = 0;
	term newB[MAX_TERMS];
	if (cols_a != b[0].row) {
		fprintf(stderr, "Incompatible matricses for MMult\n");
		exit(0);
	}
	fast_transpose(b, newB);

	/* set boundary condition */
	a[totala + 1].row = rows_a;
	newB[totalb + 1].row = cols_b;
	newB[totalb + 1].col = 0;

	for (i = 1; i <= totala; )
	{
		column = newB[1].row;
		for (j = 1; j <= totalb + 1; )
		{
			if (newB[j].row == newB[0].row) {
				break;
			}
			else if (a[i].row != row)
			{
				storesum(d, &totald, row, column, &sum);
				i = row_begin;
				for (; newB[j].row == column; j++)
					;
				column = newB[j].row;
			}
			else if (newB[j].row != column)
			{
				storesum(d, &totald, row, column, &sum);
				i = row_begin;
				column = newB[j].row;
			}
			else switch (COMPARE(a[i].col, newB[j].col))
			{
			case -1: /* go to next term in a */
				i++;
				break;
			case 0:
				/* add terms, go to next term in a and b */
				sum += (a[i++].value * newB[j++].value);
				break;
			case 1: /* advance to next term in b */
				j++;
			}
		} // end of J <= totalb+1
		for (; a[i].row == row; i++)
			;
		row_begin = i;
		row = a[i].row;
	} /* end of for I <= totala */
	d[0].row = rows_a;
	d[0].col = cols_b;
	d[0].value = totald;
}

void mAdd(term a[], term b[], term d[])
{	
	// 행렬의 끝을 표시하기위해 배열의 끝의 row값에 배열의 row값을 대입
	a[a[0].value + 1].row = a[a[0].value].row + 1;
	b[b[0].value + 1].row = b[b[0].value].row + 1;

	// 행렬의 합 조건 : 각 행렬의 row, col 값이 동일 하여야 함
	if ((a[0].row != b[0].row) || (a[0].col != b[0].col)) {
		fprintf(stderr, "Incompatible matricses for MAdd\n");
		exit(0);
	}

	// 희소행렬 표현 배열의 요소를 카르키는 인덱스
	int index_a = 1;
	int index_b = 1;

	// d의 초기설정 : d의 row와 col값은 a나 b와 같음(행렬 합 조건에 의해)
	d[0].row = a[0].row;
	d[0].col = a[0].col;
	d[0].value = 0;

	// i는 d의 index value
	for (int i = 1;; i++) {
		// d에 a의 값이 다 적용되고 b의 값이 남아있는경우
		if (a[index_a].row == a[0].row) {
			for (; b[index_b].row != b[0].row;) {
				d[i] = b[index_b++];
				d[0].value++;
			}
			break;
		}
		// d에 b의 값이 다 적용되고 a의 값이 남아있는경우
		else if (b[index_b].row == b[0].row) {
			for (; a[index_a].row != a[0].row;) {
				d[i] = a[index_a++];
				d[0].value++;
			}
			break;
		}
		else {
			// a 와 b의 row값 비교 :
			switch (COMPARE(a[index_a].row, b[index_b].row)) {
			case -1: // b.row > a.row -> insert a
				d[i] = a[index_a++];
				break;
			case 0:
				// a 와 b의 col값 비교 :
				switch (COMPARE(a[index_a].col, b[index_b].col)) {
				case -1: // b.col > a.col -> insert a
					d[i] = a[index_a++];
					break;
				case 0: // a와 b의 row & col 값이 같으므로 합산
					d[i].row = a[index_a].row;
					d[i].col = a[index_a].col;
					d[i].value = a[index_a++].value + b[index_b++].value;
					break;
				case 1: // b.col < a.col -> insert b
					d[i] = b[index_b++];
					break;
				}
				break;
			case 1: // b.row < a.row -> insert b
				d[i] = b[index_b++];
				break;
			}
			d[0].value++;
		}
	}


}

void main()
{
	term d[MAX_TERMS];
	term a[MAX_TERMS] = { {6,6,8},
				{0,0,15},
				{0,3,22},
				{0,5,-15},
				{1,1,11},
				{1,2,3},
				{2,3,-6},
				{4,0,91},
				{5,2,28} };
	term b[MAX_TERMS] = { {6,2,5},
				{0,0,1},
				{1,1,1},
				{2,0,3},
				{3,1,1},
				{4,0,2} };

	printf("\n***** Sparse Matrix Multiplication *****\n");
	/* Debug */printMatrix(a, SPARSE, "A");		 // SPARSE: 희소 행렬 형태로 출력
	/* Debug */printMatrix(b, SPARSE, "B");
	mMult(a, b, d);
	/* Debug */printMatrix(d, SPARSE, "D=AxB");
	/* Debug */printMatrix(d, MATRIX, "D=AxB");	 // MATRIX: 일반 행렬 형태로 출력

	printf("\n***** Sparse Matrix Addition *****\n");
	fast_transpose(a, b);	// b행렬을 a를 전치하여 생성
	/* Debug */printMatrix(a, SPARSE, "A");
	/* Debug */printMatrix(b, SPARSE, "B=A.T");
	mAdd(a, b, d);
	/* Debug */printMatrix(d, SPARSE, "D=A+B");
	/* Debug */printMatrix(d, MATRIX, "D=A+B");
}