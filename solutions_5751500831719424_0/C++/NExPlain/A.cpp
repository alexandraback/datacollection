#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
using namespace std;

#define CLR(a,b) memset(a,b,sizeof(a))
const int N = 1000+20;
int n;
char s[N][N];
char st[N];
int l[N];
int p[N];
bool solve()
{
    CLR(p,0);
    int tot = 0;
    for(int i = 0 ; i < l[0] ; i ++){
        if(i == 0 || s[0][i] != s[0][i-1]){
            st[tot++] = s[0][i];
        }
    }
    int pos = 0;
    int ans = 0;
    while(pos < tot){
        vector<int> vec;
        for(int i = 0 ;i < n ; i++){
            if(s[i][p[i]] != st[pos])return 0;
            int pre = p[i];
            while(s[i][p[i]] == st[pos])p[i]++;
            vec.push_back(p[i]-pre);
        }
        sort(vec.begin(),vec.end());
        int tt = vec[vec.size()/2];
        for(int i = 0 ; i < vec.size(); i ++){
            if(vec[i] > tt)ans += vec[i]-tt;
            else ans += tt-vec[i];
        }
        pos ++;
    }
    for(int i = 0 ; i < n ; i++){
        if(p[i] < l[i])return 0;
    }
    printf("%d\n",ans);
    return 1;
}
int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int T,cas = 0;
    scanf("%d",&T);
    while(T--){
        cas ++;
        printf("Case #%d: ",cas);
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){
            scanf("%s",s[i]);
            l[i] = strlen(s[i]);
        }
        if(!solve()){
            puts("Fegla Won");
        }
    }
    return 0;
}
