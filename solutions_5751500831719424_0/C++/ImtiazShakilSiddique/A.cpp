#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> paii;
typedef pair< ll, ll > pall;


#define PI (2.0*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define popc(i) (__builtin_popcountll(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 100005

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}
ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

vector<string>v;
vector<int>indx;

string reformat(string str)
{
    string tmp="";
    for(int i=0;i<SZ(str);i++)
    {
        if(i && str[i]==str[i-1] ) ;
        else tmp+=str[i];
    }
    return tmp;
}

int getCost(char ch)
{
    vector<int>len;
    for(int i=0;i<SZ(v);i++)
    {
        int l=0,j;
        for(j= indx[i] ;j<SZ(v[i]);j++)
        {
            if(v[i][j]==ch) l++;
            else break;
        }
        indx[i]=j;
        len.pb(l);
    }

    int best=oo;
    for(int i=1;i<=100;i++)
    {
        int nowBest=0;
        for(int j=0;j<SZ(len);j++)
        {
            nowBest+=Abs(len[j]-i);
        }
        best=min(best,nowBest);
    }
    return best;
}
int n;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    string str,formattedString;
    int cas,loop=0;
    scanf("%d",&cas);
    while(cas--)
    {
        v.clear();indx.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            cin>>str;
            v.pb(str);
        }
        formattedString=reformat(v[0]);
        int ok=1;
        for(int i=1;i<SZ(v);i++)
        {
            if(formattedString!=reformat(v[i])) {ok=0;break;}
        }
        if(!ok) {printf("Case #%d: Fegla Won\n",++loop);continue;}

        for(int i=0;i<SZ(v);i++) indx.pb(0);
        int cost=0;
        for(int i=0;i<SZ(formattedString);i++)
        {
            cost+=getCost(formattedString[i]);
        }
        printf("Case #%d: %d\n",++loop,cost);

    }
    return 0;
}
