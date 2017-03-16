#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a%b);
}

int lcm(int a,int b){
	return a  / gcd(a,b) * b;
}

int a[7];

int main(){
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B2.out","w",stdout);
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T; ++kase){
		int m , n , lc , T = 0; scanf("%d%d",&m,&n);
		for(int i = 0; i < m; ++i){
			scanf("%d",&a[i]);
			if(i == 0) lc = a[0];
			else lc = lcm(lc,a[i]);
		}
		for(int i = 0; i < m; ++i){
			T += lc / a[i];
		}
		n %= T;
		if(n == 0) n = T;
		int is_ok[7] , fg = 0 , curm = INF , ans = 0;
		memset(is_ok,0,sizeof(is_ok));
		for(int j = 1; j <= n; ++j){
			fg = 0;
			for(int i = 0; i < m; ++i){
				if(is_ok[i] == 0) {
					is_ok[i] = a[i];
					if(j == n) ans = i + 1;
					fg = 1;break;
				}
			}
			if(!fg){
				for(int i = 0; i < m; ++i) curm = min(curm,is_ok[i]);
				for(int i = 0; i < m; ++i) is_ok[i] -= curm;
				j--;
			}
		}
		printf("Case #%d: %d\n",kase,ans);
	}
    return 0;
}
