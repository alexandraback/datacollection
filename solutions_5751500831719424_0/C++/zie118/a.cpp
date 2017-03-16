#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;


#define PB push_back
#define MP make_pair

#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORE(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define CLR(s, x) memset(s, x, sizeof(s))

#define inf (1<<29)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int N;
int num[105], idx[105];
char s[105][105];

string uni(char* s) {
	string ret = "";
	int l = strlen(s);
	char pre = 0;
	FOR(i,0,l) {
		if (s[i] != pre) {
			if (pre != 0)
				ret.PB(pre);
			pre = s[i];
		}
	}
	if (pre != 0) ret.PB(pre);
	return ret;
}

int getnum(int i, char x) {
	int ret = 0;
	while (s[i][idx[i]] == x) {
		ret++;
		idx[i]++;
	}
	return ret;
}

int countmin() {
	int ret = inf;
	FOR(i,0,N) {
		int sum = 0;
		FOR(j,0,N) sum += abs(num[i] - num[j]);
		ret = min(ret, sum);
	}
	return ret;
}

int getmin() {
	int ret = 0;
	CLR(idx, 0);
	string order = uni(s[0]);
	FOR(i,0,order.length()) {
		char cur = order[i];
		CLR(num, 0);
		FOR(j,0,N) {
			num[j] = getnum(j, cur);
		}
		ret += countmin();
	}
	return ret;
}

int main()
{
	int T, cc=0; scanf("%d", &T);
	while (T--) {
		CLR(s, 0);
		scanf("%d\n", &N);
		FOR(i,0,N) gets(s[i]);
		string s0 = uni(s[0]);
		bool flag = true;
		FOR(i,1,N) {
			string si = uni(s[i]);
			if (s0 != si) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			printf ("Case #%d: Fegla Won\n", ++cc);
		} else {
			int ret = getmin();
			printf ("Case #%d: %d\n", ++cc, ret);
		}
	}
	return 0;
}
