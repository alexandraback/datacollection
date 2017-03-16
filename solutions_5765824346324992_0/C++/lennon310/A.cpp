#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include <queue>
using namespace std;
typedef long long ll;
int b;
ll n;
int m[1001],art[1001];
typedef pair<ll,int> pii;
int main(){
   // freopen("input1.txt","r",stdin);
    freopen("B-small-attempt3.in","r",stdin);
   //freopen("A-large.in","r",stdin);
    freopen("output1.txt","w",stdout);
    
    int t;
    cin >> t;
    
    for(int ti=1;ti<=t;ti++){
		cout << "Case #"<<ti<<": ";
        cin>>b>>n;
		
		/*vector<pii> v;
		for(int i=0;i<b;i++) {
			cin>>m[i];
			for(int j=1;j<=100;j++)
				v.push_back({m[i]*j,i+1});
		}
		if (n<=b){
			cout << n << "\n";
			continue;
		}
		sort(v.begin(),v.end());
		cout << v[n-1].second << "\n";*/
		priority_queue<pii,vector<pii>,greater<pii> > q;
		ll tot = 1;
		vector<int> mm;
		for(int i=0;i<b;i++) {
			cin>>m[i];
			mm.push_back(m[i]);
			q.push({m[i],i+1});
			tot = 1LL*tot*m[i]/__gcd(tot,1LL*m[i]);
		}
		if (n<=b){
			cout << n << "\n";
			continue;
		}
		sort(mm.begin(),mm.end());
		if (mm[0]==mm[mm.size()-1]){
			ll res = n%b;
			if (res==0) res = b;
			cout << res << "\n";
			continue;
		}
		//n = n%b;
		
		//if (n==0) n = b;
		//n++;
		//cout << b << " " << n << endl;
 		ll cur = 0;
        ll num = b;
		int ans;
		bool ok = false;
		vector<int> v;
		for(int i=1;i<=b;i++) v.push_back(i);
		bool stop = false;
		int cnt = 0;
		while (1) {
			auto it = q.top();
			q.pop();
			ll tim = it.first;
			int id = it.second;
			//cout << tim << ", " << id << endl;
			num ++;
			if (num==n){
				ans = id;
				ok = true;
				//cout << "cao \n";
				break;
			}
			
			//cout << tot << ", " << tim << " " << m[id-1] << endl;
			/*if ((tim==tot || tim+m[id-1]==tot) && !stop) {
				stop = true;
				cnt = 0;
			}*/
			if (id==1 && tim==tot)break;
		//	if (tim+m[id-1]<=tot || tim==tot){
				q.push({tim+m[id-1],id});
				v.push_back(id);
		//		if (stop) cnt++;
		//		if (cnt==b) break;
		//	}
			/*v.push_back(id);
			if (v.size()>=4 && v.size()%2==0) {
				bool good = true;
				for(int i=0;i<v.size()/2;i++){
					if (v[i]==v[i+v.size()/2]) continue;
					good = false;
				}
				if (good) break;
			}*/
		}
        if (ok) cout << ans << "\n";
		else{
			//num += b;
			//n--;
			n %= v.size();
			if (n==0) n = v.size();
			//cout << n << ", " << v.size() << endl ;
			cout << v[n-1] << "\n";
		}
		/*else{
			ll tmp = v.size()/2;
			ll rp = (n-b)%tmp;
			if (rp==0) rp = tmp;
			cout << v[rp-1] << "\n";
		}*/
    }
    return 0;
}
