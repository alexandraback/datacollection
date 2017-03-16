#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

struct duty {
	ll m;
	int p;
	ll o;
};

bool operator<(const duty& lhs, const duty& rhs) {
	if( lhs.o == rhs.o ) {
		return lhs.p > rhs.p;
	}
	return lhs.o > rhs.o;
}

bool sortM(const duty& lhs, const duty& rhs) {
	return lhs.o < rhs.o;
}

int main() {
	int t;
	cin >> t;
	for(int dt=1; dt<=t; dt++) {
		int b;
		ll n;
		cin >> b >> n;
		vector<duty> m(b);
		rep(i,b) {
			cin >> m[i].m;
			m[i].p = i+1;
			m[i].o = m[i].m;
		}
		ll lcm = m[0].m;
		for(int i=1; i<b; i++) {
			lcm = (lcm*m[i].m) / __gcd(lcm, m[i].m);
		}
		ll lcm_n = 0;
		for(int i=0; i<b; i++) {
			lcm_n += lcm / m[i].m;
		}
//		cout << "lcm = " << lcm << endl;
//		cout << "lcm_n = " << lcm_n << endl;
		n -= b;
		n %= lcm_n;
		if(n == 0) {
			sort(m.begin(), m.end(), sortM);
			cout << "Case #" << dt << ": " << m[m.size()-1].p << endl;
		} else {
			priority_queue<duty> que;
			for(int i=0; i<m.size(); i++) {
				que.push(m[i]);
			}
			ll turn = que.top().o;
			ll preO = turn;
//			cout << "n = " << n << endl;
			while(n>0) {
				duty d = que.top();
				que.pop();
//				cout << "pop " << d.p << endl;
				n--;
				if(n <= 0) {
					cout << "Case #" << dt << ": " << d.p << endl;
					break;
				}
				if(preO != d.o) {
					preO = d.o;
					turn = d.o;
				}
//				cout << "d.o : " << d.o << " -> ";
				d.o = d.m + turn;
//				cout << d.o << endl;
				que.push(d);
			}
		}
	}
	return 0;
}
