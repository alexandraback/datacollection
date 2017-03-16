#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define LL long long

using namespace std;

int n,m,a[2333],T;
bool flag;

int main(){
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&T);
for(int t=1;t<=T;t++){
    scanf("%d %d",&n,&m);
    int ans=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(m<=n){ans=m;printf("Case #%d: %d\n",t,ans);continue;}
    m-=n;
    for(int i=1;i<=n;i++){
            flag=false;
        /*LL now=n*a[i];
        int num=0;
        for(int j=1;j<=n;j++){
            num+=now/a[j];
        }
        for(int j=i+1;j<=n;j++)if((now%a[j])==0)num--;
        if(num==m){ans=i;break;}
        if(t==1)printf("hahahaha%d\n",num);*/
        int l=1,r=m,mid=0;
        while(l<=r){
            mid=(l+r)/2;
            LL now=(LL)mid*a[i];
            LL num=0;
            for(int j=1;j<=n;j++)num+=now/(LL)a[j];
            for(int j=i+1;j<=n;j++)if((now%a[j])==0)num--;
            if(num==m){flag=true;break;}
            if(num>m)r=mid-1;
            if(num<m)l=mid+1;
           // if(t==1){printf("mid=%d",mid);printf("  num=%I64d\n",num);}

        }
        if(flag){ans=i;break;}
    }
    printf("Case #%d: %d\n",t,ans);
}
    return 0;
}
