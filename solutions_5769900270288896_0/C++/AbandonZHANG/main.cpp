#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ca ++) {
		int R, C, N;
        scanf("%d%d%d", &R, &C, &N);
        if (R > C)
			swap(R, C);
		int ans;
        int tmp = (R*C + 1)/2;
		if (N <= tmp){
			ans = 0;
		}
        else{
            if (R == 1){
                if (C % 2 == 1)
					ans = (N - tmp)<<1;
                else
					ans = ((N - tmp)<<1) - 1;
            }
            else {
                int t = R*C;
                int m = (((R + C) << 1) - 4)/2;
                if (t % 2 == 1) {
                    N -= tmp;
                    int tmp1 = 0;
                    if (N <= m) tmp1 = 3*N;
                    else tmp1 = 3*m + (N - m)*4;
                    int tmp2 = 0;
                    ++N;
                    if (N <= 4) tmp2 = N*2;
                    else {
                        if (N <= m) tmp2 = (N - 4)*3 + 8;
                        else {
                            tmp2 = 8 + (m - 4)*3;
                            tmp2 += (N - m) * 4;
                        }
                    }
                    ans = min(tmp1, tmp2);
                }
                else {
                    N -= tmp;
                    if (N <= 2) ans = N << 1;
                    else {
                        if (N <= m) ans = 4 + (N - 2)*3;
                        else {
                            ans = 4 + (m - 2)*3 + (N - m)*4;
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
