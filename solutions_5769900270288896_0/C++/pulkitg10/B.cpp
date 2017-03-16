#include<bits/stdc++.h>
using namespace std;

#define LET(x, a)  __typeof(a) x(a)
#define TR(v, it) for(LET(it, v.begin()); it != v.end(); it++)
#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF 1000000000
#define MOD 1000000007
#define SET(x,y) memset(x,y,sizeof(x));
#define LL long long int
#define ULL unsigned LL
#define PII pair<int, int>

vector<int> valid;
int r, c;
int getans1(int c, int n) {
    
}
int main() {
    int t;
    cin >> t;
    int n;
    while (t--) {
        scanf("%d %d %d", &r, &c, &n);
        if (r > c)
            swap(r, c);
        if (r == 1) {
            cout << getans1(c) << endl;
            continue;
        }
        LL lim = (r / 2) * (c / 2);
        n -= lim;
        LL ans = 0;
        if (n > 0 && (r % 2 != 0 || c % 2 != 0)) {
            n --;
            ans += 2;
        }
        if (n > 0 && (r % 2 != 0 || c % 2 != 0)) {
            n --;
            ans += 2;
        }
        int border = (r + c);
        if (r % 2 != 0 || c % 2 != 0) 
            border -= 2;
        if (n > 0 && n <= border) {
            ans += n * 3; 
            n = -1;
        } else {
            n -= border;
            ans += n * 4;
        }
        cout << ans << endl;

    }
    return 0;
}

