#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define pii pair<int,int>

ofstream fout ("1AB.out");
ifstream fin ("1AB.in");

ll B,N;
ll M[1005];

int gcd(int a,int b) {
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	while (a != 0) {
		int temp = a;
		a = b%a;
		b = a;
	}
	return b;
}

int check(ll t) {
	ll tot = B;
	for (int i = 0; i < B; i++) tot += t/M[i];
	if (tot < N) return false;
	return true;
}

int main() {
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Working on Case #" << t << endl;
		fin >> B >> N;
		for (int i = 0; i < B; i++) fin >> M[i];
		ll low = 0;
		ll high = 100000000000000;
		while (high-low > 0) {
			ll mid = (high+low)/2;
			if (check(mid)) high = mid;
			else low = mid+1;
		}
		//cout << "Case #" << t << "; " << low << "\n";
		if (N <= B) {
			fout << "Case #" << t << ": " << N << "\n";
			continue;
		}
		for (int i = 0; i < B; i++) N -= (low-1)/M[i];
		N-=B;
		int ans;
		for (ans = 0; ans < B && N > 0; ans++) N -= (low%M[ans] == 0);
		fout << "Case #" << t << ": " << ans << "\n";
	}
    return 0;
}