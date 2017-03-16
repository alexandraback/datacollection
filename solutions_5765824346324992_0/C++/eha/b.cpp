#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
//TEMPLATE {{{
typedef long long lint;
typedef unsigned long long ulint;
typedef long double ldouble;

typedef vector<int> vint;
typedef vector<lint> vlint;
typedef vector<double> vdouble;

#define rep(i,n)         for(int i = 0; i < (int)(n); i++)
#define all(c)           (c).begin(), (c).end()
#define perm(c)          sort(all(c)); for(bool _b = true; _b; _b = next_permutation(all(c)))
#define uniquenize(v)    (v).erase(unique(all(v)), (v).end())

#ifdef HIBIKICHAN
#include <dumper.hpp>
#define dump(x) dumper::dumper(cerr, __LINE__, (#x), (x), 50, 1, 1)
#else
#define dump(x)
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
inline int stoi(const string &s){return atoi(s.c_str());}
inline long long stoll(const string &s){return atoll(s.c_str());}
#endif

//}}}

int solve(){
    int b, n; cin >> b >> n;
    vector<int> m(b);
    for(int i = 0; i < b; i++) cin >> m[i];

    long long l = -1, r = 100000LL * 1000000001;

    //(l, r]
    while(r-l > 1){
        long long t = (r+l)/2;

        long long cnt = 0;
        for(int i = 0; i < b; i++) cnt += t/m[i] + 1;

        if(n <= cnt){
            r = t;
        } else {
            l = t;
        }
    }

    long long cnt = 0;
    for(int i = 0; i < b; i++) cnt += (r-1)/m[i] + 1;

    for(int i = 0; i < b; i++){
        if(r%m[i] == 0) cnt++;
        if(cnt == n) return i+1;
    }
    return -1;
}

int main(){
    int TEST_CASE; cin >> TEST_CASE;
    for(int i = 1; i <= TEST_CASE; i++){
        cout << "Case #" << i << ": " << solve() << endl;
    }
}


