#include<cstdio>
using namespace std;
int arr[1000];
int tc,n,ans1,ans2,rate;
int main(){
    scanf("%d",&tc);
    for(int ct=1;ct<=tc;++ct){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }
        ans1=0;
        for(int i=1;i<n;++i){
            if(arr[i]<arr[i-1])ans1+=arr[i-1]-arr[i];
        }
        rate=0;
        for(int i=1;i<n;++i){
            if(arr[i-1]-arr[i]>rate)rate=arr[i-1]-arr[i];
        }
        ans2=0;
        for(int i=1;i<n;++i){
            if(arr[i-1]-rate>0)ans2+=rate;
            else ans2+=arr[i-1];
        }
        printf("Case #%d: %d %d\n",ct,ans1,ans2);
    }
}
