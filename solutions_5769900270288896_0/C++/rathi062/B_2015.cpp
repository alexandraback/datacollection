#include<iostream>
#include <stdlib.h>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define mai3(a,b,c) mai(a,mai(b,c))
#define READ freopen("input.tit", "r", stdin)
#define WRITE freopen("output.tit", "w", stdout)
#define LL long long
#define MX 1000000005

#define F first
#define S second
#define pii pair<int,int>
#define p(i) printf("%d",i)
#define inp(i) scanf("%d",&i)
#define inpll(i) scanf("%lld",&i)
#define getci getchar_unlocked
/*inline void inp( int &n )
 {
 n=0;
 int ch=getci();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getci();}
 
 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getci();
 n=n*sign;
 }*/

using namespace std;
bool cells[17][17];
int r,c,n;
int res=MX;
int unhappyness(int i,int j){
    int cnt=0;
    if(i!=0 && cells[i-1][j]) cnt++; //top
    if(j!=0 && cells[i][j-1]) cnt++; //left;
    return cnt;
}

int fun(int row,int clm,int n,int unhpyns){
    if(unhpyns > res) return unhpyns;
    if(n==0)
        return unhpyns;
    int result = MX;
    int j=clm;
    for(int i=row;i<r;i++){
        for(;j<c;j++){
            cells[i][j] = 1;
            int unhy = fun(i,j+1,n-1, unhpyns + unhappyness(i,j)) ;
            result = min(result,unhy);
            res = min(res,result);
            cells[i][j] = 0;
        }
        j=0;
    }
    return result;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){

        CLR(cells);
        cin>>r>>c>>n;
        res = MX;
        int res = fun(0,0,n,0);
        cout<<"Case #"<<i+1<<": "<<res<<endl;
    }
    return 0;
}