#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <numeric>

using namespace std;

int main() {
  int T;
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  for(int cn = 1; cn <= T; ++cn) {
cerr << cn << " of " << T << '\n';
    int N;
	pair<int, char> sen[26];
	int total = 0;

	cin >> N;
	for(int i = 0; i < N; ++i) {
		int z;
		cin >> z;
		total += z;
		sen[i] = make_pair(z, (char)('A' + i));
	}
	sort( &sen[0], &sen[N] );

	cout << "Case #" << cn << ":";
	while(total) {
		if(sen[N-1].first == sen[N-2].first && sen[N-1].first * 2 == total) {
		  cout << ' ' << sen[N-1].second << sen[N-2].second;
		  sen[N-1].first -= 1;
		  sen[N-2].first -= 1;
  		  sort( &sen[0], &sen[N] );
		  --total;
		  --total;
		} else {
		  cout << ' ' << sen[N-1].second;
		  sen[N-1].first -= 1;
  		  sort( &sen[0], &sen[N] );
		  --total;
		}
	}
	cout << '\n';
  }
}
