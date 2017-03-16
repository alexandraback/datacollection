#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include<map>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cstdint>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
string name = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
int hoge[100] = {};
int main() {
	int t;
	cin >> t;
	for (int i = 1;i <= t;++i) {
		cout << "Case #" << i << ":";
		int n;
		cin >> n;
		for (int q = 0;q < 100;++q) {
			hoge[q] = 0;
		}
		int all_man = 0;
		REP(q, n) {
			cin >> hoge[q];
			all_man += hoge[q];
		}
		string ans;
		while (all_man != 0) {
			int hoge_max = 0;
			for (int q = 0;q < n;++q) {
				if (hoge[hoge_max] < hoge[q]) {
				hoge_max = q;
				}
			}
			hoge[hoge_max]--;
			ans.push_back(name[hoge_max]);
			all_man--;
		}
		if (ans.length() > 2) {
			for (int i = 0;i < ans.length() - 3;i += 2) {
				cout << " " << ans[i] << ans[i + 1];
			}
			if (ans.length() % 2 == 0) {
				cout << " " << ans[ans.length() - 2] << ans[ans.length() - 1] << endl;
			}
			else {
				cout << " " << ans[ans.length() - 3];
				cout << " " << ans[ans.length() - 2] << ans[ans.length() - 1] << endl;
			}
		}
		else {
			cout << " " << ans[0] << ans[1] << endl;;
		}
	}
}