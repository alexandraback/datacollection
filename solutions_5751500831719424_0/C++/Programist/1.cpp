#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <limits.h>
#include <time.h>
#include <iterator>

#pragma comment(linker, "/STACK:167772160")

using namespace std;

int main(){
	ifstream cin("A-small-attempt0 (2).in");
	ofstream cout("ans.txt");
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {

		int n;
		string x[111];
		string y[111];
		cin >> n;
		bool ok = 1;
		for(int i=1; i<=n; i++) {
			cin >> x[i];
			y[i] = x[i][0];
			for(int j=1; j<x[i].length(); j++)
				if(x[i][j] != x[i][j-1]) y[i] += x[i][j];
			if(i > 1 && y[i] != y[i-1])  ok = 0;
		}

		if(!ok) {
			cout << "Case #" << t << ": Fegla Won\n";
			continue;
		}
		int ans = 0;
		vector <int> cnt[111];
		for(int i=1; i<=n; i++) {
			char ch = x[i][0];
			int k = 1;
			int j = 1;
			while(j < x[i].length()) {
				if(x[i][j] == ch) { k++; j++; continue; }
				cnt[i].push_back(k);
				k = 1;
				ch = x[i][j];
				j++;
			}
			cnt[i].push_back(k);
		}

		for(int j=0; j<cnt[1].size(); j++) {
			int mi = 474747;
			int ma = 0;
			for(int i=1; i<=n; i++) {
				mi = min(cnt[i][j], mi);
				ma = max(cnt[i][j], ma);
			}

			int res = 474747;

			for(int k=mi; k<=ma; k++) {
				int s = 0;
				for(int i=1; i<=n; i++)
					if(k > cnt[i][j]) s += (k - cnt[i][j]); else s += (cnt[i][j] - k);

				res = min(res, s);
			}
			ans += res;
		}
		cout << "Case #" << t << ": " << ans << "\n";
	}
    return 0;
}
 