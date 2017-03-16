#include <stdio.h>

int t,n,m[1010];

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&m[i]);
        }
        int ans1=0;
        int v=-1;
        for(int i=1;i<n;i++){
            if(m[i]<m[i-1]){
                int p = m[i-1]-m[i];
                ans1+=p;
                if(v==-1 || p>v){
                    v=p;
                }
            }
        }
        int ans2=0;
        if(v!=-1){
            for(int i=0;i+1<n;i++){
                if(v>m[i]) ans2+=m[i];
                else ans2+=v;
            }
        }
        printf("Case #%d: %d %d\n",ca,ans1,ans2);
    }
    return 0;
}
