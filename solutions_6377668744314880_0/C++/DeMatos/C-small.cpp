#include <bits/stdc++.h>

using namespace std;

#define MAXT 100010000000000LL

vector<pair<int, int> > points;

int main() {
	freopen("inputCsmall.txt", "r", stdin);
	freopen("outputCsmall.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int test = 1; test<=t; test++) {
		int n;
		points.clear();
		scanf("%d", &n);
		for(int i = 0; i<n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			points.push_back(make_pair(x, y));
		}
		printf("Case #%d:\n", test);
		for(int i = 0; i<n; i++) {
			int best = 1000000000;
			for(int j = 0; j<n; j++) {
				int neg = 0, pos = 0;
				if(i != j) {
					for(int k = 0; k<n; k++) {
						pair<int, int> p1, p2;
						p1 = make_pair(points[j].first - points[i].first, points[j].second - points[i].second);
						p2 = make_pair(points[k].first - points[i].first, points[k].second - points[i].second);
						long long aux = (long long)p1.first*p2.second-(long long)p1.second*p2.first;
						//if(test == 2 && i == 4) printf("p1:(%d %d) p2:(%d %d)", p1.first, p1.second, p2.first, p2.second);
						//if(test == 2 && i == 4) printf("j, k, aux: %d %d %lld\n", j, k, aux);
						if(aux > 0) pos++;
						else if(aux<0) neg++;
					}
					//if(test == 2) printf("->%d %d\n", pos, neg);
					best = min(best, min(pos, neg));
				}
			}
			printf("%d\n", n==1?0:best);
		}
	}
	return 0;
}
