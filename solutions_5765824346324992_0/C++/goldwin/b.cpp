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

typedef long long ll;

typedef pair<int,int> pii;

ll lcm(ll a, ll b)
{
    ll g = __gcd(a,b);
    return (a / g) * b;
}

int solve2(int b, vector<int> & m,int n)
{
    //cerr << n << endl;
    if(n == 0) return b;
    vector<int> v;
    for(int i = 0; i < b; i ++)
    {
        n--;
        if(n == 0) return i + 1;
        v.push_back(m[i]);
    }
    int idx;
    while(n--)
    {
        idx = min_element(v.begin(),v.begin() + b) - v.begin();
        int mins = v[idx];
        for(int i = 0; i < b ; i++)
        {
            v[i] -= mins;
        }
        v[idx] += m[idx];
    }
    return idx + 1;
}

int solve(int b, vector<int> & m, int n)
{
    ll l = 1;
    for(int i = 0; i < b ; i++)
    {
        l = lcm(l,m[i]);
    }
    int cnt = 0;
    for(int i = 0; i < b; i++)
    {        
        cnt += l/m[i];
    }
    //cerr << cnt << endl;
    n = (n % cnt) + cnt;
    return solve2(b,m,n);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int ca = 1; ca <= t; ca++)
    {
        int b,n;
        vector<int> m;
        scanf("%d %d",&b,&n);
        for(int i = 0; i < b; i++)
        {
            int x;
            scanf("%d",&x);
            m.push_back((ll)x);
        }
        printf("Case #%d: %d\n",ca,solve(b,m,n));
    }
    return 0;
}
