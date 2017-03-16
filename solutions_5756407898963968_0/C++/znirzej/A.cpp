#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<tr1/unordered_map>
#include<queue>
#include<cstdlib>
#include<list>
#include<set>
#include<map>
#define MP make_pair
#define PB push_back
#define s second
#define f first
#define PII pair<int,int>
#define VPII vector <pair<int,int> >
#define VI vector <int>
#define abs(a) max((a),-(a))
#define LL long long
#define LD long double
#define ALL(x) x.begin(),x.end()
#define PU putchar_unlocked
#define GU getchar_unlocked
#define DBG(x) cerr<<#x<<" "<<(x)<<endl;
using namespace std;
int a,b,c,d,e,f,n,m,mx,l,z,r,k;
int wynik;
char ch;
int INF=1e9+1;
int x[17];
void solve()
{

scanf("%d",&a);
a--;
for(int i=1;i<=16;i++)
	{
	scanf("%d",&d);
	if((i-1)/4==a)x[d]++;
	}
scanf("%d",&a);
a--;
for(int i=1;i<=16;i++)
	{
	scanf("%d",&d);
	if((i-1)/4==a)x[d]++;
	}
c=0;
for(int i=1;i<=16;i++)
	{
	if(x[i]==2)
		{
		c++;
		a=i;
		}
	x[i]=0;
	}
if(c>1)
	{
	printf("Bad magician!\n");
	}
if(c==0)
	{
	printf("Volunteer cheated!\n");
	}
if(c==1)
	{
	printf("%d\n",a);	
	}
}
main()
{
scanf("%d",&z);
for(int i=1;i<=z;i++)
	{
	printf("Case #%d: ",i);
	solve();
	}

}
