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

void solve(int test)
{
    printf("Case #%d: ", test);

    int n; cin >> n;
    vector<ll> a(n);

    forn(i, n) cin >> a[i];

    ll ans1 = 0;
    ll v = 0;

    forn(i, n - 1)
    {
    	if (a[i + 1] < a[i]) 
    	{
    		ans1 += a[i] - a[i + 1];
    		v = max(v, a[i] - a[i + 1]);
    	}
    }

    ll ans2 = 0;
    forn(i, n - 1)
    {
    	ans2 += min(v, a[i]);	
    }

    cout << ans1 << " " << ans2 << endl;
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
