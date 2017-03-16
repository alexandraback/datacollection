#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#define ll long long

using namespace std;

int c[10][10];
int cal_o(int x){
    if (x % 2 == 1)  return x / 2 + 1;
    return x / 2;
}

int cal_e(int x){
    return x / 2;
}

int cal0(int x){
    int s = 0;
    if (c[0][4] >= x) return s + 4 * x;
    s += 4 * c[0][4];
    x -= c[0][4];
     if (c[0][3] >= x) return s + 3 * x;
    s += 3 * c[0][3];
    x -= c[0][3];
     if (c[0][2] >= x) return s + 2 * x;
    s += 2 * c[0][2];
    x -= c[0][2];
     if (c[0][1] >= x) return s + 1 * x;
    s += 1 * c[0][1];
    x -= c[0][1];
    return s;
}

int cal1(int x){
    int s = 0;
    if (c[1][4] >= x) return s + 4 * x;
    s += 4 * c[1][4];
    x -= c[1][4];
     if (c[1][3] >= x) return s + 3 * x;
    s += 3 * c[1][3];
    x -= c[1][3];
     if (c[1][2] >= x) return s + 2 * x;
    s += 2 * c[1][2];
    x -= c[1][2];
     if (c[1][1] >= x) return s + 1 * x;
    s += 1 * c[1][1];
    x -= c[1][1];
    return s;
}

int cal(int x){
//    cout <<max(cal1(x), cal0(x))<<endl;
    return max(cal1(x), cal0(x));
}

int main(){
  int T, cas = 0;
    freopen("a.in", "r", stdin);
   freopen("a.out", "w", stdout);
    cin>>T;
    while(T--){
        int a, b, n, i, j;
        cin>>a>>b>>n;
        int ans = 0;
        if (a > b) swap(a, b);
        if (a == b && a == 1) ans = 0; else
        if (n <= max(a * b / 2, a * b  - a * b / 2)) ans = 0; else {
            memset(c, 0, sizeof(c));
            if (a == 1){
                c[0][1] += 1;
                c[(1 + b) % 2][1] += 1;
                c[0][2] = cal_o(b - 1) - 1;
                c[1][2] = cal_e(b - 1) ;
                ans = a * (b + 1) + b * (a + 1) -  2 * (a + b) - cal(a * b - n);
            } else {
                c[0][2] += 2;
                c[(1 + b) % 2][2] += 2;
                c[0][3] = 2 * (cal_o(b - 1) - 1);
                c[1][3] = 2 * (cal_e(b - 1) );
                c[0][3] += a - 2;
                c[(1 + b) % 2][3] += a - 2;
                c[0][4] = (a - 2) * (cal_o(b - 1) - 1);
                c[1][4] = (a - 2) * (cal_e(b - 1));
                for(i = 1; i <= 4; i++)
//                cout<<c[0][i]<<"  "<<c[1][i]<<endl;
//                cout<<a * (b + 1) + b * (a + 1)  <<endl;
                ans = a * (b + 1) + b * (a + 1) -  2 * (a + b) - cal(a * b - n);
            }
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
