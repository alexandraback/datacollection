#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

int N;
int x[MAXN];
int main(){
	int cs;
	cin >> cs;
	REP(csn, 1, cs + 1){
		printf("Case #%d: ", csn);
		cin >> N;
		REP(i, 0, N) scanf("%d", x + i);
		int ans0 = 0, ans1 = 0, rate = 0;
		REP(i, 1, N){
			if (x[i] < x[i - 1]) {
				ans0 += x[i - 1] - x[i];
				rate = max(rate, x[i - 1] - x[i]);
			}
		}
		REP(i, 1, N){
			ans1 += min(x[i - 1], rate);
		}
		printf("%d %d\n", ans0, ans1);
	}
	return 0;
}