#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	if(a<b)
		return gcd(b, a);
	if(a == b || b == 0)
		return a;
	return gcd(b, a%b);
}

int getlcm(int a, int b){
	int g = gcd(a,b);
	return (a/g * b);
}


int main(){
	int i,j,k,l;
	int N,T,B;
	int *M,index;
	long long *nextFree;
	cin>>T;
	for(l = 0 ; l < T ; l++){
		cin>>B>>N;
		M = new int[B];
		nextFree = new long long[B];
		for(i = 0 ; i < B ; i++)
			cin>>M[i];
		int lcm = M[0];
		for(i = 1 ; i < B ; i++)
			lcm = getlcm(lcm, M[i]);

		int count = 0;

		for(i = 0 ; i < B ; i++){
			count += lcm/M[i];
			nextFree[i] = 0;
		}

		N = N - (N/count)*count;
		if(N == 0)
			N = count;

		for(i = 0 ; i < N ; i++){
			index = 0;
			for(j = 0 ; j < B ; j++){
				if(nextFree[j] < nextFree[index])
					index = j;
			}
			nextFree[index] += M[index];
		}

		cout<<"Case #"<<l+1<<": ";
		cout<<index+1<<"\n";
		delete M;
		delete nextFree;
	}
	return 0;
}