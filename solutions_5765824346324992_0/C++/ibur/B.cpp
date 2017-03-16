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

int code() {
	int B, N;
	cin >> B >> N;
	vector<int> M(B);
	int maxt = 0;
	for(int i = 0; i < B; i++) {
		cin >> M[i];
		maxt = max(maxt, M[i]);
	}

	vector<int> offset(B, 0);
	vector<int> num(B, 0);
	long double total = 0;

/*
	for(int i = 0; i < B; i++) {
		total += ((long double) maxt) / M[i];
	}

	int iters = max((int) (floor(N / total) - 1), 0);
	int served = 0;
	for(int i = 0; i < B; i++) {
		served += ((intt) maxt * iters) / M[i];
		offset[i] = ((intt) maxt * iters) % M[i];
	}
*/
	for(int i = 0; i < B; i++) {
		total += ((long double) 1) / M[i];
	}

	intt iters = max((intt) (floorl(N / total) - 2 * maxt - 1), 0LL);
	intt served = 0;
	for(int i = 0; i < B; i++) {
		served += ((intt) iters) / M[i];
		offset[i] = M[i] - (((intt) iters) % M[i]);
	}
	//cout << total << " " << iters << " " << served << endl;
	N-=served;
	set<pair<intt, int> > remaining;
	for(int i = 0; i < B; i++) {
		if(offset[i] > 0) {
			N--;
			if(N == 0) return i + 1;
		}
		remaining.insert(make_pair<intt, int>(offset[i], i));
	}

	if(N <= 0) {
		cout << "ERROR" << endl;
	}
	int last_b = 0;
	while(N > 1) {
		pair<intt, int> next = *remaining.begin();
		remaining.erase(remaining.begin());
		N--;
		remaining.insert(make_pair(next.first + M[next.second], next.second));
	}

	last_b = remaining.begin()->second;

	return last_b + 1;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int res = code();
		cout << "Case #" << t << ": " << res << endl;
	}
}

