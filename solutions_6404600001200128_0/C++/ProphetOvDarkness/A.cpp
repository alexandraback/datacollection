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
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


LL n, arr[1010];

LL Y() {
    LL i, ret=0;
    for(i=1; i<n; i++) {
        if(arr[i] < arr[i-1]) ret += arr[i-1]-arr[i];
    }
    return ret;
}

LL Z() {
    LL i, rate=0, ret=0;
    for(i=1; i<n; i++) {
        rate = max(rate, arr[i-1]-arr[i]);
    }
    for(i=0; i<n-1; i++) {
        ret += min(rate, arr[i]);
    }
    return ret;
}

int main() {
    freopen("A-small.in","r",stdin);
    freopen("A-small-out.out","w",stdout);

    LL test, kase=1, i;

    sdl(test);
    while(test--) {
        sdl(n);
        rep(i, n) sdl(arr[i]);
        printf("Case #%lld: %lld %lld\n", kase++, Y(), Z());
    }

    return 0;
}
