#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int iabs(int i) {return i > 0 ? i : -i;}

int main(){
	int T;
	cin>>T;
	for (int cases = 0; cases < T; cases++) {
		int N;
		cin>>N;
		vector<pii> V[128];
		int res = 0;
		REP(i, N) {
			string s;
			cin>>s;
			V[i].clear();
			REP(j, s.size()) {
				if (j == 0) {
					V[i].pb(make_pair(s[0], 1));
				} else if (s[j] == s[j - 1]) {
					V[i][V[i].size() - 1].second++;
				} else {
					V[i].pb(make_pair(s[j], 1));
				}
			}
		}
		REP(i, N) {
			if (V[i].size() != V[0].size()) {
				printf("Case #%d: Fegla Won\n", cases + 1);
				goto next;
			}
			REP(j, V[0].size()) {
				if (V[i][j].first != V[0][j].first) {
					printf("Case #%d: Fegla Won\n", cases + 1);
					goto next;
				}
			}
		}
		
		REP(j, V[0].size()) {
			int cur = 100000;
			REP(i, N) {
				int tmp = 0;
				REP(k, N) {
					tmp += iabs(V[i][j].second - V[k][j].second);
				}
				cur = min(cur, tmp);
			}
			res += cur;
		}
		//
		printf("Case #%d: %d\n", cases + 1, res);
		next:;
	}
	return 0;
}
