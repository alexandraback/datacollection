#include<iostream>
#include<cstdio>
#include<string>
#include<memory.h>
using namespace std;

int R, C, N;

bool get(int a, int x, int y)
{
	return a & (1 << (x*C+y));
}

int dx[8] = {-1, 0, 1, 0};
int dy[8] = {0, -1, 0, 1};

int main()
{
	int T;
	cin>>T;
	for(int test_num=1;test_num<=T;test_num++)
	{
		scanf("%d%d%d", &R, &C, &N);
		int best = 1000;
		for(int i=0;i<(1<<(R*C));i++)
		{
			int cnt = 0;
			for(int j=0;j<R*C;j++)
				if (i & (1<<j)) cnt ++;
			if (cnt != N) continue;
			
			int ans = 0;
			for(int x=0;x<R;x++)
				for(int y=0;y<C;y++)
				{
					if (!get(i, x, y)) continue;
					for(int k=0;k<4;k++)
					{
						int x2=x+dx[k], y2=y+dy[k];
						if (x2 < 0 || y2 < 0 || x2 >= R || y2 >= C) continue;
						if (get(i, x2, y2)) ans++;
					}
				}
			best = min(best, ans >> 1);
			
		}
		printf("Case #%d: %d\n", test_num, best);	
	}
	
	return 0;
}
