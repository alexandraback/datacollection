#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <climits>
#include <stdint.h>
#include <utility>
#include <set>
#include <stack>
#define DEBUG 0
#define LOG if(DEBUG)
using namespace std;
typedef int64_t intt;
#define MAX_VAL	LLONG_MAX 
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((y) > (x) ? (x) : (y))
template <typename T>
void printvec(vector<T> v) {
	for(typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
}

pair<int, int> code() {
	int N;
	cin >> N;
	vector<int> m(N);
	for(int i = 0; i < N; i++) {
		cin >> m[i];
	}

	int MIN1 = 0;
	int mindiff = 0;
	for(int i = 0; i < N - 1; i++) {
		if(m[i] > m[i+1]) {
			MIN1 += m[i] - m[i+1];
			mindiff = max(mindiff, m[i] - m[i + 1]);
		}
	}
	int MIN2 = 0;
	for(int i = 0; i < N - 1; i++) {
		MIN2 += min(m[i], mindiff);
	}
	if(mindiff == INT_MAX) MIN2 = 0;

	return make_pair<int, int>(MIN1, MIN2);
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		pair<int, int> res = code();
		cout << "Case #" << t << ": " << res.first << " " << res.second << endl;
	}
}

