#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;
typedef long long Long;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

int R,C;
int dp(int mask, int i,int j, int r){
	int mi = 1000000;
	if(i == R)return r == 0 ? 0 : 1000000;
	if(j == C)return dp(mask,i+1,0,r);
	//put one
	if(r){
		int t = (mask >> j)&1;
		if(j > 0)t += (mask >> (j-1))&1;
		mi = min(mi , dp(mask | (1<<j), i, j+1, r-1) + t );
	}
	//dont put
	{
		mi = min(mi , dp(mask & ~(1<<j), i, j+1, r) );
	}
	return mi;
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int TC;
	cin >> TC;
	for(int tc = 1 ; tc<=TC; ++tc){
		int N;
		cin >> R >> C >> N;
		cout << "Case #" << tc <<": " << dp(0,0,0,N) << endl;
	}
		
}
