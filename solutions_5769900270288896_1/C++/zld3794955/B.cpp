#include<bits/stdc++.h>
using namespace std;
const int S=10010,x_[4]={0,1,0,-1},y_[4]={1,0,-1,0};
int n,r,c;
vector<int> a[S];
void init()
{
	cin>>r>>c>>n;
	for(int i=0;i<S;++i)
		a[i].clear();
	for(int i=0;i<=r+1;++i)
		a[i].resize(c+10,0);
}
int work(int mod)
{
	int x=n;
	for(int i=1;i<=r;++i)
		for(int j=1;j<=c;++j)
			if((i+j)%2==mod)
				a[i][j]=1,--x;
			else
				a[i][j]=0;
	if(x<0)
		return 0;
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=1;i<=r;++i)
		for(int j=1;j<=c;++j)
			if(!a[i][j])
			{
				int s=0;
				for(int k=0;k<4;++k)
					s+=a[i+x_[k]][j+y_[k]];
				q.push(s);
			}
	int sum=0;
	while(x--)
	{
		sum+=q.top();
		q.pop();
	}
	return sum;
}
int main()
{	
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T;
	cin>>T;
	for(int testcase=1;testcase<=T;++testcase)
	{
		init();
		cout<<"Case #"<<testcase<<": "<<min(work(0),work(1))<<endl;
	}
	return 0;
}
