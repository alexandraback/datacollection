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
using namespace std;

int f[111], ff[111], res, test, n, du;
string a[111], kk;


string toigian(string s){
    string res = "";
    res = s[0];
    f[1]++;
    FOR(i,1,s.length()-1)
        if (s[i] != res[res.length()-1]) {
            res = res + s[i];
            f[res.length()]++;
        }
        else f[res.length()]++;
    return(res);
}

int cal(string s){
    string res = "";
    res = s[0];
    FOR(i,0,100) ff[i] = 0;
    ff[1] = 1;
    FOR(i,1,s.length()-1)
        if (s[i] != res[res.length()-1]) {
            res = res + s[i];
            ff[res.length()]++;
        }
        else ff[res.length()]++;
    int k = 0;
    FOR(i,1,res.length()) k = k + abs(ff[i] - f[i]);
    return(k);
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin >> test;
    FOR(oo,1,test){
        FOR(i,0,111) f[i] = 0;
        cin >> n;
        cout << "Case #" << oo << ": ";
        FOR(i,1,n) cin >> a[i];
        kk = toigian(a[1]);
        FOR(i,2,n)
            if (kk != toigian(a[i])) {
                cout << "Fegla Won" << endl;
                goto hehe;
            }
        FOR(i,0,100) {
            if (f[i] % n >= 2) du = 1;
            else du = 0;
            f[i] = f[i] / n + du;
        }
        res = 0;
        FOR(i,1,n) res = res + cal(a[i]);
        cout << res << endl;
        hehe:;
    }
    return 0;
}
