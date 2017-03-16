#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T , n=4 , Tn=0 , x , vi[20] , arr[5][5];
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    cin>>T;
    while(T--){
        memset(vi,0,sizeof(vi));
        ++Tn;
        cin>>x;
        for(int j=1;j<=n;j++)
            for(int i=1;i<=n;i++){
                cin>>arr[j][i];
                if(j==x) vi[arr[j][i]]++;
            }
        cin>>x;
        for(int j=1;j<=n;j++)
            for(int i=1;i<=n;i++){
                cin>>arr[j][i];
                if(j==x) vi[arr[j][i]]++;
            }
        int sol=0,ans;
        for(int j=1;j<17;j++){
            if(vi[j]>1){
                sol++;
                ans=j;
            }
        }
        printf("Case #%d: ",Tn);
        if(sol==0) printf("Volunteer cheated!");
        if(sol>1) printf("Bad magician!");
        if(sol==1) printf("%d",ans);
        puts("");


    }
}
