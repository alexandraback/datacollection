#include<cstdio>

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large-output.txt","w",stdout);
    int t,b,n,time[1000];
    long long left,right,middle,temp;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d %d",&b,&n);
        for(int j=0;j<b;j++){
            scanf("%d",&time[j]);
        }
        left=0;
        right=1e14;
        while(right-left>1){
            middle=(left+right)/2;
            temp=0;
            for(int j=0;j<b;j++){
                temp+=(middle/time[j]+1);
            }
            if(temp>n){
                right=middle;
            }
            else{
                left=middle;
            }
        }

        temp=0;
        for(int j=0;j<b;j++){
            temp+=(right/time[j]+1);
        }
        temp++;
        while(temp>n){
            for(int j=b-1;j>=0;j--){
                if(right%time[j]==0){
                    temp--;
                    if(temp==n){
                        printf("Case #%d: %d\n",i,j+1);
                        break;
                    }
                }
            }
            if(temp==n){
                break;
            }
            right--;
        }
    }
    return 0;
}
