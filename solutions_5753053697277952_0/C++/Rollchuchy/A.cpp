#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
using namespace std;
#define Enter putchar(10)
#define Space putchar(32)
#define rep(x,y) for(x=0;x<(y);++x)
#define rep1(x,y) for(x=1;x<=(y);++x)
#define rep1o(x,y) for(x=1;x<(y);++x)
#define Rep(x,y) for(int x=0;x<(y);++x)
#define Rep1(x,y) for(int x=1;x<=(y);++x)
#define Rep1o(x,y) for(int x=1;x<(y);++x)
#define cin1(x) scanf("%d",&(x))
#define cin2(x1,x2) scanf("%d%d",&(x1),&(x2))
#define cout1(x) printf("%d",x)
#define cout2(x,y) printf("%d %d",x,y)
#define fin1(x) scanf("%lf",(x))
#define fin2(x1,x2) scanf("%lf%lf",&(x1),&(x2))
#define sin1(x) scanf("%s",(x))
#define aryclr(array,sign) memset((array),(sign),sizeof(array))
#define MAX(x,y) (((x)>(y))?(x):(y))
#define MIN(x,y) (((x)<(y))?(x):(y))
#define filll(X,Y) fill(X,X+(sizeof(X)/sizeof(X[0])),(Y))//记住，一定要用一维数组的变量名
typedef pair<int,int> P;
typedef long long ll;
typedef unsigned long long ull;
//这里定义常变量
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};//对于坐标系就是左上右下
const int MAX_N=3500; //提交之前改成20020
//这里声明函数
void in();
void solve();
//这里定义全局变量
int T,t;
int pn;
struct pparty{
	int n;
	char s;
}party[30];
bool cmp(const pparty&a,const pparty&b)
{
	return(a.n>b.n);
}
/*正式代码从这里开始*/
int main()
{
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt2.in","r",stdin);
	freopen("output.txt","w",stdout);
#endif
scanf("%d",&T);
for(t=1;t<=T;++t)
{
	in();
	solve();
}
	return 0;
}
void in()
{
	scanf("%d",&pn);
	for(int i=0;i<pn;++i)
	{
		scanf("%d",&party[i].n);
		party[i].s='A'+i;
	}
}
void solve()
{
	sort(party,party+pn,cmp);
	/**
	for(int i=0;i<pn;++i)
	{
		printf("%c:%d\n",party[i].s,party[i].n);
	}Enter;/**/
	printf("Case #%d:",t);
	while(party[0].n>party[1].n)
	{
		printf(" %c",party[0].s);
		--party[0].n;
	}
	for(int m=pn-1;m>=2;--m)
	{
		while(party[m].n>0)
		{
			printf(" %c",party[m].s);
			--party[m].n;
		}
	}
	while(party[0].n>0)
	{
		printf(" %c%c",party[0].s,party[1].s);
		--party[0].n;
		--party[1].n;
	}Enter;

}



