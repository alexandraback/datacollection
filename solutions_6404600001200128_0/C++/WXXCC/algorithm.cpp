#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<map>
#include<climits>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<queue>
#include<bitset>
#include<set>
#include<cmath>
#include<list>
#include<sstream>
using namespace std;
const int M = 10010;
const int N = 10;
const double eps = 1e-5;
const double dinf = 1e15;
//const int MOD = 1000000007;
const int inf = INT_MAX;
const int ninf = INT_MIN;
const long long MOD = 1000000007;
const int mod = 100007;
int n;
int mush[M];

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T --){
        printf("Case #%d: ",cas++);
        scanf("%d",&n);
        for(int i = 0; i < n; ++ i)
            scanf("%d",&mush[i]);
        int ans1 = 0, ans2 = 0;
        for(int i = 1; i < n; ++ i){
            if(mush[i - 1] > mush[i])
                ans1 += mush[i - 1] - mush[i];
        }
        int dif = 0;
        for(int i = 1; i < n; ++ i){
            dif = max(dif, mush[i - 1] - mush[i]);
        }
  //      printf("%d - ",dif);
        if(dif){
            for(int i = 0; i < n - 1; ++ i){
  //                  printf(" - %d \n",min(dif, mush[i]));
                ans2 += min(dif, mush[i]);
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
