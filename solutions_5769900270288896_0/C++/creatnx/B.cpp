#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define red(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define RED true
#define BLACK false
#define pb push_back
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ii, int> iii;
typedef vector<int> vi;
const int N = 1e6 + 7;
const int M = 1e9;
const int inf = 1e9 + 7;
const int base = 1e9 + 9;
const double pi = acos(-1);
const double ep = 1e-9;

int a[16][16];
int n, m, t;

void go(){
    int k = n * m;
    int res = inf;
    rep(st, 0, 1 << k){
        int tol = __builtin_popcount(st);
        if (tol != t) continue;
        int u = 0, v = 0;
        rep(i, 0, k){
            if ((st & (1 << i)) > 0)
                a[u][v] = 1;
            else a[u][v] = 0;
            if (v < m - 1) v++;
            else {
                u++;
                v = 0;
            }
        }
        int cnt = 0;
        rep(u, 0, n)
            rep(v, 0, m){
                if (v > 0 && a[u][v-1] + a[u][v] == 2) cnt++;
                if (u > 0 && a[u][v] + a[u-1][v] == 2) cnt++;
            }
        res = min(res,cnt);

    }
    cout<<res<<endl;
}

int main(){
    freopen("B-small-attempt1 (1).in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int test;
    cin >> test;
    //test = 1000;
    rep(ii, 1, test + 1){
        scanf("%d%d%d", &n, &m, &t);

        printf("Case #%d: ", ii);
        go();
    }

}
