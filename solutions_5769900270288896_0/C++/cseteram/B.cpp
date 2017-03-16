#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int count(vector<vector<int>> &board) {
	int ret=0;

	int R = board.size();
	int C = board[0].size();

	for(int i=0 ; i<R ; i++) {
		for(int j=0 ; j<C ; j++) {
			if(i<R-1 && board[i][j]+board[i+1][j]==2) ret++;
			if(j<C-1 && board[i][j]+board[i][j+1]==2) ret++;
		}
	}

	return ret;
}

int main() {

	int T;

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	cin>>T;
	for(int t=1 ; t<=T ; t++) {
		int R,C,N;
		int ans=987654321;
		cin>>R>>C>>N;

		vector<int> pert(R*C,0);
		for(int i=R*C-N ; i<R*C ; i++) pert[i]=1;

		vector<vector<int>> board(R);
		for(int i=0 ; i<R ; i++) board[i].resize(C);

		do {
			int index=0;
			for(int i=0 ; i<R ; i++) for(int j=0 ; j<C ; j++) board[i][j]=pert[index++];

			int t = count(board);
			if(t<ans) ans=t;
		} while(next_permutation(pert.begin(), pert.end()));

		/*
		int threshold = (R*C % 2)?(R*C/2 + 1):(R*C/2);

		if(N<=threshold) ans=0;
		else {


		}
		*/

		cout<<"Case #"<<t<<": ";
		cout<<ans;
		cout<<"\n";
	}

	return 0;
}