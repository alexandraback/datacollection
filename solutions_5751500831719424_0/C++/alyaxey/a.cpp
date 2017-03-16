#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define sz(X) ((int)(X).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define FOR(i, a, n) for(int i=(a), __ ## i=(n); i<__ ## i; i++)
#define REP(I,N) FOR(I,0,N)
#define PR(X) cout<<#X<<" = "<<(X)<<" "
#define PRL cout<<endl
#define PRV(X) {cout<<#X<<" = {";REP(__prv,sz(X)-1)cout<<(X)[__prv]<<",";if(sz(X))cout<<*(X).end();cout<<"}"<<endl;}

template<class T> ostream &operator<<(ostream &os, vector<T> &vec)
{
    os << '{';
    REP(i, sz(vec))
    {
        os << vec[i];
        if (i + 1 != sz(vec) )
            os << ',';
    }
    os << '}';
    return os;
}

template<class T1, class T2> ostream &operator<<(ostream &os, pair<T1, T2> &par)
{
    os << '(' << par.X << ',' << par.Y << ')';
    return os;
}

typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : abs(x);
}

template<class T> T sqr(T x)
{
    return x * x;
}

string a[110];
int b[110][110];
int n;

int solve(){
    string s = a[0];
    s.resize(unique(all(s)) - s.begin());
    REP(i, n){
        string s1 = a[i];
        s1.resize(unique(all(s1)) - s1.begin());
        if(s != s1)
            return -1;
        int p = 0;
        for(int j = 0; j < sz(a[i]);){
            int k = j;
            while(j < sz(a[i]) && a[i][j] == a[i][k]) ++j;
            b[p++][i] = j - k;
        }
    }
    int ans = 0;
    REP(i, sz(s)){
        nth_element(b[i], b[i] + n / 2, b[i] + n);
        REP(j, n){
            ans += abs(b[i][j] - b[i][n/2]);
        }
    }
    return ans;
}

void solve(int test)
{
    cin >> n;
    REP(i, n)
        cin >> a[i];
    int ans = solve();
    cout << "Case #" << test << ":";
    cout << fixed;
    cout << setprecision(8);
    cout << " ";
    if(ans == -1)
        cout << "Fegla Won";
    else
        cout << ans;
    cout << endl;
}

void pre()
{
}

int main()
{
    if (!freopen("1.in", "r", stdin))
    {
        cerr << "No input file" << endl;
        return 1;
    }
    if (!freopen("1.out", "w", stdout))
    {
        cerr << "Error creating output file" << endl;
        return 1;
    }
    ios::sync_with_stdio(false);
    pre();
    int n;
    cin >> n;
    string tmp;
    getline(cin, tmp);
    for (int i = 1; i <= n; ++i)
    {
        solve(i);
    }
    return 0;
}
