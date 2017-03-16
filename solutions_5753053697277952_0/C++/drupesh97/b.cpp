#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	set<pair<int,int>,greater<pair<int,int> > > s;
	for(int i = 0;i < n; i++){
		cin>>v[i];
		s.insert({v[i],i});
	}
	//cout<<"here \n";
	set<pair<int,int> >::iterator it;
	while(!s.empty()){
		//cout<<s.size()<<endl;
		pair<int,int> p = *s.begin();
		s.erase(s.begin());
		cout<<(char)(p.second+'A');
		p.first--;
		int cnt = 0;
		it = s.begin();
		while(it!=s.end()){
			cnt += it->first;
			it++;
		}
		pair<int,int> t= *s.begin();
		if(t.first > (cnt/2)){
			s.erase(s.begin());
			cout<<(char)(t.second+'A')<<" ";
			t.first--;
			if(t.first!=0)
				s.insert(t);
		}
		else cout<<" ";
		if(p.first!=0)
			s.insert(p); 
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	freopen("./input.txt","r",stdin);
	freopen("./output.txt","w",stdout);
	int t;
	cin>>t;
	for(int i = 1;i <=t; i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}	