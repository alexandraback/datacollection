#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (lol)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

const int N = 1000100;
const int mod = 1000000009;
int a[20][20], l;
bool us[N];

void go(int r, int c, int mxr, int mxc, int n) {
//    cerr << r << ' ' << c << '\n';
//    system("pause");
    if(c == 0) {
        go(r - 1, mxc, mxr, mxc, n);
    return;
    }
    if(r == 0) {
        if(n != 0)
            return;

        int ans = 0;
//        for(r = 1; r <= mxr; r++, cout << "\n")
//            for(c = 1; c <= mxc; c++)
//                cout << a[r][c] << ' ';
        for(r = 1; r <= mxr; r++)
            for(c = 1; c <= mxc ; c++)
                if(a[r][c])
                    ans += a[r][c - 1] + a[r][c + 1] + a[r - 1][c] + a[r + 1][c];
        l = min(ans / 2, l);
        return;
    }
    go(r, c - 1, mxr, mxc, n);
    if(n > 0) {
        a[r][c] = 1;
        go(r, c - 1, mxr, mxc, n - 1);
        a[r][c] = 0;
    }
}

int main() {
    inp("input.txt");
    out("output.txt");
    must;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        int r, c, n;
        cin >> r >> c >> n;
        l = 1000000;
        memset(a, 0, sizeof(a));
        go(r, c, r, c, n);
        cout << "Case #" << i << ": " << l << "\n";
    }

}

