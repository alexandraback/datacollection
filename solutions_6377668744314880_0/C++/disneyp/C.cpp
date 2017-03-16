#include <iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
#define PI 3.14159265
using namespace std;
double x[4000],y[4000];
int n;	
vector <double> v;
void f(int ind)
{
	long long st,L,R;
	int p,ans=0;
	v.clear();
	for(int i=0;i<n;i++)
	{
		if(i!=ind) v.push_back(atan2(x[ind]-x[i],y[ind]-y[i]));
		//if(i!=ind) cout << x[ind] - x[i] << " " << y[ind]-y[i] << endl;
	}
	sort(v.begin(),v.end());
	//cout << "A" << endl;
	for(int i=0;i<n-1;i++) v.push_back(v[i]+2.0*PI);
	p=0;
	v.push_back(100000.0);
	while(v[0]+PI >= v[p]-1.0e-6)
	{
		p++;
	}
	//cout << "A" << endl;
	ans = n-1-p;
	for(int i=1;i<n;i++)
	{
		while(v[i]+PI >= v[p]-1.0e-6) p++;
		ans = min(ans,n-1-(p-i));
	}
	//for(int i=0;i<2*n;i++) cout << v[i] << " ";cout << endl;
	cout << ans << endl;
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.txt","w",stdout);
	
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> n;
		for(int j=0;j<n;j++) scanf("%lf %lf",&x[j],&y[j]);
		cout << "Case #" << i+1 << ": " << endl;
		if(n==1)
		{
			cout << 0 << endl;
			continue;
		}
		for(int j=0;j<n;j++)
		{
			
			f(j);
		}
	}
}