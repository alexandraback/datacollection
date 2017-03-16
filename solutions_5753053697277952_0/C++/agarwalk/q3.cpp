#include<bits/stdc++.h>

#define pb(x) push_back(x);
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);
#define inf 1<<30
#define ll long long   
using namespace std;

typedef pair<int,int> pii;

int abso(int a,int b)
{
	if(a<b)
		return b-a;
	else
		return a-b;
}

double power(double x,ll e)
{
	double temp;
	if(e==0)
		return 1;
	if(e%2==0)
	{
		temp=power(x,e/2);
		return temp*temp;
	}
	else
	{
		temp=power(x,e/2);
		return temp*temp*x;
	}
}

bool cmp(pii x,pii y)
{
	return x.first>y.first;
}

int main()
{
	int n,t,a,b,w,ans,cnt;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		int tot=0;
		pii arr[30];
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i].first;
			arr[i].second=i;	
			tot+=arr[i].first;
		}
		int temp = 0;
		cout<<"Case #"<<k<<":";
		char ch1,ch2;
		while(temp<tot)
		{
			sort(arr+1,arr+n+1,cmp);
			if(arr[1].first==arr[2].first&&arr[3].first!=arr[2].first)
			{
				ch1 = 'A'+arr[1].second-1;
				ch2 = 'A'+arr[2].second-1;
				cout<<" "<<ch1<<ch2;
				arr[1].first--;
				arr[2].first--;
				temp+=2;
			}
			else
			{
				ch1 = 'A'+arr[1].second-1;
				cout<<" "<<ch1;
				arr[1].first--;
				temp+=1;
			}
		}
		cout<<endl;
	}
	return 0;
}
