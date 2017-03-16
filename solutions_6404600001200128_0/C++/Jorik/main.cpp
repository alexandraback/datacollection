#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstdlib>
#include <set>
#include <map>
#include <fstream>

#define PI 3.14159265359

using namespace std;
typedef unsigned long long ull;

int main()
{
    freopen("inp.in", "r", stdin);
    freopen("outp.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int kras=1; kras<=tc; kras++)
    {
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &v[i]);
        }
        int a=0;
        int rate=0;
        for(int i=0; i<n; i++)
        {
            if(v[i] > v[i+1])
            {
                a += v[i]-v[i+1];
            }
            rate = max(rate, v[i]-v[i+1]);
        }

        int b=0;
        for(int i=0; i<n-1; i++)
        {
            b += min(rate, v[i]);
        }
        printf("Case #%d: %d %d\n", kras, a, b);
    }
    return 0;
}
