#define _CRT_SECURE_NO_WARNINGS
#include <omp.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cassert>
#include <set>
#include <time.h>
using namespace std;

int main() {
//#ifdef  _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//#endif //  _DEBUG

	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		int n;
		set <pair<int, char>> st;
		cin >> n;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			st.insert(make_pair(x, i + 'A'));
			sum += x;
		}
		cout << "Case #" << q + 1 << ": ";
		if (sum % 2 != 0) {
			pair<int, char> t = *st.rbegin();
			st.erase(t);
			t.first--;
			cout << t.second << " ";
			if (t.first > 0) st.insert(t);
			sum--;
		}
		while (sum >= 2) {
			assert(st.size() >= 2);
			pair<int, char> t1 = *st.rbegin();
			st.erase(t1);
			pair<int, char> t2 = *st.rbegin();
			st.erase(t2);
			cout << t1.second << t2.second << " ";
			t1.first--; t2.first--;
			if (t1.first > 0) st.insert(t1);
			if (t2.first > 0) st.insert(t2);
			sum -= 2;
		}
		cout << endl;
	}
	return 0;
}