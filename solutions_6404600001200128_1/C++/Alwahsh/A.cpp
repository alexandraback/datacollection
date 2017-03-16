#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll arr[1005];
ll res1, res2;
int n;

void calc1() {
	for (int i = 1; i < n; i++) {
		res1+= max(0LL,arr[i-1] - arr[i]);
	}
}

void calc2() {
	ll av = 0;
	for (int i = 1; i < n; i++) {
		av = max(av,arr[i-1]-arr[i]);
	}
	for (int i = 1; i < n; i++) {
		res2+= min(av,arr[i-1]);
	}
}

int main() {
	freopen("A-large.in","r",stdin);
	freopen("output2.txt","w",stdout);
	ll t;
	cin >> t;
	for (int cnt = 1; cnt <= t; cnt++) {
		cout << "Case #" << cnt << ": ";
		res1 = 0;
		res2 = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		calc1();
		calc2();
		cout << res1 << " " << res2;
		cout << endl;
	}
	return 0;
}
