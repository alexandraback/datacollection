/*
*Sourav Sen Tonmoy
*University of Dhaka
*/

#include <bits/stdc++.h>

#define rep(i,n) for(i=0; i<n; i++)
#define repl(i,n) for(i=1; i<=n; i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin(); i!=(n).end(); i++)

#define sz(x) (int) x.size()
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define uu first
#define vv second
#define mem(x, y) memset(x, y, sizeof(x));

#define sdi(x) scanf("%d", &x)
#define sdii(x, y) scanf("%d %d", &x, &y)
#define sdiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sdl(x) scanf("%lld", &x)
#define sdll(x, y) scanf("%lld %lld", &x, &y)
#define sdlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sds(x) scanf("%s", x)
#define pfi(x) printf("%d\n", x)
#define pfii(x, y) printf("%d %d\n", x, y)
#define pfiii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pfl(x) printf("%lld\n", x)
#define pfll(x, y) printf("%lld %lld\n", x, y)
#define pflll(x, y, z) printf("%lld %lld %lld\n", x, y, z)

#define OK printf("ok\n")
#define DB(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> pii;

int setBit(int N, int pos) { return N=N | (1<<pos); }
int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


int r, c, n, TC, dp[20][(1<<16)+5], flag[20][(1<<16)+5];

inline bool isValid(int x, int y) {
    if(x >= 0 && y>=0 && x<r && y<c) return true;
    else return false;
}

int hapCount(unsigned mask) {
    bool board[r][c];
    mem(board, false);
    int i, j, k, cnt=0;
    rep(i, r) {
        rep(j, c) {
            if(checkBit(mask, cnt) == 1) {
                board[i][j] = true;
            }
            cnt++;
        }
    }

    int ret=0;
    rep(i, r) {
        rep(j, c) {
            if(board[i][j]) {
                rep(k, 4) {
                    int xx = i+fx[k];
                    int yy = j+fy[k];
                    if(isValid(xx, yy) && board[xx][yy]) ret++;
                }
            }
        }
    }

//    if(__builtin_popcount(mask) == 6) {
//        rep(i, r) {
//            rep(j, c) {
//                cout << board[i][j] << " ";
//            }
//            puts("");
//        }
//        DB(ret);
//    }

    return ret/2;
}

int DP(int idx, unsigned mask) {
    if(idx >= r*c) {
        if(__builtin_popcount(mask) == n) return hapCount(mask);
        else return INT_MAX;
    }
    if(idx > r*c) return INT_MAX;
    if(__builtin_popcount(mask) > n) return INT_MAX;

    if(flag[idx][mask] == TC) return dp[idx][mask];
    flag[idx][mask] = TC;

    int ret1 = DP(idx+1, setBit(mask, idx));
    int ret2 = DP(idx+1, mask);
    return dp[idx][mask] = min(ret1, ret2);
}

int main() {
    freopen("B-small.in","r",stdin);
    freopen("B-small-out.out","w",stdout);

    int test, kase=1;

    sdi(test);
    while(test--) {
        TC++;
        sdiii(r, c, n);
        printf("Case #%d: %d\n", kase++, DP(0, 0));
    }

    return 0;
}
