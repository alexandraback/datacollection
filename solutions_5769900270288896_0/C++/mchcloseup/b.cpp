#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int ev[10004],od[10004],en,on;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int R,C,N;
int inx(int x){
    if(x>=1&&x<=R)return true;
    return false;
}
int iny(int y){
    if(y>=1&&y<=C)return true;
    return false;
}

int sum,ans;

int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out_B.txt", "w", stdout);
    int ee,oo,i,j,k,m,l,n,t,temp;
    scanf("%d",&t);
    for(l=1;l<=t;l++){
        en=on=0;
        ee=0;oo=0;
        scanf("%d%d%d",&R,&C,&N);
        sum=(R-1)*C+(C-1)*R;
        N=R*C-N;
        for(i=1;i<=R;i++)
            for(j=1;j<=C;j++){
                if((i+j)%2==0){
                    temp=0;
                    for(k=0;k<=3;k++)
                        if(inx(i+dx[k])&&iny(j+dy[k]))
                            temp++;
                    od[++on]=temp;
                }
                else {
                    temp=0;
                    for(k=0;k<=3;k++)
                        if(inx(i+dx[k])&&iny(j+dy[k]))
                            temp++;
                    ev[++en]=temp;
                }
            }
        sort(ev+1,ev+en+1);
        sort(od+1,od+on+1);
        for(i=en;i>en-min(en,N);i--)
            ee+=ev[i];
        for(i=on;i>on-min(N,on);i--)
            oo+=od[i];
        //  printf("%d %d",ev[N],od[on]);
        ans=max(ee,oo);
        printf("Case #%d: ",l);
        printf("%d\n",sum-ans);
    }
}
