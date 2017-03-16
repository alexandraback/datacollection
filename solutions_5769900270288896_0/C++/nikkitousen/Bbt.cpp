#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define LL long long

LL R, C, N;

int a[20][20];
int best;

void bt(int r, int c, int n, int w) {
	if(n == 0) {
		if(w < best) best = w;
		return;
	}
	if(w >= best) return;
	if(r >= R || c >= C) return;
	
	
	// branch 1: skip
	if(c < C-1) bt(r, c+1, n, w);
	else bt(r+1, 0, n, w);
	
	// branch 2: put
	int auxw = w;
	
	a[r][c] = 1;
	if(r > 0 && a[r-1][c] == 1) auxw++;
	if(c > 0 && a[r][c-1] == 1) auxw++;
	
	if(c < C-1) bt(r, c+1, n-1, auxw);
	else bt(r+1, 0, n-1, auxw);
	
	a[r][c] = 0;
}



int main()
{
  int T;
  cin >> T;
  REP(caso, T) {
    cout << "Case #" << caso+1 << ": ";
   	cin >> R >> C >> N;
   	if(R > C) swap(R, C);
   	
   	memset(a, 0, sizeof(a));
   	best = 999999999;
   	
   	bt(0,0,N,0);
   	
   	cout << best << endl;
  }
}

   
   	