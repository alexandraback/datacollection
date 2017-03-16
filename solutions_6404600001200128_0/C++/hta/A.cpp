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
int n,a[100000];
int main()
{
	freopen("As.in","r",stdin);
	freopen("As.out","w",stdout);
	int T=get();
	for(int _=1;_<=T;_++)
	{
		n=get();
		for(int i=1;i<=n;i++)a[i]=get();
		int a1=0,a2=0,r=0;
		for(int i=2;i<=n;i++)
		{
			if(a[i]<a[i-1])a1+=a[i-1]-a[i];
			r=max(r,a[i-1]-a[i]);
		}
		for(int i=1;i<n;i++)a2+=min(r,a[i]);
		printf("Case #%d: %d %d\n",_,a1,a2);
	}
	return 0;
}
