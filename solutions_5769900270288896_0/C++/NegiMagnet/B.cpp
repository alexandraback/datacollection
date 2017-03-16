#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int,int> pii;

bool f[18][18];

int main() {
	int t;
	cin >> t;
	rep(dt, t) {
		int r, c, n;
		cin >> r >> c >> n;
		int res = 1000;
		for(ll i=0; i<(1<<r*c); i++) {
			memset(f, 0, sizeof(f));
			int cnt = 0;
			for(int y=1; y<=c; y++) {
				for(int x=1; x<=r; x++) {
					if( i & (1<<((y-1)*r+x-1)) ) {
						f[y][x] = true;
						cnt++;
					}
				}
			}
			if(cnt != n) continue;
			cnt = 0;
			for(int y=1; y<=c; y++) {
				for(int x=1; x<=r; x++) {
					if(!f[y][x]) continue;
					if(f[y+1][x]) cnt++;
					if(f[y][x+1]) cnt++;
				}
			}
			res = min(res, cnt);
		}
		cout << "Case #" << (dt+1) << ": " << res << endl;
	}
	return 0;
}
