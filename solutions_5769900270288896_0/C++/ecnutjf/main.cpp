#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
using namespace std;

const int maxn = 1000005;
const int inf  = 0x3f3f3f3f;
const double eps = 1e-8;
typedef long long ll;
int a[17][17];
int main() {
    int T;
    freopen("in.txt","r",stdin);
    freopen("codejam.txt", "w", stdout);
    cin >> T;
    int cas = 1;
    while(T --) {
        int r,c,n;
        cin >> r >> c >> n;
        int l = r*c;
        int _min = inf;
        for(int i=0;i<1<<l;i++){
            for(int x=0;x<r;x++){
                for(int j=0;j<c;j++){
                    a[x][j] = 0;
                }
            }
            int cnt = 0;
            for(int j=0;j<l;j++){
                if((i>>j)&1){
                    a[j/c][j%c] = 1;
                    cnt ++;
                }
            }
            if(cnt != n)continue;
            int ans = 0;
            for(int x=0;x<r;x++){
                for(int y=0;y<c;y++){
                    if(a[x][y] == 1){
                        if(x > 0){
                            if(a[x-1][y] == 1){
                                ans ++;
                            }
                        }
                        if(y > 0){
                            if(a[x][y-1] == 1){
                                ans ++;
                            }
                        }
                    }
                }
            }
            _min = min(_min, ans);
        }
        printf("Case #%d: %d\n",cas++, _min);
    }
}
