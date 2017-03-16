#include<bits/stdc++.h>
using namespace std;
struct P{
    long long int x,y;
    double ang;
};
vector<P> arr;
vector<P> wait;
int cmp(P a,P b){
    return a.ang<b.ang;
}
int n;
int sol(){
    if(n==1) return 0;
    int i,j=0,ans=-1;
    for(i=0;i<wait.size()/2;i++){

        while(j+1<wait.size() && wait[i].x*wait[j+1].y-wait[i].y*wait[j+1].x<=0) j++;
        //printf("(%d,%d-------%d,%d) ",wait[i].x,wait[i].y,i,j);
        if(ans==-1 || max(n-1-(j-i+1),0)<ans) ans=max(n-1-(j-i+1),0);
    }
    return ans;
}
int main(){
    int C=0,t,m,i,j;
    long long int x,y;
    freopen("C-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        arr.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld%lld",&x,&y);
            arr.push_back((P){x,y,0});
        }
        printf("Case #%d:\n",++C);
        for(i=0;i<n;i++){
            //if(i!=4) continue;
            wait.clear();
            for(j=0;j<n;j++){
                if(i==j) continue;//printf("%d,%d,--[%d,%d,]\n",arr[j].x,arr[j].y,arr[i].x,arr[i].y);
                wait.push_back((P){arr[j].x-arr[i].x,arr[j].y-arr[i].y,atan2(arr[j].x-arr[i].x,arr[j].y-arr[i].y)});
            }

            sort(wait.begin(),wait.end(),cmp);
            for(j=0;j<n-1;j++){
                wait.push_back(wait[j]);
            }
            printf("%d\n",sol());
        }//puts(".");
    }
}
