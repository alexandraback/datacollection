#include <iostream>

using namespace std;

long long b[2000];

int main()
{
    int T, N, B, M;
    cin >> T;
    for (int ca = 1; ca <= T; ca++)
    {
	cin >> B >> M;
	for (int i = 0; i < B; i++)
	    cin >> b[i];
	long long l = 0, r = 10000000000000000LL;
	while (l < r)
	{
	    long long mid = (l + r) >> 1;
	    long long cu = 0;
	    for (int i = 0; i < B; i++)
		cu += mid / b[i] + 1;
	    if (cu >= M)
		r = mid;
	    else
		l = mid + 1;
	}
	long long ans = 0, cu = 0;
	for (int i = 0; i < B; i++)
	    cu += (l - 1) / b[i] + 1;
	for (int ct = cu; ct < M; ct++)
	{
	    for (; ans < B; ans++)
		if (l % b[ans] == 0)
		    break;
	    ans++;
	}
	cout << "Case #" << ca << ": " << ans << endl;
    }
}

