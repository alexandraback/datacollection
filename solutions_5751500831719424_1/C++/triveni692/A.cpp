/*
user  : triveni
date  : 03/05/2014
time  : 21:21:00
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      mp(a,b)           std::make_pair(a,b)
#define      X                 first
#define      Y                 second

typedef long long ll;
ll MOD = 1000000007;

string A[111];
vector<int> v[111];

void doit(int idx)
{
	int freq =1, j=1;
	string tmp;
	tmp += A[idx][0];
	for(int i=1;i<A[idx].length();++i)
	{
		if(A[idx][i]==A[idx][i-1]) freq++;
		else v[idx].push_back(freq), freq = 1, tmp += A[idx][i];
	}
	v[idx].push_back(freq);
	A[idx] = tmp;
	return ;
}

int get(vector<int>& vv)
{
	std::sort(vv.begin(),vv.end());
	int low = vv[0], high = vv[vv.size()-1];
	int ans = 999999;
	for(int i=low;i<=high;++i)
	{
		int tmp=0;
		for(int j=0;j<vv.size();++j)
			tmp += abs(vv[j]-i);
		ans = min(ans,tmp);
	}
	return ans;
}

void solve()
{
	int N;
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>A[i];
		doit(i);
	}
	
	bool flag = true;
	for(int i=1;i<N;++i)
	{
		if(A[i] != A[i-1]) {flag = false; break;}
	}
	if(flag==false)
	{
		cout << "Fegla Won\n";
		for(int i=0;i<111;++i)
		v[i].clear();
		return ;
	}
	for(int i=1;i<N;++i)
		assert(v[i].size() == v[i-1].size());

	int ans = 0;
	vector<int> vv;
	for(int i=0;i<v[0].size();++i)
	{
		for(int j=0;j<N;++j)
			vv.push_back(v[j][i]);
		ans += get(vv);
		vv.clear();
	}
	cout << ans << endl;
	for(int i=0;i<111;++i)
		v[i].clear();
	return ;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}