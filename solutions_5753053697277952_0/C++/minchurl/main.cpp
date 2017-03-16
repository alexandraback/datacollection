#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int chk[30],b[30],n,ans[1005][5];
int is_ok(){
    int i;
    for(i=0;i<n;i++)    if(b[i])    return 1;
    return 0;
}
int main(){
    int x,i,j,cnt,T,tt,sum=0;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for(tt=1;tt<=T;tt++){
        scanf("%d",&n);
        sum=0;
        for(i=0;i<n;i++){
            scanf("%d",&b[i]);
            chk[i]=0;
            sum+=b[i];
        }
        for(i=0;i<=sum;i++) ans[i][0]=ans[i][1]=0;
        x=0;
        cnt=0;
        while(is_ok()){
            j=2;
            for(i=0;i<n;i++){
                for(;j>=1;j--){
                    if(b[i]<=0)   break;
                    if((j==2 && chk[i]+1<=(x+2)/2) || chk[i]+1<=(x+1)/2){
                          ans[cnt][2-j]=i+1;
                          chk[i]++;
                          x++;
                          b[i]--;
                    }else   break;
                }
            }
            cnt++;
        }
        printf("Case #%d: ",tt);
        for(i=cnt-1;i>=0;i--){
            for(j=0;j<2;j++){
                if(ans[i][j]==0)    break;
                printf("%c",'A'+ans[i][j]-1);
            }
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
