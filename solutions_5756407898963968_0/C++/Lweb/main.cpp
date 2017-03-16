#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;
typedef long long LL;
int a[5][5],b[5][5];

int main()
{
    int T;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca)
    {
        int fi,se;
        scanf("%d",&fi);
        --fi;
        for(int i=0;i<4;++i) for(int j=0;j<4;++j) scanf("%d",a[i]+j);
        scanf("%d",&se);
        --se;
        for(int i=0;i<4;++i) for(int j=0;j<4;++j) scanf("%d",b[i]+j);
        int cnt=0,y;
        for(int i=0;i<4;++i) for(int j=0;j<4;++j) if(a[fi][i]==b[se][j])
        {
            ++cnt;
            y=a[fi][i];
        }
        printf("Case #%d: ",ca);
        if(!cnt) puts("Volunteer cheated!");
        else if(cnt>1) puts("Bad magician!");
        else printf("%d\n",y);
    }
    return 0;
}
