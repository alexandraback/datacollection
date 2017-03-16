#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 1005

int v[MAX];

int main()
{
	int t, n;

	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf("%d", &n);
		for(int i=0; i<n; ++i) scanf("%d", &v[i]);
	
		int sol1 = 0, sol2 = 0, rate = 0;
		for(int i=0; i<n-1; ++i)
			if(v[i+1] < v[i])
			{
				sol1 += v[i] - v[i+1];
				rate = max(rate, v[i] - v[i+1]);
			}
		for(int i=0; i<n-1; ++i)
		{
			if(v[i] > rate) sol2 += rate;
			else sol2 += v[i];
		}
		
		printf("Case #%d: %d %d\n", tc, sol1, sol2);
	}

	return 0;
}
