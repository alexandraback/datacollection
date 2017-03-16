#include <bits/stdc++.h>
using namespace std;

#define DEBUG_ON 1 // 0 = off, 1 = on

namespace {
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define LEN(x) (int)((x).size())
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define OP minmax

#define FOR(i, begin, end)						\
  for (__typeof(end) i = (begin) - ((begin) > (end));			\
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif // ONLINE_JUDGE

typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<ll> vll;
template <typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

ll expmod(ll a, ll b, ll mod) {
  ll res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1)
      res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
}

const int MAX_N = 200000;
const ll MODD = 1000000009LL;
const ld EPS = 1e-9;

void solve() {
	int N;
	cin >> N;
	
	vi senators(N);
	FOR(i,0,N) cin >> senators[i];
	
	int total = accumulate(ALL(senators), 0);
	int parties_left = N;
	
	string plan = "";
	
	while (total > 0) {
		if (parties_left > 2) {
			int majority = (max_element(ALL(senators)) - senators.begin());
			plan +=  " " + string(1, 'A'+majority);
			total--;
			senators[majority]--;
			if (senators[majority] == 0)  parties_left--;
		}
		else {
			vi parties;
			FOR(i,0,N) if (senators[i] > 0) parties.push_back(i);
			if (senators[parties[0]] > senators[parties[1]]) {
				
				plan += " " + string(1, 'A' + parties[0]);
				total--;
				senators[parties[0]]--;
				if (senators[parties[0]] == 0) parties_left--;
				
			}
			else if (senators[parties[0]] < senators[parties[1]]) {
				
				plan += " " + string(1, 'A' + parties[1]);
				total--;
				senators[parties[1]]--;
				if (senators[parties[1]] == 0) parties_left--;
				
			}
			else {
				
				plan += " " + string(1, 'A' + parties[0]) + string(1, 'A' + parties[1]);
				total -= 2;
				senators[parties[0]]--;
				senators[parties[1]]--;
				if (senators[parties[0]] == 0) parties_left--;
				if (senators[parties[1]] == 0) parties_left--;
			}
		}
	}
	cout << plan << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T = 0;
  cin >> T;
  
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ":";
    solve();
  }
}
