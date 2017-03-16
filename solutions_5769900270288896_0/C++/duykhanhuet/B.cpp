// Author: Nguyen Duy Khanh
#include<bits/stdc++.h>
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define DEBUG(x) { printf << #x << " = " << x << endl; }
#define DEBUGARR(a,n) {cout << #a << " = " ; FOR(_,1,n) cout << a[_] << ' '; cout <<endl;}
#define CHECK printf("OK\n");
#define FILL(a, b) memset((a), (b), sizeof((a)))
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define Nmax 35000
using namespace std;

int a[20][20], f[20][20][20], test;

int cnt(int m, int n){
    /*
    cout << "----------------" << endl;
    FOR(i,1,m){
        FOR(j,1,n) cout << a[i][j];
        cout << endl;
    }*/
    int res = 0;
    FOR(i,1,m)
    FOR(j,1,n)
        if (a[i][j] == 1 ) res = res + a[i+1][j] + a[i][j+1];
    //cout << res << endl;
    //cout << "----------------" << endl;
    return res;
}

void xuly(int x, int y, int d, int i, int j, int k){
    if (x > i){
        if (k == d) f[i][j][k] = min (f[i][j][k], cnt(i,j));
        return;
    }
    //if (i * j - (x - 1) * j - y + 1 < k - d) return;

    int xx, yy;
    xx = x;
    yy = y;
    y++;
    if (y > j) {
        y = 1;
        x++;
    }

    xuly(x,y,d,i,j,k);
    a[xx][yy] = 1;
    xuly(x,y,d+1,i,j,k);
    a[xx][yy] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    FOR(i,1,16)
    FOR(j,1,16/i){
        FOR(k,1,i*j) f[i][j][k] = 123123;
        FOR(k,1,i*j) xuly(1,1,0,i,j,k);
    }
    //xuly(1,1,0,4,1,2);

    cin >> test;
    FOR(t,1,test){
        int i, j, k;
        cin >> i >> j >> k;
        cout << "Case #" << t << ": " << f[i][j][k] << endl;
    }

    return 0;
}
