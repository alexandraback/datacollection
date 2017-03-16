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
#include <functional>
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

int T, N, n;
VI nums;

int main() {
	cout.precision(12);
	cin >> T;
	int T1 = 0;
	while (T1++ < T) {
		nums.clear();
		cin >> N;
		rep(i, 0, N) {
			cin >> n;
			nums.push_back(n);
		}
		int minCnt = 0, minCnt1 = 0, minRate = 0;
		rep(i, 0, N - 1) {
			if (nums[i + 1] < nums[i]) {
				minCnt += nums[i] - nums[i + 1];
				minRate = max(minRate, (nums[i] - nums[i + 1]));
			}
		}
		rep(i, 0, N - 1) {
			minCnt1 += min(minRate, nums[i]);
		}

		cout << "Case #" << T1 << ": " << minCnt << " " << minCnt1 << endl;
	}

	return 0;
}