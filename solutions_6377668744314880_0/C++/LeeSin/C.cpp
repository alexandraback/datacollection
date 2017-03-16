#include <cstdio>
#include <algorithm>
#define N 3005
#define LL long long
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, ans[N];
bool u[N];
struct pt{
	int x, y, id;
} p[N];

LL cross(pt a, pt b, pt o){
	return (LL) (a.x - o.x) * (b.y - o.y) - (LL) (a.y - o.y) * (b.x - o.x);
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w+", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		scanf("%d", &n);
		fi(i, 0, n){
			scanf("%d %d", &p[i].x, &p[i].y);
			p[i].id = i;
			ans[i] = max(0, n - 3);
		}
		
		fi(i, 0, n) fi(j, i + 1, n){
			int l = 0, r = 0;
			fi(k, 0, n){
				if(cross(p[j], p[k], p[i]) < 0) l++;
				else if(cross(p[j], p[k], p[i]) > 0) r++;
			}
			
			fi(k, 0, n){
				if(cross(p[j], p[k], p[i]) < 0) ans[k] = min(ans[k], l - 1);
				else if(cross(p[j], p[k], p[i]) > 0) ans[k] = min(ans[k], r - 1);
				else ans[k] = min(ans[k], min(l, r));
			}
		}
		
		printf("Case #%d:\n", z);
		fi(i, 0, n) printf("%d\n", ans[i]);
	}
	scanf("\n");
}
