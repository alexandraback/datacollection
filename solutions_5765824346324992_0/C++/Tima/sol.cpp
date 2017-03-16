#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define pii pair<int, int>
using namespace std;          
const int N = int(2e5);
int T,n,a[N],k;
ll l,r,mid;

ll check(ll m){
	ll res = 0;
	for(int i=1;i<=n;i++){
		res += (m / a[i] + 1);
	}
	return res;
}

int solve(ll m){
	ll res = check(m-1);
	for(int i=1;i<=n;i++){
		if(m % a[i] == 0){
			res++;
			if(res == k) return i; 
		}	
	}
}

int main () {
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		printf("Case #%d: ",t);
		scanf("%d%d",&n,&k);
		l = 0, r = (ll)(1e18);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		while(r - l > 1){
			mid = (r + l) / 2;
			if(check(mid) >= k) r = mid;
			else l = mid;
		}
		if(check(l) >= k) r = l;
		printf("%d\n",solve(r));
	}
return 0;
}
