#include <bits\stdc++.h>
typedef long long ll;
using namespace std;
struct pt {
	ll x, y;
};

bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}
bool nocw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0;
}
bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}
bool noccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) >= 0;
}
void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || nocw (p1, a[i], p2)) {
			while (up.size()>=2 && ccw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || noccw (p1, a[i], p2)) {
			while (down.size()>=2 && cw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}
int t;
int n;
pt a[20];
int ans[20];
map<pair<int, int>, int> mp;
int main(){
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int qr = 0; qr < t; ++qr){
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> a[i].x >> a[i].y;
            mp[make_pair(a[i].x, a[i].y)] = i;
            ans[i] = 20;
        }
        for(int mask = 1; mask < (1 << n); ++mask){
            int cnt = 0;
            vector<pt> cur;
            for(int i = 0; i < n; ++i){
                if((1 << i) & mask){
                    cur.push_back(a[i]);
                }
                else{
                    cnt++;
                }
            }
            convex_hull(cur);
            //cnt = n - cur.size();
            for(auto it : cur){
                int id = mp[make_pair(it.x, it.y)];
                ans[id] = min(ans[id], cnt);
            }
        }
        cout << "Case #" << qr + 1 << ":\n";
        for(int i = 0; i < n; ++i){
            cout << ans[i] << "\n";
        }
    }
}
