#include <iostream>
#include <math.h>

using namespace std;

int T,B;
long N;
int M[1005];

bool enough(int t) {
	int sum=0;
	for (int i=0; i<B; i++) sum+=ceil(1.0*t/M[i]);
	cout<<"check: "<<t<<' '<<sum<<endl;
	if (sum>=N-1) return true;
	else return false;
}

int getBarber(long t) {
	// long lastStart=0;
	// int ans=0;
	// for (int i=0; i<B; i++) {
	// 	int num=ceil(1.0*t/M[i])-1;
	// 	if (num*M[i]>=lastStart) {
	// 		lastStart=num*M[i];
	// 		ans=i;
	// 	}
	// }
	// return (ans+1);
	//cout<<"get "<<t<<endl;
	long minWait=100005;
	int ans=0;
	for (int i=0; i<B; i++){
		int num=ceil(1.0*t/M[i])-1;
		if (num*M[i]<minWait) {
			minWait=num*M[i]-t;
			ans=i;
		}
	}
	//cout<<minWait<<' '<<(ans+1)<<endl;
	return (ans+1);
}

int main() {
	cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>B>>N;
		long maxm=0;
		for (int i=0; i<B; i++) {
			cin>>M[i];
			if (M[i]>maxm) maxm=M[i];
		}
		long high=maxm*N;
		long low=0;
		long mid;
		while (high-low>1) {

			mid=(low+high)/2;
			//cout<<low<<' '<<high<<' '<<mid<<endl;
			if (enough(mid)) high=mid;
			else low=mid+1;
		}
		long ans=0;
		if (enough(low)) ans=low;
		else if (enough(mid)) ans=mid;
		else if (enough(high)) ans=high;
		int ansb=getBarber(ans);
		cout<<"Case #"<<t<<": "<<ansb<<endl;
	}
	return 0;
}


