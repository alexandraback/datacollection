#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

char s[110][110];
int a[110][110];
int b[110];

int main(){
    int t=0,cas,n,i,j,k,ans;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for (i=0;i<n;++i){
            scanf("%s",s[i]);
            a[i][0] = 1;
            for (k=j=1;s[i][j];++j){
                if (s[i][j] == s[i][j-1]){
                    a[i][k-1]++;
                }else{
                    s[i][k] = s[i][j];
                    a[i][k++]=1;
                }
            }
            s[i][k]=0;
//            printf("%s \n",s[i]);
//            for (j=0;s[i][j];++j)printf("%d ",a[i][j]);puts("");
        }
        printf("Case #%d: ",++t);
        bool flag=true;
        for (j=0;j<=strlen(s[0]);++j){
            for (i=1;i<n;++i)if (s[i][j]!=s[0][j]){flag=false;break;}
        }
        if (flag){
            ans = 0;
            for (j=0;s[0][j];++j){
                for (i=0;i<n;++i)b[i] = a[i][j];
                sort(b,b+n);
//                for (i=0;i<n;++i)printf(" %d",b[i]);puts("");
//                printf("mid:%d\n",b[(n-1)/2]);
                for (i=0;i<n;++i)ans += abs(b[i]-b[(n-1)/2]);
            }
            printf("%d\n",ans);
        }else{
            puts("Fegla Won");
        }
    }
    return 0;
}
