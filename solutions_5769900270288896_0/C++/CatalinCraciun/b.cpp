#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

#define pb push_back
#define po pop_back

#define mp make_pair

#define inf 500000;

using namespace std;

ifstream f("input");
ofstream g("output");

int r,c,n;
int totalNoise = 0;
int A[20][20];

// Greedly trying to add a tenant
void tryTo() {
	int noise = 5;
	int bestx = -1, besty = -1;
	for (int i=1;i<=r;i++)
		for (int j=1;j<=c;j++) {
			if (A[i][j] == 1) continue;
			int tmp = 0;
			tmp += A[i][j-1] + A[i-1][j] + A[i+1][j] + A[i][j+1];
			if (tmp < noise) {
				noise = tmp;
				bestx = i;
				besty = j;
			}
		}
		
	A[bestx][besty] = 1;
	totalNoise += noise;
}

int answer;
int cost = 0;

void go(int i, int j, int gul) {
	if (gul > n)
		return;
		
	A[i][j] = 1;
	if (j < c) {
		cost += A[i-1][j] + A[i][j-1];
		go(i, j+1,gul+1);
		cost -= A[i-1][j] + A[i][j-1];
	} else if (i < r) {
		cost += A[i-1][j] + A[i][j-1];
		go(i+1, 1,gul+1);
		cost -= A[i-1][j] + A[i][j-1];
	} else {
		// Found possible config
		if (gul != n-1)
			return;
		
		answer = min(answer, cost + A[i-1][j] + A[i][j-1]);
	}
	
	A[i][j] = 0;
	if (j < c)
		go(i, j+1,gul);
	else if (i < r)
		go(i+1, 1,gul);
	else {
		// Found possible config
		if (gul != n)
			return;
		
		answer = min(answer, cost);
	}
}

void solve() {
	f>>r>>c>>n;
	memset(A, 0, sizeof(A));
	answer = INT_MAX;
	
	go(1,1,0);
	
	if (answer != INT_MAX)
		g<<answer;
	else
		g<<0;
}

int main() {
	
	int t; f>>t;
	for (int i=1;i<=t;i++) {
		g<<"Case #"<<i<<": ";
		solve();
		g<<'\n';
	}
	
	f.close(); g.close();
	return 0;
}