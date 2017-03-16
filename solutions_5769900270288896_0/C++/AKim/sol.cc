#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;



int main() {

	#ifdef SOL
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int t;
	scanf("%d", &t);
	for(int T = 1; T <= t; T++) {
		if(0) {
			printf("Case #%d: ", T);
			int r, c, n;
			scanf("%d%d%d", &r, &c, &n);
			for(int i = 0; i < (1 << r * c); i++) {
				int mx[16][16] = {0};
				for(int f = 0; f < 16; f++) {
					if((1 << f) & i) {
						mx[f / r][f % c] = 1;
					}
				}
			}

		} else {
			printf("Case #%d: ", T);
			int r, c, n;
			scanf("%d%d%d", &r, &c, &n);
			if(n <= (r * c + 1) >> 1) {
				printf("%d\n", 0);
				continue;
			}
			if(r > c) {swap(r, c);}
			ll ans = mod * 1ll * mod;
			int c0 = 0, c2 = 0, c3 = 0, c4 = 0;
			if(r == 1) {
				if(c & 1) {
					ans = min(c / 2, n - (c + 1) / 2) * 2;
					ans = min(ans, 1ll * (min((c + 1) / 2 - 2, max(n - (c) / 2 - 2, 0)) * 2 + min(n - (c) / 2, 2)));
				} else {
					ans = 1ll * min(c / 2 - 1, max(n - c / 2 - 1, 0)) * 2 + min(n - c / 2, 1);
				}
			} else
			if((r & 1) && (c & 1)) {
				{
					c0 = (r * c + 1) / 2;
					c4 = r * c - c0;
					c2 = 0;
					c3 = ((r / 2) + (c / 2)) * 2;
					int nn = n;
					ll vr = 0;
					nn -= c0;
					if(nn > 0) {
						vr += min(nn, c2) * 2ll;
						nn -= min(nn, c2);
					}
					if(nn > 0) {
						vr += min(nn, c3) * 3ll;
						nn -= min(nn, c3);
					}
					if(nn > 0) {
						vr += min(nn, c4) * 4ll;
						nn -= min(nn, c4);
					}
					ans = min(ans, vr);
				}
				{
					c0 = (r * c) / 2;
					c4 = r * c - c0;
					c2 = 4;
					c3 = (((r + 1) / 2) + ((c + 1) / 2)) * 2 - 8;
					int nn = n;
					ll vr = 0;
					nn -= c0;
					if(nn > 0) {
						vr += min(nn, c2) * 2ll;
						nn -= min(nn, c2);
					}
					if(nn > 0) {
						vr += min(nn, c3) * 3ll;
						nn -= min(nn, c3);
					}
					if(nn > 0) {
						vr += min(nn, c4) * 4ll;
						nn -= min(nn, c4);
					}
					ans = min(ans, vr);
				}
			} else {
				c0 = (r * c) / 2;
				c4 = r * c - c0;
				c2 = 2;
				c3 = r * 2 + c * 2 - 4;
				int nn = n;
				ll vr = 0;
				nn -= c0;
				if(nn > 0) {
					vr += min(nn, c2) * 2ll;
					nn -= min(nn, c2);
				}
				if(nn > 0) {
					vr += min(nn, c3) * 3ll;
					nn -= min(nn, c3);
				}
				if(nn > 0) {
					vr += min(nn, c4) * 4ll;
					nn -= min(nn, c4);
				}
				ans = min(ans, vr);
			}
			printf("%I64d\n", ans);
		}
	}

	return(0);
}

// by Kim Andrey
