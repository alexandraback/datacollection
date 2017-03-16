#include<cstdio>
#include<cstring>
int a[4][4],b[4][4];
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int m,n,i,j,T,tc=0,ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&m);
        for(i=0;i<4;++i) for(j=0;j<4;++j) scanf("%d",&a[i][j]);
        scanf("%d",&n);
        for(i=0;i<4;++i) for(j=0;j<4;++j) scanf("%d",&b[i][j]);
        printf("Case #%d: ",++tc);
        ans=0;
        --m,--n;
        for(i=0;i<4;++i){
            for(j=0;j<4;++j){
                if(a[m][i]==b[n][j]){
                    if(!ans) ans=a[m][i];
                    else{
                        printf("Bad magician!\n");
                        goto L;
                    }
                }
            }
        }
        if(ans) printf("%d\n",ans);
        else printf("Volunteer cheated!\n");
        L:;
    }
    return 0;
}
