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
#include<utility>
#include<stack>
#include<queue>
#include<bitset>
#include<set>
#include<cmath>
#include<list>
#include<sstream>
using namespace std;
const int M = 5000;
const int N = 10;
const double eps = 1e-8;
const double dinf = 1e15;
//const int MOD = 1000000007;
const int inf = INT_MAX;
const int ninf = INT_MIN;
const long long MOD = 1000000007;
const int mod = 100007;
pair<double, double> pt[M];
int ans[M];
int n;

double crossmulti(pair<double, double> p0,pair<double, double> p1, pair<double, double> p2){
	return (p1.first-p0.first)*(p2.second-p0.second)-(p2.first-p0.first)*(p1.second-p0.second);
}

int main(){
    freopen("C-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T --){
        printf("Case #%d:\n",cas++);
        scanf("%d",&n);
        for(int i = 0; i < n; ++ i)
            scanf("%lf%lf",&pt[i].first,&pt[i].second);
        if(n == 1)
            ans[0] = 0;
        else{
            for(int i = 0; i < n; ++ i){
                int minval = INT_MAX;
                for(int j = 0; j < n; j ++){
                    if(i == j)
                        continue;
                    int cnt = 0, cntl = 0, cntr = 0;
                    for(int k = 0; k < n; ++ k){
                        if(i == k || j == k)
                            continue;
                        double val = crossmulti(pt[i],pt[j],pt[k]);
                        if(val<-eps)
                            ++ cntr;
                        else if(val > eps)
                            ++ cntl;
                    }
                    cnt = min(cntl, cntr);
                    minval = min(minval, cnt);
                }
                ans[i] = minval;
            }
        }
        for(int i = 0; i < n; ++ i)
            printf("%d\n",ans[i]);
    }
    return 0;
}


/*
int n, b;
int bar[M];

int cal(int v){
    int res = 0;
    for(int i = 0; i < b; ++ i)
        res += v/bar[i];
    return res;
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T --){
        printf("Case #%d: ",cas++);
        scanf("%d%d",&b,&n);
        for(int i = 0; i < b; ++ i)
            scanf("%d",&bar[i]);
        int ans = 0;
        if(n <= b){
            ans = n;
        }else{
            n-=b;
            int l = 1, r = 1<<29, times;
            while(l <= r){
                int mid = (l + r)>>1;
                int val = cal(mid);
                if(val < n){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                    times = mid;
                }
            }
            for(int i = 0; i < b; ++ i){
                n -= (times - 1)/bar[i];
            }
            for(int i = 0; i < b; ++ i){
                if(times%bar[i] == 0){
                    -- n;
                    if(!n){
                        ans = i + 1;
                        break;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

/*
int n;
int mush[M];

int main(){
    freopen("A-large.in","r",stdin);
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
*/
