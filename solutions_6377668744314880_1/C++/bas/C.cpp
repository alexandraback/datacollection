#include<iostream>
#include<vector>
#include<string>

using namespace std;
	int T;
	int n;
int main(){

	cin>>T;
	for(int j=0; j<T; j++){
	    cin>>n;
	vector<int> x(n);
	vector<int> y(n), res(n,4000);
	    for (int i=0; i<n; i++)cin>>x[i]>>y[i];
	    if(n==1){
		cout<<"Case #"<<j+1<<":\n0\n";
		continue;
	    }
	    for(int i=0; i<n; i++){
		for(int k=0; k<n; k++){
		    if(i==k)continue;
		    long long  A = y[i]-y[k]; long long B = x[k]-x[i]; long long C = -((long long) x[i])*(y[i]-y[k])+((long long) y[i])*(x[i]-x[k]);

		    int s1=0; int s2=0;
		    for (int p= 0; p<n; p++){
			if(A*x[p]+B*y[p]+C<0)s1++;
			if(A*x[p]+B*y[p]+C>0)s2++;
		    }
		    res[i] = min(res[i], min(s1, s2));
		}
	    }
		
	    cout<<"Case #"<<j+1<<":\n";
	    for (int i=0; i<n; i++)
		cout<<res[i]<<"\n";
	}
	
}
