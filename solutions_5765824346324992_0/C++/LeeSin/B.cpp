#include <cstdio>
#include <algorithm>
#define N 1005
#define LL long long
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, m;
LL l, h, x[N];

bool ok(LL c){
	LL ret = 0;
	FI(i, 1, n) ret += (c - 1) / x[i] + 1;
	return ret < m;
}

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w+", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		scanf("%d %d", &n, &m);
		FI(i, 1, n) scanf("%I64d", &x[i]);
		
		l = 0; h = 1LL << 55;
		while(l < h){
			LL c = l + h + 1 >> 1;
			if(ok(c)) l = c;
			else h = c - 1;
		}
		
		LL first = 1e9;
		FI(i, 1, n){
			m -= (l - 1) / x[i] + 1;
			first = min(first, (x[i] - l % x[i]) % x[i]);
		}
		
		FI(i, 1, n) if(first == (x[i] - l % x[i]) % x[i]){
			if(!--m){
				printf("Case #%d: %d\n", z, i);
				break;
			}
		}
	}	
	scanf("\n");
}
