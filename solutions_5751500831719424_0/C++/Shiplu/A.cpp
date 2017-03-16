#include<bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps (1e-9)
#define inf (1<<29)
#define i64 long long
#define u64 unsigned i64

vector<int> cnt[105];
vector<char> a[105];
int main(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int t,cs=1,i,j,n,c;
    char x[105];
    cin>>t;
    while(t--){
        cin>>n;
        for(i = 0;i<n;i++) cnt[i].clear(),a[i].clear();
        for(i = 0;i<n;i++){
            scanf("%s",x);
            a[i].pb(x[0]);
            c = 1;
            for(j = 1;x[j];j++){
                if(x[j] == x[j-1])
                    c++;
                else{
                    cnt[i].pb(c);
                    c = 1;
                    a[i].pb(x[j]);
                }
            }
            cnt[i].pb(c);
        }
        for(i = 1;i<n;i++){
            if(cnt[i].size()!=cnt[i-1].size()) break;
        }
        printf("Case #%d: ",cs++);
        if(i<n){ printf("Fegla Won\n"); continue;}
        for(i = 0;i<a[0].size();i++){
            for(j = 1;j<n;j++){
                if(a[j][i]!=a[j-1][i]) break;
            }
            if(j<n) break;
        }
        if(i<a[0].size()){ printf("Fegla Won\n"); continue;}
        int ans = 0,p,q,k;
        for(i = 0;i<cnt[0].size();i++){
            q = 100000000;
            for(j = 1;j<=100;j++){
                p = 0;
                for(k = 0;k<n;k++){
                    p+= abs(cnt[k][i] - j);
                }
                q = min(p,q);
            }
            ans+=q;
        }


        printf("%d\n",ans);
    }
	return 0;
}
