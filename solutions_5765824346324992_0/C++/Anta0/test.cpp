#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int T;
	scanf("%d", &T);
	rep(ii, T) {
		int B, N;
		scanf("%d%d", &B, &N), -- N;
		vector<int> M(B);
		rep(i, B) scanf("%d", &M[i]);
		ll l = 0, u = (ll)*max_element(all(M)) * N;
		while(u - l > 0) {
			ll mid = (l + u + 1) / 2;
			ll cnt = 0;
			rep(i, B)
				cnt += (mid + M[i] - 1) / M[i];
//			cerr << mid << ": " << cnt << ", " << N << endl;
			if(cnt <= N)
				l = mid;
			else
				u = mid-1;
		}
		int ans = -1;
		long long t = N;
		rep(i, B) t -= (l + M[i] - 1) / M[i];
		rep(i, B) if(l % M[i] == 0) {
			if(t == 0) {
				ans = i;
				break;
			}
			-- t;
		}
		printf("Case #%d: %d\n", ii+1, ans + 1);
	}
	return 0;
}
