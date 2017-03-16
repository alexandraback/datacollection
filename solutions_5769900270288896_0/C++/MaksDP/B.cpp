#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <memory.h>
typedef long long ll;

using namespace std;

bool H[100][100];
int Min;
int N;
int R;
int C;
int Count;
const int lim=10000000;

void perebor(int x, int y, int rate, int num)
{
	H[x][y]=true;
	num++;
	if(H[x-1][y]==true) rate++;
	if(H[x+1][y]==true) rate++;
	if(H[x][y-1]==true) rate++;
	if(H[x][y+1]==true) rate++;

	if(num==N) 
	{
		if(rate<Min) Min=rate;
		H[x][y]=false;
		Count++;
		return;
	}

	for(int i=1; i<=R; i++)
		for(int j=1; j<=C; j++)
			if(H[i][j]==false) 
			{
				perebor(i, j, rate, num);
				if(Count>lim) return; 
			}

	H[x][y]=false;

}

int main()
{
	FILE* inf=fopen("input.txt", "r");
	FILE* outf=fopen("output.txt", "w");

	int T;
	fscanf(inf, "%d", &T);

	for(int t=1; t<=T; t++)
	{
		Min=99999;
		Count=0;
		memset(H, false, sizeof(H));

		fscanf(inf, "%d%d%d", &R, &C, &N);
		if(N<=(R*C)/2) Min=0; else
		if(N==R*C) Min=R*(C-1)+C*(R-1); else
		{
		H[1][1]=true;

		for(int i=1; i<=R; i++)
			for(int j=1; j<=C; j++)
				if((i!=1)||(j!=1))
				{
					perebor(i, j, 0, 1);
					if(Count>lim) break;
				}
		}

		fprintf(outf, "Case #%d: %d\n", t, Min);
	}


	fclose(inf);
	fclose(outf);
	return 0;
}