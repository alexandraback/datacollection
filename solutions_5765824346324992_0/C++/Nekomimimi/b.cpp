#include <iostream>
using namespace std;

long long gcd( long long m, long long n )
{
	while(m!=n) {
		if (m>n) m = m - n;
		else         n = n - m;
	}
	return m;
}

long long lcm(long long m,long long n)
{

	return ((m / gcd(m, n)) * n); 
}

int main() {
	int N;
	cin >> N;
	for(int i=0;i<N;i++) {
		int B;
		long long N;

		cin >> B >> N;
		long long tlcm = 1;
		int m[B];

		for (int j=0;j<B;j++) {
			int tmp;
			cin >> tmp;
			tlcm = lcm(tlcm,tmp);
			m[j] = tmp;
		}
		long long loopTotal = 0;

		for (int j=0;j<B;j++) {
			loopTotal += tlcm / m[j];
		}

		int loopNRet = N / tlcm * loopTotal;

		N = N % loopTotal;


		int t=0;
		int bar = 0;
		if (N==0) {
			N=loopTotal;
		}

		while(true) {
			for (int j=0;j<B;j++) {
				if (t%m[j]==0) {
					N--;
					if (N == 0) {
						bar = j;
						goto loop_end;
					}
				}
			}
			t++;
		}
		loop_end:

		cout << "Case #" << i+1 << ": " << bar +1 << endl; 

	}
	return 0;
}