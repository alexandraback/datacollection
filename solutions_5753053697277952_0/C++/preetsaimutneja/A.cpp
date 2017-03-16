#include <bits/stdc++.h>
using namespace std;
const int N=26;
int t;
int n, a[N];
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	cin>>t;
	for(int test=1;test<=t;++test) {
		cout<<"Case #"<<test<<": ";
		cin>>n;
		for(int i=0;i<n;++i) {
			cin>>a[i];
		}
		while(true) {
			int max_val=0,max_idx;


			for(int i=0;i<n;++i) {
				if(a[i]>max_val) {
					max_val=a[i];
					max_idx=i;
				}
			}
			if(!max_val) break;

			bool all_equal=true;
			int non_zero_idx=-1;
			int cnt_non_zero=0;
			for(int i=0;i<n;++i) {
				if(!a[i]) continue;
				cnt_non_zero++;
				if(non_zero_idx==-1) {
					non_zero_idx=i;
					
				} else {
					if(a[i]!=a[non_zero_idx]) {
						all_equal=false;
						break;
					}
				}
			}
			all_equal&=(cnt_non_zero==3);
			if(all_equal) {
				cout<<(char)('A'+non_zero_idx)<<" ";
				a[non_zero_idx]--;
			}
			else {
				int second_idx=-1;
				for(int i=0;i<n;++i) {
					if(a[i]==max_val && i!=max_idx) {
						second_idx=i;
						break;
					}
				}
				cout<<(char)('A'+max_idx);
				if(second_idx>0) {
					cout<<(char)('A'+second_idx);
				}
				cout<<" ";
				a[max_idx]--;
				if(second_idx>0) a[second_idx]--;
			}
			int tot=0;
			for(int i=0;i<n;++i) {
				tot+=a[i];
			}
			if(!tot) continue;
			for(int i=0;i<n;++i) {
				//cout<<1.*a[i]/tot<<" ";
				assert(1.*a[i]/tot<=.5);
			}
		}
		cout<<"\n";
	}
}