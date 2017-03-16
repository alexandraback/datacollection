#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define N 1000005
#define M 25
#define Mod 1000000007
#define INF 2000000007
typedef long long LL;
int n , m;
int a[5][5] , b[20];
int cases = 0;
void Solve(){
     int i , j , k , l;
     memset(b,0,sizeof(b));
     cin >> n;
     for (i=1;i<=4;++i)
         for (j=1;j<=4;++j) scanf("%d",&a[i][j]);
     for (i=1;i<=4;++i) ++b[a[n][i]];
     cin >> n;
     for (i=1;i<=4;++i)
         for (j=1;j<=4;++j) scanf("%d",&a[i][j]);
     for (i=1;i<=4;++i) ++b[a[n][i]];
     n = 0;
     for (i=1;i<=16;++i)
         if (b[i] == 2) ++n , m = i;
     printf("Case #%d: ",++cases);
     if (n == 0) puts("Volunteer cheated!"); else
     if (n == 1) printf("%d\n",m); else puts("Bad magician!");
}

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("2.txt","w",stdout);
    int test;
    cin >> test;
    while (test--) Solve();
    return 0;
}
