#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;
int arr[2000] = { 0, };
int result,row,col;
int countUnhappiness(int idx)
{
	int cnt = 0;
	if (idx >= col)
	{
		if (arr[idx - col] == 1)
			cnt++;
	}
	if (idx%col > 0)
	{
		if (arr[idx - 1] == 1)
			cnt++;
	}
	if (idx%col == col - 1)
	{
		if (arr[idx + 1] == 1)
			cnt++;
	}
	if (idx / col<row)
	{
		if (arr[idx + col] == 1)
			cnt++;
	}
	return cnt;
}
void search(int n, int idx, int inter)
{
	if (inter > result) return;
	if (n == 0){
		result = inter;
	}
	for (int i = idx + 1; i < col*row-n+1; i++)
	{
		arr[i] = 1;
		search(n - 1, i, inter + countUnhappiness(i));
		arr[i] = 0;
	}
}
void main()
{
	FILE *fs = fopen("input.txt", "r");
	FILE *fp = fopen("output.txt", "w");

	int testcase;
	fscanf(fs, "%d", &testcase);

	for (int t = 0; t < testcase; t++)
	{
		fprintf(fp, "Case #%d: ", t + 1);
		int n,max;
		fscanf(fs, "%d %d %d", &row, &col, &n);

		max = row / 2;
		if (row % 2 == 1)
			max += (col + 1) / 2;
		if (n == 0 || n<max)
		{
			fprintf(fp, "0\n");
			continue;
		}
		result = (row+1)*(col+1);
		for (int i = 0; i < row*col; i++)
		{
			arr[i] = 0;
		}
		for (int i = 0; i < row*col - n+1; i++)
		{
			arr[i] = 1;
			search(n - 1, i, 0);
			arr[i] = 0;
		}
		fprintf(fp, "%d\n", result);
	}
	fclose(fs);
	fclose(fp);
}