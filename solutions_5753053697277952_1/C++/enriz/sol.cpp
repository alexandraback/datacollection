#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <tuple>
#include <functional>
#include <cassert>

using namespace std;

typedef long long tl; //type long
int _tc;

#define LEN(x) (sizeof(x) / sizeof(*x))
#define ABS(x) ((x > 0) ? (x) : -(x))
#define FORIN(i, n) for (int i = 0; i < n; ++i)
#define SIZE 100

bool testCase() {
	int ps[SIZE];
	int n;
	int sum = 0;	
	cin >> n;
	FORIN(i, n) {
		cin >> ps[i];
		sum += ps[i];
	}
	while (sum > 0) {
		FORIN(i, n) {
			cerr << " " << ps[i] << endl;
			assert((ps[i] * 1000 / sum) <= 500);
		}
		int* mmax = std::max_element(ps, ps + n);
		assert(mmax);
		int max = *mmax;
		std::vector<int> topush;
		FORIN(i, n) {
			if (ps[i] == max) {
				topush.push_back(i);
			}
			if (topush.size() == 2)
				break;
		}		
		int c = topush.size();
		cout << " " << (char)('A' + topush[0]);
		ps[topush[0]] -= 1;
		sum -= 1;
		if (topush.size() == 2 && (sum % 2) != 0) {
			cout << (char)('A' + topush[1]);
			ps[topush[1]] -= 1;
			sum -= 1;
		}
		else if (ps[topush[0]] > 0 && (sum % 2) != 0) {
			cout << (char)('A' + topush[0]);
			ps[topush[0]] -= 1;
			sum -= 1;
		}
	}
	return true;
}

int main(){
	int ntc;

	cin >> ntc;
	//cerr << "tests " << n << endl;
	for (int _tc = 0; _tc < ntc; ++_tc) {
		cout << "Case #" << (_tc + 1) << ":";
		if (!testCase()) {
			cout << " IMPOSSIBLE";
		}
		cout << endl;
	}
	return 0;
}