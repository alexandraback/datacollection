#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
#define   sqr(a)         ((a)*(a))
#define   rep(i,a,b)  for(int i=(a);i<(int)(b);i++)
#define   per(i,a,b)  for(int i=((a)-1);i>=(int)(b);i--)
#define   PER(i,n)     per(i,n,0)
#define   REP(i,n)     rep(i,0,n)
#define   FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define   clr(a)      memset((a),0,sizeof (a))
#define   SZ(a)         ((int)((a).size()))
#define   CLEAR(a, v)    memset((a), (v), sizeof(a))
#define   ALL(v)          (v).begin(), (v).end()
#define   mabs(a)       ((a)>0?(a):(-(a)))
#define   PB push_back
#define   FI     first
#define   SE     second
#define   MP     make_pair
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
typedef long long int64;
#define   inf         1000000001
#define  MAXN     120
#define  eps      1e-6
FILE *fin;
FILE *fout;
int N;
char cs[MAXN][MAXN];
string s[MAXN];
int pos[MAXN],shu[MAXN];
bool f;
int doit(char c)
{
    clr(shu);
    REP(i,N)
    {
        int j=pos[i];
        while(j<s[i].length()&&s[i][j]==c) j++;
        if(j==pos[i])
        {
            f=true; return inf;
        }
        shu[i]=j-pos[i];
        pos[i]=j;
    }
    int ret=inf;
    rep(i,1,101)
    {
        int tret=0;
        REP(j,N) tret+=abs(shu[j]-i);
        checkmin(ret,tret);
    }
    return ret;
}
int main()
{
   	fin=fopen("A-large.in","r");
	fout=fopen("output.txt","w");
	int T;
	fscanf(fin,"%d",&T);
    int rounds;
	for (rounds=1;rounds<=T;rounds++)
	{
        fscanf(fin,"%d",&N);
        REP(i,N)fscanf(fin,"%s",cs[i]);
        REP(i,N) s[i]=string(cs[i]);
        CLEAR(pos,0);
        char pre=-1;f=false;
        int ret=0;
        REP(i,s[0].length())
        {
            if(s[0][i]==pre) continue;
            else
            {
                pre=s[0][i];
                ret+=doit(pre);
                if(f) break;
            }
        }
        REP(i,N) if(pos[i]!=s[i].length())
        {
            f=true;break;
        }
        if (f)
        {
            printf("Case #%d: Fegla Won\n",rounds);
            fprintf(fout,"Case #%d: Fegla Won\n",rounds);
        }
        else
        {
            printf("Case #%d: %d\n",rounds,ret);
            fprintf(fout,"Case #%d: %d\n",rounds,ret);

        }
    }
}
