#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 500
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif

char str[maxn][maxn];
char s[maxn][maxn];
int cnt[maxn][maxn];

int main(){
    freopen("A-large (1).in","r",stdin);
    freopen("outpu.txt","w",stdout);
    int i,j,k;
    int n,m;
    int _,cas=1;
    cin>>_;
    while(_--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
        }
        memset(cnt,0,sizeof cnt);
        int pos;
        for(int i=0;i<n;i++){
            pos = -1;
            s[i][++pos]=str[i][0];
            cnt[i][pos]=1;
            for(int j=1;str[i][j];j++){
                if(str[i][j]==str[i][j-1]){
                    cnt[i][pos]++;
                    continue;
                }
                s[i][++pos]=str[i][j];
            }
            s[i][++pos]=0;
        }
        bool ok=true;
        for(int i=1;i<n;i++){
//            printf("%s  --\n",s[i]);
            if(strcmp(s[i],s[i-1])!=0)ok=false;
        }
        printf("Case #%d: ",cas++);
        if(ok==false){
            puts("Fegla Won");
            continue;
        }
        int ans=0;
        vector<int>v;
        for(int i=0;i<pos;i++){
            v.clear();
            for(int j=0;j<n;j++){
                v.push_back(cnt[j][i]);
            }
            sort(v.begin(),v.end());
            int tmp = v[n/2];
            for(int j=0;j<n;j++){
                ans+=abs(v[j]-tmp);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
