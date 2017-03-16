// Template by Akigeor
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define ff first
#define ss second
#define pb push_back
#define PII pair<int,int>
#define rep(i,n) for (i=0;i<(n);i++)
#define fo(i,L,R) for (i=(L);i<=(R);i++)
#define cls(x) memset(x,0,sizeof(x))
#define cin(x) scanf("%d",&x)
#define mINF 0x3f
#define INF 0x3f3f3f3f
#define MOD7 1000000007
#define MOD9 1000000009
#define PI acos(-1.0)
using namespace std;
int a[1005];
int main()
{
	int Z,z;
	cin(Z);
	fo(z,1,Z)
	{
		int n;
		cin(n);
		int i,j,k,l,s1=0,s2=0;
		rep(i,n) cin(a[i]);
		fo(i,1,n-1) if (a[i]<a[i-1]) s1+=a[i-1]-a[i];
		j=0;
		fo(i,1,n-1) j=max(j,a[i-1]-a[i]);
		fo(i,1,n-1) s2+=min(j,a[i-1]);
		printf("Case #%d: %d %d\n",z,s1,s2);
	}
	system("pause");
}
