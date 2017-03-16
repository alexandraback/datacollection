#include <iostream>
#include "stdio.h"

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


int main() {
	int t;
	cin >> t;

	int n, b;
	int m[1024];
	for (int tcount = 1; tcount <= t; ++tcount) {
		cin >> b >> n;

		cin >> m[0];
		int alcm = m[0];
		for (int i = 1; i < b; ++i) {
			cin >> m[i];
			alcm = lcm(alcm, m[i]);
		}
		
		int roundPeople = 0;
		for (int i = 0; i < b; ++i) {
			roundPeople += alcm / m[i];
		}

		n = n % roundPeople;
		if (n == 0)
			n = roundPeople;
		
		if (n <= b) {
			cout << "Case #" << tcount << ": " << n << endl;
			continue;
		}

		int wait[1024];

		for (int i = 0; i < b; ++i) {
			wait[i] = m[i];
		}

		int tminpos;
		for (int i = b+1; i <= n; ++i) {
			int tmin = 10000000;
			tminpos = -1;

			for (int j = 0; j < b; ++j) {
				if (wait[j] < tmin) {
					tmin = wait[j];
					tminpos = j;
				}
			}
			for (int j = 0; j < b; ++j) {
				wait[j] -= tmin;
			}
			wait[tminpos] = m[tminpos];
		}

		cout << "Case #" << tcount << ": " << tminpos + 1 << endl;
	}

	return 0;
}