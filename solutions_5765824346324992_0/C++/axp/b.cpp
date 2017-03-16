/* ***********************************************
Author        :axp
Created Time  :2015/4/18 9:28:18
File Name     :b.cpp
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef pair<int,int> pii;
const int maxn = 10;
int T,n,b;
int arr[maxn];
int ans;
int t,m,k;
int sum;
pii p;
int to;

int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}

int lcm(int x,int y)
{
	return x*y/gcd(x,y);
}

struct cmp
{
	bool operator ()(pii x,pii y)
	{
		return x>y;
	}
};

priority_queue <pair<int,int>,vector<pair<int,int> >,cmp > q;

int main()
{
    freopen("2.in","r",stdin);
    freopen("out.txt","w",stdout);
	cin>>T;
	for(int kase=1;kase<=T;kase++)
	{
		cin>>b>>n;

		for(int i=0;i<b;i++)
		{
			cin>>arr[i];
			if(i)
				sum=lcm(sum,arr[i]);
			else
				sum=arr[i];
		}

		to=0;
		for(int i=0;i<b;i++)
			to+=sum/arr[i];

		n%=to;
		//cout<<n<<endl;

		if(n<=b)
		{
			if(n==0)
			{
				for(int i=1;i<b;i++)
					if(arr[i]<=arr[n])
						n=i;
				n++;
			}
			printf("Case #%d: %d\n",kase,n);
			continue;
		}

		while ( !q.empty() )  q.pop(); 

		for(int i=0;i<b;i++)
		{
			q.push(make_pair(arr[i],i));
			p=q.top();
			//cout<<p.first<<' '<<p.second<<endl;
		}
		
		for(int i=b;i<n-1;i++)
		{
			p=q.top();

			//cout<<p.first<<' '<<p.second<<endl;

			q.pop();
			p.first+=arr[p.second];
			q.push(p);
		}

		ans=q.top().second+1;

		printf("Case #%d: %d\n",kase,ans);
		
	}
    return 0;
}
