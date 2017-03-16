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

ll T, B, N, b;
vector<ll> MK;

bool myComp(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
{
	if (lhs.first == rhs.first) return lhs.second < rhs.second;
	return lhs.first > rhs.first;
}

int main() {
	cout.precision(12);
	cin >> T;
	int T1 = 0;
	while (T1++ < T) {
		MK.clear();
		cin >> B >> N;
		ll l = 0, r = 0;
		rep(i, 0, B) {
			cin >> b;
			MK.push_back(b);
			r = max(r, b * N);
		}
		if (B >= N) {
			cout << "Case #" << T1 << ": " << N << endl;
			continue;
		}

		while (l + 1 < r) {
			ll mid = (l + r) / 2;
			ll cnt = 0;
			rep(i, 0, B) {
				cnt += mid / MK[i];
				if (mid % MK[i]) cnt++;
			}
			if (cnt >= N) r = mid;
			else l = mid;
		}

		ll cnt = 0, idx, left;
		rep(i, 0, B) {
			cnt += l / MK[i];
			if (l % MK[i]) cnt++;
		}
		if (cnt >= N) {
			idx = l;
			left = cnt - N;
		}
		else {
			cnt = 0;
			rep(i, 0, B) {
				cnt += r / MK[i];
				if (r % MK[i]) cnt++;
			}
			idx = r;
			left = cnt - N;
		}

		VIP lastOnes;
		rep(i, 0, B) {
			if (idx % MK[i]) lastOnes.push_back(mp(idx % MK[i], i + 1));
			else lastOnes.push_back(mp(MK[i], i + 1));
		}
		sort(lastOnes.begin(), lastOnes.end(), &myComp);
		

		cout << "Case #" << T1 << ": " << lastOnes[lastOnes.size() - left - 1].second << endl;
	}

	return 0;
}