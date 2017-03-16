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

/*void gcj_solve(int caseno, ifstream &in, ofstream &out) {
	int b, n;
	in >> b >> n;
	n = 1000000000;
	vector<int> v(b);
	for (int i = 0; i < b; i++) {
		in >> v[i];
	}
	vector<int> w(b);
	n--;
	int t = 0;
	int ans = -1;
	while (1) {
		for (int i = 0; i < b; i++) {
			w[i] = max(w[i] - 1, 0);
		}
		int s = -1;
		for (int i = 0; i < b; i++) {
			if (w[i] == 0) {
				w[i] = v[i];
				s = i + 1;
				if (t == n) {
					ans = s;
					goto end;
				}
				t++;
			}
		}
	}
end:
	cout << "Case #" << caseno << ": " << ans << "\n";
	out << "Case #" << caseno << ": " << ans << "\n";
}*/
int gcd(int a, int b){
	if(b==0){
		return a;
	}
	return gcd(b, a%b);
}
void gcj_solve(int caseno, ifstream &in, ofstream &out) {
	int b;
	long long n;
	in >> b >> n;
	vector<int> v(b);
	for (int i = 0; i < b; i++) {
		in >> v[i];
	}
	long long ma = v[0];
	for (int i = 1; i < b; i++) {
		ma = ma * v[i] / gcd(ma, v[i]);
	}
	vector<int> w(b);
	int t = 0;
	vector<int> a;
	for (int i = 0; i < ma; i++) {
		for (int j = 0; j < b; j++) {
			w[j] = max(w[j] - 1, 0);
		}
		for (int j = 0; j < b; j++) {
			if (w[j] == 0) {
				w[j] = v[j];
				a.push_back(j + 1);
			}
		}
	}
	int ans = a[(n - 1) % a.size()];
	cout << "Case #" << caseno << ": " << ans << "\n";
	out << "Case #" << caseno << ": " << ans << "\n";
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