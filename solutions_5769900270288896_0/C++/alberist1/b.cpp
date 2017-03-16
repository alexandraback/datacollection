#include<iostream>
#include<cstring>
using namespace std;

char m[20][20];

int solve()
{
    int r, c, n, res = 1000000000;
    cin >> r >> c >> n;
    for (int i=0;i<(1<<(r*c));++i) {
        if (__builtin_popcount(i) == n) {
            int cnt = 0, j = i;
            memset(m,0,sizeof(m));
            for (int x=1;x<=r;++x)
                for (int y=1;y<=c;++y) {
                    if (j%2) {
                        m[x][y] = 1;
                        cnt += m[x-1][y] + m[x][y-1];
                    }
                    j/=2;
                }
            res = min(res, cnt);
        }
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    for (int t=1;t<=T;++t)
        cout << "Case #" << t << ": " << solve() << endl;
}
