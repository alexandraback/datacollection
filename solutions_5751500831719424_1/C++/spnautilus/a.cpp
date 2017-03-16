#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN (104)
#define MAXS (104)

typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <PII> VP;

int T;
int N;

VP CS[MAXN];
char S[MAXS];

int main()
{
	scanf("%d", &T);
	for(int TT = 1; TT <= T; ++TT)
	{
		int i, j, k;
		scanf("%d", &N);

		for(i = 0; i < N; ++i)
		{
			scanf("%s", S);
			k = -1;
			for(j = 0; S[j]; ++j)
			{
				if(k == -1 || CS[i][k].first != S[j])
				{
					++k;
					CS[i].push_back(PII(S[j], 1));
				}
				else
					++CS[i][k].second;
			}

//			printf("%d : %d\n", i, k);
		}

		int okay = 1;
		int sol = 0;
		int sz = CS[0].size();
		for(i = 1; i < N && okay; ++i)
		{
			if((int) CS[i].size() != sz)
				okay = 0;
		}

		if(okay)
		{
			for(i = 1; i < N && okay; ++i)
			{
				for(j = 0; j < sz && okay; ++j)
				{
					if(CS[0][j].first != CS[i][j].first)
						okay = 0;
				}
			}
		}

		if(okay)
		{
			VI ss(N);
			for(j = 0; j < sz; ++j)
			{
				for(i = 0; i < N; ++i)
					ss[i] = CS[i][j].second;

				sort(ss.begin(), ss.end());

				int med = ss[N / 2];
				for(i = 0; i < N; ++i)
				{
					sol += abs <int> (ss[i] - med);
				}
			}
		}

		printf("Case #%d: ", TT);

		if(okay)
			printf("%d\n", sol);
		else
			printf("Fegla Won\n");

		for(i = 0; i < N; ++i)
			CS[i].clear();
	}

	return 0;
}
