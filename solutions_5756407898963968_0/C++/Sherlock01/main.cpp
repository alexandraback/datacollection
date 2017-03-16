#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <map>

using namespace std;

const double eps = 1e-9;
const int N=105;
int a[N][N],b[N][N];
int main()
{
    //freopen("data.txt","r",stdin);
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;
    cin>>T;
    for(int ca=1;ca<=T;++ca)
    {
        printf("Case #%d: ",ca);
        int l,r;
        cin>>l;
        for(int i=1;i<=4;++i)
        for(int j=1;j<=4;++j)
        cin>>a[i][j];
        cin>>r;
        for(int i=1;i<=4;++i)
        for(int j=1;j<=4;++j)
        cin>>b[i][j];
        int num=0;
        int tmp=0;
        for(int i=1;i<=4;++i)
        for(int j=1;j<=4;++j)
        if(a[l][i]==b[r][j])
        {
            tmp=a[l][i];
            ++num;
        }

        if(num==1) printf("%d\n",tmp);
        else if(num==0)printf("Volunteer cheated!\n");
        else printf("Bad magician!\n");
    }
    return 0;
}
