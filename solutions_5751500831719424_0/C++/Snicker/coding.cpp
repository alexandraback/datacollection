#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
int T;
int m;
char target[110];
char temp[110];
string str[110];
int num[110][110];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    int cas = 0;
    while(T--) {
        int n;
        scanf("%d", &n);
        int m = -1;
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            cin>>str[i];
            int len = str[i].size();
            int cnt = 0;
            for(int j = 0 ; j < len; j++) {
                if(j == 0 || str[i][j] != str[i][j - 1]) {
                    temp[++cnt] = str[i][j];
                    num[i][cnt] = 1;
                } else {
                    num[i][cnt]++;
                }
            }
            if(m == -1) {
                m = cnt;
                for(int j = 1; j <= cnt; j++) {
                    target[j] = temp[j];
                }
            } else {
                if(m != cnt) {
                    flag = false;
                } else {
                    for(int j = 1; j <= cnt; j++) {
                        if(target[j] != temp[j]) {
                            flag = false;
                        }
                    }
                }
            }
        }
        printf("Case #%d: " , ++cas);
        if(flag) {
            int ans = 0;
            for(int i = 1; i <= m; i++) {
                int sum = -1;
                for(int j = 1; j <= 100; j++) {
                    int tmp = 0;
                    for(int k = 1; k <=n; k++) {
                        tmp += abs(num[k][i] - j);
                    }
                    if(sum == -1 || sum > tmp) {
                        sum = tmp;
                    }
                }
                ans += sum;
            }
            printf("%d\n", ans);
        } else {
            puts("Fegla Won");
        }
    }
    return 0;
}
