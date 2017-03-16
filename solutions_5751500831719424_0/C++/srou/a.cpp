#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define rtrav(it, v) for(typeof((v).rbegin()) it = (v).rbegin(); it != (v).rend(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(int argc, char const *argv[]) {
	int T, N;
	scanf("%d", &T);
	rep(t,0,T) {
		scanf("%d", &N);
		vector<vector<pair<char,int> > > strs;
		rep(n,0,N) {
			char s[120];
			scanf(" %s", s);
			vector<pair<char,int> > str;
			rep(i,0,110) {
				if (s[i]==0) break;
				if (str.empty() || str.back().first != s[i])
					str.push_back(pair<char,int>(s[i],1));
				else
					str.back().second++;
			}
			strs.push_back(str);
		}
		bool ok = true;
		rep(n,1,N) {
			ok = ok && strs[n-1].size() == strs[n].size();
			if(!ok) break;
			rep(i, 0, strs[n].size()) {
				ok = ok && strs[n-1][i].first == strs[n][i].first;
			}
		}
		printf("Case #%d: ",t+1);
		if (ok) {
			int totops = 0;
			rep(i, 0, strs.front().size()) {
				int sum = 0, avg1 = 0, avg2 = 0;
				rep(n,0,N)
					sum+= strs[n][i].second;
				avg1 = sum/N;
				avg2 = avg1+1;

				int ops1 = 0, ops2 = 0;
				rep(n,0,N) {
					ops1 += abs(strs[n][i].second-avg1);
					ops2 += abs(strs[n][i].second-avg2);
				}
				totops+= min(ops1, ops2);
			}
			printf("%d\n",totops);
		} else {
			printf("Fegla Won\n");
		}
	}
	return 0;
}