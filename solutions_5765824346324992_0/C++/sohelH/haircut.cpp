#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int findLcm(vector<int> &v) {
	int lcm = v[0];
	for (int i = 1; i < v.size(); i++) {
		int g = gcd(lcm, v[i]);
		lcm /= g;
		lcm *= v[i];
	}
	return lcm;
}

struct Node {
	int tm, pos;
};

bool cmp(const Node &a, const Node &b) {
	if (a.tm != b.tm) return a.tm < b.tm;
	return a.pos < b.pos;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		int b, n; vector<int> v;
		cin >> b >> n;
		for (int i = 0; i < b; i++) {
			int a; cin >> a; v.push_back(a);
		}

		if (n <= b) {
			printf("Case #%d: %d\n", cases, n);
			continue;
		}

		n -= b;

		int lcm = findLcm(v);
		//DEBUG(lcm);
		//n = n % lcm;
		//if (n == 0) n = lcm;
		//DEBUG(n);
		vector<Node> vn;
		for (int i = 0; i < v.size(); i++) {
			int cur = v[i];
			while (cur <= lcm) {
				Node nd; nd.tm = cur; nd.pos = i + 1;
				vn.push_back(nd);
				cur += v[i];
			}
		}

		n--;
		n %= vn.size();

		sort(vn.begin(), vn.end(), cmp);
		printf("Case #%d: %d\n", cases, vn[n].pos);

	}
	return 0;
}
