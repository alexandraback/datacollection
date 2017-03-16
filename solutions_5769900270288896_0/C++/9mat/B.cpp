#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>


#define FOR(i,N) for(int i=0, n_=(N); i<n_; i++)

using namespace std;

int process(int R, int C, int N){
	vector< vector<bool> > b(R, vector<bool>(C, false));

	int min = R*C*10;

	FOR(code, 1<<(R*C)){
		int cc = code;
		FOR(k, R*C){
			b[k%R][k/R] = (cc%2 == 1);
			cc /= 2;
		}

		int count = 0;
		FOR(k, R*C) if(b[k%R][k/R]) count ++;
		if(count != N) continue;

		int uh = 0;
		FOR(r, R) FOR(c,C){
			if(r<R-1 && b[r][c] && b[r+1][c]) uh++;
			if(c<C-1 && b[r][c] && b[r][c+1]) uh++; 
		}

		if(uh < min) min = uh;
	}

	return min;
}


int main(){
	int T,k;
	int N, R, C;
	cin>>T;


	FOR(t,T){
		cin>>R>>C>>N;
		cout<<"Case #"<<t+1<<": "<<process(R,C,N)<<endl;
	}

	return 0;
}