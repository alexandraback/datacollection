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
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",cas++);
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		int ans1=0,ans2=0;
		for(int i=1;i<n;++i)
		{
			if(a[i]<a[i-1]) ans1+=a[i-1]-a[i];
		}
		int max_diff=0;
		for(int i=0;i<n-1;++i)
			max_diff=max(max_diff,a[i]-a[i+1]);
		for(int i=0;i<n-1;++i)
			ans2+=min(max_diff,a[i]);
		printf("%d %d\n",ans1,ans2);
	}
    return 0;
}