#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define ST first
#define ND second

using namespace std;

const int MX = 111;

int n, L;
char s[MX];
vector<pair<char, int> > A[MX];

vector<pair<char, int> > pre() {
	int l = strlen(s+1);
	char c = s[1];
	int ile = 1;
	
	vector<pair<char, int> > ret;
	
	for (int i = 2; i <= l; i++) {
		if (s[i] != c) {
			ret.push_back(make_pair(c, ile));
			c = s[i];
			ile = 1;
		}
		else ile++;
	}
	
	ret.push_back(make_pair(c, ile));
	
	return ret;
}

bool fegla() {
	for (int i = 1; i <= n; i++) if (int(A[i].size()) != int(A[1].size())) return true;
	
	for (int i = 0; i < L; i++) for (int j = 1; j <= n; j++) if (A[j][i].ST != A[1][i].ST) return true;
	
	return false;
}

int get_opt(int u) {
	vector<int> c;
	for (int i = 1; i <= n; i++) c.push_back(A[i][u].ND);
	sort(c.begin(), c.end());
	
	return c[(int(c.size())-1)/2];
}

void solve(int testcase) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s+1);
		A[i] = pre();
	}
	
	L = int(A[1].size());
	
	if (fegla()) {
		printf("Case #%d: Fegla Won\n", testcase);
		return;
	}
	
	
	int W = 0;
	
	for (int i = 0; i < L; i++) {
		int k = get_opt(i);
		//printf("opt[%d] = %d\n", i, k);
		for (int j = 1; j <= n; j++) W += abs(A[j][i].ND - k);
	}
	
	printf("Case #%d: %d\n", testcase, W);
}

int main() {
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
	return 0;
}