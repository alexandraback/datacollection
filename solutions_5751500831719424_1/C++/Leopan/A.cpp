#include <bits/stdc++.h>
#define mpr std::make_pair
#define lg std::__lg
#define X first
#define Y second
#define mst(x) memset(x,0,sizeof(x))
#define mst1(x) memset(x,-1,sizeof(x))
#define RI(n) scanf("%d",&n);
#define RI2(a,b) scanf("%d%d",&a,&b);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
typedef long long LL;
typedef double LD;
template<class T>inline void maz(T &a,T b){if(a<b)a=b;}
template<class T>inline void miz(T &a,T b){if(a>b)a=b;}
template<class T>inline T abs(T a){return a>0?a:-a;}
using namespace std;
const int MAXN = 100 + 10;
string s[MAXN];
char a[MAXN][MAXN];
int c[MAXN][MAXN];
int p[MAXN];
int T,Case=0,n,ans;
bool check(){
    for(int i=0;i<n;i++){
        if(p[i]!=p[0])return 0;
    }
    for(int i=0;i<=p[0];i++){
        for(int j=0;j<n;j++){
            if(a[j][i]!=a[0][i])return 0;
        }
    }
    return 1;
}
main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        for(int i=0;i<n;i++)cin>>s[i];
        for(int i=0;i<n;i++){
            char last=-1;
            int cc=0,top=-1;
            for(int j=0;j<s[i].size();j++){
                if(last!=s[i][j]){
                    last=s[i][j];
                    a[i][++top]=s[i][j];
                    c[i][top]=1;
                }
                else{
                    c[i][top]++;
                }
            }
            p[i]=top;
        }
        if(check()==0)printf("Case #%d: Fegla Won\n",++Case);
        else{
            for(int i=0;i<=p[0];i++){
                int res=2147483647;
                for(int j=0;j<n;j++){
                    int sum=0;
                    for(int k=0;k<n;k++){
                        sum+=abs(c[j][i]-c[k][i]);
                    }
                    miz(res,sum);
                    //printf("%d %d %d %d\n",i,j,k,sum);
                }
                ans+=res;
            }
            printf("Case #%d: %d\n",++Case,ans);
        }
    }
}
