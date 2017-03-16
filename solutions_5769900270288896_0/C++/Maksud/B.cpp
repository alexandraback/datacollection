//#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<utility>
#include<functional>
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <assert.h>
//#include<unordered_set>
//#include<unordered_map>



#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define deb(a)      cerr<<"#"<<__LINE__<<" -> "<<#a<<"  "<<a<<endl;
#define popcount(a) (__builtin_popcountll(a))
#define SZ(a)       ((int)a.size())
#define fs           first
#define sc           second
#define pb          push_back
#define ll          long long
#define ld          long double
#define MP          make_pair
#define SS          stringstream
#define VS          vector<string>
#define VI          vector<int>
#define CON(a,b)  ((a).find(b)!=(a).end())
#define mem(a,b)    memset(a,b,sizeof(a))
#define memc(a,b)   memcpy(a,b,sizeof(b))
#define accu(a,b,c) accumulate((a),(b),(c))
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fii(a,b)    for(i=a;i<b;i++)
#define fij(a,b)    for(j=a;j<b;j++)
#define fik(a,b)    for(k=a;k<b;k++)
#define fil(a,b)    for(l=a;l<b;l++)
#define ri(i,a)     for(i=0;i<a;i++)
#define rii(a)      for(i=0;i<a;i++)
#define rij(a)      for(j=0;j<a;j++)
#define rik(a)      for(k=0;k<a;k++)
#define ril(a)      for(l=0;l<a;l++)
#define fore(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define ERR         (1e-7)
#define EQ(a,b)     (fabs((a)-(b))<ERR)
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
#define p2(a)       (1<<a)
#define EX(msk,a)   (msk&p2(a))


//bool EX(int msk,int x)
//{
//    if(msk&p2(x))   return true;
//    return false;
//}



#define debug(a...)          {cout<<" #--> ";dbg,a; cout<<endl;}

struct debugger
{
    ///Collected from rudradevbasak
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;


const double pi=acos(-1.0);
const double eps=1e-7;

template<class TT>TT sqr(TT a){return a*a;}
template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
typedef pair<int,int> pii;



int get()
{
    int r,n,c;

    scanf("%d%d%d",&r,&c,&n);
    int N = r*c;
    if(n==0)    return 0;
    int ans=r*c*4,cur,u,l;

    for(int msk=0;msk<p2(N);msk++)
    {
        if(__builtin_popcount(msk)!=n)    continue;
//        debug(msk,__builtin_popcount(msk));
        cur=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
//                debug(i,j,r);
//                cout<<i*r+j;
//                cout<<EX(msk,i*r+j);
                if(!EX(msk,i*c+j))  continue;
                if(i)
                {
                    u =(i-1)*c+j;
                    if(EX(msk,u))   cur++;
                }
                if(j)
                {
                    l=i*c+j-1;
                    if(EX(msk,l))   cur++;
                }
            }
//            cout<<endl;
        }

//        deb(cur);
        ans=min(ans,cur);
    }
//    if(ans==0)  debug(r,c,n);
    return ans;
}


int main()
{
//    freopen("in.in","r",stdin);
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out.in","w",stdout);


    int i,j,k,tks=1,ks=1,n;

    scanf("%d",&tks);
    while(tks--){

        n = get();

        printf("Case #%d: %d\n",ks++,n);
    }

    return 0;
}




