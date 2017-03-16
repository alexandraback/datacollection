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

int T,p,q,a[4][4],b[4][4];

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d",&p); p--;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++) scanf("%d",&a[i][j]);
		scanf("%d",&q); q--;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++) scanf("%d",&b[i][j]);
		int ans=-1;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if (a[p][i]==b[q][j])
					if (ans==-1)
						ans=a[p][i];
					else
						ans=-2;
		printf("Case #%d: ",tt);
		if (ans==-1) puts("Volunteer cheated!");
		else if (ans==-2) puts("Bad magician!");
		else printf("%d\n",ans);
	}
	
	return 0;
}
