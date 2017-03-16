/*
ID: iamquan2
PROG: test
LANG: C++
*/

// Author: QCC
#include <bits/stdc++.h>

using namespace std;

//Loop
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define REP(i,a,b) for( int i=(a),_b=(b);i<_b;++i)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
//Debugging
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define DEBUGARR(a,n) {cout << #a << " = " ; FOR(_,1,n) cout << a[_] << ' '; cout <<endl;}
#define CHECK printf("OK\n");
//Read and init
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RC(X) scanf("%c", &(X))
#define DRC(X) char (X); scanf("%c", &X)
#define FILL(a, b) memset((a), (b), sizeof((a)))
//Shorten keyword
#define pb push_back
#define mp make_pair
#define st first
#define nd second

int gcd(int a, int b) { int r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int getBit(int s, int i) { return (s >> i) & 1; }
int onBit(int s, int i) { return s | (int(1) << i); }
int offBit(int s, int i) { return s & (~(int(1) << i)); }
int cntBit(int s) { return __builtin_popcount(s); }
int sqr(int x) {return x*x; };


typedef pair< int, int > PII;
typedef long long LL;

const int MOD = 1e9+7;
const int SIZE = 1e6+10;
const int DX[4] = {-1, 1, 0, 0};
const int DY[4] = {0, 0, 1, -1};

int n;
int b;
int m[1111];

int canCut(LL time) {
    LL sum = 0;
    FOR(i, 1, b) {
        sum += (LL)time/(LL)m[i];
        if (time % m[i] != 0) sum++;
    }
    if (sum >= n) return 1;
    else return -1;
}

int cnt[1111];
LL t[1111];

int calPos(LL time){
    LL cnt = 0;
    FOR(i, 1, b) {
        cnt += time/m[i];
        if (time % m[i] != 0) cnt++;
    }
    FOR(i, 1, b)
        if (time % m[i] == 0){
            cnt++;
            if (cnt == n) return i;
        }
    if (cnt >= n) return -1;
    else return -2;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    DRI(nTest);
    FOR(test, 1, nTest) {
        RII(b, n);
        FOR(i, 1, b)
            RI(m[i]);
        LL le = 0;
        LL ri = (LL)100000*(LL)1000000000;
        LL saveTime = 0;
        while (true) {
            LL mid = (le + ri) / 2;
            int pos = calPos(mid);
            if (pos > 0){
                printf("Case #%d: %d\n", test, pos);
                break;
            } else if (pos == -1) ri = mid;
            else if (pos == -2) le = mid + 1;
        }
    }
    return 0;

}



