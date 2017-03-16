#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll arr[6];
ll n;
ll nb;
ll sim[6];

ll lcm(ll a, ll b) {
	return a*b/__gcd(a,b);
}



ll get_ind() {
	ll minn = sim[0];
	for (int i = 1; i < nb; i++) {
		minn = min(sim[i],minn);
	}
	for (int i = 0; i< nb; i++) {
		sim[i]-= minn;
	}
	for (int i = 0; i < nb; i++) {
		if (sim[i] == 0) {
			sim[i] = arr[i];
			return i+1;
		}
	}
}

void sim1() {
	for (ll i = 1; i < n; i++) {
		get_ind();
	}
	cout << get_ind() << endl;
}


int main() {
	freopen("B-small-attempt9.in","r",stdin);
	freopen("output1.txt","w",stdout);
	ll t;
	cin >> t;
	for (int cnt = 1; cnt <= t; cnt++) {
		cout << "Case #" << cnt << ": ";
		cin >> nb;
		cin >> n;
		for (int i = 0; i < nb; i++) {
			cin >> arr[i];
			sim[i] = arr[i];
		}
		ll mm = lcm(arr[0],arr[1]);
		for (ll i = 2; i < nb; i++) {
			mm = lcm(mm,arr[i]);
		}
		ll sum = 0;
		for (ll i = 0; i < nb; i++) {
			sum+= mm/arr[i];
		}
		n%= sum;
		if (n <= nb) {
			if (n == 0)
				cout << nb << endl;
			else
				cout << n << endl;
			continue;
		}
		n-= nb;
		sim1();
	}
	return 0;
}
