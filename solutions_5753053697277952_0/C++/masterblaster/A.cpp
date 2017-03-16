#include<fstream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<deque>
#include<iostream>
#include<map>
#include<set>
using namespace std;

bool comp(const pair<int,int>& a, const pair<int,int>& b)
{
	return a.second < b.second;
}

vector<pair<int,int> > solve(vector<pair<int,int> >& v)
{
	int sum = 0;
	int len = v.size();
	
	for(int i = 0;i < len;++i)
	{
		sum += v[i].second;
	}
	sort(v.begin(), v.end(), comp);
	vector<pair<int,int> > sol;
	
	while(sum > 0)
	{
		pair<int,int> p;
		if(v[len - 1].second + v[len - 2].second == sum)
		{
			p.first = v[len - 1].first;
			p.second = v[len - 2].first;
			--v[len - 1].second;
			--v[len - 2].second;
			sum -= 2;
		}
		else
		{
			p.first = v[len - 1].first;
			p.second = -1;
			--v[len - 1].second;
			sum -= 1;
		}
		sol.push_back(p);
		sort(v.begin(), v.end(), comp);
	}
	
	return sol;
}

int main()
{
	ifstream in("A.in");
	ofstream out("A.out");
	
	int t;
	in >> t;
	
	for(int i = 0;i < t;++i)
	{
		int N;
		in >> N;
		
		vector<pair<int,int> > v;
		
		for(int j = 0;j < N;++j)
		{
			int nr;
			in >> nr;
			v.push_back(make_pair(j, nr));
		}
		vector<pair<int,int> > sol;
		sol = solve(v);
		
		out<<"Case #"<<i + 1<<": ";
		int len = sol.size();
		
		for(int j = 0;j < len;++j)
		{
			char c = 'A' + sol[j].first;
			out<<c;
			if(sol[j].second != -1)
			{
				c = 'A' + sol[j].second;
				out<<c;
			}
			out<<" ";
		}
		out<<"\n";
	}
	in.close();
	out.close();
}
