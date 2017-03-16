#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
struct POINT
{
    double x,y;
    int original;
};
using namespace std;
POINT a[15];
int stack[100];
POINT x_point[15];
double mul(POINT p1,POINT p2,POINT p)
{
    double temp = (p1.x-p.x)*(p2.y-p.y)-(p1.y-p.y)*(p2.x-p.x);
    return temp;
}
bool cmp(POINT p1,POINT p2)
{
 if (p1.x==p2.x)
  return p1.y<p2.y;
 else
  return p1.x<p2.x;
}
int top;
void chull(int pcount)
{
    top=2;
    stack[0]=0; stack[1]=1;
    for (int i=2;i<pcount;i++)
    {
        while (top>1 && (mul(x_point[i],x_point[stack[top-1]],x_point[stack[top-2]]) - 0) < -(1e-10))
            top--;
        stack[top++]=i;
    }
    int t=top;
    stack[top++]=pcount-2;
    for (int i=pcount-3;i>=0;i--)
    {
        while (top>1 && (mul(x_point[i],x_point[stack[top-1]],x_point[stack[top-2]]) - 0) < -(1e-10))
            top--;
        stack[top++]=i;
    }
}
int main()
{
    int n;
    int times;
    freopen("C-small.in","r",stdin);
    freopen("C-small.txt","w",stdout);
    scanf("%d\n",&times);
    memset(a,0,sizeof(a));
    for (int t = 1; t <= times; t++)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf",&a[i].x,&a[i].y);
            a[i].original = i;
        }

        memset(x_point,0,sizeof(x_point));
        int ans[15];
        for (int i = 0; i < 15 ; i++)
        {
            ans [i]  = 15;
        }
        for (int i = 7; i < 1 << n; i++)
        {
            int pcount = 0;
            int ii = i;
            for (int j = 0; j < n; j++)
            {
                if (ii & 1 == 1)
                {
                    x_point[pcount ++] = a[j];
                }
                ii = ii >> 1;
            }
            if (pcount < 3) continue;
            else
            {
                top = 0;
                memset(stack,0,sizeof(stack));
                sort(x_point,x_point+pcount,cmp);
                chull(pcount);
                for (int j= 0; j < top; j++)
                {
                    if (ans[x_point[stack[j]].original] > n-pcount)
                        ans[x_point[stack[j]].original] = n-pcount;
                }
            }
        }
        printf("Case #%d:\n",t);
        for (int i = 0; i < n; i++)
        {
            printf("%d\n",ans[i]);
        }
    }
}
