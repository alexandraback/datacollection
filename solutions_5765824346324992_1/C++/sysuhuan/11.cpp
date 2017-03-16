#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	ll t;
	cin >> t;
	for(int casenum = 1;casenum<=t;casenum++){
		ll ans =  -1,B;
		ll low = 0, high = 0;
		vector<ll> a;
		ll n;
		cin >>B>>n;
		for(int i = 0;i<B;i++){
			ll tmp;
			cin >> tmp;
			a.push_back(tmp);
			high = max(high, tmp*n+1);
		}
		while(1){
			ll mid = (low+high)/2;
			ll sum = 0;
			ll now = 0;
			for(int i = 0;i<B;i++){
				sum+=(mid-1)/a[i]+1;
				//sum+=ceil((double)(mid-1)/a[i]);
				//if(mid%a[i]==0)now++;
				now+=mid/a[i]+1; 
			}

			if(sum>=n){
				high = mid;
			}else if(now<n){
				low = mid+1;
			}else{
				ans = mid;
				break;
			}
		}
		ll which = -1;
		ll sum = 0;
		vector<int> w;
		for(int i =0;i<B;i++){
			sum+=ceil((double)(ans)/a[i]);
			if(ans%a[i]==0)w.push_back(i+1);
		}
		cout <<"Case #"<<casenum<<": "<<w[n-sum-1]<<endl;
	}
	return 0;
}