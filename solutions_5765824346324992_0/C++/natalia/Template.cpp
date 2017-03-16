#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

int n, b;
vector<ll> a;
vector<bool> fr;

ll calc(ll t)
{
	ll cnt = 0;

	forn(i, b)
	{
		cnt += t / a[i];
		if (t % a[i] == 0) fr[i] = true;	
		else 
		{
			fr[i] = false;
			cnt++;
		}
	}

	return cnt;
}
void solve(int test)
{
    printf("Case #%d: ", test);

    scanf("%d %d\n", &b, &n);
    a.resize(b);
    forn(i, b) scanf("%d", &a[i]);

    fr.resize(b);

    ll L = 0, R = 1000000000000000ll;

    while (R - L > 2)
    {
    	ll mid = (L + R) / 2;
    	if (calc(mid) >= n) R = mid;
    	else L = mid;	
    }

    ll mid;


    for (mid = L; mid <= R; mid++)
    {
    	if (calc(mid) >= n) break;
    }
	mid--;
	ll cnt = calc(mid);
    

    forn(i, b)
    {
    	if (!fr[i]) continue;
    	cnt++;
    	if (cnt == n)
    	{
    		printf("%d\n", i + 1);
    		return;
    	}
    }

}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);
    
    return 0;
}
