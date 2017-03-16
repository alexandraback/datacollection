#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

struct Barber
{
	int k;
	int t;
	Barber(int k_, int t_) : k(k_), t(t_) {}
};

bool operator<(const Barber& a, const Barber& b)
{
	return !(a.t < b.t || (a.t == b.t && a.k < b.k));
}

int gcd(int a, int b)
{
	int r = a % b;
	if (r == 0) return b;
	return gcd(b, r);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		int B, N;
		cin >> B >> N;
		priority_queue<Barber> pq;
		vector<int> Mk(B);
		for (int k = 0; k < B; ++k) {
			cin >> Mk[k];
			Barber b(k, 0);
			pq.push(b);
		}

		int l = Mk[0];
		for (int k = 1; k < B; ++k) {
			l = lcm(l, Mk[k]);
		}

		vector<Barber> pattern;
		Barber b(0, 0);
		while (!pq.empty()) { 
			b = pq.top();
			pq.pop();
			pattern.push_back(b);

			b.t += Mk[b.k];
			if (b.t < l)
				pq.push(b);
		}

		N = N - 1;
		N = N % pattern.size();

		cout << "Case #" << tt << ": " << pattern[N].k + 1 << endl;
	}
}
