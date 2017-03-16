#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return (a.first < b.first);
}



int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	int k = 1;
	while(t--)
	{
		cout<<"Case #"<<k<<": ";
		k++;
		int n;
		cin>>n;
		vector<pair<int, int> > v;
		int total = 0;

		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			v.push_back(make_pair(temp,i));
			total += temp;
		}
		sort(v.begin(),v.end(),compare);
		// for(int i=0;i<v.size();i++)
		// {
		// 	cout<<v[i].second<<" ";
		// }
		// cout<<endl;
		int last = n-1;
		while(total > 0)
		{
			cout<<(char)(v[last].second + 'A');
			v[last].first--;
			total--;
			if(total <= 0)
				break;
			if(last != 0 && ((v[last-1].first > (total/2)) || (v[last-1].first*2 == total && v[last].first != v[last-1].first && (last-2 >=0 && v[last-2].first != v[last-1].first)) ))
			{
				cout<<(char)(v[last-1].second + 'A')<<" ";
				v[last-1].first--;
				total--;
			}
			else
			{
				cout<<" ";
			}
			sort(v.begin(),v.end(),compare);
		}
		cout<<endl;
	}
	return 0;
}