#include <iostream>

using namespace std;

int main(){
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++){
		int n;
		cin >> n;
		int q[n];
		for (int i = 0; i < n; i++) cin >> q[i]; 
		int sum1 = 0, big = 0;
		for (int i = 0; i < n - 1; i++){
			if (q[i + 1] < q[i]){
				sum1 += q[i] - q[i + 1];
				big = max(big, q[i] - q[i + 1]);
			}
		}
		int rate = big, sum2 = 0;
		for (int i = 0; i < n - 1; i++){
			if (q[i] >= rate) sum2 += rate;
			else sum2 += q[i]; 
		}
		cout << "Case #" << k << ": " << sum1 << " " << sum2 << endl;
	}
	
	return 0;
} 
