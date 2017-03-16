#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <deque>
#include <ctime>
#include <cstring>

//#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sd second
#define pb push_back
#define mp make_pair

#define endl '\n'

#define forr(i, n) for(ll (i) = 0LL; (i) < (n); (i)++)
#define mp3(a, b, c) mp(a, mp(b, c))

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector < vector < double > > vvd;
typedef vector < double > vd;
typedef vector < pair < double, double> > vdd;
typedef vector < vector < long long > > vvl;
typedef vector < long long > vl;
typedef vector < pll > vll;

int INT_MAX_VAL = (int)  0x3F3F3F3F;
int INT_MIN_VAL = (int) -0x3F3F3F3F;
ll LONG_MAX_VAL = (ll)   0x3F3F3F3F3F3F3F3F;
ll LONG_MIN_VAL = (ll)  -0x3F3F3F3F3F3F3F3F;

#define MAXN 500006
#define MOD 1000000007

string solve(int test)
{
    int n; cin >> n;
    vector<int> ps(n);
    int cnt = 0;
    forr(i, n) {
        cin >> ps[i];
        cnt += ps[i];
    }

    bool odd = cnt & 1;

    string res = "";
    for (int i = 0; i < cnt; ++i) {
        auto it = max_element(ps.begin(), ps.end());
        if (*it != 0) {
            res += char('A' + (it - ps.begin()));
            (*it)--;
        } else {
            break;
        }
        if (odd) {
            if (!(i & 1)) {
                res += " ";
            }
        } else {
            if (i & 1) {
                res += " ";
            }
        }
    }
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << solve(t) << endl;
    }

    return 0;
}
