#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int maxlen = 105;

char s[maxlen];
char symb[maxlen];
vector<int> lens[maxlen];
int n;

int main()
{
	int NT = 0;
	scanf("%d", &NT);
	for (int T = 1; T <= NT; T++)
	{
		printf("Case #%d:", T);
		scanf("%d", &n);
		scanf("%s", s);
		int len = strlen(s);
		s[len] = '$';
		int ksymb = 0;
		int curkv = 1;
		for (int i = 1; i <= len; i++)
		{
			if (s[i] == s[i - 1]) curkv++;
			else
			{
				symb[ksymb] = s[i - 1];
				lens[ksymb].resize(0);
				lens[ksymb].push_back(curkv);
				ksymb++;
				curkv = 1;
			}
		}
		bool bad = false;
		for (int j = 1; j < n; j++)
		{
			scanf("%s", s);
			int len = strlen(s);
			s[len] = '$';
			int cursymb = 0;
			int curkv = 1;
			for (int i = 1; i <= len; i++)
			{
				if (s[i] == s[i - 1]) curkv++;
				else
				{
					if (cursymb >= ksymb || s[i - 1] != symb[cursymb]) bad = true;
					lens[cursymb].push_back(curkv);
					cursymb++;
					curkv = 1;
				}
			}
			if (cursymb != ksymb) bad = true;
		}
		if (bad)
		{
			printf(" Fegla Won\n");
			fprintf(stderr, "%d/%d cases done!\n", T, NT);
			continue;
		}
		int ans = 0;
		for (int i = 0; i < ksymb; i++)
		{
			int bestcur = n * 100;
			for (int j = 0; j < (int)lens[i].size(); j++)
			{
				int cur = 0;
				for (int k = 0; k < (int)lens[i].size(); k++) cur += abs(lens[i][k] - lens[i][j]);
				bestcur = min(bestcur, cur);
			}
			ans += bestcur;
		}
		printf(" %d\n", ans);
		fprintf(stderr, "%d/%d cases done!\n", T, NT);
	}
	return 0;
}
