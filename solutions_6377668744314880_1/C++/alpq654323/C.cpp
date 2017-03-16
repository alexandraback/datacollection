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
struct node {int x,y;} t[10005];
int cmp(node i,node j){return 1ll*i.x*j.y>1ll*i.y*j.x;}
int CMP(node i,node j){return 1ll*i.x*j.y>=1ll*i.y*j.x;}
int T,_,A[10005],B[10005],cnt,i,j,n,R,L,ans,LL;
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        _++;
        printf("Case #%d:\n",_);
        scanf("%d",&n);
        for (i=1; i<=n; i++) scanf("%d%d",&A[i],&B[i]);
        if (n==1) {printf("0\n"); continue;}
        for (i=1; i<=n; i++)
        {
            cnt=0;
            for (j=1; j<=n; j++) if (i!=j)
            {
                t[++cnt].x=A[j]-A[i];
                t[cnt].y=B[j]-B[i];
            }
            R=cnt;while (R>=1 && t[R].x<0) R--;
            for (j=1; j<=R; j++) if (t[j].x<0) {swap(t[j],t[R]); while (R>=j && t[R].x<0) R--;}
            R=cnt; while (R && t[R].x<0) R--;
            sort(t+1,t+R+1,cmp); sort(t+R+1,t+cnt+1,cmp);
            ans=453266144;
            for (j=cnt+1; j<=2*cnt; j++) t[j]=t[j-cnt];
            L=2;LL=2;
            for (j=1; j<=cnt; j++)
            {
                while (L<j+cnt && cmp(t[j],t[L])) L++; L=max(L,j+1); LL=max(LL,j+1);
                if (L==j+cnt) {ans=0; break;}
                ans=min(ans,L-j-1); while (LL<j+cnt && CMP(t[j],t[LL])) LL++; ans=min(ans,cnt-(LL-j));
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
