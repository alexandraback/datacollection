#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<list>
#include<queue>
#include<deque>
#include<algorithm>
//#include<numeric>
#include<utility>
//#include<memory>
#include<functional>
#include<cassert>
#include<set>
#include<stack>
#include<random>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

void solve() {
	int n;
	cin >> n;
	vector<pii> alpha(n);
	for (int i = 0; i < n; i++){
		cin >> alpha[i].first;
		alpha[i].second = i;
	}
	while (1) {
		sort(alpha.rbegin(), alpha.rend());
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += alpha[i].first;
		if (sum == 0) break;
		if (alpha[0].first == alpha[1].first && sum != 3) {
			alpha[0].first -= 1;
			alpha[1].first -= 1;
			cout << (char)('A'+alpha[0].second) << (char)('A'+alpha[1].second) ;
			sum -= 2;
		} else {
			alpha[0].first -= 1;
			cout << (char)('A'+alpha[0].second) ;
			sum -= 1;
		}
		if (sum) cout << " ";
	}
	cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
    	cout << "Case #" << t << ": " ;
    	solve();
    }
    return 0;
}
