#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long LINT;

void main()
{
	int t;
	cin>>t;
	for(int ii=0; ii<t; ii++)
	{
		int n;
		cin>>n;
		vector<vector<int> > vvn;
		vector<vector<char> > vvc;

		bool res=true;
			string mb;
		for(int i=0; i<n; i++)
		{
			string s;
			cin>>s;


			string mm;
			vector<int> vn;

			mm+=s[0];
			vn.push_back(1);

			for(int j=1; j<s.length(); j++)
			{
				if(s[j]==s[j-1])
					vn.back()++;
				else
				{
					mm+=s[j];
					vn.push_back(1);
				}
			}

			vvn.push_back(vn);
			if(mb=="")
				mb=mm;
			else
			{
				if(mm!=mb)
					res=false;
			}
		}

		if(res==false)
		{
			cout<<"Case #"<<ii+1<<": "<<"Fegla Won"<<endl;
			continue;
		}

		int sol=0;
		for(int i=0; i<vvn[0].size(); i++)
		{
			vector<int> vt;
			for(int j=0; j<n; j++)
			{
				vt.push_back(vvn[j][i]);
			}
			sort(vt.begin(),vt.end());
			int med=vt[vt.size()/2];
			
			for(int j=0; j<vt.size(); j++)
			{
				sol+=abs(med-vt[j]);
			}
		}

		cout<<"Case #"<<ii+1<<": "<<sol<<endl;
	}
}
