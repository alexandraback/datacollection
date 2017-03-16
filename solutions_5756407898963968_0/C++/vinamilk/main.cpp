#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <sstream>

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long

using namespace std;

int x,y;int a[6][6],b[6][6];
set<int> sx,sy,kq;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("vd.out","w",stdout);
    int t,i,j,it;
    scanf("%d",&t);
    for(it=1;it<=t;++it)
    {
        scanf("%d",&x);
        for(i=1;i<=4;++i)
        {
            for(j=1;j<=4;++j) scanf("%d",&a[i][j]);
        }
        scanf("%d",&y);
        for(i=1;i<=4;++i)
        {
            for(j=1;j<=4;++j) scanf("%d",&b[i][j]);
        }
        sx.clear();sy.clear();kq.clear();
        for(j=1;j<=4;++j) sx.insert(a[x][j]);
        for(j=1;j<=4;++j) sy.insert(b[y][j]);
        for(i=1;i<=16;++i) if (sx.count(i) && sy.count(i)) kq.insert(i);
        if (kq.size()==0) printf("Case #%d: Volunteer cheated!\n",it);
        else
        {
            if (kq.size()>1) printf("Case #%d: Bad magician!\n",it);
            else printf("Case #%d: %d\n",it,*(kq.begin()));
        }
    }
}
