#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
typedef long long ll;
using namespace std;

int m[1001];

int main() {
    int n;
    int i, j, k, t, tt, a, b, bb;
    cin >> tt;
    xrep(t, 1, tt+1) {
        cin >> n;
        rep(i, n) { cin >> m[i]; }
        a = b = bb = 0;
        xrep(i, 1, n) {
            if (m[i] < m[i-1]) {
                a += m[i-1] - m[i];
                bb = max(bb, m[i-1] - m[i]);
            }
        }
        rep(i, n-1) { b += min(m[i], bb); }
        cout << "Case #" << t << ": " << a << ' ' << b << endl;
    }
}
