#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <assert.h>
#include <time.h>

using namespace std;

int gcd(int a, int b){
	return (a == 0 ? b : gcd(b% a, a));
}

int lcm(int a, int b){
	return a / gcd(a, b) * b;
}
const int INF = 1e9;
int main(){
	int t;
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	scanf("%d", &t);
	for (int te = 0; te < t; te++){
		int n, b;
		scanf("%d %d", &b, &n);
		if (b == 1){
			int ans = 1;
			printf("Case #%d: %d\n", te + 1, ans);
			continue;
		}
		vector<int> a(b);
		for (int i = 0; i < b; i++){
			scanf("%d", &a[i]);
		}
		int g = a[0];
		int p = a[0];
		for (int i = 1; i < b; i++){
			g = gcd(g, a[i]);
			p *= a[i];

		}
		p /= g;
		//n %= (p * b);
		//cout << p << " " << n << endl;
		vector<int> r(b, 0);
		int last = -1;
		int vv = -1;
		vector<int> d;
		for (int i = 0; ; i++){
			if (i > 1000000){
				assert(1 == 0);
			}
			int idx = -1;
			int mn = INF;
			for (int j = 0; j < b; j++)
				if (r[j] < mn){
					mn = r[j];
					idx = j;
				}
			r[idx] = r[idx] + a[idx];
			d.push_back(idx);
			int q = r[0];
			bool ok = true;
			for (int j = 1; j < b; j++)
				if (r[j] != q){
					ok = false;
					break;
				}
			if (ok){
				vv = i + 1;
				break;
			}
			//cout << "i = " << i << " d[i] = " << d[i] << endl;
		}
		int tt = n % vv;
		if (tt == 0) tt = vv;
		//cout << tt << " " << d[tt - 1] << endl;
		last = d[tt - 1];
		printf("Case #%d: %d\n", te + 1, last + 1);
	}
}