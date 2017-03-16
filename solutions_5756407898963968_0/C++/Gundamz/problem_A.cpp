#include <stdio.h>

int matrix1[16];
int matrix2[16];

int main()
{
	int num_of_test;
	FILE *f = fopen("A-small-attempt1.in", "r");
	FILE *out = fopen("A-small-attempt1.out", "w");
	fscanf(f, "%d", &num_of_test);
	int ans1, ans2;
	int matrix_element1, matrix_element2, matrix_element3, matrix_element4;
	for (int i = 0; i < 16; i++)
	{
		matrix1[i] = 0;
		matrix2[i] = 0;
	}
	for (int i = 1; i <= num_of_test; i++)
	{
		fscanf(f, "%d", &ans1);
		for (int row = 0; row < 4; row++)
		{
			fscanf(f, "%d %d %d %d", &matrix_element1, &matrix_element2, &matrix_element3, &matrix_element4);
			matrix1[0+row*4] = matrix_element1;
			matrix1[1+row*4] = matrix_element2;
			matrix1[2+row*4] = matrix_element3;
			matrix1[3+row*4] = matrix_element4;
		}
		fscanf(f, "%d", &ans2);
		for (int row = 0; row < 4; row++)
		{
			fscanf(f, "%d %d %d %d", &matrix_element1, &matrix_element2, &matrix_element3, &matrix_element4);
			matrix2[0+row*4] = matrix_element1;
			matrix2[1+row*4] = matrix_element2;
			matrix2[2+row*4] = matrix_element3;
			matrix2[3+row*4] = matrix_element4;
		}
		// judge
		int count = 0;
		int index1 = 4*(ans1-1);
		int index2 = 4*(ans2-1);
		int right_num = 0;
		for (int row1 = 0; row1 < 4; row1++)
		{
			for (int row2 = 0; row2 < 4; row2++)
			{
				if (matrix1[row1+index1] == matrix2[row2+index2])
				{
					right_num = matrix1[row1+index1];
					count++;
				}
			}
		}
		if (count == 1)
			fprintf(out, "Case #%d: %d\n", i, right_num);
		else if (count > 1)
			fprintf(out, "Case #%d: Bad magician!\n", i);
		else
			fprintf(out, "Case #%d: Volunteer cheated!\n", i);
	}
	fclose(f);
	fclose(out);
}