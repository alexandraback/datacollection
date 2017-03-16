#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("a_out.txt","w",stdout);
	int T;
	int cas = 0;
	int N;
	int data[10005];
	int ans1,ans2;
	scanf("%d",&T);
	while(T--)
	{
		ans1 = 0;
		ans2 = 0;
		int bigDiff = 0;
		scanf("%d",&N);
		for(int i = 0; i < N; ++i)
			scanf("%d",&data[i]);
		
		for(int i = 1; i < N; ++i)
		{
			if(data[i-1] > data[i])
				ans1 += data[i-1] - data[i];
		}
		for(int i = 1; i < N; ++i)
		{
			int diff = data[i-1] - data[i];
			bigDiff = max(bigDiff,diff);
		}
		for(int i = 0; i < N-1; ++i)
			ans2 += min(bigDiff,data[i]);

		printf("Case #%d: %d %d\n",++cas,ans1,ans2);
	}
	return 0;
}
