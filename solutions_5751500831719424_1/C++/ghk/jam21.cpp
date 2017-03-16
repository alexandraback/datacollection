#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int t, k;
int n, l, tt;
int i, j, p, q;
int ans;
char ch[100][120];
char ich[120];
int cnt[100][120];

string PROG = "A-Large";
//string PROG = "A-small-attempt1";
FILE *fin, *fout;

bool check()
{
	int i, j, k, p;
	for (i = 1; i < n; i++)
	{
		j = 0;
		if (ch[i][0] != ich[0])
			return false;
		cnt[i][0] = 1;
		for (k = 1; k < strlen(ch[i]); k++)
		{
			if (ch[i][k] == ich[j])
			{
				cnt[i][j]++;
			}
			else
			{
				j++;
				if ((j > l) || (ch[i][k] != ich[j]))
					return false;
				cnt[i][j] = 1;
			}
		}
		if (j < l) return false;
	}
	return true;
}

int main()
{
	fin = fopen((PROG + ".in").c_str(), "r");
	fout = fopen((PROG + ".out").c_str(), "w");
	
	fscanf(fin, "%d", &t);
	for (k = 1; k <= t; k++)
	{
		fscanf(fin, "%d", &n);
		for (i = 0; i < n; i++)
			fscanf(fin, "%s\n", ch[i]);
		/*
		for (i = 0; i < n; i++)
		{
			printf("%s %d\n", ch[i], strlen(ch[i]));
		}*/
			
		l = 0;
		ich[0] = ch[0][0];
		cnt[0][0] = 1;
		for (i = 1; i < strlen(ch[0]); i++)
		{
			if (ch[0][i] == ch[0][i - 1])
			{
				cnt[0][l]++;
			}
			else
			{
				l++;
				ich[l] = ch[0][i];
				cnt[0][l] = 1;
			}
		}
		
		if (check())
		{
			ans = 0;
			for (i = 0; i <= l; i++)
			{
				for (p = 0; p < n - 1; p++)
					for (q = p + 1; q < n; q++)
						if (cnt[p][i] > cnt[q][i])
						{
							tt = cnt[p][i]; cnt[p][i] = cnt[q][i]; cnt[q][i] = tt;
						}
				for (j = 0; j < n / 2; j++)
					ans -= cnt[j][i];
				for (j = (n + 1) / 2; j < n; j++)
					ans += cnt[j][i];
				
			}
		}
		else
		{
			ans = -1;
		}
		
		fprintf(fout, "Case #%d: ", k);
		if (ans == -1)
		{
			fprintf(fout, "Fegla Won\n");
		}
		else
		{
			fprintf(fout, "%d\n", ans);
		}
	}
	return 0;
}