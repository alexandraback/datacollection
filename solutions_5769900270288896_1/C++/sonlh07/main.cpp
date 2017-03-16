#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#define pb push_back
#define mp make_pair
#define pp pair<int,int>
#define ppp pair<pp,pp>
#define st first
#define nd second
typedef long long ll;
using namespace std;
int R,C,N;
int a[10010][10010];
vector <pp> c;

int Cal(int x,int y)
{
    int ans = 0;
    if (a[x - 1][y] == 1) ans++;
    if (a[x][y-1] == 1) ans++;
    return ans;
}

int main()
{

   freopen("A.in","r",stdin);
   freopen("A.out","w",stdout);

    int nTest;
    cin>>nTest;
    for (int kk = 1; kk<=nTest; kk++)
    {
        int res = 0;
        c.clear();
        memset(a,0,sizeof(a));
        cin>>R>>C>>N;
        for (int i = 1; i<=R; i++)
        for (int j = 1; j<=C; j++)
             if ((i + j)% 2 == 0) c.pb(mp(i,j));
       // 4 goc
       //c.pb(mp(1,1));
       if ((C!=1) && ((1 + C)% 2 == 1)) c.pb(mp(1,C));

       if (R!=1)
       {
           if ((C!=1) && ((R + C)% 2 == 1)) c.pb(mp(R,C));
           if ((R + 1)% 2 == 1) c.pb(mp(R,1));
       }

        // hang 1
        for (int i = 2; i<C; i+=2)
            c.pb(mp(1,i));
        // hang R
        if (R!=1) {
        if (R % 2 == 0)
           for (int i =3; i<C; i+=2)
               c.pb(mp(R,i));
        else
           for (int i = 2; i<C; i+=2)
                c.pb(mp(R,i));
        }
        // cot 1
        for (int i = 2; i<R; i+=2)
            c.pb(mp(i,1));
         // cot C
        if (C!=1) {
        if (C % 2 == 0)
            for (int i =3; i<R; i+=2)
               c.pb(mp(i,C));
        else
           for (int i = 2; i<R; i+=2)
                c.pb(mp(i,C));
        }
        // final
        for (int i = 2; i<R; i++)
        for (int j = 2; j<C; j++)
        if ((i + j)% 2 == 1) c.pb(mp(i,j));
        //

        for (int i = 1; i<=N; i++)
        {
            int u = c[i - 1].st;
            int v = c[i - 1].nd;
            a[u][v] = 1;
        }
        for (int i = 1; i<=R; i++)
        for (int j = 1; j<=C; j++)
             if (a[i][j] == 1) res+=Cal(i,j);
        int res2 = 0;

        /** step 2: **/
        c.clear();
        memset(a,0,sizeof(a));
        for (int i = 1; i<=R; i++)
        for (int j = 1; j<=C; j++)
             if ((i + j)% 2 == 1) c.pb(mp(i,j));
       // 4 goc
       c.pb(mp(1,1));
       if ((C!=1) && ((1 + C)% 2 == 0)) c.pb(mp(1,C));

       if (R!=1)
       {
           if ((C!=1) && ((R + C)% 2 == 0)) c.pb(mp(R,C));
           if ((R + 1)% 2 == 0) c.pb(mp(R,1));
       }

        // hang 1
        for (int i = 3; i<C; i+=2)
            c.pb(mp(1,i));
        // hang R
        if (R!=1) {
        if (R % 2 == 0)
           for (int i =2; i<C; i+=2)
               c.pb(mp(R,i));
        else
           for (int i = 3; i<C; i+=2)
                c.pb(mp(R,i));
        }
        // cot 1
        for (int i = 3; i<R; i+=2)
            c.pb(mp(i,1));
         // cot C
        if (C!=1) {
        if (C % 2 == 0)
            for (int i =2; i<R; i+=2)
               c.pb(mp(i,C));
        else
           for (int i = 3; i<R; i+=2)
                c.pb(mp(i,C));
        }
        // final
        for (int i = 2; i<R; i++)
        for (int j = 2; j<C; j++)
        if ((i + j)% 2 == 0) c.pb(mp(i,j));
        //

        for (int i = 1; i<=N; i++)
        {
            int u = c[i - 1].st;
            int v = c[i - 1].nd;
            a[u][v] = 1;
        }
        for (int i = 1; i<=R; i++)
        for (int j = 1; j<=C; j++)
             if (a[i][j] == 1) res2+=Cal(i,j);

        cout<<"Case #"<<kk<<": "<<min(res,res2)<<"\n";
    }
    return 0;
}
