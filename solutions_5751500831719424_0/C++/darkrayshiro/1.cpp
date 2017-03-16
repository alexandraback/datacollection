#include<bits/stdc++.h>
using namespace std;
//cout<<"Case #"<<i<<": ";
int main()
{
	int t;
	cin>>t;
	for(int ii=1;ii<=t;ii++)
	{
		int n;
		cin>>n;
		vector<std::string> s(n);
		for(int j=0;j<n;j++)
		{
			cin>>s[j];
		}
		vector< vector<std::pair<int,char> > > A(101);
		for(int i=0;i<n;i++)
		{
			int count=1;
			for(int j=0;j<s[i].length()-1;j++)
			{
				if(s[i][j]==s[i][j+1])
				{
					count++;
				}
				else{
					A[i].push_back(make_pair(count,s[i][j] ));
					count=1;
				}
			}
			A[i].push_back(make_pair(count,s[i][s[i].length()-1] ));			
		}
		bool check=false;
		for(int i=0;i<n-1;i++)
		{
			if(A[i].size()!=A[i+1].size())
			{
				check=true;
			}
		}
		int ans=0;
		bool xx=false;
		if(!check)
		{
			for(int j=0;j<A[0].size();j++)
			{
				if(!xx)
				{
				int min,max;
				min=A[0][j].first;
				max=min;
				for(int i=1;i<n;i++)
				{
					if(A[i][j].second!=A[i-1][j].second)
					{
						xx=true;
					}
					if(A[i][j].first>max)
					{
						max=A[i][j].first;
					}
					if(A[i][j].first<min)
					{
						min=A[i][j].first>max;
					}
				}
				if(!xx)
				{
					int minn=1000000;

					for(int xt=min;xt<=max;xt++)
					{
						int pp=0;
						for(int i=0;i<n;i++)
						{
						pp+=abs(A[i][j].first-xt);
						}
						if(pp<minn)
						{
							minn=pp;
						}
					}
					ans+=minn;
				}
				}
			}
		}
		if(check||xx)
		{
			cout<<"Case #"<<ii<<": "<<"Fegla Won"<<endl;
		}
		else{
			cout<<"Case #"<<ii<<": "<<ans<<endl;
		}
	}
	return 0;
}
