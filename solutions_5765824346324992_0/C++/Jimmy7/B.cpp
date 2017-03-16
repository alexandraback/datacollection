#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;

int N,B;
int M[1500];

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

int stuff() {
	int minDec = 500000;
	for (int i = 0 ; i < B; i++) {
		cin >> M[i];
		minDec = min(minDec,M[i]);
	}
	if (N <= B)
		return N;
	int result = 1;
	for (int i = 0; i < B; i++) {
		result *= M[i];
	}
	int totalServed = 0;
	for (int i = 0; i < B; i++) {
		totalServed += result/M[i];
	}
	N = N%totalServed;
	if (N <= B)
		return N;
	int started = B;
	int av[1500];
	for (int i = 0; i < B; i++) {
		av[i]=M[i];
	}
	for (int i = 0; i < N && started <= N; i++) {
		for (int j = 0; j < B; j++) {
			av[j] -= minDec;
			if (av[j] <= 0) {
				started++;
				if (started==N)
					return j+1;
				av[j] += M[j];
			}
		}
	}
	return B;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	cin >> T;
	for (int t = 0 ; t < T; t++) {
		cin >> B >> N;
		cout << "Case #" << t+1 << ": " << stuff() << endl;
	}
	return 0;
}