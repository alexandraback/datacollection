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

int test, n, a[1111];

int method1(){
    int res = 0;
    FOR(i,2,n)
        if (a[i] < a[i-1]) res += a[i-1] - a[i];
    return res;
}

int method2(){
    int res = 0;
    int d = 0;
    FOR(i,2,n) d = max(d, a[i-1] - a[i]);
    if (d == 0) return 0;
    FOR(i,1,n - 1) res += min(a[i], d);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> test;
    FOR(t,1,test){
        cout << "Case #" << t << ": ";
        cin >> n;
        FOR(i,1,n) cin >> a[i];
        cout << method1() << " " << method2() << endl;
    }

    return 0;
}
