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


typedef pair< long long, long long > PII;
typedef long long LL;

const int MOD = 1e9+7;
const int SIZE = 1e6+10;
const int DX[4] = {-1, 1, 0, 0};
const int DY[4] = {0, 0, 1, -1};

int n;
PII p[3333];
#define X first
#define Y second

PII origin;
void operator -= (PII &A, PII B){ A.X-=B.X; A.Y-=B.Y; }
bool ccw(PII O, PII A, PII B){ A-=O, B-=O; return (LL)A.X*(LL)B.Y > (LL)A.Y*(LL)B.X; }
bool cmp(PII A, PII B){ return ccw(origin, A, B); }

int x[3333];
PII a[3333];
int nP;
int res;

void check(int cur) {
    int saveNP = 0;
    nP = 0;
    FOR(i, 1, n)
        if (x[i] == 1) {
            a[++nP] = p[i];
        }
    if (nP == 0) return;
    saveNP = nP;
    if (n - nP > res) return;
    sort(a+1, a+nP+1);
    origin = a[1];
    sort(a+2, a+nP+1, cmp);
    a[0]=a[nP]; a[nP+1]=a[1];
    int j=1;
    for (int i=1; i<=nP+1; i++){
        while (j>2 && !ccw(a[j-2], a[j-1], a[i])) j--;
        a[j++]=a[i];
    }
    nP=j-2;
    a[nP + 1] = a[1];
    bool tt = false;
    FOR(i, 1, nP) {
        if (ccw(a[i], a[i+1], p[cur]) == 0) tt = true;
    }
    if (!tt) return;
    //DEBUGARR(x,n);
    res = min(res, n-saveNP);
}


void attempt(int i, int cur) {
    if (i > n) {
        //DEBUG(n);
        check(cur);
        return;
    }
    FOR(j, 0, 1) {
        x[i] = j;
        attempt(i+1, cur);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    DRI(nTest);
    FOR(test, 1, nTest) {
        RI(n);
        FOR(i, 1, n)
            cin >> p[i].X >> p[i].Y;
        printf("Case #%d:\n", test);
        FOR(i, 1, n) {
            res = n + 1;
            attempt(1, i);
            printf("%d\n", res);
        }
    }
    return 0;
}



