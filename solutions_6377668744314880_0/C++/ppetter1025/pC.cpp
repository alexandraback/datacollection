#include <bits/stdc++.h>

using namespace std;

const int N = 3000 + 10;
const double EPS = 1e-5;

struct PT {
	double x, y, sita;

	PT operator-(const PT &b) const {
		return (PT) {x-b.x, y-b.y, atan2(y-b.y, x-b.x)};
	}

	double operator^(const PT &b) const {
		return x*b.y - y*b.x;
	}
} p[N];
vector<PT> sita;
int n;

bool cmp(PT a, PT b) {
	return a.sita < b.sita;
}

int solve(int k) {
	if(n <= 3)	return 0;

	for(int i = 0; i < n; i++) {
		if(i == k)	continue;
		sita.push_back( (PT) {p[i].x, p[i].y, atan2(p[i].y-p[k].y, p[i].x-p[k].x) } );
	}
	sort(sita.begin(), sita.end(), cmp);
	int tmp = sita.size();
	for(int i = tmp; i < tmp*2; i++)
		sita.push_back(sita[i-tmp]);

	int ret = n*10;
	for(int i = 0; i < n; i++) {
		int l = 0, r = 0;
		if(i == k)	continue;
		for(; l < sita.size()/2; l++) {
			r = max(l+1, r);
			while(r-l < sita.size()/2-1 && r < sita.size() && ((sita[l]-p[k])^(sita[r]-p[k])) > 0)	r++;

			ret = min(ret, min(r-l-1, (int)sita.size()/2 - (r-l) ));
		}
	}
	sita.clear();
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++)	scanf("%lf%lf", &p[i].x, &p[i].y);

		printf("Case #%d:\n", kase);
		for(int i = 0; i < n; i++)	printf("%d\n", solve(i));
	}

	return 0;
}
