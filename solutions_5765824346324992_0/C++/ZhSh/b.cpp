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

//#define DEBUGPRINT
#ifdef DEBUGPRINT
#define print(x) cout << #x" = "; printImpl(x);
#else
#define print(x) ;
#endif

long long numberInProgress(ll t, int B, const vll & M)
{
    long long res = 0;
    for (int i = 0; i < B; ++i)
    {
        res += ((t + M[i] - 1) / M[i]);
    }

    return res;
}

int solve(int B, long long N, const vll & M)
{
    if (N <= B)
    {
        return N;
    }

    ll l = 0;
//    ll r = 1000000000LL * 100000LL;
    ll r = *max_element(M.begin(), M.end()) * N;
    while (numberInProgress(r, B, M) < N)
    {
        r *= 2;
    }

    while (r - l > 1)
    {
        ll m = (l + r) / 2;
        if (numberInProgress(m, B, M) < N)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }

    ll T = l;
    ll processed = numberInProgress(T, B, M);
    ll needIx = N - processed;
    for (int i = 0; i < B; ++i)
    {
        if ((T % M[i]) == 0)
        {
            needIx--;
            if (needIx == 0)
            {
                return i + 1;
            }
        }
    }

    cout << "ERROR" << endl;
    return 0;
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        int B;
        ll N;
        cin >> B >> N;
        vll M(B);
        REP(i,B)
        {
            cin >> M[i];
        }

        int res = solve(B, N, M);
        cout << "Case #" << csIx << ": " << res << endl;
    }
    
    return 0;
}
