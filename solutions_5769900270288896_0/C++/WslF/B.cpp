//solution by Wsl_F
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <bitset>
#include <numeric>
#include <cassert>
#include <time.h>
#include <ctime>
#include <memory.h>
#include <complex>
#include <utility>
#include <climits>
#include <cctype>
#include <x86intrin.h>



using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")


typedef long long LL;
typedef unsigned long long uLL;
typedef double dbl;
typedef vector<int> vi;
typedef vector<LL> vL;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)
#define sqr(x) ((x)*(x))

void solve()
{
    LL r,c,n;
    cin>>r>>c>>n;
    int ans= 2*1000*1000*1000;
    if (n<2) { cout<<0<<endl; return; }
    for (LL mask= (1<<(r*c))-1; mask>0; mask--)
    {
        LL t= 0;
        LL unH= 0;
        for (LL i= 0; i<17; i++)
            if ((mask&(1<<i))!=0)
            {
                t++;
                if ((i+1)%r!=0)
                {
                    if ( (mask&(1<<(i+1))) !=0) unH++;
                }
                if ((i/r+1)<c)
                    if ( (mask&(1<<(i+r))) !=0) unH++;
            }
        if ((t==n) && unH<ans) ans= unH;
    }
    cout<<ans<<endl;
}
int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 srand(__rdtsc());
 // LL a[110];
 // memset(a,0,sizeof(a));

 freopen("input.in","r",stdin);
 freopen("output.txt","w",stdout);
 //cout<<fixed;
 //cout<<setprecision(9);
 int numberOfTestCases;
 cin>>numberOfTestCases;
 for (int testCase= 1; testCase<=numberOfTestCases; testCase++)
 {
    cout<<"Case #"<<testCase<<": ";
    solve();
 }

 return 0;
}


