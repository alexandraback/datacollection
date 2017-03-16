//============================================================================
// Name        : codeforceA.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include<bits/stdc++.h>
using namespace std;

int t,b,a[1000];
long long g,n,no,c[1000];
long long minm;
long long turn(long long t){
	long long sum = 0;
	for(int i = 0; i<b; i++){
		sum +=(t/a[i]);
	}
	return sum;
}

int find(long long t){
	long long no = 0;
	for(int i = 0; i < b; i++){
		no = no +((t-minm)/a[i]);
		c[i] = (long long)a[i]*((t-minm)/a[i]);
		if (c[i] < (t-minm)){
			c[i] += a[i];
			no++;
		}
		cout << c[i]<<' ';
		cout << (t-minm)/a[i]<<'\n';
	}
	cout << (n-no)<<' ';
	long long r = n - no;
	long long i;
	int mini;
	for(i = 0; i < r; i++){
		mini = 0;
		for(int j = 1; j < b; j++){
			if (c[j] < c[mini])
				mini = j;
		}
		c[mini] += a[mini];
	}
	return (mini+1);
}

int main() {
	ios::sync_with_stdio(false);
	ifstream in("input");
	ofstream out("output");
	in >> t;
	for (int i = 0; i < t; i++){
		in >> b >> n;
		in >> a[0];
		c[0] = a[0];
		minm = a[0];
		for (int j = 1; j < b; j++){
			in >> a[j];
			c[j] = a[j];
			if (a[j] > minm)
				minm = a[j];
		}
		long long r = (n-1)*a[0];
		long long l = 0;
		while(l < r){
			//cout << l <<' '<<r<<'\n';
			long long mid = (l+r)/2;
			if (turn(mid) < n){
				l = mid+1;
			}else{
				r = mid;
			}
		}
		cout << r<<' ';
		out<<"Case #"<<i+1<<": "<<find(r)<<'\n';
	}
	in.close();
	out.close();
	return 0;
}
