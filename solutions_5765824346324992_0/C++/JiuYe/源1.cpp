/*
by:http://blog.csdn.net/acmmmm
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <time.h>
#include <string>
#include <queue>
template <class T>
inline bool rd(T &ret) {
	char c; int sgn;
	if (c = getchar(), c == EOF) return 0;
	while (c != '-' && (c<'0' || c>'9')) c = getchar();
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : (c - '0');
	while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
	ret *= sgn;
	return 1;
}
template <class T>
inline void pt(T x) {
	if (x <0) {
		putchar('-');
		x = -x;
	}
	if (x>9) pt(x / 10);
	putchar(x % 10 + '0');
}
using namespace std;
typedef long long ll;
const int N = 1000;
int gcd(int x, int y){
	if (x > y)swap(x, y);
	while (x){ y %= x; swap(x, y); }
	return y;
}
int lcm(int x, int y){
	return x / gcd(x, y)*y;
}
int n, B, a[N], lm, peo;
int solve(){
	if (n == 0)n += peo;
	for (int i = 0; ; i++){
		for (int j = 1; j <= B; j++)
		{
			if (i % a[j] == 0)
			{
				n--;
				if (n == 0)return j;
			}
		}
	}
	return 1;
}
int main()
{
	freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
	int T, Cas = 1;
	rd(T);
	while (T--){
		rd(B); rd(n);
		lm = 1;
		peo = 0;
		for (int i = 1; i <= B; i++)rd(a[i]), lm = lcm(lm, a[i]);
		for (int i = 1; i <= B; i++){
			peo += lm / a[i];
		}
		n %= peo;


		printf("Case #%d: %d\n", Cas++, solve());
	}
	return 0;
}
