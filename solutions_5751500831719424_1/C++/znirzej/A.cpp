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
int a,b,c,d,e,f,n,m,mx,l,z,r,k,x;
int wynik;
char ch;
int INF=1e9+1;
vector <PII> t[103];
string s;
void solve()
{
scanf("%d",&n);
for(int i=1;i<=n;i++)
	{
	t[i].clear();
	cin>>s;
	for(int j=0;j<s.size();j++)
		{
		a=j;
		while(a+1<s.size()&&s[j]==s[a+1])
			{
			a++;
			}
		t[i].PB(MP(j-a+1,s[a]));
		j=a; 
		}
		
	}
for(int i=2;i<=n;i++)
	{
	if(t[i].size()!=t[i-1].size())
		{
		puts("Fegla Won");
		return;
		}
	for(int j=0;j<t[i].size();j++)
		{
		if(t[i-1][j].s!=t[i][j].s)
			{
			puts("Fegla Won");
			return;
			}
		}
	}
int wynik=0;
VI pom;
for(int j=0;j<t[1].size();j++)
	{
	pom.clear();
	for(int i=1;i<=n;i++)
		{
		pom.PB(t[i][j].f);
		}
	sort(ALL(pom));
	for(int i=0;i<pom.size();i++)
		{
		wynik+=abs(pom[i]-pom[pom.size()/2]);
		}
	}
printf("%d\n",wynik);
}
main()
{
scanf("%d",&z);
for(int ii=1;ii<=z;ii++)
	{
	printf("Case #%d: ",ii);	
	solve();
	}
}
