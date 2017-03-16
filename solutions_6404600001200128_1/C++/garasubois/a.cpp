#include <bits/stdc++.h>

#define INF (1 << 29)
#define rep2(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define EPS 1e-10

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int func1(vector<int> &m){
    int n = m.size();
    int res = 0;
    rep(i,n-1) res += max(m[i]-m[i+1],0);
    return res;
}

int func2(vector<int> &m){
    int n = m.size();
    int diff = 0;
    rep(i,n-1){
        diff = max(m[i]-m[i+1],diff);
    }
    int p = diff;
    int res = 0;
    rep(i,n-1){
        res += min(m[i],p);
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    rep(case_num,T){
        int n;
        cin >> n;
        vector<int> m(n);
        rep(i,n) cin >> m[i];
        printf("Case #%d: %d %d\n",case_num+1,func1(m),func2(m));
    }
    return 0;
}

