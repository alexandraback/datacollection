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
	freopen("B-small-attempt1.in" , "r" , stdin);
	freopen("B-small-attempt1.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int b;
        i64d n;
        int a[1050];
        scanf("%d %lld" , &b , &n);
        for (int i = 0; i < b; i ++) scanf("%d" , &a[i]);

        if (n <= b) printf("%lld\n" , n);
        else
        {
            i64d high = ((i64d)1)<<47;
            i64d low = 0 , k = 0;
            while (low < high)
            {
                i64d mid = (high + low) / 2;
                i64d num = 0;
                for (int i = 0; i < b; i ++)
                {
                    num += (mid / (i64d)a[i]) + (mid % (i64d)a[i] > 0);
                }
                if (num >= n) high = mid - 1;
                else {low = mid + 1; k = mid;}
            }
            i64d num = 0;
            i64d t[1050] = {0};
            i64d r[1050] = {0};
            for (int i = 0; i < b; i ++)
            {
                t[i] = k / (i64d)a[i];
                r[i] = k % (i64d)a[i];
                if (r[i] > 0) r[i] = (i64d)a[i] - r[i];
                num += t[i] + (r[i] > 0);
            }
            i64d res = -1;
            while (num < n)
            {
                i64d mint = 10000000;
                for (int i = 0; i < b; i ++)
                {
                    if (r[i] == 0)
                    {
                        num ++;
                        r[i] = a[i];
                        if (num == n) {res = i+1; break;}
                        mint = min(mint , r[i]);
                    }
                    else mint = min(mint , r[i]);
                }
                for (int i = 0; i < b; i ++)
                {
                    r[i] -= mint;
                }
                if (res != -1) break;
            }
            printf("%lld\n" , res);
        }

    }
    return 0;
}