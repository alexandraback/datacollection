#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

#define REP(i, n) for(int i=0;i<(n);++i)
#define FOR(i, j, k) for(int i=(j);i<=(k);++i)
#define mst(x, y) memset(x, y, sizeof(x))
#define pii pair<int, int>
#define fr first
#define sc second
#define seed 13331
#define ll long long
#define ull unsigned long long

template <typename OutputIterator>
void input(OutputIterator first, OutputIterator last){
    while(first != last) cin >> *(first++);
}

template <typename InputIterator>
void output(InputIterator first, InputIterator last, string fs=" ", bool newline=0){
    while(first != last) cout << *(first++) << fs;
    if(newline) cout<<endl;
}

static inline int Rint()
{
    struct X{ int dig[256]; X(){
    for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
    }};
    static     X fuck;int s = 1, v = 0, c;
    for (;!fuck.dig[c = getchar()];);
    if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
    for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
    return s ? v : -v;
}

int n, b, m[1010];
ll cal(ll t){
    ll sum = 0;
    REP(i, b) sum += t/m[i];
    return sum;
}

int people, tmp[1010];
int solve(){
    int ans;
    while(people < n){
        int mi = 2e8;
        REP(i, b) mi = min(tmp[i], mi);
        REP(i, b) tmp[i] -= mi;
        REP(i, b) if(!tmp[i]){
            people ++;
            if(people == n) ans = i;
            tmp[i] = m[i];
        }
    }
    return ans;
}

int main(){
    freopen("B-large.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int test;
    cin>>test;
    FOR(cas, 1, test){
        cin>>b>>n;
        REP(i, b)cin>>m[i];
        int ans = 0;
        if(n < 2100){
            people = 0;
            mst(tmp, 0);
            ans = solve();
        }else{
            ll l = 1, r = 100000*1e9 + 1;
            while(l < r){
                ll mid = l+r>>1;
                if(cal(mid) < n-2001) l = mid+1;
                else r = mid;
            }
            ll tt = l-1;
            people = 0;
            REP(i, b) {
                people += tt / m[i];
                if(tt % m[i] == 0)  tmp[i] = 0;
                else tmp[i] = m[i] - (tt%m[i]), people ++;
            }
            ans = solve();
        }
        printf("Case #%d: %d\n", cas, ans+1);
    }

    return 0;
}
