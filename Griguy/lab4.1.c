// variant 4
#include <stdlib.h>
#include <stdio.h>

#define     WORD_SIZE    64   // settings area  *dangerous field: don't diminish too hard
#define MATRIX_LENGTH    5    // settings area
#define MATRIX_NUMBER    1    // settings area

int main()
{
	int i, j, k, m, case_, diff = 'a' - 'A';
	char ***matrix;

	printf("Size of word: %d\n", WORD_SIZE);    //65 90 97 122
	printf("Words in array: %d\n",MATRIX_LENGTH);
	printf("Number of arrays: %d\n\n", MATRIX_NUMBER);

	matrix = (char***)calloc(MATRIX_NUMBER, sizeof(char**));
	for (i = 0; i < MATRIX_NUMBER; i++) {
		matrix[i] = (char**)calloc(MATRIX_LENGTH, sizeof(char*));
		for (j = 0; j < MATRIX_LENGTH; j++) {
			matrix[i][j] = (char*)calloc(WORD_SIZE, sizeof(char));
		}
	}
	for (i = 0; i < MATRIX_NUMBER; i++) {
		printf("Enter array %d:\n", i+1);
		for (j = 0; j < MATRIX_LENGTH; j++) {
			gets(matrix[i][j]);
		}
		putchar('\n');
	}
//---------------------------------------------------------------------------

	for (i = 0; i < MATRIX_NUMBER; i++) {
		for (j = 0; j < MATRIX_LENGTH; j++) {
			case_= 1;
			k = 0;
			while(matrix[i][j][k]) {
				m = k + 1;
				while (matrix[i][j][m]) {
					if (matrix[i][j][k] == matrix[i][j][m])
						case_ = 0;
					m++;
				}
				k++;
			}

			if (!case_) {
				k = 0;
				while (matrix[i][j][k]) {
					if (matrix[i][j][k] >= 'A' && matrix[i][j][k] <= 'Z') {
						matrix[i][j][k] += diff;
					}
					k++;
				}
			}
			else {
				k = 0;
				while (matrix[i][j][k]) {
					if (matrix[i][j][k] >= 'a' && matrix[i][j][k] <= 'z') {
						matrix[i][j][k] -= diff;
					}
					k++;
				}
			}
		}
	}

//---------------------------------------------------------------------------
	for (i = 0; i < MATRIX_NUMBER; i++) {
		printf("Array %d:\n", i+1);
		for (j = 0; j < MATRIX_LENGTH; j++) {
			puts(matrix[i][j]);
		}
		putchar('\n');
	}

//---------------------------------------------------------------------------
	for (i = 0; i < MATRIX_NUMBER; i++) {
		for (j = 0; j < MATRIX_LENGTH; j++) {
			free(matrix[i][j]);
		}
		free(matrix[i]);
	}
	free(matrix);

	getchar();
	return 0;
}
