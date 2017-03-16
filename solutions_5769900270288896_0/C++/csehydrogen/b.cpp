#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int a[16][16];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t; ++ti){
        int r, c, n, ans = INF;
        scanf("%d%d%d", &r, &c, &n);
        memset(a, 0, sizeof(a));
        while(true){
            int cnt = 0;
            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){
                    cnt += a[i][j];
                }
            }

            if(cnt == n){
                int uh = 0;
                for(int i = 0; i < r; ++i){
                    for(int j = 0; j < c; ++j){
                        if(a[i][j]){
                            for(int k = 0; k < 4; ++k){
                                int nx, ny;
                                nx = i + dx[k];
                                ny = j + dy[k];
                                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                                if(a[nx][ny]){
                                    ++uh;
                                }
                            }
                        }
                    }
                }
                uh /= 2;
                ans = min(ans, uh);
            }
            if(cnt == r*c) break;

            ++a[0][0];
            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){
                    if(a[i][j] > 1){
                        a[i][j] = 0;
                        if(j + 1 == c){
                            ++a[i + 1][0];
                        }else{
                            ++a[i][j + 1];
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n", ti, ans);
    }
    return 0;
}
