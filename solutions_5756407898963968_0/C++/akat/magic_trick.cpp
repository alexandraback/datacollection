#include<iostream>
using namespace std;
void solve()
{
	int a1,a2,i,j,o[20],a,br2=0,k;
	for(i=0;i<20;i++)
		o[i]=0;
	cin>>a1;
	for(i=1;i<5;i++)
		for(j=1;j<5;j++)
		{
			cin>>a;
			if(i==a1)o[a]++;
		}
	cin>>a2;
	for(i=1;i<5;i++)
		for(j=1;j<5;j++)
		{
			cin>>a;
			if(i==a2)o[a]++;
		}
	for(i=0;i<20;i++)
	{
		if(o[i]==2)
		{
			k=i;
			br2++;
		}
	}
	if(br2==1)cout<<k<<endl;
	else if(br2>1)cout<<"Bad magician!"<<endl;
	else cout<<"Volunteer cheated!"<<endl;
}
int main()
{
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}
}
