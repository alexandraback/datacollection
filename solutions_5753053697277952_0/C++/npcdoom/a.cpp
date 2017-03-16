#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define NINF -0x3f3f3f3f

using namespace std;

typedef pair<int,int> pii;

int P[50];

void solve ()
{
	int N;
	cin >> N;
	
	int rem = 0;
	for (int i = 0; i < N; i += 1)
	{
		cin >> P[i];
		rem += P[i];
	}
	
	while (rem)
	{
		char op[5] = { 0 };
		
		int curMx = 30;
		for (int i = 0; i < N; i += 1)
		{
			if (P[i] > P[curMx])
				curMx = i;
		}
		
		--P[curMx];
		--rem;
		op[0] = 'A'+curMx;
		
		if (rem % 2 == 1)
		{
			curMx = 30;
			for (int i = 0; i < N; i += 1)
			{
				if (P[i] > P[curMx])
					curMx = i;
			}
			
			--P[curMx];
			--rem;
			op[1] = 'A'+curMx;
		}
		
		printf(" %s",op);
	}
	
	printf("\n");
}

int main ()
{
	int T;
	scanf("%d",&T);
	
	for (int t = 1; t <= T; ++t)
	{
		printf("Case #%d:",t);
		solve();
	}
	
	return 0;
}
