#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

typedef unsigned long long ull;

int main() {

	int nCases;
	cin>>nCases;
	
	for(int nCase=1; nCase<=nCases; nCase++) {
		cout<<"Case #"<<nCase<<": ";
		int N;
		cin>>N;
		vector<int> m(N);
		for(int i=0;i<N;i++) cin>>m[i];
		int n1=0;
		for(int i=1;i<N;i++) {
			if(m[i]<m[i-1]) n1+=m[i-1]-m[i];
		}
		cout<<n1<<" ";
		int rate=0,n2=0;
		for(int i=1;i<N;i++) {
			if(m[i-1]-m[i]>rate) rate=m[i-1]-m[i];
		}
		for(int i=0;i<N-1;i++) {
			if(m[i]>=rate) n2+=rate;
			else n2+=m[i];
		}
		cout<<n2<<endl;
	}

	return 0;
}
