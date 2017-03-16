//============================================================================
// Name        : codeforceB.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int t,n,a[1001];
long long s1, s2;
int main() {
	ios::sync_with_stdio(false);
	ifstream in("input");
	ofstream out("output");
	in >> t;
	for(int i = 0; i < t; i++){
		in >> n;
		s1 = 0;
		s2 = 0;
		for(int j = 0; j < n; j++){
			in >> a[j];
		}
		long long maxi = 0;
		for(int j = 0; j < n-1; j++){
			if (a[j] > a[j+1]){
				s1 +=a[j] - a[j+1];
				if (a[j] - a[j+1]>maxi)
					maxi = a[j] - a[j+1];
			}
		}
		for(int j = 0; j < n-1; j++){
			if (a[j] < maxi){
				s2 += a[j];
			}else{
				s2 +=maxi;
			}
		}
		out<<"Case #"<<i+1<<": "<<s1<<' '<<s2<<'\n';
	}
	in.close();
	out.close();
	return 0;
}
