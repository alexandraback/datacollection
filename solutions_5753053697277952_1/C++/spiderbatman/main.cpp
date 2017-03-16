#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>

#define INF 2000000000
#define MOD 1000000000

using namespace std;



int main() {
	int testCnt;
	cin >> testCnt;
	for (int testNum = 1; testNum <= testCnt; testNum++) {
		cout << "Case #" << testNum << ": ";
		vector< pair<int, char> > vec;
		int n;
		cin >> n;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			pair<int, int> p;
			cin >> p.first;
			sum += p.first;
			p.second = 'A' + i;
			vec.push_back(p);
		}
		while (vec.size() < 3) {
			vec.push_back(make_pair(0, 'z'));
		}
		sort(vec.rbegin(), vec.rend());
		while (vec[0].first > 0) {
			if (vec[1].first * 2 <= sum - 1) {
				vec[0].first -= 1;
				sum--;
				cout << vec[0].second << " ";
			}
			else {
				cout << vec[0].second << vec[1].second << " ";
				vec[0].first--;
				vec[1].first--;
				sum -= 2;
			}
			sort(vec.rbegin(), vec.rend());
		}
		cout << endl;
	}
	return 0;
}
