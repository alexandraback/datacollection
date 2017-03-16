#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <math.h>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <time.h>
#include <stdio.h>
#include <deque>
#include <string.h>


#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define POW(n) ((n)*(n))
#define cerr if(true) cerr

using namespace std;

typedef char S8;
typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<unsigned long long> vull;

int T, N;
vi P;

char getChar(int i) {
	return static_cast<char>('A' + i);
}

vi getMaxIndex() {
	vi ret;
	int max = 0;

	REP(i, N) {
		if (P[i] > max) {
			ret.clear();
			max = P[i];
			ret.push_back(i);
		}
		else if (P[i] == max) {
			ret.push_back(i);
		}
	}

	return ret;
}

bool isEmpty() {
	for (int n : P) {
		if (n > 0)return false;
	}
	return true;
}

void solve() {

	while (!isEmpty()) {
		vi max = getMaxIndex();
		string out = " ";

		if (max.size() == 1) {
			out += getChar(max[0]);
			P[max[0]]--;
		}
		else if (max.size() == 2 || max.size() > 3) {
			out += getChar(max[0]);
			out += getChar(max[1]);
			P[max[0]]--;
			P[max[1]]--;
		}
		else if (max.size() == 3) {
			out += getChar(max[0]);
			P[max[0]]--;
		}
		assert(!max.empty());

		cout << out;
	}
}

int main() {
	P.reserve(30);
	cin >> T;

	REP(t, T) {
		P.clear();
		cin >> N;

		REP(n, N) {
			int Pi;
			cin >> Pi;
			P.push_back(Pi);
		}

		printf("Case #%d:", (t + 1));
		solve();
		cout << endl;
	}

	return 0;
}