#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool occ[20][20];

int t;
ll r,c,n;

ll cost(int i, int j) {
	if (!occ[i][j])
		return -500;
	ll res = 0;
	if (i > 0) {
		if (occ[i-1][j])
			res++;
	}
	if (i+1 < r) {
		if (occ[i+1][j])
			res++;
	}
	if (j > 0) {
		if (occ[i][j-1])
			res++;
	}
	if (j + 1 < c) {
		if (occ[i][j+1])
			res++;
	}
	return res;
}

ll add() {
	int mn = -500;
	int mni = 0;
	int mnj = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (cost(i,j) > mn) {
				mn = cost(i,j);
				mni = i;
				mnj = j;
			}
		}
	}
	occ[mni][mnj] = false;
	return mn;
}

int count() {
	ll res = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i+1 < r)
				res++;
			if (j+1 < c)
				res++;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	freopen("B-small-attempt2.in","r",stdin);
	freopen("a2.out","w",stdout);
	cin >> t;
	for (int cntt = 1; cntt <= t; cntt++) {
		memset(occ,false,sizeof occ);
		cout << "Case #" << cntt << ": ";
		cin >> r >> c >> n;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				occ[i][j] = true;
		}
		ll cnt_walls = count();
		ll res = cnt_walls;
		n = r*c-n;
		while(n--)
			res-= add();
		cout << res;
		cout << endl;
	}
	return 0;
}
