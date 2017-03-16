#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define N 3456
#define pb push_back
#define mp make_pair
#define x first.first
#define y first.second
typedef long long ll;
typedef pair<pair<ll,ll>,int> pnt;


int t, n, ans[N], ans2[N], bst;
pnt ps[N], bpnt;
ll cp(pnt a, pnt b, pnt c) {
	return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}
ll dst(pnt a, pnt b) {
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
bool cmp(pnt a, pnt b) {
	if (a.second == bst) return true;
	if (b.second == bst) return false;
	return cp(bpnt, a, b) > 0;
}
pnt ref;
bool cmp2(pnt a, pnt b) {
	return cp(a, ref, b) > 0;
}
int main() {
	freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	scanf("%d", &t);
	fo(tc,1,t+1) {
		printf("Case #%d:\n", tc);
		scanf("%d", &n);
		fo(i,0,n) ans[i] = ans2[i] = 0;
		fo(i,0,n) {
			scanf("%lld %lld", &ps[i].x, &ps[i].y);
			ps[i].second = i;
		}
		bst = 0;
		fo(i,1,n) if (ps[i].y < ps[bst].y || (ps[i].y == ps[bst].y && ps[i].x < ps[bst].x)) bst = i;
		bpnt = ps[bst];
		sort(ps, ps+n, cmp);
		ans[bst] = 0;
		fo(i,1,n) {
			vector<pnt> lft, rht;
			ref = ps[i];
			fo(j,0,n) if (j != i) {
				if (ps[j].second == bst) rht.pb(ps[j]);
				else if (cp(bpnt, ref, ps[j]) < 0) rht.pb(ps[j]);
				else if (cp(bpnt, ref, ps[j]) > 0) lft.pb(ps[j]);
				else if (dst(bpnt, ref) < dst(bpnt, ps[j])) lft.pb(ps[j]);
				else rht.pb(ps[j]);
			}
			sort(lft.begin(), lft.end(), cmp2);
			sort(rht.begin(), rht.end(), cmp2);
			int ut = -1; 
			ans[ps[i].second] = min(lft.size(), rht.size());
			printf("%lld %lld %d %d\n", ps[i].x, ps[i].y, lft.size(), rht.size());
			fo(j,0,lft.size()) printf("%lld %lld\n", lft[j].x, lft[j].y);
			fo(j,0,rht.size()) printf("%lld %lld\n", rht[j].x, rht[j].y);
			fo(j,0,rht.size()) {
				while (ut+1 < lft.size() && cp(rht[j], ref, lft[ut+1]) >= 0) ut++;
				ans[ps[i].second] = min(ans[ps[i].second], int(j + lft.size() - ut - 1));
			}
		}
		fo(i,0,n) printf("%d\n", ans[i] + ans2[i]);
	}

	return 0;
}