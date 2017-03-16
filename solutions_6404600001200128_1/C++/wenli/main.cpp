#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		long long int *m = new long long int[N];
		for (int i = 0; i < N; i++)
			cin >> m[i];
		
		long long int result1 = 0;
		for (int i = 1; i < N; i++)
			if (m[i] < m[i-1])
				result1 += m[i-1]-m[i];
		
		double result2 = 0;
		double rate = 0;
		for (int i = 1; i < N; i++)
			if ((m[i-1]-m[i])/10.0 > rate)
				rate = (m[i-1]-m[i])/10.0;
		for (int i = 1; i < N; i++)
			if (m[i-1] >= 10*rate)
				result2 += 10*rate;
			else
				result2 += m[i-1];
		
		cout << "Case #" << t+1 << ": " << result1 << " " << (long long int)(round(result2)) << endl;
		
		delete[] m;
	}

	return 0;
}
