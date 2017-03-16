#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int cas;
int ev[10004],od[10004];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int r,c;
int inx(int x){
    if(x>=1&&x<=r)return true;
    return false;
}
int iny(int y){
    if(y>=1&&y<=c)return true;
    return false;
}
int main(){
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int T;
    int n,sum,tot,ans,ee,oo,en,on,temp;
    scanf("%d",&T);
    while(T--){
        ee=oo=0;
        en=on=0;
        scanf("%d%d%d",&r,&c,&n);
        sum=(r-1)*c+(c-1)*r;
        n=(r*c-n);
        for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            if((i+j)%2==0){
                temp=0;
                for(int k=0;k<=3;k++)
                    if(inx(i+dx[k])&&iny(j+dy[k]))
                        temp++;
                od[++on]=temp;
            }
            else {
                temp=0;
                for(int k=0;k<=3;k++)
                    if(inx(i+dx[k])&&iny(j+dy[k]))
                        temp++;
                ev[++en]=temp;
            }
        }
        sort(ev+1,ev+en+1);
        sort(od+1,od+on+1);
        for(int i=en;i>en-min(en,n);i--)
            ee+=ev[i];
        for(int i=on;i>on-min(n,on);i--)
            oo+=od[i];
        ans=max(ee,oo);
        printf("Case #%d: ",++cas);
        printf("%d\n",sum-ans);
    }
    return 0;
}

