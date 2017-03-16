#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int test, q1, q2;
int a1[4][4], a2[4][4];
int cnt[20];

int main()
{
	
	FILE *in = fopen("A-small-attempt0.in", "r");
	//FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");

	int caseNum = 1;
	fscanf(in, "%d", &test);
	while(test-- > 0) {
		fscanf(in, "%d", &q1);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				fscanf(in, "%d", &a1[i][j]);
		fscanf(in, "%d", &q2);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				fscanf(in, "%d", &a2[i][j]);

		for (int i = 1; i <= 16; i++)
			cnt[i] = 0;

		for (int j = 0; j < 4; j++)
			cnt[ a1[q1-1][j] ]++;
		for (int j = 0; j < 4; j++)
			cnt[ a2[q2-1][j] ]++;

		int res = 0, pos;
		for (int i = 1; i <= 16; i++) {
			//printf("%d : %d\n", i, cnt[i]);
			if (cnt[i] == 2) {
				res++;
				pos = i;
			}
		}
		//printf("==============================\n");

		if (res == 1)
			fprintf(out, "Case #%d: %d\n", caseNum, pos);
		else if (res > 1)
			fprintf(out, "Case #%d: Bad magician!\n", caseNum);
		else if (res == 0)
				fprintf(out, "Case #%d: Volunteer cheated!\n", caseNum);	
		caseNum++;
	}

	fcloseall();

	return 0;
}
