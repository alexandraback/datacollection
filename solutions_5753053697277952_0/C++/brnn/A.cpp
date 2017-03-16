#include <iostream> 
using namespace std;

void solve_case(int T){
	int N, total = 0;
	int counts[26];
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> counts[i];
		total += counts[i];
	}

	cout << "Case #" << T << ": ";

	int num_nonzero, max, second;
	char c;
	while (total > 0){
		max = 0;
		num_nonzero = 0;
		for (int i = 0; i < N; i++){
			if (counts[i] > 0){
				num_nonzero++;
				if (counts[i] > counts[max]){
					max = i;
				}
			}
		}

		counts[max]--;
		c = 'A' + max;
		cout << c;
		total--;

		if (num_nonzero < 3){
			for (int i = 0; i < N; i++){
				if (i != max && counts[i] > 0){
					second = i;
					break;
				}
			}

			if (counts[max] <= counts[second]){
				counts[second]--;
				c = 'A' + second;
				cout << c;
				total--;
			}
		}

		cout << " ";
	}

	cout << endl;
}

int main() {
  	int t;
  	cin >> t; 
  	for (int i = 1; i <= t; i++) {
  	  solve_case(i);
  	}
  	return 0;
}