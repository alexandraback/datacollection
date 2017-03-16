#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <set>

using namespace std;


int main()
{
    int n=4,T,a[6][6],b[6],x,y,count,ans,cased=0;
    freopen("a.txt","r",stdin);
    freopen("b.txt","w",stdout);
    cin>>T;
    while(T--)
    {
        count=0;
        cin>>x;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                cin>>a[i][j];
        for(int i=1; i<=n; i++)b[i]=a[x][i];
        cin>>y;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                cin>>a[i][j];
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
              //  cout<<b[i]<<" "<<a[y][j]<<endl;
                if(b[i]==a[y][j])
                {
                    count++;
                    ans=b[i];

                }
            }
        if(count==1)printf("Case #%d: %d\n",++cased,ans);
        else if(count>1)printf("Case #%d: Bad magician!\n",++cased);
        else printf("Case #%d: Volunteer cheated!\n",++cased);

    }
}
