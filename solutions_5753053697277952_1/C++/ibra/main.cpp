#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <map>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <set>
#include <ctime>
#include <stack>
#include <cstring>
#include <sstream>
#include <ctype.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#pragma comment(linker, "/STACK:16777216")
template<typename T> T fac(T a){ return a ? a*fac(a-1) : 1; }
template<typename T> T power(T a, int p){ return !p?1:(p&1?a*power(a, p-1):power(a*a,p>>1)); }
template<typename T> T gcd(T a, T b){ return b ? gcd(b, a%b) : a; }
template<typename T> T lcm(T a, T b){ return b / gcd(a, b) * a; }
template<typename T> T next(){ T _; cin >> _; return _; }
template<> int next<int>(){int _; scanf("%d", &_); return _; }
template<> double next<double>(){ double _; scanf("%lf", &_); return _; }
template<> ll next<ll>(){ ll _; scanf("%I64d", &_); return _; }
template<typename E> vector<E> next(int n){ vector<E> res(n); for(int i = 0; i < n; i++) res[i] = next<E>(); return res;}
template<class C, class E> int count(const C &c, const E &e){return count(c.begin(), c.end(), e);}
template<class E> bool has(const vector<E> &c, const E &e){return find(c.begin(), c.end(), e) != c.end();}
template<class E> int find(const vector<E> &c, const E &e){return find(c.begin(), c.end(), e) - c.begin();}
template<class E> bool binary_has(const vector<E> &c, const E &e){return binary_search(c.begin(), c.end(), e);}
template<class E> int binary_find(const vector<E> &c, const E &e){return lower_bound(c.begin(), c.end(), e) - c.begin();}
template<typename T> T dist2(T i1, T j1, T i2, T j2){return (i1-i2)*(i1-i2) + (j1-j2)*(j1-j2);}
bool ok(int i, int j, int n, int m){return 0<=i&&i<n&&0<=j&&j<m;}
const double EPS = 1e-9;
bool LE(double a, double b){return b-a > -EPS;}
bool BE(double a, double b){return a-b > -EPS;}
bool EQ(double a, double b){return fabs(a-b) < EPS;}
bool LESS(double a, double b){return b-a > EPS;}
bool BIGG(double a, double b){return a-b > EPS;}
template <int N, typename T> class lug {public: T at[N];};

class party
{
public:
    int cnt;
    char c;
};

bool operator<(const party &a, const party &b)
{
    if(a.cnt != b.cnt)
        return a.cnt > b.cnt;
    else
        return a.c < b.c;
}

int main()
{
    freopen("/Users/ibra/Desktop/in.txt", "r", stdin);
    freopen("/Users/ibra/Desktop/out.txt", "w", stdout);
    
    int t = next<int>();
    for(int test = 1; test <= t; test++)
    {
        int n = next<int>();
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            v[i] = next<int>();
        
        vector<string> res;
        set<party> s;
        int all = 0;
        for(int i = 0; i < n; i++)
        {
            s.insert({v[i], (char)('A'+i)});
            all += v[i];
        }
        
        while(s.size())
        {
            string cur = "";
            party p = *s.begin();
            s.erase(s.begin());
            p.cnt--;
            all--;
            cur += p.c;
            if(p.cnt)
                s.insert(p);
            if(s.begin()->cnt*2 > all)
            {
                party q = *s.begin();
                s.erase(s.begin());
                q.cnt--;
                all--;
                cur += q.c;
                if(q.cnt)
                    s.insert(q);
            }
            res.push_back(cur);
        }
        
        
        
        cout << "Case #" << test << ":" ;
        for(int i = 0; i < res.size(); i++)
        {
            cout << " " << res[i];
        }
        cout << endl;
    }
    
    return 0;
}



















