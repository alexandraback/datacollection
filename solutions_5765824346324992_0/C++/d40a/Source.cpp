#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stack>

using namespace std;
#define LL long long
#define FILES freopen("input.txt" ,"r", stdin); freopen("output.txt", "w", stdout);
#define FASTER ios::sync_with_stdio(0);

const LL maxn = 2 * 1e5 + 1;

stack <LL> st;
vector <LL> inputData;
int main() {
	FILES;
	FASTER;
	LL T;
	cin >> T;
	for (LL test = 1; test <= T; test++) {
		int n;
		LL m_cnt;
		cin >> n >> m_cnt;
		vector <LL> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		LL l = 0, r = 1e15;
		LL t = 1e15;
		LL bcnt = 1e15;
		while (l <= r) {
			LL md = (l + r) >> 1;
			LL cnt = n;
			for (int i = 0; i < n; i++)
				cnt += md / a[i];
			if ( cnt >= m_cnt && t > md ) {
				bcnt = cnt;
				t = md;
				r = md - 1;
			}
			else
				l = md + 1;
		}

		vector <int> ids;
		for (int i = 0; i < a.size(); i++)
			if (t % a[i] == 0) ids.push_back(i);


		cout << "Case #" << test << ": ";
		cout << ids[ids.size() + m_cnt - bcnt - 1] + 1 << endl;
	}
}