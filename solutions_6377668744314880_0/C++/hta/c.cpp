#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <vector>
#include <ctime>
#include <set>
#include <bitset>
#include <deque>
#include <fstream>
#include <stack>
#include <map>
#include <utility>
#include <cassert>
#include <string>
#include <iterator>
#include <cctype>
using namespace std;
typedef long long LL;
double getd()
{
    double d=0,d2=0,d3=1; char ch; bool flag=0;
    while(!isdigit(ch=getchar()))if(ch=='-')break;
    if(ch=='-')flag=true;else d=ch-48;
    while(isdigit(ch=getchar()))d=d*10+ch-48;
    if(ch=='.')
    {
        while(isdigit(ch=getchar()))d2=d2*10+ch-48,d3=d3*0.1;
        d+=d3*d2;
    }
    if(flag)return -d;else return d;
}
int get()
{
    int f=0,v=0;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')break;
    if(ch=='-')f=1;else v=ch-48;
    while(isdigit(ch=getchar()))v=v*10+ch-48;
    if(f==1)return -v;else return v;
}
typedef long long LL;
struct Tpoint
{
    LL x,y;
    Tpoint(){}
    Tpoint(LL _x,LL _y){x=_x,y=_y;}
}a[30000];
int n;
Tpoint operator +(Tpoint a,Tpoint b){return Tpoint(a.x+b.x,a.y+b.y);}
Tpoint operator -(Tpoint a,Tpoint b){return Tpoint(a.x-b.x,a.y-b.y);}
LL operator *(Tpoint a,Tpoint b){return a.x*b.y-a.y*b.x;}
int main()
{
	freopen("Cs.in","r",stdin);
	freopen("Cs.out","w",stdout);
	int T=get();
	for(int _=1;_<=T;_++)
	{
		n=get();
		printf("Case #%d:\n",_);
		for(int i=1;i<=n;i++)a[i].x=get(),a[i].y=get();
		for(int i=1;i<=n;i++)
		{
			int ans=n;
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				for(int l=1;l<=n;l++)
				{
					if(l==i||l==j)continue;
					int a1=0,a2=0;
					for(int k=1;k<=n;k++)
					{
						LL tp1=(a[j]-a[i])*(a[k]-a[i]);
						LL tp2=(a[l]-a[i])*(a[k]-a[i]);
						if(tp1<0||tp1<0)a1++;
						if(tp2>0||tp2)a2++;
					}
					ans=min(ans,min(a1,a2));
				}
				
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
