#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int R, C, n;
vector<vector<vector<vector<int> > > > dp;
int calc(int r, int c, int rem, int mask){
	if (rem<0)
		return 60000;
	if(c==C)
		return calc(r + 1, 0, rem, mask);
	if (r == R)
		return rem ? 60000 : 0;
	int &ret = dp[r][c][rem][mask];
	if(ret!=-1)
		return ret;
	ret = calc(r, c + 1, rem, mask&~(1 << c));
	ret = min((int)ret, ((mask >> c) & 1) + (!c ? 0 : ((mask >> (c - 1)) & 1)) + calc(r, c + 1, rem - 1, mask | (1 << c)));
	return ret;
}
int main()
{
	freopen("src.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int qq;
	scanf("%d", &qq);
	for (int T = 1; T <= qq; ++T){
		printf("Case #%d: ", T);
		cin >> R >> C >> n;
		dp = vector<vector<vector<vector<int> > > >(R, vector<vector<vector<int> > >(C, vector<vector<int> >(n + 1, vector<int>(1 << C, -1))));
		printf("%d\n", (int)calc(0, 0, n, 0));
	}
	return 0;
}