#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <stack>
#include <bitset>
#include <list>

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define bitcnt(x) __builtin_popcountll(x)
#define rt return

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

const int INF = (int)1e9 + 37;
const ld PI = acos(-1.0);
const int MAXN = 5115;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
const char dir[4] = {'L', 'U', 'R', 'D'};

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int T;
	cin >> T;
	for (int Test = 1; Test <= T; Test++){
		int n, sum = 0;
		cin >> n;
		vector <int> cnt(n);
		for (int i=0;i<n;i++){
			cin >> cnt[i];
			sum += cnt[i];
		}
		vector <char> ans;
		
		while (sum > 0){
			vector <int> maxs;
			int curmax = -1;
			for (int i=0;i<n;i++){
				if (cnt[i] > curmax){
					curmax = cnt[i];
					maxs.clear();
					maxs.pb(i);
				} else if (cnt[i] == curmax){
					maxs.pb(i);
				}
			}

			if ((int)maxs.size() == 2){
				if (cnt[maxs[0]] * 2 == sum){
					cnt[maxs[0]]--;
					cnt[maxs[1]]--;
					sum -= 2;
					ans.pb(char('A' + maxs[0]));
					ans.pb(char('A' + maxs[1]));
					ans.pb(' ');
				} else {
					if (sum % 2 == 1){
						cnt[maxs[0]]--;
						sum--;
						ans.pb(char('A' + maxs[0]));
						ans.pb(' ');
					} else {
						if (cnt[maxs[0]] >= 2){
							cnt[maxs[0]] -= 2;
							sum -= 2;
							ans.pb(char('A' + maxs[0]));
							ans.pb(char('A' + maxs[0]));
							ans.pb(' ');
						} else {
							cnt[maxs[0]]--;
							sum--;
							ans.pb(char('A' + maxs[0]));
							ans.pb(' ');
						}
					}
				}
			} else {
				if (sum % 2 == 1){
					cnt[maxs[0]]--;
					sum--;
					ans.pb(char('A' + maxs[0]));
					ans.pb(' ');
				} else {
					if (cnt[maxs[0]] >= 2){
						cnt[maxs[0]] -= 2;
						sum -= 2;
						ans.pb(char('A' + maxs[0]));
						ans.pb(char('A' + maxs[0]));
						ans.pb(' ');
					} else {
						cnt[maxs[0]]--;
						sum--;
						ans.pb(char('A' + maxs[0]));
						ans.pb(' ');
					}
				}
			}	
		}
		
		
					
		printf("Case #%d: ", Test);
		for (int i=0;i<(int)ans.size();i++){
			cout << ans[i];
		}
		printf("\n");
	}
	
	
    rt 0;
}
