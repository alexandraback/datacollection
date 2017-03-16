#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;


int n;
vector<int> v;


int main()
{
	ios::sync_with_stdio(0);
	int z; cin>>z; for(int x=0; x<z; x++)
	{
		cin>>n; int w1=0; int w2;
		for(int i=0; i<n; i++)
			{int a; cin>>a; v.push_back(a);}

		int ma = 0;
		int m = v[0];
		for(int i=1; i<n; i++)
		{
			ma=max(ma, v[i-1]-v[i]);
			if(v[i] < m)
			{
				w1+=m-v[i];
				m=v[i];
			}
			else
				m=v[i];
		}

//cout<<ma<<endl;
	//	w2=min(v[n-1], ma);
w2=0;

		for(int i=0; i<n-1; i++)
		{
			w2+=max(min (ma, v[i]), 0);
		}
		cout<<"Case #"<<x+1<<": "<<w1<<" "<<w2<<endl;
v.clear();
	}

	return 0;
}