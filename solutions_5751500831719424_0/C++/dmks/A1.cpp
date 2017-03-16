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
	vector<pair<char, int> > a = parse(str[0]);
	vector<pair<char, int> > b = parse(str[1]);
	int ret = 0;
	if (a.size() != b.size()) {
		cout << "Fegla Won";
		return;
	}
	REP(i, a.size()) {
		if (a[i].first != b[i].first) {
			cout << "Fegla Won";
			return;
		} else {
			ret += abs(a[i].second - b[i].second);
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
