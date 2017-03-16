#include <cstdio>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REPE(i,x,y) for (int i=(x);i<(y);i++)
#define REP(i,x,y) for (int i=(x);i<=(y);i++)
#define DREP(i,x,y) for (int i=(x);i>=(y);i--)
#define mp make_pair
#define pb push_back
#define MAXN 100100

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int A[MAXN];

int main() {
	ios::sync_with_stdio(false);
	int tc; cin>>tc; int n;
	REP(qq,1,tc) {
		cin>>n;
		REP(i,1,n) {
			cin>>A[i];
		}
		int ans1 = 0;
		REP(i,1,n-1) {
			if (A[i] > A[i+1]) { ans1 += A[i] - A[i+1]; }
		}
		int ans2 = 0;
		int diff = 0;
		REP(i,1,n-1) {
			diff = MAX(diff, A[i] - A[i+1]);
		}

		REP(i,1,n-1) {
			ans2 += MIN(A[i],diff);
		}

		cout<<"Case #"<<qq<<": "<<ans1<<" "<<ans2<<endl;
	}
	
}
