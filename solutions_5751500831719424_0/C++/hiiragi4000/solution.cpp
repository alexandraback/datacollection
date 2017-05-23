#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define N 110
#define L 110
using namespace std;
typedef pair<char,int>pci;
int n;
char s[L];
vector<pci>vec[N];
int a[N];
void invert(int i,char*s){
    int len=strlen(s);
    for(int j=0;j<len;j++){
        vec[i].push_back(make_pair(s[j],1));
        while(j+1<len&&s[j+1]==s[j])vec[i].back().second++,j++;
    }
}
bool cmp(){
    int m=vec[1].size();
    for(int i=2;i<=n;i++){
        if(vec[i].size()!=m)return 0;
        for(int j=0;j<m;j++)if(vec[i][j].first!=vec[1][j].first)return 0;
    }
    return 1;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)vec[i].clear();
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            invert(i,s);
        }
        if(!cmp()){
            printf("Case #%d: Fegla Won\n",t);
            continue;
        }
        int m=vec[1].size(),ans=0;
        for(int i=0;i<m;i++){
            for(int j=1;j<=n;j++)a[j]=vec[j][i].second;
            sort(a+1,a+n+1);
            for(int j=1;j<=n;j++)ans+=abs(a[j]-a[n+1>>1]);
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
