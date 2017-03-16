#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define fi first
#define sc second
#define MP make_pair
#define pb push_back
#define PI acos(-1.0)
#define vi vector<int>
#define vii vector<pii>
#define ALL(c) (c).begin(), (c).end()
#define RESET( c,a ) memset( (c), a, sizeof(c) )
#define REP( a,b,c ) for ( int a=b, _c=c; a<_c; ++a )
#define RED( a,b,c ) for ( int a=b, _c=c; a>=_c; --a )
#define REPI( it, c ) for ( __typeof( (c).begin() ) it=(c).begin(); it!=(c).end(); ++it )

const int big = 1000000000;
const double INF = 1e9;
const double EPS = 1e-9;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

int main() {
	int T;
	scanf("%d",&T);
	for (int tc = 1; tc <= T; tc++) {
		int N,a,b;
		scanf("%d",&N);
		double angle[N+5][N+5];
		pii points[N+5];
		for (int i = 0; i < N; i++)
			scanf("%d%d",&points[i].fi,&points[i].sc);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				double deltaX = points[j].fi - points[i].fi;
				double deltaY = points[j].sc - points[i].sc;

				angle[i][j] = atan2(deltaY, deltaX) * 180.0 / PI;
				if (angle[i][j] < 0)
					angle[i][j] += 360.0;
			}
		}

		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				printf("%.0lf ",angle[i][j]);
			printf("\n");
		}
		*/

		printf("Case #%d:\n",tc);
		for (int k = 0; k < N; k++) {
			int mini = N;
			for (int i = 0; i < N; i++) {
				int count = 0;
				for (int j = 0; j < N; j++) {
					double temp = angle[k][j] - angle[k][i];
					if (temp < -EPS)
						temp += 360.0;
					if (temp <= 180.0+EPS || j == k) {
						count++;
					}
				}
				mini = min(mini,min(count,N-count));
			}
			printf("%d\n",mini);
		}
	}
	return 0;
}