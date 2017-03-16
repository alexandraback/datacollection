#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define EPS (1e-10)
#define lef(x) (x<<1)
#define rig(x) (x<<1)+1
#define PI (2*acos(0.0))
int mush[1005];
void solve(){
     printf(" ");
     int n;
     scanf("%d",&n);
     for (int i=0;i<n;++i) scanf("%d",&mush[i]);
     int m1,m2;
     //method 1
     m1=0;
     for (int i=1;i<n;++i){
         if (mush[i-1]>=mush[i]){
            m1+=(mush[i-1]-mush[i]);
         }
     }
     //method 2
     m2=0;
     int rate=0;
     for (int i=1;i<n;++i){
         if (mush[i-1]>mush[i] && rate<mush[i-1]-mush[i]){
            rate=mush[i-1]-mush[i];
         }
     }
     for (int i=1;i<n;++i){
         if (mush[i-1]<=rate) m2+=mush[i-1];
         else{
              m2+=rate;
         }
     }
     printf("%d %d\n",m1,m2);
}
int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d:",test);
        solve();
    }
    return 0;
}
