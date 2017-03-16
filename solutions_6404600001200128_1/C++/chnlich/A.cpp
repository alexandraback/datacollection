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

int T,a[1010],n;

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		llint ans=0,ma=0;
		for(int i=1;i<n;i++) if (a[i]>a[i+1])
		{
			ans+=a[i]-a[i+1];
			ma=max(ma,(llint)a[i]-a[i+1]);
		}
		llint cnt=0;
		for(int i=1;i<n;i++)
			if (a[i]<ma) cnt+=a[i]; else cnt+=ma;
		printf("Case #%d: %I64d %I64d\n",tt,ans,cnt);
	}
	
	return 0;
}
