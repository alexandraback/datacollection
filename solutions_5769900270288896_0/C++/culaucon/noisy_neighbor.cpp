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
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

int dp[1000010];

bool ok(int m, int p) {
	return (((1<<p)&m)>0);
}

int main() {
	freopen("noisy_neighbor.in","r",stdin);
	freopen("noisy_neighbor.out","w",stdout);
	int tc, nt=1;
	cin>>tc;
	while (tc--) {
		int n, m, k;
		cin>>n>>m>>k;
		int ret=-1;
		for (int i=0;i<(1<<(n*m));i++)
			if (__builtin_popcount(i)==k) {
				int c=0;
				for (int x=0;x<n;x++)
					for (int y=1;y<m;y++)
						if (ok(i,x*m+y-1) && ok(i,x*m+y)) c++;
				for (int y=0;y<m;y++)
					for (int x=1;x<n;x++)
						if (ok(i,(x-1)*m+y) && ok(i,x*m+y)) c++;
				if (ret==-1 || ret>c) ret=c;
			}
		cout<<"Case #"<<nt++<<": "<<ret<<endl;
	}
}
