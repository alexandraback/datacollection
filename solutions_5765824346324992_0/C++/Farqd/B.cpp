#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
#define int long long



int n; int k;
vector<int> v;





main()
{
	ios::sync_with_stdio(0);
	int z; cin>>z; for(int x=0; x<z; x++)
	{
		cin>>n; cin>>k;
		for(int i=0; i<n; i++)
		{
			int a; cin>>a; v.push_back(a);
		}
		// how many in time x


		int X = 1;
		for(int i=0; i<v.size(); i++)
			X*=v[i];

		int ile = 0;
		for(int i=0; i<v.size(); i++)
			ile+= X / v[i];

		k = k%ile;
		if(k==0)
			k=ile;


		//cerr<<k<<endl;

		vector<pair<int, int> > V;
			//cerr<<"P";
			for(int i=0; i<v.size(); i++)
			{
				for(int u=0; u<k; u++)
				{
					V.push_back({  u*v[i]   , i});
				}

			}
		

		sort(V.begin(), V.end());
		cout<<"Case #"<<x+1<<": "<<V[k-1].second+1<<endl;

		//cout<<X<<endl;
		v.clear();
		V.clear();

	}

	return 0;
}