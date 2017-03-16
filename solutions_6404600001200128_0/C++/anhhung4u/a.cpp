//Pham Huu Canh
//Problem A. Mushroom Monster
//Algorithm:
//Complexity:
//AC:

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define max64 9223372036854775807LL
#define max32 2147483647
#define maxty 1001001001
#define max16 32767
#define EPS 1e-8
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define timmax(x, y)    ((x) > (y) ? (x) : (y))
#define timmin(x, y)    ((x) < (y) ? (x) : (y))
#define fori(i, n)      for((i) = 0; (i) < (n); (i)++)
#define ford(i, n)      for((i) = (n-1); (i) >= 0; (i)--)
#define fore(i, v)		for(typeof(v.begin()) i = v.begin(); i != v.end(); i++)
#define repi(i, a, b)   for((i) = (a); (i) <= (b); (i)++)
#define repd(i, a, b)   for((i) = (a); (i) >= (b); (i)--)
#define all(tmpv)      tmpv.begin(), tmpv.end()
#define ms(a, x)		memset(a, x, sizeof(a))

#define fii "a.inp"
#define foo "a.out"
#define MOD 1000000007

using namespace std;

typedef pair<int, int> II;
typedef vector<int> VI;

int a[1005];

void input()
{
	int itest, ntest, i, n;
	int res1, res2, diff;
	
	scanf("%d", &ntest);
	repi(itest, 1, ntest){
		scanf("%d", &n);
		diff = -maxty;
		repi(i, 1, n){
			scanf("%d", &a[i]);
			if (i > 1 && a[i] <= a[i-1])	diff = timmax(diff, a[i-1] - a[i]);
		}
		
		res1 = 0;
		repi(i, 2, n)	if (a[i] < a[i-1])	res1 += a[i-1] - a[i];
		
		res2 = 0;
		repi(i, 1, n-1)	res2 += timmin(diff, a[i]);
		
		printf("Case #%d: %d %d\n", itest, res1, res2);
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    	freopen(fii,"r",stdin);
    	freopen(foo,"w",stdout);
    #endif

    input();

    return 0;
}

