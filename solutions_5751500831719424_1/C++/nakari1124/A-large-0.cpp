#include <utility>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long i64;
typedef unsigned long long ui64;

typedef i64 nkr_int;

typedef pair<i64, i64> pi;

typedef vector<nkr_int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define iter(T) T::iterator
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(std::identity<decltype((c).begin())>::type i = (c).begin(); i != (c).end(); ++i)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(s, e, n)  for(n = (s); n < (e); ++n)

class Solver {
public:
  Solver() {}
  ~Solver() {}

  void solve();
};

#define FEGLA "Fegla Won"

void Solver::solve() {
	i64 N;
	cin >> N;
	vector<string> S(N);
	getchar();
	i64 i, j;
	REP(0, N, i) {
		getline(cin, S[i]);
	}
	
	vector<vector<pi> > chars(N);
	i64 prev = -1;
	REP(0, N, i) {
		prev = -1;
		REP(0, sz(S[i]), j) {
			if(S[i][j] != prev) {
				chars[i].pb(pi(S[i][j], 1));
			}
			else {
				chars[i].back().second++;
			}
			prev = S[i][j];
		}
	}
	
	REP(0, N, i) {
		if(sz(chars[i]) != sz(chars[0])) {
			cout << FEGLA << endl;
			return;
		}
		REP(0, sz(chars[i]), j) {
			if(chars[i][j].first != chars[0][j].first) {
				cout << FEGLA << endl;
				return;
			}
		}
	}
	
	i64 ans = 0;
	vi nums(N);
	REP(0, sz(chars[0]), j) {
		REP(0, N, i) {
			nums[i] = chars[i][j].second;
		}
		sort(all(nums));
		i64 mid = nums[N/2];
		REP(0, N, i) {
			ans += abs(nums[i] - mid);
		}
	}
	cout << ans << endl;
	return;
}

int main(int argc, char *argv[]){

  i64 N;
  cin >> N;
  i64 n;

  Solver s;

  REP(0, N, n) {
    cout << "Case #" << n + 1 << ": ";

    s.solve();
  }

  return 0;
}

