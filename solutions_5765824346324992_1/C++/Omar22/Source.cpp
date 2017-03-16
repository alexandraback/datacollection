#include <iostream>
#include <algorithm>

using namespace std;

long long BinarySearch(long long upper, long long lower, long long me, int B, int *M){
	long long ans = -1;
	while (upper >= lower){
		long long minute = (upper + lower) / 2, customers = B;
		
		for (int i = 0; i < B; i++){
			customers += (minute / M[i]);
		}
		if (customers >= me){
			upper = minute - 1;
		}
		if (customers < me){
			lower = minute + 1;

			ans = max(minute, ans);
		}
	}
	return ans + 1;
}


int main(){

	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++){
		int B, N, M[1234];
		cin >> B >> N;
		for (int i = 0; i < B; i++){
			cin >> M[i];
		}
		
		long long minute = BinarySearch(1234567890123, 0, N, B, M);
		int ON = N;

		while (N){
			if (BinarySearch(1234567890123, 0, N, B, M) != minute){
				break;
			}
			N--;
			
		}

		for (int i = 0; i < B; i++){
			if (minute % M[i] == 0){
				N++;
				if (N == ON){
					cout << "Case #" << t << ": " << i + 1 << endl;
				}
			}
		}
			
	}

}


