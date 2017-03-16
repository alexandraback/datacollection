#include<bits/stdc++.h>
using namespace std;
int n;
vector<char> chs[120];
vector<int> chc[120];
int cal(vector<int> &data)
{
	sort(data.begin(),data.end());
	int ans=0;
	int bb=data[data.size()/2];
	for(int i=0;i<data.size();i++)
		ans+=abs(data[i]-bb);
	return ans;
}
int solve()
{
	int t=chs[0].size();
	for(int i=1;i<n;i++)
		if(chs[i].size()!=t)
			return -1;
	for(int i=1;i<n;i++)
		for(int j=0;j<chs[i].size();j++)
			if(chs[i][j]!=chs[0][j])
				return -1;
	vector<int> data; 
	int ans=0;
	for(int i=0;i<chs[0].size();i++)
	{
		data.clear();
		data.resize(n);
		for(int j=0;j<n;j++)
		{
			data[j]=chc[j][i];
		}
		ans+=cal(data);
	}
	return ans;
}
int main()
{
	int T;
	cin>>T;
	for(int no=1;no<=T;no++)
	{
		cin>>n;
		string temp;
		for(int i=0;i<n;i++){
			chs[i].clear();
			chc[i].clear();
			cin>>temp;
			chs[i].push_back(temp[0]);
			chc[i].push_back(1);
			for(int j=1;j<temp.size();j++)
			{
				if(temp[j]==chs[i].back()){
					chc[i].back()++;
				}else{
					chs[i].push_back(temp[j]);
					chc[i].push_back(1);
				}
			}
		}
//		for(int i=0;i<n;i++){
//			for(int j=0;j<chc[i].size();j++)
//			{
//				cout<<chs[i][j]<<" "<<chc[i][j]<<",";
//			}
//			cout<<endl;
//		}
		int ans=solve();
		if(ans==-1)
			printf("Case #%d: Fegla Won\n",no);
		else
			printf("Case #%d: %d\n",no,ans);
	}
}

