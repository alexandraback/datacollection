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
#define MAXN 1010
#define llint long long

int N;
llint a[MAXN];

void Debug()
{
}

void Read()
{
    cin >> N;
    for(int i=1; i<=N; ++i)
        cin >> a[i];
}

llint Count1()
{
    llint out = 0LL;
    for(int i=2; i<=N; ++i)
        if(a[i-1] > a[i])
            out += (a[i-1]-a[i]);
    return out;
}

llint Count2()
{
    llint maxdiff=0LL, out=0LL;
    for(int i=2; i<=N; ++i)
        if(a[i-1] > a[i])
            maxdiff=max(maxdiff, a[i-1]-a[i]);
    for(int i=1; i<N; ++i)
    {
        if(a[i] > maxdiff)
            out += maxdiff;
        else
            out += a[i];
    }

    return out;
}

void Solve()
{
    cout << Count1() << " " << Count2() << "\n";
}

int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; ++i)
    {
        Read();
        printf("Case #%d: ", i);
        Solve();
        Debug();
    }
    return 0;
}
