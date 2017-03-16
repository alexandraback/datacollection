#include <iostream>

using namespace std;

int mushrooms[1000];

int main() {
	int t;
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> mushrooms[i];
		
		int sum_first = 0;
		for (int i = 1; i < n; i++)
			sum_first += (mushrooms[i] < mushrooms[i-1]) ? mushrooms[i-1]-mushrooms[i] : 0;
		
		int sum_second = 0;
		int max_eats = 0;
		for (int i = 1; i < n; i++)
			if (mushrooms[i] < mushrooms[i-1] && mushrooms[i-1]-mushrooms[i] > max_eats)
				max_eats = mushrooms[i-1] - mushrooms[i];
		for (int i = 0; i < n-1; i++)
			sum_second += (mushrooms[i] < max_eats) ? mushrooms[i] : max_eats;
			
		cout << "Case #" << t1 << ": " << sum_first << " " << sum_second << endl;
	}
}
