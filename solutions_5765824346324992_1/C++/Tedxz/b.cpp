#include <cstdio>
#include <iostream>

using namespace std;

const int MAX_B = 1007;

typedef long long ll;

int T;
int m[MAX_B];
ll b, n;

bool check(ll time, int num) {
    ll sum = 0;
    for (int i = 0; i < b; ++i) {
        sum += (time / m[i]) + 1;
    }
    return sum >= num;
}



int calc(ll time) {
    int res = 0;

    ll last = 0;
	for (int i = 0; i < b; ++i) {
		last += (time / m[i]) + 1;
		if (0 == time % m[i])
			--last;
	}
	last = n - last;

	for (int i = 0; i < b; ++i) {
		if (time % m[i] == 0) {
            --last;
			if (last == 0) {
				res = i + 1;
				break;
			}
		}
	}
    return res;
}

int main() {
     freopen("B-large.in", "r", stdin);
     freopen("b.out", "w", stdout);

    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        cin >> b >> n;
        for (int i = 0; i < b; ++i) {
            cin >> m[i];
        }

        ll max_time = 100000 * n;
        ll l = 0, r = max_time, mid = (l + r) / 2;
        for (; l < r; mid = (l + r) / 2) {
            if (check(mid, n)) r = mid;
            else l = mid + 1;
        }

        int ans;
        ans = calc(l);

        cout << "Case #" << cs << ": " << ans << endl;
    }

    return 0;
}
