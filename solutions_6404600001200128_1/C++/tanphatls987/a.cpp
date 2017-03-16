#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A-large.in","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e3+10;

int test,n,a[N];
int main(){
    INPUT;OUTPUT;
    scanf("%d",&test);
    FOR(T,1,test){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",a+i);
        int ans1=0,ans2=0;
        FOR(i,2,n) if (a[i]<a[i-1]) ans1+=a[i-1]-a[i];
        int per=0;
        FOR(i,2,n) per=max(per,a[i-1]-a[i]);
        FOR(i,1,n-1) ans2+=min(a[i],per);
        printf("Case #%d: %d %d\n",T,ans1,ans2);
    }
}
