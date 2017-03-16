#include<bits/stdc++.h>
typedef long long int uli;
using namespace std;

const int mx=1e3+10;
int d[mx];

int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int t,n;
    scanf("%d",&t);
        
    for(int tt=1;tt<=t;tt++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",d+i);
        }
        int y=0;
        int v=0;
        for(int i=0;i<n-1;i++){
            if(d[i]>d[i+1]){
                y+=d[i]-d[i+1];
                v=max(v,d[i]-d[i+1]);
            }
        }
        int z=0;
        for(int i=0;i<n-1;i++){
            z+=min(d[i],v); 
        }
        printf("Case #%d: %d %d\n",tt,y,z);        
    }
    return 0;
}
