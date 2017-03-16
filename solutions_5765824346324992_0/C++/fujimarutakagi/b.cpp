#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 1000000000
#define LLINF 1000000000000000000
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
#define fi first
#define se second
#define pu push
#define pb push_back

int main(){
	LL tc,n,b,temp;
	vi barber;
	cin>>tc;

	for(int zz=1; zz<=tc; zz++){
		barber.clear();
		//cout<<"HAHA"<<endl;
		cin>>b>>n;

		

		for(int i=0; i<b; i++){
			cin>>temp;
			barber.pb(temp);
		}

if(n<=b){
				cout<<"Case #"<<zz<<": "<<n<<endl;
				continue;
		}

		LL l = 0;
		LL r = LLINF;
		LL m;
		LL ans = LLINF;

		while(l<=r){
			m = (l+r)/2;

			temp = 0;
			for(int i=0; i<barber.size(); i++)
				temp+=m/barber[i]+1;

			if(temp<n)
				l=m+1;
			else{
				r=m-1;
				ans=min(ans,m);
			}
		}

		//ans = r;
		//cout<<ans<<"A"<<endl;
		LL ans2=0;
		ans--;

		for(int i=0; i<barber.size(); i++)
			ans2+=ans/barber[i]+1;

		ans2=n-ans2;
		ans++;

		//cout<<ans2<<"B"<<endl;
		for(int i=0; i<barber.size(); i++){
			if(ans%barber[i] == 0)
				ans2--;
			if(ans2==0){
				cout<<"Case #"<<zz<<": "<<i+1<<endl;
				break;
			}
		}

	}
	return 0;
}