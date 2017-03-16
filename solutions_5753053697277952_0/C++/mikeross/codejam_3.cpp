#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n,i,j,k=1;
	vector<pair<int,int> >a;
	cin>>t;
	while(t--){
		a.clear();
		int sum=0;
		cin>>n;
		for(i=0;i<n;++i){
			cin>>j;
			a.push_back(make_pair(j,i));
			sum+=j;
		}
		sort(a.begin(),a.end());
		reverse(a.begin(),a.end());
		string ans;
		while(sum){
			if(sum==3 && a.size()>=3 && a[0].first==a[1].first && a[1].first==a[2].first){
				sum--;
				a[0].first--;
				ans.push_back(a[0].second+65);
				ans.push_back(32);
				sort(a.begin(),a.end());
				reverse(a.begin(),a.end());
				continue;
			}
			//cout<<sum<<endl;
			sum-=2;
			a[0].first--;
			a[1].first--;
			ans.push_back(a[0].second+65);
			ans.push_back(a[1].second+65);
			ans.push_back(32);
			sort(a.begin(),a.end());
			reverse(a.begin(),a.end());	
		}

		cout<<"Case #"<<k++<<": "<<ans<<endl;
	}
	return 0;
}