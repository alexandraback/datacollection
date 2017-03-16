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

int TT,T,n,a[1111];

int main(){
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&TT);
	rep(T,1,TT){
		scanf("%d",&n);
		rep(i,1,n)	scanf("%d",&a[i]);
		int ans1=0,ans2=0,ans3=0;
		rep(i,2,n){
			if	(a[i]<a[i-1])	ans1+=a[i-1]-a[i];
			ans2=max(ans2,a[i-1]-a[i]);
		}
		rep(i,2,n){
			if	(a[i-1]<ans2)	ans3+=a[i-1];
			else	ans3+=ans2;
		}
		printf("Case #%d: %d %d\n",T,ans1,ans3);
	}
}

