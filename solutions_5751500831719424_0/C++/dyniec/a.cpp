#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string in[100];
vector<int>num[100];
int n,size;
bool valid()
{	for(int i=1;i<n;i++)if(in[i].size()!=in[i-1].size())return false;
	for(int i=1;i<n;i++)
		if(in[i]!=in[i-1])
			return false;
	return true;
}
void reduce(int i)
{
	string temp,pro=in[i];
	int act=1;
	temp.push_back(pro[0]);
	for(int j=1;j<pro.size();j++)
	{
		if(pro[j]!=pro[j-1])
		{
			temp.push_back(pro[j]);
			num[i].push_back(act);
			act=1;
		}
		else
			act++;
	}
	num[i].push_back(act);
	in[i]=temp;
	size=in[i].size();
	
}
void test()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		num[i].clear();
		in[i].clear();
	}
	for(int i=0;i<n;i++)
	{
		cin >> in[i];
		reduce(i);
	}
	if(!valid())
	{
		cout <<"Fegla Won";
		return;
	}
	int odp=0;
	for(int i=0;i<size;i++)
	{
		vector<int>temp;
		for(int j=0;j<n;j++)
		{
			temp.push_back(num[j][i]);
		}
		sort(temp.begin(),temp.end());
		int mid=temp[n/2];
		for(int j=0;j<n;j++)
		{
			odp+=abs(temp[j]-mid);
		}
	}
	cout << odp;
}
int main()
{
	int t;
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		cout << "Case #"<<i<<": ";
		test();
		cout << endl;
	}
	return 0;
}
