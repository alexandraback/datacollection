#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
using namespace std;
int T,n,m[1005],ans,i,MAX,_;
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (i=1; i<=n; i++) scanf("%d",&m[i]); ans=0;
        for (i=1; i<n; i++) if (m[i]>m[i+1]) ans+=m[i]-m[i+1];
        _++; printf("Case #%d: %d ",_,ans);  MAX=ans=0;
        for (i=1; i<n; i++) if (m[i]>m[i+1]) MAX=max(MAX,m[i]-m[i+1]);
        for (i=1; i<n; i++) ans+=m[i]-max(0,m[i]-MAX);
        printf("%d\n",ans);
    }
    return 0;
}
