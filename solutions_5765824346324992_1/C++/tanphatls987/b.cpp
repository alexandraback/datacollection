#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B-large.in","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
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

int test,n,x,a[N];
int main(){
    INPUT;OUTPUT;
    scanf("%d",&test);
    FOR(T,1,test){
        scanf("%d%d",&n,&x);
        FOR(i,1,n) scanf("%d",a+i);
        ll L=0,R=ll(1e14);
        while (L<=R){
            ll M=(L+R)/2,per=0;
            FOR(i,1,n) per+=M/a[i]+1;
            //cout<<M<<" "<<per<<'\n';
            if (per>=x) R=M-1;
            else L=M+1;
        }

        FOR(i,1,n) x-=(L-1)/a[i]+1;
        //cout<<L<<" "<<x<<'\n';
        int sel;
        FOR(i,1,n) if (x&&L%a[i]==0) x--,sel=i;
        printf("Case #%d: %d\n",T,sel);
    }
}
