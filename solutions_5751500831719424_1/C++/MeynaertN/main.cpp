#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string test();

int main()
{
	int t=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cout<<"Case #"<<i+1<<": "<<test()<<'\n';
	}
	cout<<flush;
}

string test()
{
	int c=0;
	cin>>c;
	vector<string> words;
	for(int i=0;i<c;i++)
	{
		string t;
		cin>>t;
		words.push_back(t);
	}
	int count=0;
	vector<int> index(c,0);
	while(index[0]<words[0].size())
	{
		vector<int> result(c,0);
		char current=words[0][index[0]];
		for(int i=0;i<c;i++)
		{
			for(int n=0;;n++)
			{
				if(index[i]>=words[i].size()||words[i][index[i]]!=current)
				{
					if(n==0)
					{
						return "Fegla Won";
					}
					result[i]=n;
					break;
				}
				index[i]++;
			}
		}
		sort(result.begin(),result.end());
		int v=result[(result.size()-1)/2];
		for(int i=0;i<result.size();i++)
		{
			count+=abs(result[i]-v);
		}
	}
	for(int i=0;i<c;i++)
	{
		if(index[i]<words[i].size())
		{
			return "Fegla Won";
		}
	}
	ostringstream out;
	out<<count;
	return out.str();
}
