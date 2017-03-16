#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define REP(i, n) for(int i = 0; i<(n); i++)
#define abs(a) ((a) >= 0 ? (a) : -(a))
#define inf 2000000001
typedef vector<int> VI;
typedef vector<string> VS;

typedef long long i64;
typedef unsigned long long u64;

vector<pair<char, int> > parse(string str) {
	vector<pair<char, int> > ret;
	char pre;
	int num = 0;
	REP(i, str.size()) {
		if (num == 0) {
			pre = str[i];
			num++;
		} else if (str[i] == pre) {
			num++;
		} else {
			ret.push_back(make_pair(pre, num));
			pre = str[i];
			num = 1;
		}
	}
	if (num > 0) ret.push_back(make_pair(pre, num));
	return ret;
}

void go() {
	int N;
	cin >> N;
	string str[101];
	REP(i, N) {
		cin >> str[i];
	}
	vector<pair<char, int> > a[101];
	REP(i, N) {
		a[i] = parse(str[i]);
	}
	int ret = 0;
	for (int i = 1; i < N; i++) {
		if (a[i].size() != a[0].size()) {
			cout << "Fegla Won";
			return;
		}
	}
	
	REP(i, a[0].size()) {
		VI temp;
		temp.push_back(a[0][i].second);
		for (int j = 1; j < N; j++) {
			if (a[j][i].first != a[0][i].first) {
				cout << "Fegla Won";
				return;
			}
			temp.push_back(a[j][i].second);
		}
		sort(temp.begin(), temp.end());
		int mid = temp[(N - 1) / 2];
		REP(k, N) {
			ret += abs(temp[k] - mid);
		}
	}
	cout << ret;
}

int main() {
  int T;
  cin>>T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
	go();
	cout << endl;
  }
}
