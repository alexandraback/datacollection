#include <cmath>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int B, N;
		cin >> B >> N;
		int *M = new int[B];
		for (int b = 0; b < B; b++)
			cin >> M[b];
		
		int period = 1;
		for (int b = 0; b < B; b++)
			period = lcm(period, M[b]);
		int pcount = 0;
		for (int b = 0; b < B; b++)
			pcount += period/M[b];
		
		N %= pcount;
		if (N == 0)
			N = pcount;
		
		int *R = new int[B];
		for (int b = 0; b < B; b++)
			R[b] = 0;
		int choice;
		while (N > 0) {
			choice = -1;
			for (int b = 0; b < B; b++)
				if (R[b] == 0) {
					choice = b;
					R[b] = M[b];
					break;
				}
			if (choice == -1) {
				int r = 100000;
				for (int b = 0; b < B; b++)
					if (R[b] < r)
						r = R[b];
				for (int b = 0; b < B; b++)
					R[b] -= r;
			} else {
				N--;
			}
		}
		cout << "Case #" << t+1 << ": " << choice+1 << endl;
		delete[] R;
		
		delete[] M;
	}

	return 0;
}
