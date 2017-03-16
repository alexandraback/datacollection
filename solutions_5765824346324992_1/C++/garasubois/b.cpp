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

int main()
{
    int T;
    cin >> T;
    rep(case_num,T){
        ll n;
        int b;
        cin >> b >> n;
        vector<int> m(b);
        rep(i,b) cin >> m[i];
        int res = -1;

        ll p = 0; ll q = 100000LL*n;
        while(q-p>1){
            ll r = (q+p+1)/2;
            ll sum = 0;
            rep(i,b) sum += (r+m[i]-1)/m[i];
            if(sum>=n) q = r;
            else p = r;
        }
        priority_queue< P,vector<P>,greater<P> > pque;
        rep(i,b){
            n -= (p+m[i]-1)/m[i];
            pque.push(P(p%m[i],i));
        }
        while(n>0){
            P tar = pque.top();
            pque.pop();
            n--;
            res = tar.second+1;
            pque.push(P(tar.first+m[tar.second],tar.second));
        }

        printf("Case #%d: %d\n",case_num+1,res);
    }
    return 0;
}


