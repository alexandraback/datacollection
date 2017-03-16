#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int cases;
	cin>>cases;
	for(int t =0;t<cases;t++){
		int n;
		cin>>n;
		vector<int> a,b;
		a.resize(n);
		b.resize(n-1);
		for(int j =0;j< n;j++){
			cin >> a[j];
			if(j>0){
				b[j-1]=a[j-1]-a[j];
			}
		}
		/*
		for( vector<int>::const_iterator i = a.begin(); i != a.end(); ++i){
			cout<<*i<<" ";
		}
		cout<<endl;
		for( vector<int>::const_iterator i = b.begin(); i != b.end(); ++i){
			cout<<*i<<" ";
		}
		cout<<endl;
		*/
		int sum1=0, sum2=0;
		int max_diff = *max_element(b.begin(),b.end());
		for(int k =0;k<n-1;k++){
			if(b[k]>0){sum1+=b[k];}
			if(a[k]<max_diff){
				sum2+=a[k];
			}else{
				sum2+=max_diff;
			}
		}
		cout<<"Case #"<<t+1<<": "<<sum1<<" "<<sum2<<endl;
	}
	return 0;
}

