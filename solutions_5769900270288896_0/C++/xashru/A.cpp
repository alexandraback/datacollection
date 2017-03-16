#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <ratio>
#include <regex>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <valarray>

using namespace std;

#define sz(v) v.size()
#define eps 1e-10
#define fill(v,n,x) for(int i=0;i<(int)n;i++) v.push_back(x)
#define re return
#define sum(v) accumulate(v.begin(),v.end(),0)
#define asrt(v) sort(v.begin(),v.end())
#define dsrt(v) sort(v.rbegin(),v.rend())
#define rev(v) reverse(v.begin(),v.end())
#define pi 3.1415926535897932384626433832795
#define print(v) for (auto& i:v) cout<<i<<endl
#define print "Case #"+to_string(t1)+": "

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;

int B[20][20];

int main() {
	freopen("b.txt", "r", stdin);
	freopen("b.out", "w", stdout);
	int T;
	cin>>T;
	for(int t1=1; t1<=T; t1++) {
		int r,c,N;
		cin>>r>>c>>N;
		int n=r*c;
		int res=99999999;
		for(int i=0; i<(1<<n); i++) {
			int cnt=0;
			for(int x=0; x<r; x++) for(int y=0; y<c; y++) B[x][y]=0;
			for(int j=0; j<n; j++) {
				if(i&(1<<j)) {
					cnt++;
					int ii=j/c,jj=j%c;
					B[ii][jj]=1;
				}
			}
			if(cnt!=N) continue;
			int cur=0;
			for(int i=0; i<r; i++) {
				for(int j=0; j<c-1; j++) {
					if(B[i][j]==1 && B[i][j+1]==1) cur++;
				}
			}
			for(int i=0; i<r-1; i++) {
				for(int j=0; j<c; j++) {
					if(B[i][j]==1 && B[i+1][j]==1) cur++;
				}
			}
			res=min(res,cur);
		}
		cout<<print<<res<<endl;
	}
	return 0;
}

