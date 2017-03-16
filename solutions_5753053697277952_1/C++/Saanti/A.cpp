#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

#define MINX(a, b) ((a) < (b) ? (a) : (b));
#define MAX(a, b) ((a) > (b) ? (a) : (b));

typedef unsigned long long ulng;
typedef signed long long slng;
typedef unsigned int uint;
typedef signed int sint;

int findmax(int *a, int N)
{
	int max = -1, maxi = -1;
	for (int i = 0; i < N; i++) {
		if (a[i] > max) {
			max = a[i];
			maxi = i;
		}
	}
	return maxi;
}

void solve()
{
	int N, m1, m2;
	cin >> N;
	int *a = new int[N];
	slng sum = 0;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
		sum += a[i];
	}
	while (sum) {
		int m1 = findmax(a, N);
		assert(m1 > -1 && a[m1]);
		cout << (char)('A' + m1);
		a[m1]--;
		sum--;
		if (sum == 0)
			break;
		int m2 = findmax(a, N);
		assert(m2 > -1 && a[m2]);
		if (a[m2] > sum - a[m2]) {
			cout << (char)('A' + m2);
			a[m2]--;
			sum--;
		}
		cout << " ";
	}
	
	delete[] a;
}

int main()
{
	int c;
	cin >> c;
	for (int i = 1; i <= c; i++) {
		cout << "Case #" << i << ": ";
		solve();
		cout << "\n";
	}
}
