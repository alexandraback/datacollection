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

int test, b, n, a[1111];
long long dau, cuoi, giua;

int check(long long k){
    long long dem = 0;
    FOR(i,1,b)
        if (k % a[i] == 0) dem += k / a[i];
        else dem += k / a[i] + 1;
    FOR(i,1,b)
        if (k % a[i] == 0){
            dem++;
            if (dem == n) return i;
        }
    if (dem >= n) return -1;
    else return -2;
}


int main()
{
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> test;
    FOR(t,1,test){
        cout << "Case #" << t << ": ";
        cin >> b >> n;
        FOR(i,1,b) cin >> a[i];

        dau = 0;
        cuoi = 1000000000000000000LL;
        while (1) {
            giua = (dau + cuoi) / 2;
            int k = check(giua);
            if (k > 0){
                cout << k << endl;
                break;
            }
            if (k == -1) cuoi = giua;
            if (k == -2) dau = giua + 1;
        }
    }

    return 0;
}
