// Author : Abhisar Singhal
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>   
#include <map>
#include <string>  
#include <climits> 
#include <set>
#include <string>    
#include <sstream>
#include <utility>   
#include <ctime>
#include <cassert>
#include <fstream>
#include <iomanip>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<long long> VLL;
typedef vector<bool> VB;

#define SZ(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A, x) (A.find(x) != A.end())
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12

#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
inline void inp( int &n ) {
	n=0; int ch = getcx(); int sign = 1;
	while(ch < '0' || ch > '9') { if(ch == '-') sign=-1; ch = getcx(); }
	while(ch >= '0' && ch <= '9') { n = (n << 3) + (n << 1) + ch - '0', ch = getcx(); }
	n = n * sign;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int tc = 0;
	while (t--) {
		tc++;
		int n;
		cin >> n;
		vector<pair<int, int>> A;
		int left = 0;
		REP (i, n) {
			int x;
			cin >> x;
			left += x;
			A.push_back(MP(x, i));
		}
		string ans = "";
		sort(A.begin(), A.end());
		int diff = A[n - 1].X - A[n - 2].X;
		REP (i, diff) {
			ans += char('A' + A[n - 1].Y);
			A[n - 1].X--;
		}
		if (diff) ans += " ";
		REP (i, n - 2) {
			REP (j, A[i].X) {
				ans += char('A' + A[i].Y);
				ans += " ";
			}
		}
		REP (i, A[n - 1].X) {
			ans += char('A' + A[n - 1].Y);
			ans += char('A' + A[n - 2].Y);
			ans += " ";
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return 0;
}
