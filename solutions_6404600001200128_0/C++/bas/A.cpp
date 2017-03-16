#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
	int C, N;
int main(){
	vector<int > a;
	
	cin>>C; 
	for(int j=0; j<C; j++){
		cin>>N;
		a.clear(); a.resize(N);
		for(int i=0; i<N; i++){cin>>a[i];}
		int res1=0,res2=0; int r = 0;
		for(int i=0; i<N-1; i++){
		    if(a[i]-a[i+1]>r)r=a[i]-a[i+1];
		}		
		for(int i=0; i<N-1; i++){
		    res1 += max(a[i]-a[i+1], 0);
		    res2+= min(r, a[i]);
		}		
		cout<<"Case #"<<j+1<<": "<<res1<<" "<<res2<<"\n" ;
	}
	
}
