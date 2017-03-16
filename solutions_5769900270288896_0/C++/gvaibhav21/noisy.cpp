#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<map>
using namespace std;
 
#define sd(a) scanf("%d",&a)
#define pd(a) prlong longf("%d\n",(a))
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	bool mark[16][16];
	int t,r,c,n,i,j,k,l,x,cur,num,minn;
	sd(t);
	for(l=1;l<=t;++l)
	{
		sd(r);
		sd(c);
		sd(n);
		minn=1000000000;
		for(i=0;i<(1<<(r*c));++i)
		{
			num=0;
			for(j=0;j<r*c;++j)
			{
				mark[j/c][j%c]=(i&(1<<j));
				if(i&(1<<j))
					num++;
			}
			if(num==n)
			{
				cur=0;
				for(j=0;j<r;++j)
				{
					for(k=0;k<c;++k)
					{
						if(j>0&&mark[j][k]&&mark[j-1][k])
							cur++;
						if(k>0&&mark[j][k]&&mark[j][k-1])
							cur++;
						if(j<r-1&&mark[j][k]&&mark[j+1][k])
							cur++;
						if(k<c-1&&mark[j][k]&&mark[j][k+1])
							cur++;

					}	
				}
				cur/=2;
				minn=min(minn,cur);
			}
		}
		printf("Case #%d: %d\n",l,minn);
	}
}