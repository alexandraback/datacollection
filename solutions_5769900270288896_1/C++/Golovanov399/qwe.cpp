#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

void solve(){
	int r, c, n;
	cin >> r >> c >> n;
	int N = r * c;
	if (n <= (N + 1) / 2){
		puts("0");
		return;
	}
	n = N - n;
	if (r == 1 || c == 1){
		int m2 = (r * c - 2) / 2;
		int ans = r * (c - 1) + c * (r - 1);
		if (n <= m2)
			ans -= n * 2;
		else
			ans -= m2 * 2 - (n - m2) * 1;
		cout << ans << "\n";
		return;
	}
	int m4 = ((r - 2) * (c - 2) + 1) / 2;
	int m3 = r - 1 + c - 1;
	if (r % 2 && c % 2)
		m3 -= 4;
	else
		m3 -= 2;
	int ans = r * (c - 1) + c * (r - 1);
	if (n <= m4)
		ans -= n * 4;
	else if (n <= m4 + m3)
		ans -= m4 * 4 + (n - m4) * 3;
	else
		ans -= m4 * 4 + m3 * 3 + (n - m4 - m3) * 2;
	int mans = ans;

	m4 = (r - 2) * (c - 2) / 2;
	m3 = r - 1 + c - 1;
	if (r % 2 == 0 || c % 2 == 0)
		m3 -= 2;
	ans = r * (c - 1) + c * (r - 1);
	if (n <= m4)
		ans -= n * 4;
	else if (n <= m4 + m3)
		ans -= m4 * 4 + (n - m4) * 3;
	else
		ans -= m4 * 4 + m3 * 3 + (n - m4 - m3) * 2;

	cout << min(ans, mans) << "\n";
}

int main(){

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		printf("Case #%d: ", i + 1);
		solve();
		cerr << "Test #" << i + 1 << " completed\n";
	}

	return 0;
}