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

#define MAX 10002

int R, C, K;
int bad[MAX][MAX];

void addx(int a, int b) {
	if(a < 0 || a >= R) return;
	if(b < 0 || b >= C) return;
	bad[a][b]++;
}

void add(int a, int b) {
	addx(a-1, b);
	addx(a+1, b);
	addx(a, b-1);
	addx(a, b+1);
}

int greedy(int startc) {
	FOR(i, R) FOR(j, C) bad[i][j] = 0;
	int k = K;
	for(int i = 0; k && i < R; i++) {
		int j1 = (i % 2) ? startc : (1 - startc); 
		for (int j = j1; k && j < C; j += 2) {
			k--;
			add(i, j);
		}
	}

	/*
	cout << "GO FOR " << R << "," << C << "," << K << " and " << startc << endl;
	FOR(i, R) {
		FOR(j, C) {
			cout << bad[i][j] << ",";
		}
		cout << endl;
	}
	*/

	// include the extra guys
	vector<int> v;
	FOR(i, R) {
		FOR(j, C) {
			if(bad[i][j]) {
				v.pb(bad[i][j]);
			}
		}
	}
	sort(all(v));
	int score = 0;
	int until = min(k, sz(v));
	if (until < k) {
		return MAX * MAX;
	}
	FOR(i, until) {
		score += v[i];
	}
	return score;
}

void solve() {
	cin >> R >> C >> K;
	int ans = min(greedy(0), greedy(1));
	cout << ans << endl;
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
