#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 2000;
long long T, n, b, ans, tot, a[N];
class Q{
public:
	long long lab, tim;
	bool operator<(const Q &rhs) const{
		return ((tim > rhs.tim) || (tim == rhs.tim && lab > rhs.lab));
	}
};
priority_queue<Q> q;
int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	cin >> T;
	for (long long Ti = 1; Ti <= T; ++Ti){
		cin >> b >> n;
		for (long long i = 1; i <= b; ++i) cin >> a[i];
		long long L = 0, R = 1000000000000000;
		for (; L + 1 < R; ){
			long long mid = (L + R) / 2;
			tot = 0;
			for (long long i = 1; i <= b; ++i) tot += (mid + a[i] - 1) / a[i];
			if (tot < n) L = mid;
			else R = mid;
		}
		while (!q.empty()) q.pop();
		//cout << L << "\n";
		tot = 0;
		for (long long i = 1; i <= b; ++i){
			Q tmp;
			tmp.lab = i;
			tmp.tim = (L + a[i] - 1) / a[i] * a[i];
			tot += (L + a[i] - 1) / a[i];
			q.push(tmp);
		}
		for (++tot; tot <= n; ++tot){
			Q tmp = q.top();
			//cout << tmp.lab << " " << tmp.tim << "\n";
			q.pop();
			tmp.tim += a[tmp.lab];
			q.push(tmp);
			if (tot == n) ans = tmp.lab;
		}
		cout << "Case #" << Ti << ": " << ans << "\n";
	}
	return 0;
}
