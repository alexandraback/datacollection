#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sll(x) scanf("%I64d",&x)
#define pll(x) printf("%I64d\n",x)
#define sc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define sf(x) scanf("%f",&x)
#define pf(x) printf("%f",x)
#define sd(x) scanf("%lf",&x)
#define pd(x) printf("%lf",x)
#define sld(x) scanf("%Lf",&x)
#define pld(x) printf("%Lf",x)
#define clr(a) memset(a,0,sizeof(a))
#define MOD 1000000009
using namespace std;
int main(void){
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int ss=0;
    while(t--){
        ss++;
        int a;
        int b;
        int freq[17];
        memset(freq,0,sizeof(freq));
        int m1[4][4];
        int m2[4][4];
        cin>>a;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cin>>m1[i][j];
                if(i==a-1){
                    freq[m1[i][j]]++;
                }
            }
        }
        cin>>b;
        int ans;
        int c=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cin>>m2[i][j];
                if(i==b-1){
                    if(freq[m2[i][j]]){
                        ans=m2[i][j];
                        c++;
                    }
                }
            }
        }
        if(c==1)
            printf("Case #%d: %d\n",ss,ans);
        else if(c>1)
            printf("Case #%d: Bad magician!\n",ss,ans);
        else
            printf("Case #%d: Volunteer cheated!\n",ss,ans);
    }
    return 0;
}
