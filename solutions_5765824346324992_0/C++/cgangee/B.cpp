#include <iostream>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;

#define M 1000
#define N 1000000000ll

typedef long long ll;

int a[M+10];
int m;

ll getCnt(ll z){
	ll ret = 0;
	for (int i = 1; i <= m; ++i)
		ret += (z+a[i]-1) / a[i];
	return ret;
}


int solve(){
	ll n;
	cin>>m>>n;
	for (int i = 1; i<=m; ++i) scanf("%d", &a[i]);

	ll x = 0, y = N*200000;
	while (x!=y){
		ll z=(x+y+1)/2;
		if (getCnt(z)<n) x=z;
		else y=z-1;
	}
	ll cnt = getCnt(x);
	for (int i = 1; i<=m; ++i)
		if (x%a[i]==0){
			if (++cnt==n) return i;
		}
}

int main(){
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; ++test){
		printf("Case #%d: %d\n", test, solve());
	}
	return 0;
}
