#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<fstream>
#include<cmath>
#include<iomanip>
using namespace std;
//#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#define ll long long
#define ull unsigned long long
#define inf 2000000007
#define mod 1000000007
#define pii pair<int,int>
#define vi vector<int>
#define VS vector<string>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define N 1020
#define pi 3.14159265358979323846
#define DBG(vari) cerr<<#vari<<"="<<(vari)<<endl;
#define FOREACH(i,t) for(typeof(t.begin()) i=t.begin();i!=t.end();i++)

char s[110];
string t[110];
int a[N];
vi v[110];
int main()
{
	freopen("1.txt","r",stdin);
	freopen("A-small.txt","w",stdout);
    int i,j,k,n,m,T,ca=0,d;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			m=strlen(s);t[i]="";v[i].clear();
			for(j=0;j<m;j=k)
			{
				k=j;
				while(k<m&&s[k]==s[j])k++;
				t[i]+=s[j];
				v[i].pb((k-j));ans+=k-j-1;
			}
		}
		bool ok=1;
		for(i=1;i<n;i++)
		if(t[i]!=t[i-1]){ok=0;break;}
		if(!ok){printf("Case #%d: Fegla Won\n",++ca);continue;}
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			int s=0;
			for(j=0;j<n;j++)
			if(j!=i)
			{
				int p=v[i].size();
				int x=0;
				while(x<p)
				{
					if(v[i][x]==v[j][x])x++;
					else s+=abs(v[i][x]-v[j][x]),x++;
				}
			}
			ans=min(ans,s);
		}
		
		printf("Case #%d: %d\n",++ca,ans);
	}
}