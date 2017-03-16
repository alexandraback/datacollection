#include <iostream>
#include <cstdlib>
#include <cstdio>

#include <algorithm>
#include <cmath>

#define repp(i,a,b,d) for(int i=a;i<=b;i+=d)
#define rep(i,a,b) repp(i,a,b,1)
#define revv(i,a,b,d) for(int i=a;i>=b;i-=d)
#define rev(i,a,b) revv(i,a,b,1)

#define OO (int)1e9
#define INF (long long)1e17

using namespace std;

typedef long long ll;

int tc;
int n;
int arr[1005];
int a1,a2;
int dmax;

int main(){
    scanf("%d",&tc);
    rep(z,1,tc){
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&arr[i]);
        
        a1=a2=dmax=0;
        rep(i,2,n){
            if(arr[i-1]>arr[i]){
                dmax = max(dmax, arr[i-1]-arr[i]);
                a1 += arr[i-1]-arr[i];
            }
        }
        rep(i,1,n-1){
            if(arr[i]>dmax)a2+=dmax;
            else a2+=arr[i];
        }
        printf("Case #%d: %d %d\n",z,a1,a2);
    }
    
    //system("pause");
    return 0;
}
