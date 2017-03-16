#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <math.h>
#include <vector>
#include <ctime>
#include <cctype>
#include <stack>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <stdexcept>
#include <utility> 
using namespace std;
#define ll long long 
#define m0(a) memset(a, 0, sizeof(a))
#define m1(a) memset(a, -1, sizeof(a))
#define C1(x)  cout<<x<<endl
#define C2(x,y)  cout<<x<<" "<<y<<endl
#define C3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<endl
#define C4(x,y,z,zz)  cout<<x<<" "<<y<<" "<<z<<" "<<zz<<endl
#define min(x,y) ((x)>(y)?(y):(x))
#define max(x,y) ((x)>(y)?(x):(y))
#define r() (rand()/(double)(RAND_MAX))
struct stu
{
	int x,y,z;
	bool operator < (const stu &b) const
	{
		return x>b.x;	
	}
};
const int inf = 0x3f3f3f3f; 
const double eps = 1e-15;
const double pi = acos((double)-1) ;
const int maxn = 100100;
const ll M = 1e9+7;
int i,j,k,l,m,n,x,y,z,ans,num;
stu a[maxn]={0};
int v[maxn]={0};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
string s;
ll gcd(ll x,ll y)
{
	if (x==0 || y==0)  return x+y;
	return (x%y==0)?y:gcd(y,x%y);
}
int main () 
{
	srand((unsigned)time(NULL));
	#ifdef ONLINE_JUDGE
	
	#else
	
	    freopen("A-large (2).in","r",stdin);
	    freopen("in.out","w",stdout);
	
	#endif
	int cas;
	/*
	while (scanf("%d",&x)!=EOF) 
	{
		C1(x);
	}
	*/
	
	scanf("%d",&cas);
	for (int casi=1;casi<=cas;casi++)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i].x);
			a[i].y=i;
			l+=a[i].x;
		}
		//for (int i=0;i<n;i++) printf("%d %d\n",a[i].y,a[i].x);printf("\n");
		printf("Case #%d:",casi);
		sort(a,a+n);
		while (l>0)
		{
			if (l==3)
			{
				//printf("111");
				printf(" %c",'A'+a[0].y);
				//C1('A'+a[0].y);
				a[0].x--;
				l--;
			}
			else if (a[1].x>0)
			{
				//C2('A'+a[0].y,'A'+a[1].y);
				//printf("222");
				printf(" %c%c",'A'+a[0].y,'A'+a[1].y);
				a[0].x--;
				a[1].x--;
				l-=2;
			}
			else 
			{
				//printf("333");
				printf(" %c",'A'+a[0].y);
				C1('A'+a[0].y);
				a[0].x--;
				l--;
			}
			
			sort(a,a+n);
			//for (int i=0;i<n;i++) printf("%d %d\n",a[i].y,a[i].x);printf("\n");
			//printf("L=%d\n",l);
		}
		printf("\n");
	}
	return 0;
}
