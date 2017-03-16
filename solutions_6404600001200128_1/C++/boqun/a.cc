#include <iostream>

using namespace std;

int m[1000];
int main()
{
	int T, N;
	cin >> T;
	for (int n = 1; n <= T; n++) {
		cin >> N;
		int m1 = 0;
		int m2 = 0;
		int speed = 0;
		for (int i = 0; i < N; i++)
			cin >> m[i];

		for (int i = 0; i < N - 1; i++) {
			if (m[i] > m[i+1]) {
				m1 += m[i] - m[i+1];
				speed = max(speed, m[i] - m[i+1]);
			}
		}

		for (int i = 0; i < N - 1; i++) {
			m2 += min(speed, m[i]);	
		}

		


		cout << "Case #" << n << ": " << m1 << " " << m2 << endl;
	}
	return 0;
}
