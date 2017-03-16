#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

//cout.precision(6);
//cout.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed

const long long MOD = 1000000007LL;

#define REP(i,N) for (int i = 0; i < (N); ++i)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned int ui;
typedef long long ll;
typedef vector<ll> vll;

template<class T> void printImpl(const vector<T> & coll) { copy(coll.begin(), coll.end(), ostream_iterator<T>(cout, " ")); cout << endl; }
template<class T, int N> void printImpl(T (&coll)[N]) { copy(coll, coll + N, ostream_iterator<T>(cout, " ")); cout << endl; }
template<class Key, class Value> void printImpl(const map<Key, Value> & data) { typename map<Key, Value>::const_iterator it; for (it = data.begin(); it != data.end(); ++it) { cout << it->first << ":" << it->second << endl; } }
template <class T> void printImpl(const T & data) { cout << data << endl; }

#define DEBUGPRINT
#ifdef DEBUGPRINT
#define print(x) cout << #x" = "; printImpl(x);
#else
#define print(x) ;
#endif

int solve(const vll & X, const vll & Y, int v)
{
    int N = X.size();
    if (N < 3)
    {
        return 0;
    }

    int res = N;
    for (int other = 0; other < N; ++other)
    {
        if (other == v) continue;

        int c1 = 0, c2 = 0;
        for (int k = 0; k < N; ++k)
        {
            if (k == v || k == other) continue;
            ll v1x = X[other] - X[v];
            ll v1y = Y[other] - Y[v];
            ll v2x = X[k] - X[v];
            ll v2y = Y[k] - Y[v];

            ll val = v1x * v2y - v2x * v1y;
            if (val > 0) c1++;
            if (val < 0) c2++;
        }

        res = min(res, min(c1, c2));
    }

    return res;
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        int N;
        cin >> N;
        vll X(N), Y(N);
        REP(i,N)
        {
            cin >> X[i] >> Y[i];
        }
        cout << "Case #" << csIx << ":" << endl;
        REP(t, N)
        {
            cout << solve(X, Y, t) << endl;
        }
    }
    
    return 0;
}
