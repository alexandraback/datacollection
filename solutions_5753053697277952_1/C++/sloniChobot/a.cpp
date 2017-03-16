#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <limits>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <deque>
#include <queue>
#include <forward_list>
#include <stack>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <utility>
#include <sstream>

using namespace std;
typedef unsigned long long int ulint;
typedef long long int lint;
typedef pair<int,int> pi;
typedef pair<lint,lint> pl;
typedef vector<int> vi;
struct dbg_ {
	template<typename T> dbg_ & operator ,(const T & x) {
		cout << x << ' ';
		return *this;
	}
} dbg_t;

#define EPS 0.0000001
#define REP(i,a,b) for(int i=a;i<b;i++)
#define PER(i,a,b) for(int i=a;i>b;i--)
#define REPi(type,cont,a) for (type<int>::iterator a = cont.begin(); a!=cont.end(); ++a)
#define REPs(cont,a) for (set<int>::iterator a = cont.begin(); a!=cont.end(); ++a)
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define MIN(X, Y)  ((X) < (Y) ? (X) : (Y))
#define MAX(X, Y)  ((X) > (Y) ? (X) : (Y))
#define NUMDIGIT(x,y) (((int)(log10((x))/log10((y))))+1)
#define MP make_pair
#define PB push_back
#define ALL(a) a.begin(), a.end()
#define HAS(a,b) (a.find(b) != a.end())
#define x first
#define y second
#ifdef SLONICHOBOT
	#undef dbg
	#undef tu
	#define tu cout << "#line: " << __LINE__ << endl
	#define dbg(args ...) { cout << "|" << __LINE__ << "| "; dbg_t,args;cout << endl; }
	#define dbgg(X) cerr << #X ": " << X << endl
#else
	#define tu
	#define dbg
	#define dbgg
#endif

int abc[26];
void solve() {
	int n; cin >> n;
	int sum = 0;
	REP(i,0,n) {
		cin>>abc[i];
		sum += abc[i];
	}

	while(sum > 0) {
		int lemax = 0, maxind, maxcnt = 0, othermax = 0;
		REP(i,0,26) if (lemax < abc[i]) { lemax=abc[i]; maxind = i;  maxcnt=1; } else if (lemax == abc[i]) { maxcnt++; othermax=i; }
		if (maxcnt == 2) {
			sum--; abc[othermax]--;
			cout << (char)('A'+othermax);
		}
		sum--; abc[maxind]--;
		cout << (char)('A'+maxind) << ' ';
	}
	cout << endl;
}

int main()
{
	int T; cin >> T;
	REP(i,0,T) {
		cout << "Case #" << (i+1) << ": ";
		solve();
	}

	return 0;
}
