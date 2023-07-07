#include <stdio.h>
#include <stdlib.h>

void getMatrixSize(int * r, int * c);
void initEmptyMatrix(int r, int c, int ** matrix);
int ** getMatrixElements(int r, int c);
void checkValidMatrices(int cA, int rB);
int ** multiplyMatrices(int cA, int cB, int rA, int ** matrixA, int ** matrixB);
void printMatrix(int r, int c, int ** matrix);

int main(void) {
	int rA = 0;
	int rB = 0;
	int cA = 0;
	int cB = 0;
	int ** matrixA;
	int ** matrixB;
	int ** multiplied;
	
	printf("matrix A values\n");
	getMatrixSize(&rA, &cA);
	printf("size of matrix A is %dx%d\n", rA, cA);
	matrixA = getMatrixElements(rA, cA);
	printf("here is matrix A\n");
	printMatrix(rA, cA, matrixA);

	printf("matrix B values\n");
	getMatrixSize(&rB, &cB);
	printf("size of matrix B is %dx%d\n", rB, cB);
	matrixB = getMatrixElements(rB, cB);
	printf("here is matrix B\n");
	printMatrix(rB, cB, matrixB);

	checkValidMatrices(cA, rB);
	
	printf("multiplied matrix is\n");
	multiplied = multiplyMatrices(cA, cB, rA, matrixA, matrixB);
	printMatrix(rA, cB, multiplied);
	

}

void getMatrixSize(int * r, int * c) {	
	//get sizes of matrix from user
	printf("enter the amount of rows\n");
	scanf("%d", r);

	printf("enter the amount of columns\n");
	scanf("%d", c);
}

void checkValidMatrices(int cA, int rB) {
	if (cA != rB) {
		printf("invalid matrix sizes (matrix A's column amount must be equal to matrix B's row amount)\n");
		exit(-1);
	}
}

int ** getMatrixElements(int r, int c) {
	int i;
	int j;
	
	//init empty matrix
	int ** matrix = (int**)malloc(r * sizeof(int*));
	for (i = 0; i < r; i++) {
		matrix[i] = (int*)malloc(c * sizeof(int));
	}
	
	//fill with user values
	printf("enter the elements of your matrix\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	return matrix;
}

void printMatrix(int r, int c, int ** matrix) {
	int i;
	int j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int ** multiplyMatrices(int cA, int cB, int rA, int ** matrixA, int ** matrixB) {
	int i;
	int j;
	int k;
	
	//init empty matrix
	int ** multiplied = (int**)malloc(rA * sizeof(int*));
	for (i = 0; i < rA; i++) {
		multiplied[i] = (int*)malloc(cB * sizeof(int));
	}

	//multiplication
	for(i = 0; i < rA; i++) {
		for(j = 0; j < cB; j++) {
			multiplied[i][j] = 0; 
			for(k = 0; k < cA; k++) {
				multiplied[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
	return multiplied;
}
