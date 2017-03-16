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


void solve(){
    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    if(n == 1){
        cout << 0 << endl;
        return;
    }

    for(int i = 0; i < n; i++){
        vector<long double> angle;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            angle.push_back(atan2(y[j]-y[i], x[j]-x[i]));
            angle.push_back(atan2(y[j]-y[i], x[j]-x[i]) + 2*M_PI);
        }
        sort(all(angle));

        int k = 0;
        int ans = 114514;
        for(int j = 0; j < n-1; j++){
            while(angle[k] - angle[j] < M_PI + 1e-12) k++;
            ans = min(ans, n-1-(k-j));
        }
        cout << ans << endl;
    }

}

int main(){
    int TEST_CASE; cin >> TEST_CASE;
    for(int i = 1; i <= TEST_CASE; i++){
        cout << "Case #" << i << ":" << endl;
        solve();
    }
}


