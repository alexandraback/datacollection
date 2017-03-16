#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <numeric>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define y1 stupid_y1
#define ll long long
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define file "a"

const int inf = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n;
int ans[10010];
int x[10010], y[10010];

ll area(int ax, int ay, int bx, int by, int cx, int cy){
	bx -= ax;
	by -= ay;
	cx -= ax;
	cy -= ay;
	return bx*1ll*cy - by*1ll*cx;
}

void Solve(){
	scanf("%d", &n);	

	for (int i=0;i<n;i++){
		scanf("%d%d", &x[i], &y[i]);
	}

	for (int i=0;i<n;i++){
		ans[i] = n-1;
	}


	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			int f1 = 0, f2 = 0;
			for (int k=0;k<n;k++){
				ll t = area(x[i], y[i], x[j], y[j], x[k], y[k]);
				if ( t > 0 ) f1++;
				if ( t < 0 ) f2++; 
			}	
			ans[i] = min(ans[i], min(f1, f2));
			ans[j] = min(ans[j], min(f1, f2));
		}
	}

	for (int i=0;i<n;i++)
		printf("%d\n", ans[i]);


}

int main () {
	#ifdef LOCAL
	freopen(file".in", "r", stdin);
	freopen(file".out", "w", stdout);
	#endif

	int T;
	scanf("%d", &T);

	for (int i=0;i<T;i++){
		printf("Case #%d:\n", i + 1);
		Solve();
	}




	#ifdef LOCAL
	cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif

	return 0;
}

