#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

#define MAXN 111011

int T, n, R, C;

int main(){
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);

    int cas = 1;

    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &R, &C, &n);

        if(R == 1 && C == 1) {
            printf("Case #%d: 0\n", cas++);
            continue;
        }

        int m = R * C;
        int lim = (m + 1) / 2;
        if(n <= lim) {
            printf("Case #%d: 0\n", cas++);
        } else {
            int ans = (R - 1) * C;
            ans += (C - 1) * R;

            int four = 0, three = 0, two = 0, one = 0;

            if(R != 1 && C != 1) {
                int r = R - 2; int c = C - 2;
                four = (r * c + 1) / 2;

                if(r > c) swap(r, c);
                if(r == 1 && c == 1) {
                    three = 0;
                } else if(r == 1) {
                    three = c / 2 * 2 + 1;
                    if(!(c & 1)) three++;
                } else {
                    three = r / 2 + c / 2;
                    three <<= 1;
                }
                two = 1;
                if(r & 1) two++;
                if(c & 1) two++;
                if((r & 1) == (c & 1)) two++;
            } else if(R == 1) {
                two = (C - 1) / 2;
                if(C & 1) one = 0;
                else one = 1;
            } else if(C == 1) {
                two = (R - 1) / 2;
                if(R & 1) one = 0;
                else one = 1;
            }


            int nd = R * C - n;
            if(nd > four) {
                nd -= four;
                ans -= 4 * four;
            } else {
                ans -= nd * 4;
                nd = 0;
            }

            if(nd > three) {
                nd -= three;
                ans -= 3 * three;
            } else {
                ans -= nd * 3;
                nd = 0;
            }

            if(nd > two) {
                nd -= two;
                ans -= 2 * two;
            } else {
                ans -= nd * 2;
                nd = 0;
            }

            if(nd > one) {
                nd -= one;
                ans -= one;
            } else {
                ans -= nd;
                nd = 0;
            }

            printf("Case #%d: %d\n", cas++, ans);
        }
    }

    return 0;
}

