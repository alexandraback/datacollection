#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> PII;
bool operator <(PII a, PII b) { return a.first < b.first || (a.first == b.first && a.second < b.second); }
// !!! CHANGE int TO LL if needed!!!
ll cross(PII a,PII b, PII c){
	PII ab = make_pair(b.first-a.first,b.second-a.second);
	PII ac = make_pair(c.first-a.first,c.second-a.second);
	return ab.first*ac.second - ab.second*ac.first;
}
// Returns convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<PII> ConvexHull(vector<PII> P) {
	int n = P.size(), k = 0; vector<PII> H(2*n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; i++)
	{ while (k >= 2 && cross(H[k-2], H[k-1], P[i]) < 0) k--; H[k++] = P[i]; }
	for (int i = n-2, t = k+1; i >= 0; i--)
	{ while (k >= t && cross(H[k-2], H[k-1], P[i]) < 0) k--; H[k++] = P[i]; }
	H.resize(k);
	return H;
}

ll mini[100], x[100], y[100];
int main()
{
	int test;
	cin>>test;
	for(int z=1;z<=test;z++)
	{
		ll n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>x[i]>>y[i];
		for(int i=1;i<=n;i++)
			mini[i]=n-1;
		ll w = 1<<n;
		for(int mask=1;mask<w;mask++)
		{
			vector<PII> pts;
			for(int i=1;i<=n;i++)
			{
				if(mask&(1<<(i-1)))
				{
					pts.push_back(PII(x[i],y[i]));
				}
			}
			ll nx = (ll) pts.size() ;
		//	cout<<mask<<" "<<nx<<endl;
			pts = ConvexHull(pts);
		//	cout<<nx<<" "<<pts.size()<<endl;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<pts.size();j++)
				{
					if(x[i]==pts[j].first && y[i]==pts[j].second)
						mini[i]=min(mini[i], n-nx);
				}
			}
		}
		cout<<"Case #"<<z<<":"<<endl;
		for(int i=1;i<=n;i++)
			cout<<mini[i]<<endl;
	}
}
