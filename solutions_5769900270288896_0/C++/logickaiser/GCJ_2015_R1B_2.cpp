
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <set>
#include <ctime>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i=a; i<(int)n; i++)
#define per(i,n,a) for (int i=n; i>=a; i--)
#define hk push_back
#define pk pop_back
#define mp make_pair
#define PI 3.141592653589793
#define clr(a) memset(a, 0, sizeof(a))
#define clr1(a) memset(a, -1, sizeof(a))
typedef vector<int> VI;
typedef vector< pair<int, int> > VIP;
typedef vector< pair<int, pair<int, double> > > VIPP;
typedef vector<string> VS;
typedef vector <double> VD;
typedef vector <bool> VB;
typedef long long ll;
#define MAX_V 1000
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
	ll res = 1; a %= mod; for (; b; b >>= 1){ if (b & 1)res = res*a%mod; a = a*a%mod; }return res;
}

ll T, R, C, N;
int minNoise;
bool visited[16][16];

void dfs(int x, int y, int left) {
	if (left == 0) {
		int noise = 0;
		rep(i, 0, R) {
			rep(j, 0, C - 1) {
				if (visited[i][j] && visited[i][j + 1]) noise++;
			}
		}
		rep(j, 0, C) {
			rep(i, 0, R - 1) {		
				if (visited[i][j] && visited[i + 1][j]) noise++;
			}
		}
		minNoise = min(minNoise, noise);
		return;
	}
	rep(i, x, R) {
		rep(j, 0, C) {
			if (i == x && j < y) continue;
			if (!visited[i][j]) {
				visited[i][j] = 1;
				dfs(i, j, left - 1);
				visited[i][j] = 0;
			}
		}
	}
}

int main() {
	cout.precision(12);
	cin >> T;
	int T1 = 0;
	while (T1++ < T) {
		clr(visited);
		cin >> R >> C >> N;
		minNoise = R * C * 10;
		dfs(0, 0, N);
		cout << "Case #" << T1 << ": " << minNoise << endl;
	}

	return 0;
}