#include <bits/stdc++.h>
using namespace std;
int mat[10000][10000];

int r,c;

int solve(int n) {
	int res = 0;
	if (mat[0][0] == 0) {
		if (c == 1 || r == 1)
			res += 1;
		else 
			res += 2;
		n--;
		mat[0][0] = 1;
	}
	
	if (n == 0) return res;
	if (mat[0][c-1] == 0) {
		if (c == 1 || r == 1)
			res += 1;
		else 
			res += 2;
		n--;
		mat[0][c-1] = 1;
	}
	
	if (n == 0) return res;
	if (mat[r-1][0] == 0) {
		if (c == 1 || r == 1)
			res += 1;
		else 
			res += 2;
		n--;
		mat[r-1][0] = 1;
	}
	
	if (n == 0) return res;
	if (mat[r-1][c-1] == 0) {
		if (c == 1 || r == 1)
			res += 1;
		else 
			res += 2;
		n--;
		mat[r-1][c-1] = 1;
	}
	
	if (n == 0) return res;
	for (int i = 0; i < r; i++) {
		if (mat[i][0] == 0) {
			if (c > 1)
				res += 3;
			else 
				res += 2;
			n--;
			mat[i][0] = 1;
		}
	
		if (n == 0) return res;
		if (mat[i][c-1] == 0) {
			if (c > 1)
				res += 3;
			else 
				res += 2;
			n--;
			mat[i][c-1] = 1;
		}
	
		if (n == 0) return res;
	}
	for (int i = 0; i < c; i++) {
		if (mat[0][i] == 0) {
			if (r > 1)
				res += 3;
			else 
				res += 2;
			n--;
			mat[0][i] = 1;
		}
	
		if (n == 0) return res;
		if (mat[r-1][i] == 0) {
			if (r > 1)
				res += 3;
			else 
				res += 2;
			n--;
			mat[r-1][i] = 1;
		}
	
		if (n == 0) return res;
	}
	return res + 4*n;
}

int main() {
	int tests, n;
	cin >> tests;
	for (int t = 1; t <= tests; t++) {
		cout << "Case #" << t << ": ";
		int res = -1;
		cin >> r >> c >> n;
		
		int count = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				mat[i][j] = (i+j)%2;
				count += (i+j)%2;
			}
		if (count >= n) 
			res = 0;
		else 
			res = solve(n-count);
		
		count = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				mat[i][j] = (i+j+1)%2;
				count += (i+j+1) %2;
			}
		if (count >= n) 
			res = 0;
		else 
			res = min(res,solve(n-count));
		cout << res << endl;
	}
	return 0;
} 