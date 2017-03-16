#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int getCount(int **A, int num, int N, int R, int C){
	int i,j,count = 0;
	for(i = 0 ; i < R*C ; i++){
		if((num & (1 << i)) != 0){
			count++;
			A[i/C][i%C] = 1;
		}
		else{
			A[i/C][i%C] = 0;
		}
	}
	if(count != N)
		return 10000;
	count = 0;
	for(i = 0 ; i < R ; i++){
		for(j = 0 ; j < C ; j++){
			if(A[i][j] == 0)
				continue;
			if(i + 1 < R && A[i+1][j] == 1)
				count++;
			if(j + 1 < C && A[i][j+1] == 1)
				count++;

		}
	}
	return count;
}

int main(){
	int i,j,k,l;
	int N,T,R,C,**A;
	cin>>T;
	for(l = 0 ; l < T ; l++){
		cin>>R>>C;
		cin>>N;
		cout<<"Case #"<<l+1<<": ";
		if(N == 0){
			cout<<"0"<<"\n";
			continue;
		}
		A = new int *[R];
		for(i = 0 ; i < R ; i++)
			A[i] = new int[C];
		int mn = 1000000;
		for(i = 1 ; i < pow(2, R*C) ; i++){
			int cnt = getCount(A, i, N, R, C);
			mn = min(mn, cnt);
		}
		cout<<mn<<"\n";
	}
}