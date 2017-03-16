#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FOR(a,b,c) for(int (a) = (b), _n = (c); (a) <= _n ; (a)++)
#define FORD(a,b,c) for(int (a) = (b), _n = (c) ; (a) >= _n ; (a)--)
#define FOR_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) <= _n ; (a)+= _m )
#define FORD_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) >= _n ; (a)-= _m)
#define EACH(v,it) for(__typeof(v.begin()) it = v.begin(); it != v.end() ; it++)
#define INF 200000000
#define MAX 1

using namespace std;

int method1(int n, vector<int> & v)
{
    int last = 0;
    int ret = 0;
    for(int i = 0; i < n; i++)
    {
        if(last > v[i])
        {
            ret += last - v[i];            
        }
        last = v[i];
    }
    return ret;
}

int method2(int n, vector<int> & v)
{
    int maxD = 0,ret = 0;
    for(int i = 0; i < n-1; i++)
    {
        int d = v[i] - v[i+1];
        //cerr << d << endl;
        maxD = max(maxD,d);
    }
    //cerr << "D : " << maxD << endl;
    for(int i = 0; i < n-1; i++)
    {
        ret += min(v[i],maxD);
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int ca = 1 ; ca <= t; ca++)
    {
        vector<int> v;
        int n;
        scanf("%d",&n);
        for(int i =0; i < n; i++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }        
        printf("Case #%d: %d %d\n",ca,method1(n,v),method2(n,v));
    }
    return 0;
}
