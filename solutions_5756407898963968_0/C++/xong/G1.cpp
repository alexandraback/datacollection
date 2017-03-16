#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
//	freopen("gg.txt","r",stdin);
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a-ans.txt","w",stdout);
	int tt,temp,rowid,ans;
	bool flag[17];
	cin>>tt;
	for (int ci=1;ci<=tt;ci++)
	{
		memset(flag,0,sizeof(flag));
		int cnt=0;
		cin>>rowid;
		for (int i=1;i^5;i++)
			for (int j=1;j^5;j++)
			{
				cin>>temp;
				if (i==rowid)
					flag[temp]=true;
			}
		cin>>rowid;
		for (int i=1;i^5;i++)
			for (int j=1;j^5;j++)
			{
				cin>>temp;
				if (i==rowid&&flag[temp])
				{
					cnt++;
					ans=temp;
				}
			}
		cout<<"Case #"<<ci<<": "; 
		if (cnt==1)
			cout<<ans<<endl;
		else if (!cnt)
			cout<<"Volunteer cheated!"<<endl;
		else
			cout<<"Bad magician!"<<endl;
	}
	return 0;
}
