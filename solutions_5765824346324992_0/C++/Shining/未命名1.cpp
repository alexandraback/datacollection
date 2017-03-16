#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define rep(a,b,c) for(int a=b;a<=c;++a)
#define per(a,b,c) for(int a=b;a>=c;--a)
#define X first
#define Y second
#define PII pair<int,int>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define pb push_back
#define mp make_pair

typedef long long ll;

int T,TT,b,n;
ll l,r,mid;
int c[1111];

ll check(ll lim){
	ll taken=0;
	rep(i,1,b)
		taken+=ll(lim/c[i])+1;
	return	taken;
}

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&TT);
	rep(T,1,TT){
		scanf("%d%d",&b,&n);
		rep(i,1,b)	scanf("%d",&c[i]);
		l=0;r=1000000000000000ll;
		while	(l<r){
			mid=(l+r)/2;
			if	(check(mid)>=n)	r=mid;
			else	l=mid+1;
		}
		while	(check(l)<n)	l++;
		while	(check(l-1)>=n)	l--;
		int le=n-check(l-1);
		rep(i,1,b){
			if	(l%c[i]==0)	le--;
			if	(le==0){
				printf("Case #%d: %d\n",T,i);
				break;
			}
		}
	}
}

