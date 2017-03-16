#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",cas++);
		int b,n;
		scanf("%d%d",&b,&n);
		vector<int> m(b);
		for(int i=0;i<b;++i)
			scanf("%d",&m[i]);
		long long lo=1,hi=1000000000000000LL,res=-1;
		while(lo<=hi)
		{
			long long mid=(lo+hi)/2LL;
			long long cnt=0;
			for(int i=0;i<b;++i)
				cnt+=(mid+m[i]-1)/m[i];
			if(cnt<n) lo=mid+1;
			else res=mid,hi=mid-1;
		}
		assert(res!=-1);
		int answer=-1;
		long long cnt=0;
		for(int i=0;i<b;++i)
			cnt+=(res-1+m[i]-1)/m[i];
		for(int i=0;i<b;++i)
			if((res+m[i]-1)/m[i] != (res-1+m[i]-1)/m[i])
			{
				++cnt;
				if(cnt==n)
				{
					answer=i+1;
					break;
				}
			}
		printf("%d\n",answer);
	}
    return 0;
}