#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>

#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;
inline long double get_time(){   
	return (long double)clock()/CLOCKS_PER_SEC;
};

const string fegla_won = "Fegla Won";

string solve() {
	int res = 0;
	int n;
	cin >> n;
	vector < string > strings;
	string tmp;
	for (int i = 0; i < n; ++i) cin >> tmp, strings.push_back(tmp);
	vector <vector <pair <int, char> > > bukvi;
	for (int i = 0; i < n; ++i) {
		bukvi.push_back(vector <pair <int, char> > ());
		int last = -1;
		for (int j = 0; j < strings[i].size(); ++j) {
			if (j && strings[i][j] == strings[i][j-1]) {
				bukvi[i][last].first++;
			} else {
				bukvi[i].push_back(make_pair(1, strings[i][j]));
				last++;
			}
		}
	}

	bool wrong = false;
	for (int j = 0; j < bukvi[0].size(); ++j) {
		char bukva = bukvi[0][j].second;
		for (int i = 0; i < n; ++i) {
			if (bukvi[i].size() != bukvi[0].size() || bukvi[i][j].second != bukva) {
				wrong = true;
				break;
			}
		}
	}
	if (wrong) return fegla_won;

	for (int j = 0; j < bukvi[0].size(); ++j) {
		vector <int> broiki;
		for (int i = 0; i < n; ++i) {
			broiki.push_back(bukvi[i][j].first);
		}
		sort(broiki.begin(), broiki.end());
		int mid = broiki.size() / 2;
		for (int i = 0; i < n; ++i) {
			res += abs(broiki[i]-broiki[mid]);
		}
	}

	string result;
	stringstream ss;
	ss << res;
	ss >> result;
	return result;
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	//program
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		printf("Case #%d: %s\n", test, solve().c_str());
	}
	//end program
	return 0;
}




