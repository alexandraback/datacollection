#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <cstring>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <functional>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <iomanip>

using namespace std;

#define fer(i, s, e) for(int i = (s) ; i < (e) ; ++i)
#define rep(i, n)  fer(i, 0, n)
#define clr(a, val)  memset(a, val, sizeof a)

#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define pb  push_back
#define fx(x) fixed << setprecision(x)
#define mkp	make_pair

#define fi first
#define se second

typedef long long ll ;

const int MAX = 1000001 ;

inline int NumberOfSetBits(int i)
{
	 i = i - ((i >> 1) & 0x55555555);
	 i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	 return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

bool mark[18][18];
int dx[] = {-1,+1, 0, 0}, dy[] = { 0, 0,-1,+1};
map < int, pair<int,int> > val ;

int main() {
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int t ; cin >> t;
	int r, c, n ;
	int __case=1;
	while(t--) {
		val.clear();
		cin >> r >> c >> n;
		int x = r * c;
		int cnt=0,ans=(1 << 28);
		rep(i, r) { 
			rep(j, c) {
				val[cnt] = mkp(i,j);
				cnt++;
			}
		}
		rep(msk, (1<<x)){
			int b = NumberOfSetBits(msk) ;
			if(b == n) {
				clr(mark, 0) ;
				fer(i, 0, x) {
					if(msk & (1 << i)) {
						mark[val[i].fi][val[i].se] = 1;
					}
				}
				int sum=0;
				rep(i, r) {
					rep(j, c) {
						if(mark[i][j]) {
							int cntt=0;
							rep(k, 4) {
								int rr = i + dx[k] ;
								int cc = j + dy[k] ;
								if(rr < 0 || cc < 0 || rr >= r || cc >= c) continue;
								if(mark[rr][cc]) cntt++ ;
							}
							sum += cntt ;
						}
					}
				}
				sum /= 2;
				ans = min(ans, sum);
			}
		}
		printf("Case #%d: %d\n",__case++,ans);
	}
	return 0;
}