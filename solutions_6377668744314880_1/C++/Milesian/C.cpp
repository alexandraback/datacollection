#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#define ll long long
#define maxn 3020
using namespace std;
int n,T;
int X[maxn],Y[maxn];
int ans[maxn];
struct yqh
{
    ll x,y;
    int bh;
}a[maxn],b[maxn];
int n1,n2;
int lft,rgt,p1,p2,p3,p4,mid;
bool cmp(yqh a,yqh b)
{
    return a.y*b.x<b.y*a.x;
}
bool getpd(yqh a,yqh b)
{
    if(a.bh==b.bh)return a.y*b.x<a.x*b.y;
    else return a.y*b.x>a.x*b.y;
}
int main()
{
    int T;

    scanf("%d",&T);
    
    for(int ii=1;ii<=T;++ii)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d",&X[i],&Y[i]);
            ans[i]=n;
        }
        if(n==1)
        {
            ans[1]=0;
        }else
        {
            for(int i=1;i<=n;++i)
            {
                n1=0;
                n2=0;
                for(int j=1;j<=n;++j)
                {
                    if(i==j)continue;
                    if(X[j]>X[i]||((X[j]==X[i])&&(Y[j]>Y[i])))
                    {
                        ++n1;
                        a[n1].x=X[j]-X[i];
                        a[n1].y=Y[j]-Y[i];
                        a[n1].bh=0;
                    }else
                    {
                        ++n2;
                        b[n2].x=X[j]-X[i];
                        b[n2].y=Y[j]-Y[i];
                        b[n2].bh=1;
                    }
                }
                sort(a+1,a+1+n1,cmp);
                sort(b+1,b+1+n2,cmp);
                
                
                /*    printf("%d %d\n",n1,n2);
                 for(int j=1;j<=n1;++j)
                 {
                	cout<<a[j].x<<" "<<a[j].y<<endl;
                 }
                 for(int j=1;j<=n2;++j)
                 {
                	cout<<b[j].x<<" "<<b[j].y<<endl;
                 }
                 printf("\n");*/
                for(int j=1;j<=n1;++j)
                {
                    lft=1;rgt=n1;
                    p1=0;
                    while(lft<=rgt)
                    {
                        int mid=(lft+rgt)>>1;
                        if(getpd(a[mid],a[j]))
                        {
                            p1=mid;
                            lft=mid+1;
                        }else rgt=mid-1;
                    }
                    
                    lft=1;rgt=n1;
                    p2=n1+1;
                    while(lft<=rgt)
                    {
                        int mid=(lft+rgt)>>1;
                        if(getpd(a[j],a[mid]))
                        {
                            p2=mid;
                            rgt=mid-1;
                        }else lft=mid+1;
                    }
                    
                    lft=1;rgt=n2;
                    p3=0;
                    while(lft<=rgt)
                    {
                        int mid=(lft+rgt)>>1;
                        if(getpd(b[mid],a[j]))
                        {
                            p3=mid;
                            lft=mid+1;
                        }else rgt=mid-1;
                    }
                    
                    lft=1;rgt=n2;
                    p4=n2+1;
                    while(lft<=rgt)
                    {
                        int mid=(lft+rgt)>>1;
                        if(getpd(a[j],b[mid]))
                        {
                            p4=mid;
                            rgt=mid-1;
                        }else lft=mid+1;
                    }
                    
                    p2=n1+1-p2;
                    p4=n2+1-p4;
                    
                    ans[i]=min(ans[i],min(p1+p4,p2+p3));
                    //    printf("%d %d %d %d\n",p1,p2,p3,p4);
                }
                
                for(int j=1;j<=n2;++j)
                {
                    lft=1;rgt=n1;
                    p1=0;
                    while(lft<=rgt)
                    {
                        int mid=(lft+rgt)>>1;
                        if(getpd(a[mid],b[j]))
                        {
                            p1=mid;
                            lft=mid+1;
                        }else rgt=mid-1;
                    }
                    
                    lft=1;rgt=n1;
                    p2=n1+1;
                    while(lft<=rgt)
                    {
                        int mid=(lft+rgt)>>1;
                        if(getpd(b[j],a[mid]))
                        {
                            p2=mid;
                            rgt=mid-1;
                        }else lft=mid+1;
                    }
                    
                    lft=1;rgt=n2;
                    p3=0;
                    while(lft<=rgt)
                    {
                        int mid=(lft+rgt)>>1;
                        if(getpd(b[mid],b[j]))
                        {
                            p3=mid;
                            lft=mid+1;
                        }else rgt=mid-1;
                    }
                    
                    lft=1;rgt=n2;
                    p4=n2+1;
                    while(lft<=rgt)
                    {
                        int mid=(lft+rgt)>>1;
                        if(getpd(b[j],b[mid]))
                        {
                            p4=mid;
                            rgt=mid-1;
                        }else lft=mid+1;
                    }
                    
                    p2=n1+1-p2;
                    p4=n2+1-p4;
                    
                    ans[i]=min(ans[i],min(p1+p4,p2+p3));
                    
                    //    printf("%d %d %d %d\n",p1,p2,p3,p4);
                }
                //    printf("\n");
            }
        }
        printf("Case #%d:\n",ii);
        for(int i=1;i<=n;++i)
        {
            printf("%d\n",ans[i]);
        }
    }
    
    return 0;
}
