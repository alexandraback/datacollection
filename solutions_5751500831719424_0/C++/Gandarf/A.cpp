#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

#define N 105
int test, caseNum;
int c[N][N], n;
int res;
char s[N][N];
int len;
string ch[N];

int main()
{
	FILE *in = fopen("A-small-attempt2.in", "r");
	//FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");

	caseNum = 1;
	fscanf(in, "%d", &test);
	while(caseNum <= test)
	{
		for (int i = 0 ; i < N; i++)
			for (int j = 0; j < N; j++)
				c[i][j] = 0;

		fscanf(in, "%d", &n);
		for (int i = 0; i < n; i++)
			fscanf(in, "%s", s[i]);
		
		int pos = 0;
		string k;
		for (int i = 0; i < n; i++) {
			pos = 0;
			k = s[i];
			ch[i] = "";
			for (int j = 0; j < k.size(); j++) {
				if (j == 0 || k[j] == k[j-1])
					c[i][pos]++;
				else
					c[i][++pos]++;
				
				if (j > 0 && k[j] == k[j-1])
					continue;
				ch[i] += k[j];
			}
		}

		if (caseNum == 1)
		{
			for (int i = 0 ; i < n; i++) {
				printf("%s\n", s[i]);
				for (int j = 0 ; j < N; j++)
					printf("%d ", c[i][j]);
				printf("\n");
			}
		}

		bool flag = true;
		for (int i = 1 ; i < n; i++) {
			if (ch[i] != ch[i-1]) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			fprintf(out, "Case #%d: Fegla Won\n", caseNum++);
		}

		else {
			res = 0;

			string ok = ch[0];
			//printf("ok = %s\n", ok.c_str());
			int kk;
			for (int i = 0; i < N ; i++) {
				if (c[0][i] == 0)
							continue;
				int resmin = 99999999;
					for (int t = 1; t <= 100; t++) { // t 개로 맞출 때 필요 경비
						
						int cnt = 0;
						for (int q = 0; q < n; q++)
							cnt += abs(c[q][i] - t);
						resmin = min(resmin, cnt);
					}
				if (caseNum == 1) printf("min(%d) : %d\n", i, resmin);
				res += resmin;
			}

			// result	
			fprintf(out, "Case #%d: %d\n", caseNum++, res);
		}
	}

	fcloseall();
	return 0;
}
