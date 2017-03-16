#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define N 5

int r, c, n;
vector<int> b(N);

int calc_b() {
	if (r % 2 != 0) 
		swap(r, c);
	b[0] = (r / 2) * c;
	b[1] = 0;
	b[2] = 2;
	b[3] = r + c - 4;
	b[4] = r * c - b[0] - b[2] - b[3];
}

int calc_b1() {
	b[0] = r * c / 2;
	b[1] = 0;
	b[2] = 4;
	b[3] = (r / 2 + c / 2) * 2 - 4;
	b[4] = r * c - b[0] - b[2] - b[3];
}

int calc_b2() {
	b[0] = r * c / 2 + 1;
	b[1] = 0;
	b[2] = 0;
	b[3] = (r / 2 +  c / 2) * 2;
	b[4] = r * c - b[0] - b[2] - b[3];
}

int calc_b3() {
	if (r == 1)
		r = c;
	if (r % 2 == 0) {
		b[0] = r / 2;
		b[1] = 1;
		b[2] = r - b[0] - b[1];
	} else {
		b[0] = r / 2 + 1;
		b[1] = 0;
		b[2] = r - b[0] - b[1];
	}
	b[3] = 0;
	b[4] = 0;
}

int get_h() {
	int p = n;
	int res = 0;
	for (int i = 0; i < N; i++) {
		//cout << b[i] << "|";
		if (p >= b[i]) {
			res += b[i] * i;	
			p -= b[i];
		} else {
			res += p * i;
			break;
		}
	}
	return res;
}

int solve() {
	if (r == 1 || c == 1) {
		calc_b3();
		return get_h();
	}
	if (r % 2 == 0 || c % 2 == 0) {
		calc_b();
		return get_h();
	} else {
		calc_b1();
		int res = get_h();
		calc_b2();
		res = min(get_h(), res);
		return res;
	}
}

int main() {
	int nt;
	cin >> nt;
	for (int i = 0; i < nt; i++) {
		cin >> r >> c >> n;
		cout << "Case #" << i + 1 << ": ";
		cout << solve() << endl;
	}
	return 0;
}
