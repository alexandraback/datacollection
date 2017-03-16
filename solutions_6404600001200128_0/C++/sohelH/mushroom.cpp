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

int methodOne(int n, vector<int> v) {
	int sum = 0;
	int cur = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i] < cur) {
			sum += cur - v[i];
		}
		cur = v[i];
	}
	return sum;
}

int methodTwo(int n, vector<int> v) {
	int low = 0;
	int high = 10000;

	while(low < high) {
		int p = (low + high) / 2;
		int cur = v[0];
		int sum = 0;
		int i;
		for (i = 1; i < n; i++) {
			int newVal = cur - p;

			if (newVal < 0) sum += cur;
			else if (newVal <= v[i]) {
				sum += p;
			}

			if (newVal <= v[i]) cur = v[i];
			else {
				break;
			}
		}
		if (i == n) {
			high = p;
		} else {
			low = p + 1;
		}
	}
	low = low - 5;
	if (low < 0) low = 0;
	for (int p = low; p < low + 10; p++) {
		int cur = v[0];
		int sum = 0;
		int i;
		for (i = 1; i < n; i++) {
			int newVal = cur - p;

			if (newVal < 0) sum += cur;
			else if (newVal <= v[i]) {
				sum += p;
			}

			if (newVal <= v[i]) cur = v[i];
			else {
				break;
			}
		}
		if (i == n) return sum;
	}
	return -1;
}


int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		int n;
		vector<int> v;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a; cin >> a; v.push_back(a);
		}

		int one = methodOne(n, v);
		int two = methodTwo(n, v);

		printf("Case #%d: %d %d\n", cases, one, two);

	}
	return 0;
}
