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
int b[1005],c[1005];
int main()
{
	int Z,z;
	cin(Z);
	fo(z,1,Z)
	{
		int n,m,i,j,k;
		cin(m); cin(n);
		rep(i,m) cin(b[i]);
		long long l=0,r=1000000000000000LL,a=0,tt=0;
		while (l<=r)
		{
			long long mid=(l+r)/2LL;
			long long t=0;
			if (mid>0) rep(i,m) t+=(mid-1)/b[i]+1;
			if (t<n)
			{
				a=mid;
				l=mid+1;
				tt=t;
			}
			else
			{
				r=mid-1;
			}
		}
		n-=tt;
		j=10000000;
		rep(i,m) if (a%b[i]==0) {n--; if (n==0) break;}
		printf("Case #%d: %d\n",z,i+1);
	}
}
