#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int wz[17][2];
int main(){
    int n,m,i,j,k,l,T,tt;
    freopen("A.out","w",stdout);
    scanf("%d",&T);
    tt=0;
    while(T--){
        tt++;
        scanf("%d",&n);
        for(i=1;i<=4;i++)
            for(j=1;j<=4;j++){
                scanf("%d",&k);
                wz[k][0]=i;
            }
        scanf("%d",&m);
        for(i=1;i<=4;i++)
            for(j=1;j<=4;j++){
                scanf("%d",&k);
                wz[k][1]=i;
            }   
        j=0;
        k=0;
        for(i=1;i<=16;i++)
            if(wz[i][0]==n&&wz[i][1]==m){
                j++;
                k=i;
            }
        printf("Case #%d: ",tt);
        if(j==0)printf("Volunteer cheated!\n");
        else if(j>1)printf("Bad magician!\n");
        else printf("%d\n",k);
    }
    return 0;
}
