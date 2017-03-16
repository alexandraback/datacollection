#include <iostream>

using namespace std;

int a[1005];
int T,N;

int main() {
	cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>N;
		for (int i=0; i<N; i++) cin>>a[i];
		int ans1=0;
		for (int i=0; i<N-1; i++) {
			if (a[i]>a[i+1]) {
				ans1+=a[i]-a[i+1];
				//cout<<a[i]<<endl;
			}
		}
		int ans2=0;
		int md=0;
		for (int i=0; i<N-1; i++)
			if (a[i]-a[i+1]>md) md=a[i]-a[i+1];
		for (int i=0; i<N-1; i++)
			if (a[i]<md) ans2+=a[i];
			else ans2+=md;
		cout<<"Case #"<<t<<": "<<ans1<<' '<<ans2<<endl;
	}
	return 0;
}