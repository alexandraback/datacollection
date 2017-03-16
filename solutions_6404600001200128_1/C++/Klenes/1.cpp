#include<iostream>
#include<vector>
using namespace std;


int main(){
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++){
		int n;
		int res1 = 0;
		int res2 = 0;
		int max = 0;
		cin >> n;
		vector<int> A;
		A.resize(n);
		for (int i = 0; i < n; i++){
			cin >> A[i];
			if (i > 0){
				if (A[i] < A[i - 1])
					res1 += A[i-1] - A[i];
				if (A[i] < A[i - 1] && (A[i - 1] - A[i] > max))
					max = A[i - 1] - A[i];
			}
		}
		for (int i = 0; i < n-1; i++)
		if (A[i] > max)
			res2 += max;
		else
			res2 += A[i];
		printf("Case #%d: %d %d\n", tc, res1, res2);
	}


	return 0;
}