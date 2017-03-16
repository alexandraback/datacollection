#pragma comment(linker, "/STACK:216000000")
#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
#include <set>
const int MAX = 1000001;
using namespace std;
typedef long long ll;

void main() {
	//ios_base::sync_with_stdio(false);
	ifstream cin{ "in.txt" };
	ofstream cout{ "out.txt" };
	int t;
	cin >> t; 
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << i + 1 << ": ";
		int n;
		cin >> n;
		vector<pair<int, int>> ans;
		pair<int, int> queue;
		for (int j = 0; j < n; ++j) {
			int pj;
			cin >> pj;
			for (int k = 0; k < pj; ++k) {
				if (queue.second == 0) {
					queue.second = 1;
					queue.first = j;
				}
				else if (queue.first == j) {
					queue.second++;
				}
				else {
					queue.second--;
					ans.push_back(make_pair(queue.first, j));
				}
			}
		}
		for (int j = 0; j < queue.second; ++j) {
			cout << (char)('A' + queue.first) << " ";
		}
		for (int j = ans.size() - 1; j >= 0; --j) {
			cout << (char)('A' + ans[j].first) << (char)('A' + ans[j].second) << " ";
		}
		cout << endl;
	}
	cin.close();
	cout.close();
}