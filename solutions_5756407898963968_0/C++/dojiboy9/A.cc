#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>
#include <deque>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef complex<ld> vec;

typedef pair<int,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

#define MAXN MAXR*MAXC
#define MAXR 5
#define MAXC MAXR
int A[MAXR][MAXC];
int a[MAXN];
int b[MAXN];
int main() {
	int TEST;
	cin >> TEST;
	
	const int R = 4; const int C = 4;
	FORALL(test,1,TEST) {
		int r1,r2;
		scanf("%d",&r1);
		FOR(i,R) FOR(j,C) scanf("%d",&A[i][j]), a[A[i][j]] = (i+1);
		scanf("%d",&r2);
		FOR(i,R) FOR(j,C) scanf("%d",&A[i][j]), b[A[i][j]] = (i+1);
		
		vector<int> candidates;
		FORALL(i,1,16) if (a[i] == r1 && b[i] == r2)
			candidates.push_back(i);
		
		printf("Case #%d: ", test);
		if (candidates.size() == 0){
			printf("Volunteer cheated!\n");
		} else if (candidates.size() > 1) {
			printf("Bad magician!\n");
		} else {
			printf("%d\n", candidates[0]);
		}
	}
}













