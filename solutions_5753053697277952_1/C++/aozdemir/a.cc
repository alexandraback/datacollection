#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l;
int a[1005], v[1005], d[1005];

int main() {

    int tt, tn; cin >> tn;
    string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    F1(tt,tn) {
        printf("Case #%d:", tt);
        cin >> n;
        int tot = 0;
        F0(i,n) {cin >> a[i]; tot += a[i];}
        while (tot > 0) {
            if (tot > 3 || tot == 2) {
                m = j = 0;
                F0(i,n) if (a[i] > a[m]) m = i;
                a[m] -= 1;
                F0(i,n) if (a[i] > a[j]) j = i;
                a[j] -= 1;
                cout << ' ' << A[m] << A[j];
                tot -= 2;
            }
            else if (tot == 3) {
                m = j = 0;
                F0(i,n) if (a[i] > a[m]) m = i;
                a[m] -= 1;
                cout << ' ' << A[m];
                tot--;
            }
            else {cerr << ":(";}
        }
        cout << endl;
    }
    return 0;
}
