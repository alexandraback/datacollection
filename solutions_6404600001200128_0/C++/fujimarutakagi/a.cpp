#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 1000000000
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
#define fi first
#define se second
#define pu push
#define pb push_back

vi mush;

int main(){
	int tc,temp;
	cin>>tc;
	for(int zz=1; zz<=tc; zz++){
		mush.clear();
		int n;
		cin>>n;
		while(n--){
			cin>>temp;
			mush.pb(temp);
		}
		int ans = 0,ans2 = 0, maks = 0;

		for(int i=1; i < mush.size(); i++){
			if(mush[i]<mush[i-1])
				ans+=mush[i]-mush[i-1];
		}

		for(int i=1; i<mush.size(); i++)
			maks = max(maks,mush[i-1]-mush[i]);
		//cout<<maks<<endl;
		for(int i=0; i<mush.size()-1; i++){
			ans2+=min(maks,mush[i]);
			//cout<<ans2<<" ";
		}
		//cout<<endl;
		cout<<"Case #"<<zz<<": "<<-ans<<" "<<ans2<<endl;
	}
	return 0;
}