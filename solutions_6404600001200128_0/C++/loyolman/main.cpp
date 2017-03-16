#include <iostream>
#include <vector>
#include <algorithm>

//YOLO
//loyolman

using namespace std;

int main() {
	int T;
	cin>>T;
	for (int j=1;j<=T;j++) {
		int N;
		vector<int> v;
		cin>>N;
		
		for (int g=0;g<N;g++) {
			int h;
			cin>>h;
			v.push_back(h);
		}
		
		int fm=0;//first method
		for (int i=0;i<v.size()-1;i++) {
			if (v[i]>v[i+1]) fm+=v[i]-v[i+1];
		}
		
		int sm=0;//second method
		int mmax=0;
		for (int i=0;i<v.size()-1;i++) {
			if (v[i]>v[i+1]) mmax=max(mmax,v[i]-v[i+1]);
		}
		for (int i=0;i<v.size()-1;i++) {
		 	sm+=min(v[i],mmax);
		}
		
		cout<<"Case #"<<j<<": "<<fm<<" "<<sm<<endl;
	}
	return 0;
}
