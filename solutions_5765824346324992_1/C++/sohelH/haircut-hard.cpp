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

struct Node {
	int tm, pos;
};

bool cmp(const Node &a, const Node &b) {
	if (a.tm != b.tm) return a.tm < b.tm;
	return a.pos < b.pos;
}

long long howMany(vector<int> &v, long long tm) {
	long long sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += tm / v[i] + 1;
	}
	return sum;
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

		long long low = 1;
		long long high = 1000000000;
		high *= 1000000;

		while (low < high) {
			long long mid = (low + high) / 2;
			long long processed = howMany(v, mid);
			if (processed < n) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		long long sofar = howMany(v, low - 1);
		long long dif = n - sofar;
		int i;
		for (i = 0; i < v.size(); i++) {
			if (low % v[i] == 0 ) dif--;
			if (dif == 0) break;
		}
		printf("Case #%d: %d\n", cases, i + 1);
	}
	return 0;
}
