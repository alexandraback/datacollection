#include <bits/stdc++.h>
using namespace std;
//#include <conio.h>
int cnt[26];
int valid(int n)
{
	int ret=0;
	for(int i=0;i<n;i++)
		ret+=cnt[i];
		return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t;
	cin>>t;
	for(int i1=1;i1<=t;i1++)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>cnt[i];
		cout<<"Case #"<<i1<<": ";
		//system("pause");
		while(valid(n))
		{
			int m1=0,m2=0;
			m1=0;m2=1;
			if(cnt[m1]<cnt[m2])
				swap(m1,m2);
		
//			getch();
			//system("pause");
			for(int i=2;i<n;i++)
			{
				if(cnt[i]>cnt[m1])
				{
					m2=m1;
					m1=i;
					continue;
				}
				else if(cnt[i]>cnt[m2])
				{
					m2=i;
				}
			}
	//cout<<cnt[m1]<<" "<<cnt[m2]<<endl;
			if(cnt[m1]>=cnt[m2]+2)
			{
				char ch=(char)('A'+m1);
				cout<<ch<<ch<<" ";
				cnt[m1]-=2;	
				continue;
			}
			else if(cnt[m1]>=cnt[m2]+1)
			{
			char ch=(char)('A'+m1);
				cout<<ch<<" ";
				cnt[m1]-=1;
				continue;		
			}
			else if(cnt[m1]==cnt[m2]&&(cnt[m1]!=1||valid(n)==2))
			{
				char ch='A'+m1,d='A'+m2;
				cout<<ch<<d<<" ";
				cnt[m1]--;
				cnt[m2]--;
				continue;
			}
			else if(cnt[m1]==cnt[m2]&&cnt[m1]==1&&valid(n)>2)
			{
				char ch=(char)('A'+m1);
				cout<<ch<<" ";
				cnt[m1]-=1;
				continue;	
			}
		}
		cout<<endl;
	}

	return 0;
}