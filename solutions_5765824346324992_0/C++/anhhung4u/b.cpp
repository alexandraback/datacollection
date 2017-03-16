//Pham Huu Canh
//
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

#define fii "b.inp"
#define foo "b.out"
#define MOD 1000000007

using namespace std;

typedef pair<int, int> II;
typedef vector<int> VI;

int gcd(int x, int y){
	int r;
	while (y)	r = x % y, x = y, y = r;
	return x;
}
int lcm(int x, int y){
	return x / gcd(x, y) * y;
}

int a[20], t[20];

void input()
{
	int itest, ntest, k, bcnn, n;
	int i, id, j;
	
	scanf("%d", &ntest);
	repi(itest, 1, ntest){
		scanf("%d %d", &n, &k);
		fori(i, n)	scanf("%d", &a[i]);
		
		bcnn = 1;
		fori(i, n)	bcnn = lcm(bcnn, a[i]);
		
		k %= bcnn;
		fori(i, n)	t[i] = 0;
		fori(i, k){
			int mint = maxty;
			fori(j, n)	if (t[j] < mint)	mint = t[j], id = j;
			t[id] += a[id];
		}
		
		printf("Case #%d: %d\n", itest, id);
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

