//------------------------------------------------------------------------------
//  Problem : 
//  User    : 
//  Date    : 
//------------------------------------------------------------------------------


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

int n, m, p;
int a[100][100];
int TC;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void fillin(int x) {
	int now = 0;
	while(x) {
		if(x&1) {
			a[now/m][now%m] = 1;
		}
		x >>= 1;
		now++;
	}
	return;
}

int calc() {
	int ret = 0;
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < m; ++j)
	if(a[i][j])
	for(int k = 0; k < 4; ++k) {
		int x, y;
		x = i+dx[k], y = j+dy[k];
		if(x >= 0 && x < n && y >= 0 && y < m && a[x][y]) {
			ret++;
		}
	}
	return ret;
}

int ct(int x) {
	int ret = 0;
	while(x) {
		ret += x&1;
		x >>= 1;
	}
	return ret ;
}
		

void work(int testcase) {
	scanf("%d%d%d", &n, &m, &p);
	int N = 1<<(n*m);
	int ans = 10000000;
	for(int i = 0; i < N; ++i) {
		if(ct(i) == p) {
			memset(a, 0, sizeof(a));
			fillin(i);
			ans = min(ans, calc());
		}
	}
	printf("Case #%d: %d\n", testcase, ans>>1);
}

int main( int argc , char *argv[] )
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &TC);
	for(int i = 1; i <= TC; ++i) {
		work(i);
	}
	return 0;
}
