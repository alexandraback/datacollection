#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>

using namespace std;
//-----------------------------------------------------------
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

#define bit(i) ((ull)1 << i)
//-----------------------------------------------------------
//#define DBG
#define MAXN 110

int N;
int ans;
int len;
bool isok;
char s[MAXN][MAXN];

struct S{
	char c;
	int cnt;
}n[MAXN][MAXN];

void readfile(){
	scanf("%d", &N);
	forn(i, N){
		scanf("%s", s[i]);

		char tmp = s[i][0];
		int tmpi = 0;
		n[i][tmpi].c = s[i][0];
		n[i][tmpi].cnt = 1;
		//printf("%s <= \n", s[i]);
		for(int j = 1; j < (int)strlen(s[i]); j++) {
			if( s[i][j] == tmp ) {
				n[i][tmpi].cnt++;
			} else {
				tmpi++;
				tmp = s[i][j];
				n[i][tmpi].c = s[i][j];
				n[i][tmpi].cnt = 1;
			}
			//printf("%d %d %d\n", i, j, tmpi);
		}
		if(!len) len = tmpi + 1;
		if(len != tmpi + 1) isok = false;
		//printf("%d\n", len);
	}
}

void solve(){
	// check first
	int tmp[MAXN];

	forn(i, len)
	{

		for( int j = 1; j < N; j++ ){
			if(n[j][i].c != n[0][i].c) {
				isok = false;
				return;
			}
		}
	}

	forn(i, len)
	{
		memset(tmp, 0, sizeof(tmp));
		forn(j, N)
		{
			tmp[j] = n[j][i].cnt;

		}
        sort( tmp, tmp + N );
        forn(k, N) {
        	//printf("%d %d\n", tmp[k], tmp[N>>1]);
            ans += abs(tmp[k]-tmp[N>>1]);
        }
	}
}

int main() {
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {
		ans = 0;
		len = 0;
		isok = true;
		memset(s, 0, sizeof(s));
		memset(n, 0, sizeof(n));
		readfile();

		solve();

		if(isok) {
			printf("Case #%d: %d\n", casenum++, ans);
		}
		else {
			printf("Case #%d: Fegla Won\n", casenum++);
		}
		fflush(stdout);
	}
	return 0;
}
