#include <iostream>
#include <cassert>
using namespace std;

typedef long long LL;

const LL MAXM = 100000LL;
const LL MAXN = 1000000000LL;
const LL MAXH = MAXM * MAXN + 5;

int N;
int B;
LL M[1001];

LL f(LL h) {
	// sum_{i=0..B-1} {ceiling(h/M_i)}
	//cout << "h = " << h << endl;
	LL res = 0;
	for (int i = 0; i < B; i++) {
		//cout << "M[i] = " << M[i] << endl;
		res += (h+M[i]-1) / M[i];
	}
	//cout << "res = " << res << endl;
	return res;
}

LL binSearch(LL a, LL b) {
	//cout << a << " " << b << endl;
	if (a == b)
		return a;
	LL m = (a+b+1)/2;
	if (f(m) < N)
		return binSearch(m, b);
	//else
		return binSearch(a, m-1);
}

LL geth0() {
	return binSearch(0, MAXH);
}

int solve() {
	// find h s.t. f(h) < N and f(h+1) >= N
	LL h0 = geth0();
	int next = (LL)N - f(h0);
	//cout << "next = " << next << endl;
	// find next slot with M_k divids h
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (h0 % M[i] == 0) {
			cnt++;
			if (cnt == next)
				return i+1;
		}
	}
	return -1;
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> B >> N;
		for (int i = 0; i < B; i++)
			cin >> M[i];
		
		int res = solve();
		
		cout << "Case #" << icase << ": " << res << endl;
	}
	return 0;
}
