#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<iomanip>
#include <functional>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int INF = 1 << 28;
//cout << fixed << std::setprecision(9)
//memset(a, 0, sizeof(a));
//--------------------------

int t, n;
int p[26];
double r[26];

void calc(int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += p[i];
	}

	for (int i = 0; i < n; i++) {
		r[i] = (double)p[i] / (double)sum;
	}
}

void solve(int n)
{
	while (1) {
		calc(n);

		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += p[i];
		}
		if (sum == 3) {
			int i = 0;
			while (!p[i]) i++;
			p[i]--;
			cout << " " << (char)(i + 'A');
			continue;
		}

		double max = 0.0;
		int maxi = 0;
		for (int i = 0; i < n; i++) {
			if (max < r[i]) {
				max = r[i];
				maxi = i;
			}
		}
		if (max == 0.0) break;
		else {
			p[maxi]--;
			cout << " " << (char)(maxi + 'A');
		}

		calc(n);
		max = 0.0;
		maxi = 0;
		for (int i = 0; i < n; i++) {
			if (max < r[i]) {
				max = r[i];
				maxi = i;
			}
		}
		if (max == 0.0) break;
		else {
			p[maxi]--;
			cout << (char)(maxi + 'A');
		}
	}
	return;
}



int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		memset(p, 0, sizeof(p));
		for (int j = 0; j < n; j++) {
			cin >> p[j];
		}
		cout << "Case #" << i + 1 << ":";
		solve(n);
		cout << endl;
	}

	return 0;
}