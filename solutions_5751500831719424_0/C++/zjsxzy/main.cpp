#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 105;
int n;
int main() {
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		cin >> n;
		bool flag = true;
		vector<pair<char, int> > vec;
		vector<vector<int> > med;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			str += '#';

			char cur = str[0];
			int cnt = 1;
			vector<pair<char, int> > temp;
			for (int j = 1; j < str.size(); j++) {
				if (str[j] != cur) {
					if (i != 0) temp.PB(MP(cur, cnt));
					else vec.PB(MP(cur, cnt));
					cur = str[j];
					cnt = 1;
				} else cnt++;
			}

			if (i != 0) {
				if (temp.size() != vec.size()) flag = false;
				else {
					for (int j = 0; j < vec.size(); j++)
						if (vec[j].first != temp[j].first) {
							flag = false;
							break;
						}
				}
			}
			if (flag) {
				if (i == 0) {
					med.resize(vec.size());
					temp = vec;
				}
				for (int j = 0; j < temp.size(); j++) {
					med[j].PB(temp[j].second);
				}
			}
		}

		if (!flag) puts("Fegla Won");
		else {
			int ret = 0;
			for (int i = 0; i < med.size(); i++) {
				sort(med[i].begin(), med[i].end());
				int median = med[i][n / 2];
				for (int j = 0; j < med[i].size(); j++) {
					ret += abs(med[i][j] - median);
				}
			}
			cout << ret << endl;
		}
	}
	return 0;
}

