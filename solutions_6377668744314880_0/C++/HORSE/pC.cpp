#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

const int N_MAX = 16;
struct pnt{
	ll x, y;
} tree[N_MAX];

vector<int> vec, up, down;

bool cmp(int a, int b){
	if(tree[a].x != tree[b].x)
		return tree[a].x < tree[b].x;
	else
		return tree[a].y < tree[b].y;
}

ll crs(pnt s, pnt e1, pnt e2){
	e1.x -= s.x, e1.y -= s.y;
	e2.x -= s.x, e2.y -= s.y;
	return e1.x * e2.y - e2.x * e1.y;
}

void convex(){
	up.clear(), down.clear();
	if(vec.size() <= 3){
		for(int i = 0; i < vec.size(); i++)
			up.push_back(vec[i]);
		return;
	}
	sort(vec.begin(), vec.end(), cmp);
	up.push_back(vec[0]), down.push_back(vec[0]);
	for(int i = 1; i < vec.size(); i++){
		while(up.size() >= 2){
			pnt st = tree[up[up.size() - 2]], ed = tree[up[up.size() - 1]], cur = tree[vec[i]];
			if(crs(st, ed, cur) < 0)
				up.pop_back();
			else
				break;
		}
		up.push_back(vec[i]);
		while(down.size() >= 2){
			pnt st = tree[down[down.size() - 2]], ed = tree[down[down.size() - 1]], cur = tree[vec[i]];
			if(crs(st, ed, cur) > 0)
				down.pop_back();
			else
				break;
		}
		down.push_back(vec[i]);
	}
	return;
}

int ans[N_MAX];

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("pC_small.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int cnt = 1; cnt <= t; cnt ++){
		int n;
		scanf("%d", &n);
		int left = 0;
		for(int i = 0; i < n; i++)
			scanf("%lld%lld", &tree[i].x, &tree[i].y);
		fill(ans, ans + n, n);

		for(int i = 0; i < (1 << n); i++){
			vec.clear();
			int tmp = n;
			for(int j = 0; j < n; j++){
				if((i >> j) & 1){
					tmp --;
					vec.push_back(j);
				}
			}
			//puts("oops");
			convex();
			for(int j = 0; j < up.size(); j++)
				ans[up[j]] = min(ans[up[j]], tmp);
			for(int j = 0; j < down.size(); j++)
				ans[down[j]] = min(ans[down[j]], tmp);
		}
		printf("Case #%d: \n", cnt);
		for(int i = 0; i < n; i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}
