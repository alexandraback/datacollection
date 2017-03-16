#include<algorithm>
#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<sstream>
#include<queue>
#include<vector>

using namespace std;

#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

vector<long long> times;

long long f(long long k, int b)
{
    long long res = 0;
    forn(i,b)
        res += (k/times[i])+1;
    return res;
}

int solve(int b, long long n)
{
    long long mx = 1000000000000000LL, mn = -1;
    while(mx-mn > 1)
    {
        long long k = (mx+mn)/2;
        if(f(k,b)>=n)
            mx = k;
        else
            mn = k;
    }
    long long t = n-f(mx-1,b)-1;
    forn(i,b)
    if(mx%times[i] == 0)
    {
        if(t == 0)
            return i+1;
        else
            t--;
    }
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
	int casos;
	cin >> casos;
	for(int casito = 1; casito <= casos; casito++)
    {
        int b;
        long long n;
        cin >> b >> n;
        times.resize(b);
        forn(i,b)
            cin >> times[i];
        cout << "Case #" << casito <<": "<< solve(b,n) << endl;
    }
}
