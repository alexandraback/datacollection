#include <iostream>
#include <algorithm>  
using namespace std;

int gcd(int m, int n) {
	while (n != 0) {
		int r = m % n;
		m = n;
		n = r;
	}
	return m;
}

int lcm(int m, int n) {
	return m * n / gcd(m, n);
}

int main()
{
	FILE *input;
	FILE *output;
	freopen_s(&input, "B-small-attempt3.in", "r", stdin);
	freopen_s(&output, "B-small-attempt3.out", "w", stdout);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++){
		int barbers[1000];
		int times[1000] = { 0 };
		int B;
		cin >> B;

		int N;
		cin >> N;

		for (int j = 0; j < B; j++){
			cin >> barbers[j];
		}
		
		int l = 1;
		int sum = 0;
		for (int j = 0; j < B; j++){
			l = lcm(l, barbers[j]);
		}
		
		for (int j = 0; j < B; j++){
			sum += l / barbers[j];
		}

		//cout << "l = " << l << endl;
		//cout << "sum = " << sum << endl;

		N = N % sum;
		if (N == 0) N = sum;

		//cout << "N = " << N << endl;
		
		int q = 0;		
		int answer = 1;
		while (q < N){
			
			int min = *min_element(times, times + B);
			//cout << min << endl;
			for (int j = 0; j < B; j++){
				if (min == times[j]){
					q++;
					if (q == N){
						answer = j+1;
						break;
					}
					times[j] = barbers[j];
				} else {
					times[j] -= min;
				}
			}
		}

		cout << "Case #" << i << ": " << answer << endl;
	}

	//system("pause");
}