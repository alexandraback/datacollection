#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

int main()
{
	freopen("A-small-attempt0.in" , "r" , stdin);
	freopen("A-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int n;
        int a[1050];
        scanf("%d" , &n);
        for (int i = 0; i < n; i ++) scanf("%d" , &a[i]);
        int res1 = 0 , res2 = 0;
        int maxv = 0;
        for (int i = 1; i < n; i ++)
        {
            if (a[i-1] - a[i] > 0) res1 += (a[i-1]-a[i]);
            if (a[i-1] - a[i] > maxv) maxv = a[i-1] - a[i];
        }
        for (int i = 1; i < n; i ++)
        {
            if (a[i-1] > maxv) res2 += maxv;
            else res2 += a[i-1];
        }
        printf("%d %d\n" , res1 , res2);
    }
    return 0;
}