#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define mod 1000000007
typedef long long ll;
using namespace std;


int in[20][20];
int r, c;

ll go(int rr, int cc, int n) {
    ll ret = 0;
    if (n == 0) { return 0; }
    if (rr == r+1) {
        return INF;
    }
    if (cc == c) { ret = go(rr+1, 1, n); }
    else { ret = go(rr, cc+1, n); }
    ll temp(0);
    in[rr][cc] = 1;
    if (in[rr-1][cc]) temp++;
    if (in[rr][cc-1]) temp++;
    if (cc == c) { ret = min(ret, temp + go(rr+1, 1, n-1)); }
    else { ret = min(ret, temp + go(rr, cc+1, n-1)); }
    in[rr][cc] = 0;
    return ret;
}



int main() {
    int n;
    int i, j, t, tt;
    cin >> tt;
    xrep(t, 1, tt+1) {
        cin >> r >> c >> n;
        memset(in, 0, sizeof(in));
        cout << "Case #" << t << ": " << go(1, 1, n) << endl;
    }
}
