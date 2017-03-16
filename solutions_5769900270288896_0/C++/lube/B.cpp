#include <stdio.h>

#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) (x)>(y)?(x):(y)

int main() {
    freopen("B-small-attempt4.in", "r", stdin);
    freopen("outB.txt", "w+", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++) {
        int R,C,N,ans;
        scanf("%d%d%d", &R,&C,&N);
        int th = (R*C+1)/2;
        int th1 = R+C-2;
        if(N<=th)   ans = 0;
        else {
            int m = min(R,C);int M = max(R,C);
            int k = N-th;
            int k1 = N-th1;
            if(m==1)
                ans = 2*k-(M+1)%2;
            else if (m==2)
                ans = 3*k-(k>2?2:k);
            else if (m==3) {
                if(M==3) {
                    if(k1 == 4) ans = 8;
                    else    ans = k*3;
                } else {
                    if(k1<3)   ans = 2*k;
                    else if(N==9||N==10) ans = 3*(N-6)-2;
                    else if(k1<=5)    ans = 2*k1;
                    else if(k1<=6)   ans = 2*k1+1;
                    else    ans = 17;
                }
            } else if (m==4) {
                if(k1<=4)    ans = k*2;
                else if(k1<=6)   ans = 4+(k1-4)*3;
                else if(k1<=8)   ans = k1*2;
                else    ans = 16+(k1-8)*4;
            }
        }

        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}
