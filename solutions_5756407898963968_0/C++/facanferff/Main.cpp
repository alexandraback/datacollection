#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sz(v) (int)v.size()
#define all(c) (c).begin(), (c).end()

typedef long long int ll;

// %I64d for ll in CF

int main() {
	int t;
	scanf("%d", &t);
	int q = 1;
	while (t--) {
		int r1;
		scanf("%d", &r1);
		bool used[20];
		memset(used, false, sizeof used);
		for (int i = 0; i < 16; i++) {
			int c;
			scanf("%d", &c);
			if (i / 4 + 1 == r1) used[c]++;
		}

		int r2;
		scanf("%d", &r2);
		set<int> cards;
		for (int i = 0; i < 16; i++) {
			int c;
			scanf("%d", &c);
			if (i / 4 + 1 == r2 && used[c]) cards.insert(c);
		}

		printf("Case #%d: ", q);
		if (cards.size() == 1) printf("%d\n", *cards.begin());
		else if (cards.size() == 0) printf("Volunteer cheated!\n");
		else printf("Bad magician!\n");

		q++;
	}
	return 0;
}
