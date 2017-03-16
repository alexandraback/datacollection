#include <iostream>

using namespace std;

long long a[10000];

int main()
{
    int T, N;
    cin >> T;
    for (int ca = 1; ca <= T; ca++)
    {
	cin >> N;
	for (int i = 0; i < N; i++)
	    cin >> a[i];
	long long a1 = 0;
	long long maxv = 0;
	for (int i = 1; i < N; i++)
	    if (a[i - 1] > a[i])
	    {
		a1 += a[i - 1] - a[i];
		if (a[i - 1] - a[i] > maxv)
		    maxv = a[i - 1] - a[i];
	    }
	long long a2 = 0;
	for (int i = 0; i < N - 1; i++)
	    if (a[i] > maxv)
		a2 += maxv;
	    else
		a2 += a[i];
	cout << "Case #" << ca << ": " << a1 << ' ' << a2 << endl;
    }
}
