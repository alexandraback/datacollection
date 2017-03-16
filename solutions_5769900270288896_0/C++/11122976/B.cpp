/**************************************************
 * Author	 : xiaohao Z
 * Blog	 : http://www.cnblogs.com/shu-xiaohao/
 * Last modified : 2015-05-02 23:59
 * Filename	 : A.cpp
 * Description	 : 
 * ************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<unsigned int,unsigned int> puu;
typedef pair<int, double> pid;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int LEN = 20;
int Map[LEN][LEN];
int n, m, q;

int Cnt(int x, int N) {
	int ret = 0;
	for(int i=0; i<N; i++) {
		if(x & (1<<i)) ret ++;
	}
	return ret;
}

int solve(int x, int N) {
	int ret = 0;
	memset(Map, 0, sizeof Map);
	int ind = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(x & (1<<ind)) Map[i][j] = 1;
			ind ++;
		}
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			if(i < n-1 && Map[i][j] && Map[i + 1][j]) ret ++;
			if(j < m-1 && Map[i][j] && Map[i][j + 1]) ret ++;
		}
	return ret;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("outB.txt", "w", stdout);

	int T, kase = 1;
	cin >> T;
	while(T--) {
		cin >> n >> m >> q;
		int N = n*m, ans = INF;
		for(int i=0; i<(1<<N); i++) if(Cnt(i, N) == q){
			ans = min(ans, solve(i, N));
		}
		cout << "Case #" << kase ++ << ": " << ans << endl;
	}
	return 0;
}

