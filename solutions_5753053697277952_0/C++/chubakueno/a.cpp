#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int z=1;z<=t;++z){
		int n;
		cin>>n;
		vector<int> arr(n,0);
		int tot=0;
		for(int i=0;i<n;++i)
			cin>>arr[i];
		printf("Case #%d: ",z);
		while(1){
			int maxind=-1,mv=0;
			int tot=0;
			for(int i=0;i<n;++i){
				tot+=arr[i];
			}
			for(int i=0;i<n;++i){
				if(arr[i]>mv){
					mv=arr[i];
					maxind=i;
				}
			}
			if(tot-mv<mv){
				cout<<"asdf"<<endl;
			}
			if(maxind==-1) break;
			string ans="";
			ans+='A'+maxind;
			--arr[maxind];
			maxind=-1;
			for(int i=0;i<n;++i){
				if(mv==arr[i]){
					maxind=i;
					mv=arr[i];
				}
			}
			int cnt=0;
			for(int i=0;i<n;++i)
				if(arr[i]==mv) ++cnt;
			if(cnt==1){
				--arr[maxind];
				ans+='A'+maxind;
			}
			cout<<ans<<" ";
		}
		cout<<endl;
	}
}