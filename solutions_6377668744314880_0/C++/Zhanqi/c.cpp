#include <iostream>
#include <math.h> 

using namespace std;

long T,N,x[3005],y[3005],ans[3005];

int main() {
	cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>N;
		for (int i=0; i<N; i++) cin>>x[i]>>y[i];
		for (int i=0; i<N; i++) ans[i]=N;
		for (int i=0; i<N; i++) 
			for (int j=0; j<N; j++) {
				if (i==j) continue;
				int pos=0,neg=0;
				for (int k=0; k<N; k++) {
					if (k==i || k==j) continue;
					long Ax=x[i],Ay=y[i],Bx=x[j],By=y[j],X=x[k],Y=y[k];
					if ( (Bx-Ax)*(Y-Ay) - (By-Ay)*(X-Ax) > 0 ) pos++;
					if ( (Bx-Ax)*(Y-Ay) - (By-Ay)*(X-Ax) < 0 ) neg++;
				}
				if (pos<ans[i]) ans[i]=pos;
				if (neg<ans[i]) ans[i]=neg;
				//if (i==4) cout<<i<<' '<<j<<' '<<pos<<' '<<neg<<endl;
			}
		cout<<"Case #"<<t<<":"<<endl;
		if (N<=3) {
			for (int i=0; i<N; i++) cout<<0<<endl;
		}
		else for (int i=0; i<N; i++) cout<<ans[i]<<endl;
	}
	return 0;
}


//position = sign( (Bx-Ax)*(Y-Ay) - (By-Ay)*(X-Ax) )