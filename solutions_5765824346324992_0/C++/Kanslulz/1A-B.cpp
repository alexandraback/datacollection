#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

#define ll long long



int gcd(int u, int v) {
	int t;
	while (v) {
		t = u;
		u = v;
		v = t % v;
	}
	return u < 0 ? -u : u; /* abs(u) */
}

int simulate(vector<int> &v, int g, int rank) {
	if (rank <= v.size())
		return rank;
	
	
	int ans = v.size();
	int mint = g;
	while (true) {
		for (int i = 0; i < v.size(); i++) {
			if (mint%v[i] == 0)
				ans++;
			if (ans == rank)
				return i + 1;
		}
		mint+=g;
	}
	return -1;
}

int main() {
	ifstream cin("in.in");
	ofstream cout2("out.txt");
	int T;
	cin >> T;
	for (int idx = 1; idx <= T; idx++) {
		int B,N;
		cin >>B >> N;
		vector<int> v(B);
		for (int i = 0; i < B; i++)
			cin >> v[i];

		int g;
		if (B == 1) {
			cout2 << "Case #" << idx << ": " << N << endl;
			continue;
		}
		else {
			g = gcd(v[0], v[1]);
			for (int i = 2; i < v.size(); i++)
				g = gcd(g, v[i]);
		}
		int prod = 1;
		for (auto i : v) prod *= i;
		int lcm = prod / g;
		int period = 0;
		for (auto i : v)
			period += lcm / i;
		int rank = N % period;
		if (rank == 0) rank = period;
		

		cout2 << "Case #" << idx << ": " << simulate(v,g,rank) << endl;
		cout << "Case #" << idx << ": " << simulate(v, g, rank) << endl;
	}
	return 0;
}