#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 7;
int n, t;
int a[26];
pair<int,int> b[26];
int get() {
	int s = 0;
	for(int i=0;i<n;i++) s+=b[i].first;
	return s;
}
void main2() {
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		b[i] = {a[i],i};
	}
	string la, lb;
	vector<string> ans;
	while(get() > 0) {
		la = lb;
		sort(b,b+n);
		reverse(b,b+n);
		lb += (char)('A' + b[0].second);
		b[0].first--;
		if(get() == 0) {
			ans.push_back(lb);
			break;
		}
		sort(b,b+n);
		reverse(b,b+n);
		lb += (char)('A' + b[0].second);
		b[0].first--;
		ans.push_back(lb);
		lb.clear();
	}
	int nn = ans.size();
	la = ans[nn-1];
	lb = ans[nn-2];
	if(la.size() == 1) swap(ans[nn-2],ans[nn-1]);
	for(string ss : ans) cout<<ss<<' ';
	cout<<'\n';
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("I.in","r",stdin);
		freopen("O.out","w",stdout);
	#endif
	cin>>t;
	for(int cases=1;cases<=t;cases++) {
		cout<<"Case #"<<cases<<": ";
		main2();
	}
	return 0;
}