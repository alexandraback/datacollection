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
int n,m;
LL a[10000];
LL calc(LL b)
{
	LL res=0;
	for(int i=1;i<=m;i++)res+=(b-1)/a[i]+1;
	return res;
}
int main()
{
	freopen("Bs.in","r",stdin);
	freopen("Bs.out","w",stdout);
	int T=get();
	for(int _=1;_<=T;_++)
	{
		m=get(),n=get();
		for(int i=1;i<=m;i++)a[i]=get();
		LL l=1,r=LL(1e16);
		while(l<r)
		{
			LL mid=(l+r)/2;
			if(calc(mid)>=n)r=mid;else l=mid+1;
		}
		LL tp=calc(l-1);
		for(int i=1;i<=m;i++)
			if((l-1)%a[i]==0)
			{
				tp++;
				if(tp==n)
				{
					printf("Case #%d: %d\n",_,i);
					break;
				}
			}
	}
	return 0;
}
