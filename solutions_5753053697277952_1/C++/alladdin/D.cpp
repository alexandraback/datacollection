#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <cassert>
#include <climits>
#include <memory.h>
#include <bitset>

using namespace std;

int n, tt, x;
multiset<pair<int, int> > s;
vector<string> v;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> tt;
	for (int i = 0; i < tt; i++) {
		cin >> n;
		s.clear();
		v.clear();
		int sum = 0;
		int a = -1, b = 0;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (a == -1) {
				a = x;
			}
			else {
				b = x;
			}
			sum += x;
			s.insert(make_pair(x, i));
		}
		if (n != 2) {
			while (sum) {
				if (sum > 2) {
					multiset<pair<int, int> >::iterator it = s.end();
					it--;
					int mx = it->first;
					int num1 = it->second;
					s.erase(it);
					if (mx == 0)
						break;
					string tmp = "";
					tmp += ('A' + num1);
					v.push_back(tmp);
					mx--;
					sum--;
					s.insert(make_pair(mx, num1));
				}
				else {
					multiset<pair<int, int> >::iterator it = s.end();
					it--;
					int mx = it->first;
					int num1 = it->second;
					s.erase(it);
					it = s.end();
					it--;
					int smx = it->first;
					int num2 = it->second;
					s.erase(it);
					string tmp = "";
					tmp += ('A' + num1);
					tmp += ('A' + num2);
					v.push_back(tmp);
					mx--;
					s.insert(make_pair(mx, num1));
					smx--;
					s.insert(make_pair(smx, num2));
					sum -= 2;
				}
			}
		}
		else {
			while (a > b) {
				v.push_back("A");
				a--;
			}
			while (b > a) {
				v.push_back("B");
				b--;
			}
			while (a) {
				v.push_back("AB");
				a--;
			}
		}
		cout << "Case #" << i + 1 << ": ";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << endl;

	}

	return 0;
}