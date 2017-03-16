#include<bits/stdc++.h>

using namespace std;
#include <fstream>
#include <sstream>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF INT_MAX/3
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)

#define VS vector<string>
#define VI vector<int>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PI acos(-1.0)

#define INFILE() freopen("B-small-attempt0.in","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define FASTIO ios_base::sync_with_stdio(0);cin.tie();

#define LL long long
#define ULL unsigned long long
#define EPS 1e-9
#define MOD 1000000007
#define xx first
#define yy second
#define PII pair<LL,LL>
template<typename T>inline string toString(T a){
    ostringstream os(""); os<<a; return os.str();
}
template<typename T>inline LL toLong(T a){
    LL res; istringstream os(a); os>>res; return res;
}
//MATHEMATICS
template<typename T>inline T  SQ(T a){ return a*a; }

template<typename T>inline ULL bigmod(T a, T b, T m) {
    if (b == 0)return 1;
    else if (b % 2 == 0)return SQ(bigmod(a, b / 2, m)) % m;
    else return (a % m*bigmod(a, b - 1, m)) % m;
}
template<typename T>inline VS parse(T str){
    VS res; string s; istringstream os(str); while(os>>s)res.PB(s); return res;
}
template<typename T>inline ULL  dist(T A,T B) {
    ULL res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y); return res;
}
template<typename T>inline double cosAngle(T a,T b,T c) {
    double res=a*a+b*b-c*c; res=res/(2*a*b); res=acos(res); return res;
}
int n,e,src;
int dp[8][(1<<8) + 4][17];
int R,C,N,M;
int solve(int,int,int);
int dfs(int idx, int pos, int bit , int cur ,  int sit){
    int ret=0;
    if(idx==C){
        ret=solve(pos+1,cur,sit);
        return ret;
    }
    else {
//        ret=MIN( )
        int a = dfs(idx+1, pos, bit, cur, sit);
        int nxtbit=cur|(1<<idx);

        int cost=0;
        if(bit&(1<<idx))cost++;
        if(idx !=0 && cur &(1<<(idx-1)) )cost++;

        int b =cost+ dfs(idx+1, pos, bit , nxtbit, sit+1 );
        ret=MIN(a,b);
    }
    return ret;

}


int solve(int pos, int bit, int sit){


    if(sit>N)return INF;

    if(pos==R){
        if(sit==N)return 0;
        return INF;
    }

    int &ret=dp[pos][bit][sit];

    if(ret!=-1)return ret;

    ret=dfs(0,pos,bit,0,sit);

}

int main(){

    INFILE();
    OUTFILE();

    int x,y;
    int ks,cas;
    cin>>ks;
    for(int cas=1;cas<=ks;cas++){
        cin>>R>>C>>N;
        LL ret=INF;
        if(R==1 && C==1){
            ret=0;
        }
        else if(R==1 || C==1){
            M=max(R,C);

            for(int i=0;i<(1<<M);i++ ){

                int x =__builtin_popcount(i);
                if(x==N){
                    int cur=0;
                    for(int j=1;j<M;j++){
                        if(i&(1<<j) && (i&(1<<(j-1)) ) )cur++;
                    }
                    ret=MIN(ret,cur);
                }

            }
        }
        else{
            SET(dp,-1);
            ret=solve(0,0,0);
        }

        cout<<"Case #"<<cas<<": "<<ret<<endl;
    }


//    INFILE();
//    OUTFILE();



}
