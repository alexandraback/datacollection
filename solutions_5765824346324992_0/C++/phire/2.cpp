#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>

#define foreach(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i) 

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

pair<ll, ll> findq(const VI& b, ll t)
{
    pair<ll, ll> ret(0, 0);

    foreach(it, b) {
        ret.first += (t / *it);
        if (t % *it)
            ret.first++;
        else
            ret.second++;
    }
    ret.second += ret.first;
    return ret;
}

int do_try(const VI& b, ll N, ll t)
{
    ll done = 0;

    if (t < 0)
        return -1;

    done = findq(b, t).first;

    for (size_t i = 0; i < b.size(); i++)
        if (t % b[i] == 0) {
            if (done == N)
                return i + 1;
            done++;
        }

    return -1;
}

int solve(const VI& b, ll N)
{
    ll mn = 0, mx = N * 10000000;

    while (mn + 1 < mx) {
        ll t = (mn + mx) / 2;
        pair<ll, ll> q = findq(b, t);
        if (q.first <= N)
            mn = t;
        else
            mx = t;
    }
    
    //cout << "mn = " << mn << endl;
    
    return do_try(b, N, mn);
}

int main(int argc, const char* argv[])
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int B, N;
        cin >> B >> N;
        VI b(B);
        for (int i = 0; i < B; i++)
            cin >> b[i];
        cout << "Case #" << t << ": " << solve(b, N-1) << endl;
    }
    return 0;
}
