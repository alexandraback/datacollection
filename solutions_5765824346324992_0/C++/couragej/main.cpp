#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 10005;//数据规模，可修改

int m[N];
int gcd(int a,int b)
{
    int tmp;
    if(a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    while(a % b != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return b;
}
int lcm(int a, int b)

{

        return a*b/gcd(a, b);

}

int nlcm(int *a, int n){
      if (n == 1)
            return *a;
      else
            return lcm(a[n-1], nlcm(a, n-1));

}

int flag[N];
int place[25*25*25*25*25 + 5];

map <int, int> MII;


int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cases;
    scanf ("%d", &cases);
    for(int cas = 1; cas <= cases; cas ++) {
        MII.clear();
        int B, n;
        scanf ("%d %d", &B, &n);
        int num = 1;
        for (int i = 0; i < B; i++) {
            scanf ("%d", &m[i]);
            num *= m[i];
            flag[i] = -1;
        }
        for (int i = 0; i < num; i++) {
            place[i] = 0;
        }
        //cout << num << endl;
        int ans = 0;
        int id = 0;
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < B; j++) {
                //printf ("%d %d - %d m = %d\n", i, j, flag[j], m[j]);
                if ((i - flag[j]) >= m[j] || flag[j] == -1) {
                    flag[j] = i;
                    place[i] = j + 1;
                    MII[++id] = j + 1;
                    //break;
                }
            }
            //printf ("place %d\n", place[i]);
        }
        n %= id;
        if (n == 0) n = id;
        ans = MII[n];
//        if (ans == 0) {
//            n %= num;
//            ans = place[n];
//        }

        printf ("Case #%d: %d\n", cas, ans);
    }

    return 0;
}
