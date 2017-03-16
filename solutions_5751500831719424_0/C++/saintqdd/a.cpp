#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

string modify(string a)
{
	string ret = "";
	ret += a[0];
	for(int i=1;i<a.size();i++)
	{
		if(a[i]!=a[i-1])
			ret += a[i];
	}
	return ret;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,N;
	vector<string> data;
	set<string> moda;
	cin >> T;
	for(int cas=1;cas<=T;cas++)
	{
		cin >> N;
		data.clear();
		for(int i=0;i<N;i++)
		{
			string t;
			cin >>  t;
			data.push_back(t);
		}
		vector<int> ap[110];
		moda.clear();
		for(int i=0;i<N;i++)
		{
			moda.insert(modify(data[i]));
			for(int j=0;j<101;j++)
			{
				ap[i].push_back(0);
			}
			int cnt = 0;
			for(int j=0;j<data[i].size();j++)
			{
				if(j==0)
					ap[i][cnt]++;
				else if(data[i][j]==data[i][j-1])
					ap[i][cnt]++;
				else
				{
					cnt++;
					ap[i][cnt]++;
				}
			}
		}
		bool ok = moda.size()==1;
		if(ok)
		{
			// 从每个维度上，找一个最近的点
			int ret = 0;
			for(int i=0;i<101;i++)
			{
				int Mdis = 1000000;
				int vdis = 0;
				for(int mid = 0;mid <= 100; mid++)
				{
					int alldis = 0;
					for(int j=0;j<N;j++)
					{
						alldis += abs( mid - ap[j][i] );
					}
					if(alldis<Mdis)
					{
						Mdis = alldis;
						vdis = mid;
					}
				}
				ret += Mdis;
			}
			printf("Case #%d: %d\n",cas,ret);
		}
		else
		{
			printf("Case #%d: Fegla Won\n",cas);
		}
	}
	return 0;
}
