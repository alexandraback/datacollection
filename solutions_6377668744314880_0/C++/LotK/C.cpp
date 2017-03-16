#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int x[4000], y[4000];

int sol(int pos) {
    int minimum = n;
    for(int i=0 ; i<n ; i++) {
        if(i==pos) continue;

        if(x[pos] != x[i]) {
            double m = 1.0 * (y[pos] - y[i]) / (x[pos] - x[i]);
            double c = y[pos] - m*x[pos];

            int up = 0, down = 0;
            for(int j=0 ; j<n ; j++) {
                if(j==pos || j==i) continue;
                double temp = y[j] - (m*x[j]+c);
                if(temp > 1e-6) up++;
                else if(temp < -1e-6) down++;
            }

            if(min(up, down) < minimum) {
                minimum = min(up, down);
//                printf("1 pos %d i=%d %d %d\n", pos, i, up, down);
            }
        }
        else {
            int left = 0, right = 0;
            for(int j=0 ; j<n ; j++) {
                if(j==pos || j==i) continue;
                double temp = x[pos] - x[j];
                if(temp > 1e-6) left++;
                else if(temp < -1e-6) right++;
            }

            if(min(left, right) < minimum) {
                minimum = min(left, right);
//                printf("2 pos %d i=%d %d %d\n", pos, i, left, right);
            }
        }
    }
    return minimum;
}
int main() {
    int tt;
    scanf("%d", &tt);
    for(int t=0 ; t<tt ; t++) {
        scanf("%d", &n);
        for(int i=0 ; i<n ; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }

        printf("Case #%d:\n", t+1);
        for(int i=0 ; i<n ; i++) {
            if(n==1) printf("0\n");
            else
                printf("%d\n", sol(i));
        }
    }
}
