#include <cstdio>
#include <algorithm>
#define N 17
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, x, y, a[N], b[N], cnt, ans;

void solve(){
	scanf("%d", &x);
	FI(i, 1, 4){
		FI(j, 1, 4){
			int f;
			scanf("%d", &f);
			a[f] = i;
		}
	}
	scanf("%d", &y);
	FI(i, 1, 4){
		FI(j, 1, 4){
			int f;
			scanf("%d", &f);
			b[f] = i;
		}
	}
	
	cnt = 0;
	fi(i, 1, N) if(a[i] == x && b[i] == y){
		ans = i;
		cnt++;
	}
	
	if(cnt == 1) printf("%d\n", ans);
	else if(cnt > 1) puts("Bad magician!");
	else puts("Volunteer cheated!");
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		printf("Case #%d: ", z);
		solve();
	}
}
