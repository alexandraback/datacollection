#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <algorithm>
// Problem A

#include <set>
#include <string.h>
#include <map>
#include <queue>
#include <stack>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<ii> vii;

void solve() {
	int N;
	cin >> N;
	int m[1010];
	for (int i=0; i<N; i++) cin >> m[i];
	
	int s1 = 0;
	int s2 = 0;
	int v = 0;
	
	for (int i=0; i<N-1; i++) {
		s1+=max(0, m[i]-m[i+1]);
		v=max(v, m[i]-m[i+1]);
	}
	for (int i=0; i<N-1; i++)
		s2 += min(v, m[i]);
		
	cout << s1 << " " << s2 << endl;
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
	
	return 0;
}
