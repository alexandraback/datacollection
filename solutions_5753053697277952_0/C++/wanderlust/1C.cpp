#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
#define f0(i,N) for (int i=0; i< N; i++) 
#define f1(i,N) for (int i=1; i<=N; i++) 
int a[26], N, X, c; 

int getMax()
{
	int max = a[0] , maxi = 0;
	f1(i, 25) {
		if (a[i] > max) { max = a[i]; maxi = i; }
	}
	return maxi;
}

int major()
{
	f0(i, 26) if (a[i] * 2 > c) return 1;
	return 0;
}

void recur()
{
	if (c == 0) return;
	int m = getMax();
	a[m]--; c--;  cout << (char)('A' + m);
	m = getMax(); c--; a[m]--; 
	if (major()) { c++; a[m]++; }
	else { cout << (char)('A' + m); }
	cout << " ";
	recur();
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;
	f1(t, T)
	{
		cout << "Case #" << t << ": ";
		memset(a, 0, sizeof(a));
		cin >> N;
		f0(n, N) { cin >> X; a[n] += X; c += X; }
		recur();
		cout << endl;
	}
	return 0;
}