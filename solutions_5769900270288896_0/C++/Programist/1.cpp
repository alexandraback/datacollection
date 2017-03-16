#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <functional>
 
#pragma comment(linker, "/STACK:134217728")
 
using namespace std;
//
//long long f(long long n)
//{
//	int res = 0;
//	while(n > 0)
//	{
//		res = res * 10 + n % 10;
//		n /= 10;
//	}
//	return res;
//}
//int dp[1000100];
//
//long long calc(long long n)
//{
//	long long ans = 0;
//	while(n > 0)
//	{
//		if(!(n % 10))
//		{
//			n--;
//			ans++;
//		}
//
//		if(f(n) >= n && n > 0)
//		{
//			n--;
//			ans++;
//		}
//		 else
//			if(n > 0)
//			{
//				 n = f(n);
//				 ans++;
//			}
//	}
//	return ans;
//}
int x[33][33];
int ans = 10000;


void go(int a, int b, int cnt, int k, int n, int m) {
	//cout << a << " " << b << cnt << endl;
	if(cnt == k)
	{
		//cout << "here"  << endl;
		int temp = 0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
			{
				if(x[i][j] == 1 && x[i+1][j] == 1) temp++;
				if(x[i][j] == 1 && x[i][j+1] == 1) temp++;
			}
		//cout << temp << endl;
		ans = min(ans, temp);
	}
	else
	{
		for(int i=a; i<=n; i++)
			for(int j=b; j<=m; j++)
				if(x[i][j] != 1)
				{
					x[i][j] = 1;
					go(i, j, cnt + 1, k, n, m);
					x[i][j] = -1;
				}

		for(int i=a+1; i<=n; i++)
			for(int j=1; j<=m; j++)
				if(x[i][j] != 1)
				{
					x[i][j] = 1;
					go(i, j, cnt + 1, k, n, m);
					x[i][j] = -1;
				}
	}
}

int brute(int n, int m, int k) {
	for(int i=0; i<=17; i++)
		for(int j=0; j<=17; j++)
			x[i][j] = -1;
	ans = 101010;

	go(1, 1, 0, k, n, m);
	return ans;
}
int main() {   
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	//dp[0] = 0;
	//for(int i=1; i<=1000000; i++) {
	//	dp[i] = dp[i-1] + 1;
	//	if(i <= 10 || !(i % 10)) dp[i] = dp[i-1] + 1;
	//	else
	//	{
	//		int p = f(i);
	//		if(p < i)
	//			dp[i] = min(dp[i-1] + 1, dp[f(i)] + 1);

	//	}
	//}

	for(int t=1; t<=T; t++) {
		int n, m, k;
		cin >> n >> m >> k;

		cout << "Case #" << t << ": ";
		cout << brute(n, m, k) << endl;
	}
    return 0;
}