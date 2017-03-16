#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

const double pi=acos(-1.0);
const double eps=1e-11;
const int Mod=(int)1e9+7;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

template<class T> inline void Min(T &a,T b){if(b<a) a=b;}
template<class T> inline void Max(T &a,T b){if(b>a) a=b;}

template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T euclide(T a,T b,T &x,T &y)
{if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}


int T,n;
char s[110];
int a[110][110],num1[110][110],d[110];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	//outfile.open("output.txt");
	scanf("%d",&T);
	int num=0;
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(num1,0,sizeof(num1));
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			int cnt=1;
			for(int j=0;s[j];j++)
			{
				if(s[j]==s[j+1])
					cnt++;
				else
				{
					a[i][0]++;
					a[i][a[i][0]]=s[j];
					num1[i][a[i][0]]=cnt;
					cnt=1;
				}
			}
		}
		int flag=0,tmp=a[0][0],ans=0;
		for(int i=1;i<n;i++)
			if(a[i][0]!=tmp)
				flag=1;
		for(int j=1;j<=tmp;j++)
		{
			for(int i=0;i<n;i++)
			{
				d[i]=num1[i][j];
				if(i&&a[i][j]!=a[i-1][j])
					flag=1;
			}
			sort(d,d+n);
			for(int i=0;i<n;i++)
				ans+=abs(d[i]-d[n/2]);
		}
		printf("Case #%d: ",++num);
		if(flag)
			printf("Fegla Won\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}

