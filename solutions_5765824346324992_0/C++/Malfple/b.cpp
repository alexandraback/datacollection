#include <iostream>
#include <cstdlib>
#include <cstdio>

#include <vector>
#include <cstring>

#include <algorithm>
#include <cmath>

#define repp(i,a,b,d) for(int i=a;i<=b;i+=d)
#define rep(i,a,b) repp(i,a,b,1)
#define revv(i,a,b,d) for(int i=a;i>=b;i-=d)
#define rev(i,a,b) revv(i,a,b,1)

#define OO (int)1e9
#define INF (long long)1e17

#define pb push_back

using namespace std;

typedef long long ll;

int tc;
int b,n;
int arr[1005];
int tmp[1005];
vector<int>ord;
int mn;

int main(){
    scanf("%d",&tc);
    rep(z,1,tc){
        ord.clear();
        scanf("%d %d",&b,&n);
        rep(i,1,b)scanf("%d",&arr[i]);
        rep(i,1,b)tmp[i]=0;
        while(1){
            rep(i,1,b)if(tmp[i]==0){
                tmp[i]=arr[i];
                ord.pb(i);
                break;
            }
            mn = OO;
            rep(i,1,b)mn = min(mn, tmp[i]);
            rep(i,1,b)tmp[i]-=mn;
            bool quit = true;
            rep(i,1,b)if(tmp[i]>0)quit = false;
            if(quit)break;
        }
        //rep(i,0,(int)ord.size()-1)printf("%d ",ord[i]);printf("\n");
        printf("Case #%d: %d\n",z,ord[(n-1)%(int)ord.size()]);
    }
    //system("pause");
    return 0;
}
