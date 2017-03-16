#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <iostream>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define piii pair<pair<int,int>,int>
#define pii pair<int,int>
#define pdd pair<double,double>
#define MAXB 1010
#define MAXTIME 0x3f3f3f3f3fLL
#define llint long long

int B;
llint N;
llint b[MAXB];

void Debug()
{
}

void Read()
{
    cin >> B >> N;

    for(int i=1; i<=B; ++i)
        cin >> b[i];
}

llint findCut(llint tim)
{
    llint out=0LL;
    for(int i=1; i<=B; ++i)
        out += (llint)((tim+((b[i]-(tim%b[i]))%b[i]))/b[i]);
//    printf("findCut(%lld): %lld\n", tim, out);
    return out;
}

llint findTime(llint Ord)
{
    llint lo = 0LL, hi = MAXTIME, mid;

    while(lo < hi)
    {
        mid = (lo+hi+1LL)/2LL;
        if(findCut(mid) < Ord)
            lo = mid;
        else
            hi = mid-1;
    }

    return lo;
}

int Solve()
{
    llint tim = findTime(N);
//    printf("tim: %lld\n", tim);
    llint countCut = findCut(tim);
    int left = (int)(N-countCut);
//    printf("left: %d\n", left);
//    ++tim;

    for(int i=1; i<=B; ++i)
    {
        if(tim % b[i] == 0LL)
        {
            if(left == 1)
                return i;
            else
                --left;
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; ++i)
    {
        Read();
        printf("Case #%d: ", i);
        cout << Solve() << "\n";
        Debug();
    }
    return 0;
}
