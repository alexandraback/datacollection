/*
	Author : ChnLich
*/
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<bitset>
#include<functional>
#include<utility>

using namespace std;

typedef long long llint;
typedef pair<int,int> ipair;
typedef unsigned int uint;
#define pb push_back
#define fi first
#define se second
#define mp make_pair

const int MOD=1000000007,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
const double eps=1e-8;

void read(int &k)
{
	k=0; char x=getchar();
	while(x<'0'||x>'9') x=getchar();
	while(x>='0'&&x<='9') { k=k*10-48+x; x=getchar(); }
}

int T,n,K,m[1010],lis[1010];

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d%d",&n,&K);
		for(int i=0;i<n;i++) scanf("%d",m+i);
		llint L,R,t;
		for(L=0,R=100000000000000ll;L<=R;)
		{
			t=(L+R)>>1;
			//fprintf(stderr,"%I64d\n",t);
			int len=0;
			llint cnt=0;
			for(int i=0;i<n;i++)
			{
				llint add=t/m[i];
				if (t%m[i]==0)
					cnt+=add,lis[++len]=i;
				else
					cnt+=add+1;
			}
			if (cnt>=K)
				R=t-1;
			else if (cnt+len<K)
				L=t+1;
			else
			{
				printf("Case #%d: %d\n",tt,lis[K-cnt]+1);
				break;
			}
		}
	}
	
	return 0;
}
