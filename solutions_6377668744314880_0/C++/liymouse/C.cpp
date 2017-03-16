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
    //freopen("input.txt" , "r" , stdin);
	freopen("C-small-attempt4.in" , "r" , stdin);
	freopen("C-small-attempt4.out" , "w" , stdout);
    //freopen("output.txt" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d:\n" , ca);
        int n;
        scanf("%d" , &n);
        int x[3010] , y[3010];
        int res[3010];

        for (int i = 0; i < n; i ++)
        {
            scanf("%d %d" , &x[i] , &y[i]);
            res[i] = n;
        }
        
        if (n <= 3)
        {
            for (int i = 0; i < n; i ++) printf("0\n");
            continue;
        }
        

        for (int va = 0; va < (1<<n); va ++)
        {
            int num = 0;
            int tmp = va;
            while (tmp) {num += tmp & 1; tmp >>= 1;}
            if (n - num  <= 3)
            {
                for (int i = 0; i < n; i ++)
                    if (((1<<i) & va) == 0 && num < res[i])
                    {
                        res[i] = num;
                    }
                continue;
            }

            //find right-bottom
            int t;
            int sign[3010] = {0};
            int my = 10000000, mx = -1000000;
            for (int i = 0; i < n; i ++)
                if (((1<<i) & va) == 0)
                {
                    if (y[i] < my || (y[i] == my && x[i] > mx))
                    {
                        my = y[i];
                        mx = x[i];
                        t = i;
                    }
                }
            //sign[t] = 1;
            int start = t;
            int a1 = 1, b1 = 0;
            while (1)
            {
                double maxd = -10;
                i64d mindi = (i64d)10000000000000LL;
                int next = -1;
                for (int i = 0; i < n; i ++)
                    if ((((1<<i) & va) == 0) && i != t && sign[i] == 0)
                    {
                        int a2 = x[i]-x[t];
                        int b2 = y[i]-y[t];

                        double di = (double)a1*(double)a2 + (double)b1 * (double)b2;
                        double len1 = sqrt((double)a1*(double)a1+(double)b1*(double)b1);
                        double len2 = sqrt((double)a2*(double)a2+(double)b2*(double)b2);
                        double cosd = di / len1 / len2;
                        //if (cosd > maxd)
                        if (cosd - maxd > 1e-9)
                        {
                            next = i;
                            maxd = cosd;
                            mindi = (i64d)a2*(i64d)a2 + (i64d)b2*(i64d)b2;
                        }
                        //else if (cosd == maxd && len2 < mindi)
                        //else if (fabs(cosd-maxd)<1e-8 && len2 < mindi)
                        else
                        {
                            int a3 = x[next]-x[t];
                            int b3 = y[next]-y[t];
                            if ((i64d)a2*(i64d)b3-(i64d)b2*(i64d)a3 == 0)
                            {
                                if ((i64d)a2*(i64d)a2 + (i64d)b2*(i64d)b2 < mindi)
                                {
                                    next = i;
                                    maxd = cosd;
                                    mindi = (i64d)a2*(i64d)a2 + (i64d)b2*(i64d)b2;
                                }
                            }
                        }
                    }
                if (next == -1) break;
                sign[next] = 1;
                a1 = x[next] - x[t];
                b1 = y[next] - y[t];
                t = next;
                if (next == start) break;
            }
            
            for (int i = 0; i < n; i ++)
                if (sign[i] == 1 && num < res[i]) res[i] = num;
        }
        for (int i = 0; i < n; i ++) printf("%d\n" , res[i]);
    }
    return 0;
}