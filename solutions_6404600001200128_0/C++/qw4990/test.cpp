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

int n, m[1010];

int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int test;
    cin>>test;
    FOR(cas, 1, test){
        cin>>n;
        input(m, m+n);
        int ans1 = 0;
        REP(i, n-1) if(m[i] > m[i+1]) ans1 += m[i]-m[i+1];
        int ans2 = 0, rapid = 0;
        REP(i, n-1) rapid = max(rapid, m[i]-m[i+1]);
        REP(i, n-1) ans2 += min(rapid, m[i]);
        printf("Case #%d: %d %d\n", cas, ans1, ans2);
    }
}
