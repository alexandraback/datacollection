#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int A[10000][10000];

void init(int R, int C) {
	for(int r=0;r<R;r++) {
		for(int c=0;c<C;c++) {
			A[r][c] = 0;
		}
	}
}

int dfs(int R, int C, int N) {

	if(N == 0)
		return 0;

	int ans = INT_MAX;
	for(int r=0;r<R;r++) {
		for(int c=0;c<C;c++) {
			if(A[r][c] == 0) {
				A[r][c] = 1;
				int z =0;
				for(int d=0;d<4;d++) {
					int rr = r + dy[d];
					int cc = c + dx[d];
					if(rr < 0 || rr >= R || cc < 0 || cc >= C) 
						continue;
					if(A[rr][cc] == 1)
						z++;
				}
				

				int cost = z + dfs(R, C, N-1);
				if(cost < ans)
					ans = cost;
				A[r][c] = 0;
			}
		}
	}



	return ans;
}

int solve(int R, int C, int N) {

	if( (C & 1) == 0 ) { // C is even
		if(N <= C/2 * R)
			return 0;
	}
	else {
		int k = (C+1)/2;
		int n = (R/2)*(k+k-1) + (R%2)*(k);
		if(N <= n)
			return 0;
	}
	for(int c=0;c<C;c+=2)
		A[0][c] = 1;

	for(int r=2;r<R;r+=2)
		A[r][0] = 1;

	int r = 0;
	if(A[r][C-1] == 0)
		r++;
	for(;r<R;r+=2)
		A[r][C-1] = 1;

	//int c=0;
	//if(A[R-1][c] == 0) {
	//	c++;
	//}

	//for(;c<C;c+=2)
	//	A[R-1][c] = 1;
	//if(C >= 2 && A[R-1][C-1] == 1 && A[R-1][C-2] == 1)
	//	A[R-1][C-1] = 0;

	for(int r=0;r<R;r++) {
		for(int c=0;c<C;c++) {
			if(A[r][c] == 1)
				N--;
		}
	}
	return dfs(R, C, N);
}




int main() {


	freopen("C:\\Users\\weihaoc\\ACM\\a.in", "r", stdin);
	freopen("C:\\Users\\weihaoc\\ACM\\a.out", "w+", stdout);

	int T;
	cin >> T;
	
	for(int t=1;t<=T;t++) {

		int R,C,N;
		cin >> R >> C >> N;
		init(R,C);
		int ans = solve(R, C, N);

		cout<<"Case #"<<t<<": "<<ans<<endl;
	}

	return 0;

}


//int solve(int R, int C, int N) {
//
//
//	for(int r=0;r<R;r++) {
//		for(int c=0;c<C;c++) {
//			A[r][c] = 0;
//		}
//	}
//
//	int ans = 0;
//
//	if( C & 1 == 0 ) { // C is even
//		if(N <= C/2 * R)
//			return 0;
//		N -= C/2 * R;
//		for(int r=0;r<R;r++) {
//			for(int c=r%2;c<C;c+=2) {
//				A[r][c] = 1;
//			}
//		}
//
//
//	}
//	else {
//		int k = (C+1)/2;
//		int n = (R/2)*(k+k-1) + (R%2)*(k);
//		if(N <= n)
//			return 0;
//		N -= n;
//		for(int r=0;r<R;r++) {
//			for(int c=r%2;c<C;c+=2) {
//				A[r][c] = 1;
//			}
//		}
//	}
//	int n2 = 0;
//	int n3 = 0;
//	int n4 = 0;
//	for(int r=0;r<R;r++) {
//		for(int c=0;c<C;c++) {
//
//			if(A[r][c] == 0) {
//
//				int z = 0;
//
//				for(int d=0;d<4;d++) {
//					int rr = r + dy[d];
//					int cc = c + dx[d];
//					if(rr < 0 || rr >= R || cc < 0 || cc >= C) 
//						continue;
//					if(A[rr][cc] == 1)
//						z++;
//				}
//				if(z == 2)
//					n2++;
//				if(z == 3)
//					n3++;
//				if(z == 4)
//					n4++;
//			}
//		}
//	}
//
//	if(N <= n2) {
//		return ans + N*2;
//	}
//	N -= n2;
//	ans += n2*2;
//
//	if(N <= n3) {
//		return ans + N*3;
//	}
//	N -= n3;
//	ans += n3*3;
//
//	if(N <= n4) {
//		return ans + N*4;
//	}
//	N -= n4;
//	ans += n4*4;
//	return ans;
//}

