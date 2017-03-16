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
        int b, n;
        scanf("%d %d", &b, &n);
        vector<long long> times(b);
        for(int i=0; i<b; i++)
        {
            scanf("%lld", &times[i]);
        }

        long long lo=0;
        long long hi=1000000000000000000LL;
        while(lo<hi)
        {
            long long mid = (lo+hi+1)/2;
            long long clients_served = 0;
            for(int i=0; i<b; i++)
            {
                clients_served += (mid+times[i]-1)/times[i];
            }
            if(clients_served >= n)
            {
                hi = mid-1;
            }
            else
            {
                lo = mid;
            }
        }

        //cout << lo << endl;
        long long clients_served = 0;
        for(int i=0; i<b; i++)
        {
            clients_served += (lo+times[i]-1)/times[i];
        }
        //cout << clients_served << endl;
        vector< pair<int, int> > v(b);
        for(int i=0; i<b; i++)
        {
            if(lo%times[i] == 0)
            {
                v[i] = make_pair(0, i);
            }
            else
            {
                v[i] = make_pair(times[i]-lo%times[i], i);
            }
        }
        sort(v.begin(), v.end());
        int index = n-clients_served-1;
        printf("Case #%d: %d\n", kras, v[index].second+1);
    }
    return 0;
}
