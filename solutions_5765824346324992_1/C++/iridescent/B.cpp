#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = 1e17;

int B;
ll N;
int M[1005];

int main()
{
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++)
	{
		cin >> B >> N;
		for(int i = 0; i < B; i++) cin >> M[i];
		ll low = -1, high = inf;
		while(low + 1 < high)
		{
			ll mid = (low + high) / 2;
			ll num = 0;
			for(int i = 0; i < B; i++)
				num += (mid + M[i]) / M[i];
			if(num < N) low = mid;
			else high = mid;
		}
		ll before = 0;
		for(int i = 0; i < B; i++)
			before += (low + M[i]) / M[i];
		if(!(before < N)) {
			cout << test << ' ' << before << ' ' << N << endl; cout << B << ' ' << N << endl; for(int i = 0; i < B; i++) cout << M[i] << ' '; return 0;}
		ll remain = N - before;
		int target = -1;
		for(int i = 0; i < B; i++)
			if(high % M[i] == 0)
			{
				remain--;
				if(remain == 0) target = i + 1;
			}
		assert(target != -1);
		//cout << "time = " << high << endl;
		cout << "Case #" << test << ": " << target << endl;
	}
}
