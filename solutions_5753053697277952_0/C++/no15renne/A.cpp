
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <climits>
#include <complex>
#include <numeric>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef vector<int> vi;

const int INF = 1e9;
const int MOD = 1e9+7;

int main(void){
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int n;
		cin >> n;
		vi p(n);
		vi pp(n, 0);
		int sum = 0;
		REP(i, n){
			cin >> p[i];
			sum += p[i];
		}
		vi num(n, 0);
		int res = 0;
		vector<string> ans;
		while(res < sum){
			//cout << res << " " << sum << endl;
			int f = 2;
			int k = (res + 2) / 2;
			string str = "";
			for(int i = 0; i < n; i++){
				if(f == 0) break;
				if(pp[i] != p[i] && pp[i] < k){
					pp[i]++;
					f--;
					str += (char)('A' + i);
				}
			}
			ans.push_back(str);
			res += str.size();
		}
		cout << "Case #" << tt << ":";
		RREP(i, ans.size()){
			cout << " " << ans[i];
		}
		cout << endl;
	}	
	
	
	return 0;
}

