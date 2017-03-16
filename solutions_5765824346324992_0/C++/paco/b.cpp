#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

typedef unsigned long long ull;

template <class T>
T GCD(T a, T b) {
	T t;
	while(b != 0) {t = b;b = a % b;a = t;}
	return a;
}

template <class T>
T LCM(T a, T b) {
	return (a*b)/GCD(a,b);
}


int main() {

	int nCases;
	cin>>nCases;
	
	for(int nCase=1; nCase<=nCases; nCase++) {
		cout<<"Case #"<<nCase<<": ";
		int B,N;
		cin>>B>>N;
		if(N<=B) {
			cout<<N<<endl;
			continue;
		}
		vector<int> M(B);
		for(int i=0;i<B;i++) cin>>M[i];
		
		int lcm=M[0];
		for(int i=1;i<B;i++) {
			lcm=LCM(lcm,M[i]);
			
		}
		int mod=0;
		for(int i=0;i<B;i++) mod+=lcm/M[i];
		N=N%mod;
		vector<int> Q(B,0);
		int j=B;
		while(N>0) {
			for(int i=0;i<B;i++) {
				if(Q[i]==0) {
					j=i+1;
					Q[i]=M[i]-1;
					N--;
					if(N==0) break;
				}
				else Q[i]--;
			}
		}
		cout<<j<<endl;
	}

	return 0;
}
