#include <iostream>
#include <cstdlib>

using namespace std;

/*System of equations we are solving is:
4x - 3y + z = - 10
2x + y + 3z = 0
- x + 2y - 5z = 17

and the solution is (x, y, z) = (1, 4, - 2).
*/

void printMatrix(int myMatrix[3][4]);
void RowReduce(int A[][4]);
void addMatrices(int A[3][4], int B[3][4]);

int main() {

	int matrix1[3][4] = { { 4, -3, 1, -10 },
						 { 2, 1,  3, 0 },
						 { -1,  2, -5, 17 } };

	int matrix2[3][4] = { { 1, 8, -8, 2 },
						  { 3, 1,  6, 11 },
						  { 4, 6, 3, -9 } };
	
	addMatrices(matrix1, matrix2);

	printMatrix(matrix1);
	RowReduce(matrix1);

	system("pause");
	return 0;
}

void addMatrices(int A[3][4], int B[3][4]) {
	int row = 3;
	int col = 4;
	int resultantMatrix[3][4] = { {} };

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			resultantMatrix[i][j] = A[i][j] + B[i][j];
		}
	}

	printMatrix(resultantMatrix);
	cout << endl;
}

void printMatrix(int myMatrix[3][4]) {
	int p = 3; //number of rows
	int q = 4; //number of columns

	for (int i = 0; i < p; i++) {
		for (int j = 0; j < q; j++) {
			cout << myMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

void RowReduce(int myMatrix[][4])
{
	const int row = 3;
	const int col = 4; 

	int pivot = 0;

	while (pivot < row) {
		float divisor, multiplier;

		for (int r = 0; r < row; r++) { 
			divisor = myMatrix[pivot][pivot];
			multiplier = myMatrix[r][pivot] / myMatrix[pivot][pivot];

			for (int c = 0; c < col; c++) { 
				if (r == pivot)
					myMatrix[r][c] /= divisor; 
				else
					myMatrix[r][c] -= myMatrix[pivot][c] * multiplier;
			}
			cout << endl;
		}

		pivot++;
		printMatrix(myMatrix);
	}
}