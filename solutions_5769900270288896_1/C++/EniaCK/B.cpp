#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#define abs(x) (((x)>0)?(x):(-x))
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))
using namespace std;
int T;
int r, c, n;
vector <vector <bool> > a;
int add[10];

const int dx[4] = {0,  0,  1, -1};
const int dy[4] = {1, -1,  0,  0};

int fullfill()
{
    int res = 0;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            if (i % 2 == j % 2){
                a[i][j] = true;
                res ++;
            }
            else {
                a[i][j] = false;
            }
        }
    }
    return res;
}

int main()
{
    cin >> T;
    for (int Case = 1; Case <= T; Case++) {
        cout << "Case #" << Case << ": ";
        cin >> r >> c >> n;
        a.clear();
        a.resize(r + 2);
        for (int i = 0; i < r + 2; i++){
            a[i].resize(c + 2);
        }
        int s = fullfill();
        if (s < (r*c / 2)) {
            for (int i = 1; i <= r; i++){
                for (int j = 1; j <= c; j++){
                    a[i][j] = a[i][j] ^ true;
                }
            }
            s = r*c - s;
        }

        if (n <= s) {
            cout << 0 << endl;
        }
        else {
            int ans = 0, p;
            memset(add, 0, sizeof(add));
            for (int i = 1; i <= r; i++){
                for (int j = 1; j <= c; j++){
                    if (!a[i][j]){
                        p = 0;
                        for (int k = 0; k < 4; k++) {
                            if (a[i+dx[k]][j+dy[k]]) {
                                p++;
                            }
                        }
                        add[p]++;
                    }
                }
            }
            p = 1;
            while (s + add[p] < n) {
                s += add[p];
                ans += p * add[p];
                p++;
            }
            ans += p * (n-s);

            int ans1 = ans;
            for (int i = 1; i <= r; i++){
                for (int j = 1; j <= c; j++){
                    a[i][j] = a[i][j] ^ true;
                }
            }
            s = r*c - s;
            ans = 0;
            memset(add, 0, sizeof(add));
            for (int i = 1; i <= r; i++){
                for (int j = 1; j <= c; j++){
                    if (!a[i][j]){
                        p = 0;
                        for (int k = 0; k < 4; k++) {
                            if (a[i+dx[k]][j+dy[k]]) {
                                p++;
                            }
                        }
                        add[p]++;
                    }
                }
            }
            p = 1;
            while (s + add[p] < n) {
                s += add[p];
                ans += p * add[p];
                p++;
            }
            ans += p * (n-s);

            ans = min(ans1, ans);
            cout << ans << endl;
        }
    }
    return 0;
}
