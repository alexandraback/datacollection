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
#include <cstring>
#include <fstream>
#include <queue>


using namespace std;

void gcj_solve(int caseno, ifstream &in, ofstream &out) {
	int n;
	in >> n;
	vector<int> m(n);
	for (int i = 0; i < n; i++) {
		in >> m[i];
	}
	int a = 0;
	for (int i = 1; i < n; i++) {
		if (m[i] < m[i - 1]) {
			a += m[i - 1] - m[i];
		}
	}
	int b = 1e9;
	int ma = *max_element(m.begin(), m.end());
	for (int i = 0; i <= ma; i++) {
		int u = 0;
		bool bo = true;
		for (int j = 0; j < n - 1; j++) {
			int t = max(0, m[j] - i);
			u += m[j] - t;
			if (t > m[j + 1]) {
				bo = false;
				break;
			}
		}
		if (bo) {
			cout << i << ' '<< u << endl;
			b = min(b, u);
		}
	}
	cout << "Case #" << caseno << ": " << a << " " << b << "\n";
	out << "Case #" << caseno << ": " << a << " " << b << "\n";
}

int google_code_jam() {
	ifstream in("input.in");
	ofstream out("output.out");
	if (!in.is_open() || in.eof() || !out.is_open()) {
		cout << "error" << endl;
		return -1;
	}
	int nc;
	in >> nc;
	for (int i = 1; i <= nc; i++) {
		if (in.eof()) {
			cout << "error 2" << endl;
			return -1;
		}
		gcj_solve(i, in, out);
	}
	in.close();
	out.close();
	return 0;
}

int main() {
	google_code_jam();
}