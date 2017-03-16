#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

string s[105];

int main()
{
	ifstream f1("A-large.in");
	ofstream f2("out.txt");
	int T;
	f1>>T;
	for(int tt=0;tt!=T;++tt)
	{
		f2<<"Case #"<<tt+1<<": ";
		int N;
		f1>>N;
		for(int i=0;i!=N;++i)
			f1>>s[i];
		vector<vector<pair<char,int> > > sum;
		for(int i=0;i!=N;++i)
		{
			char c=s[i][0];
			int num=0;
			vector<pair<char,int> > temp;
			for(int j=0;j!=s[i].size();++j)
			{
				if(s[i][j]==c)
				{
					num++;
				}
				else
				{
					temp.push_back(make_pair(c,num));
					c=s[i][j];
					num=1;
				}
			}
			temp.push_back(make_pair(c,num));
			sum.push_back(temp);
		}
		int ans=0;
		int flag=1;
		for(int i=0;i!=sum[0].size();++i)
		{
			for(int j=0;j!=N;++j)
			{
				if(i>=sum[j].size()||sum[j][i].first!=sum[0][i].first)
				{
					flag=0;
					break;
				}
			}
			if(flag==0)
				break;
			vector<int> temp;
			for(int j=0;j!=N;++j)
				temp.push_back(sum[j][i].second);
			sort(temp.begin(),temp.end());
			for(int j=0;j!=N;++j)
				ans+=abs(temp[j]-temp[(N-1)/2]);
		}
		for(int i=0;i!=N;++i)
		{
			if(sum[0].size()!=sum[i].size())
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
			f2<<ans<<endl;
		else
			f2<<"Fegla Won"<<endl;
	}
	return 1;
}