#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;

int my;
int num;
vector<int> tab;

bool possible(long long k) {
	long long sum = 0;
	for (int i = 0; i < tab.size(); i++) {
		sum += k / tab[i];
	}
	return sum >= my - 1;
}

int main() {
	int tests;
	scanf("%d",&tests);
	for(int test = 1; test <= tests; test++) {
		scanf("%d %d",&num,&my);
		tab.clear();
		for (int i =0; i < num;i++) {
			int t;
			scanf("%d",&t);
			tab.push_back(t);
		}
		long long a = 0, b = 1e15, c = 0;
		while(true) {
			c = (a + b) / 2;
			if(possible(c)) {
				b = c;
			} else {
				a = c;
			}
			if (b - a < 2) {
				if (possible(a)) c = a;
				if(possible(b)) c = b;
				break;
			}
		}		

		int sum = 0;
		for (int i = 0; i < tab.size(); i++) {
			sum += c / tab[i];
		}
		int todo = my - sum;
		if (todo <= 0) {
			c--;sum = 0;
			for (int i = 0; i < tab.size(); i++) {
				sum += c / tab[i];
			}
			todo = my - sum;
		}
		vector<pair<int,int> > v;
		for (int i = 0; i < tab.size(); i++) v.push_back(make_pair((tab[i] - c % tab[i])%tab[i], i));
		sort(v.begin(), v.end());

		int res = v[todo-1].second+1;
		if(num == 1) res = 1;

		printf("Case #%d: %d\n", test, res);
	}
	return 0;
}