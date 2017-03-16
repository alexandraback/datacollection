/*
 * =====================================================================================
 *
 *       Filename:  b.cc
 *        Version:  1.0
 *        Created:  05/03/2015 12:20:58 AM
 *       Revision:  none
 *       Compiler:  GNU C++
 *
 *                     I  don't  want  to  be  alone.
 *
 * =====================================================================================
 */
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB              push_back
#define SIZE(x)         (int)x.size()
#define clr(x,y)        memset(x,y,sizeof(x))
#define MP(x,y)         make_pair(x,y)
#define RS(n)           scanf ("%s", n)
#define ALL(t)          (t).begin(),(t).end()
#define FOR(i,n,m)      for (int i = n; i <= m; i ++)
#define ROF(i,n,m)      for (int i = n; i >= m; i --)
#define IT              iterator
#define FF              first
#define SS              second

typedef long long               ll;
typedef unsigned int            uint;
typedef unsigned long long      ull;
typedef vector<int>             vint;
typedef vector<string>          vstring;
typedef pair<int, int>          PII;

void RI (int& x){
	x = 0;
	char c = getchar ();
	while (!(c>='0' && c<='9' || c=='-'))     c = getchar ();
	bool flag = 1;
	if (c == '-'){
		flag = 0;
		c = getchar ();
	}
	while (c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar ();
	}
	if (!flag)      x = -x;
}
void RII (int& x, int& y){RI (x), RI (y);}
void RIII (int& x, int& y, int& z){RI (x), RI (y), RI (z);}
void RC (char& c){
	c = getchar ();
	while (c == ' '||c == '\n')     c = getchar ();
}
char RC (){
	char c = getchar ();
	while (c == ' '||c == '\n')     c = getchar ();
	return c;
}

/**************************************END define***************************************/

const ll mod = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;

int a[104][104];

int main (){
	int T;
	RI (T);
	FOR (cas, 1, T){
		int r, c, n;
		RIII (r, c, n);
		int t = r*c;
		int ans = INF;
		FOR (i, 0, (1<<t)-1){
			int sum = 0;
			clr (a, 0);
			FOR (j, 0, t-1){
				if ((1<<j)&i){
					sum ++;
					a[j/c][j%c] = 1;
				}
			}
			if (sum == n){
				int tt = 0;
				FOR (j, 0, r-1){
					FOR (k, 0, c-1){
						if (a[j][k]){
							if (k>0&&a[j][k-1]){
								tt ++;
							}
							if (j>0&&a[j-1][k]){
								tt ++;
							}
						}
					}
				}
				ans = min (ans, tt);
			}
		}
		printf ("Case #%d: %d\n", cas, ans);
	}
}


