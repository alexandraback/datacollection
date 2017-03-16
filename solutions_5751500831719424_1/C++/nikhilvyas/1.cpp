#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int gg(vector<int> d,int s){
	//cout<<"gg"<<endl;
	int ret=0;
	for(int i=0;i<d.size();i++){
		ret=ret+abs(s-d[i]);
	}
	return ret;
}
		

int ff(vector<string> a,vector<int> b){
	//cout<<"ff"<<endl;
	int q=0;
	for(int i=0;i<a.size();i++){
		if(a[i].size() <= b[i]) q++;
	}
	if(q==a.size()) return 0;
	
	//cout<<q<<endl;
	if( q==0){
		//if(q!=0) return -1;
		//cout<<"in"<<endl;
	int k=b.size();
	vector<int> d(k);
	char c=a[0][b[0]];
	for(int i=0;i<a.size();i++){
		int p=b[i];
		for(int j=b[i];j<a[i].size();j++){
			if(a[i][j] == c) b[i]++;
			else break;
		}
		if(p == b[i]) return -1;
		d[i] = b[i] - p;
	}
	if(k % 2 == 1){
		//cout<<"odd"<<endl;
		nth_element(d.begin(),d.begin()+(k-1)/2,d.end());
		int ss = d[(k-1)/2];
		int fg = gg(d,ss);
		int uy = ff(a,b);
		if(uy == -1) return -1;
		return fg+uy;
	}
	if( k % 2 == 0){
		//cout<<"even"<<endl;
		nth_element(d.begin(),d.begin()+(k)/2,d.end());
		int ss = d[k/2];
		int fg = gg(d,ss);
		int uy = ff(a,b);
		if(uy == -1) return -1;
		return fg+uy;
	}}
	//else return 0;
	else return -1;
}
		
	

int main(){
	int gg;
	cin>>gg;
	for(int kk=0;kk<gg;kk++){
		int n;
		cin>>n;
		vector<string> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		vector<int> b(n,0);
		int z = ff(a,b);
		if(z == -1) cout<<"Case #"<<kk+1<<": Fegla Won"<<endl;
		else cout<<"Case #"<<kk+1<<": "<<z<<endl;
	}
}
