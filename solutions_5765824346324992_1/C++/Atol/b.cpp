#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
#define sz(A) (int)(A).size()
#define FOR(A,B) for(int A=0; A < (int) (B);A++)
#define FOREACH(I,C) for(__typeof(C.begin()) I = (C).begin(); I != (C).end(); I++)
#define pb push_back
#define all(x) x.begin() , x.end()
#define mp make_pair

int B, N;
vector<int> times;

long long qtd(long long at) {
	if (at < 0) {
		return 0;
	}
	if (at == 0) {
		return B;
	}
	long long done = 0;
	FOR(i, B) {
		done += (long long) (at / times[i]) + 1;
	}
	return done;
}

void debug_input() {
	return;
	cout << "B = " << B << ", N = " << N << endl;
	FOR(i, B) {
		cout << times[i] << ", ";
	}
	cout << endl;
}

int calc() {
	long long begin = 0, end = 1000000000000000ll;
	while(begin + 3 < end) {
		long long mid = (begin + end) / 2;
		if (qtd(mid) >= N) {
			end = mid;
		} else {
			begin = mid+1;
		}
	}
	debug_input();
	for(long long at = begin; at <= end; at++) {
		long long posso = qtd(at);
		if (posso >= N) {
			// cout << "AT " << at << " posso " << posso << endl;
			long long tinha = qtd(at-1);
			// cout << "AT menos um " << at-1 << " tinha " << tinha << endl;
			long long missing = N - tinha;
			FOR(free_id, B) {
				if (at % times[free_id] == 0) {
					missing--;
					if (missing == 0) {
						return free_id;
					}
				}
			}
			return -2;
		}
	}
	return -2;
}

void solve() {
	times.clear();
	cin >> B >> N;
	FOR(i, B) {
		int aux;
		cin >> aux;
		times.pb(aux);
	}

	if (B >= N) {
		cout << N << endl;
		return;
	}

	int x = calc();
	cout << x+1 << endl;
}

int main() {
  int num_testes;
  scanf("%d", &num_testes);
  for(int t = 1; t <= num_testes; t++) {
    printf("Case #%d: ", t);
    solve();
  }
  return 0;
}
