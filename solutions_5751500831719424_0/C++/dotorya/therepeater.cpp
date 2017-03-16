#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> N[105];
vector <char> C[105];
int t_n[105];
int n;
int abs(int a) {
	if(a < 0) a = -a;
	return a;
}
int get_ans() {
	sort(t_n+1, t_n+n+1);
	int min_ans, tmp;
	int i, j;
	for(i = t_n[1]; i <= t_n[n]; i++) {
		tmp = 0;
		for(j = 1; j <= n; j++) tmp += abs(t_n[j]-i);
		if(i == t_n[1] || tmp < min_ans) min_ans = tmp;
	}
	return min_ans;
}
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test_no, T, i, j, tmp, Ans;
	char s[150];
	scanf("%d", &T);
	for(test_no = 1; test_no <= T; test_no++) {
		for(i = 1; i <= 100; i++) {
			N[i].clear();
			C[i].clear();
		}
		Ans = 0;
		scanf("%d", &n);
		for(i = 1; i <= n; i++) {
			for(j = 0; j <= 100; j++) s[j] = 0;
			scanf("%s", s);
			for(j = 0; s[j] != 0; j+=tmp) {
				tmp = 1;
				while(1) {
					if(s[j+tmp] != s[j]) break;
					tmp++;
				}
				N[i].push_back(tmp);
				C[i].push_back(s[j]);
			}
		}
		for(i = 2; i <= n; i++) if(C[i].size() != C[1].size()) break;
		if(i != n+1) {
			printf("Case #%d: Fegla Won\n", test_no);
			continue;
		}
		for(i = 0; i < C[1].size(); i++) {
			for(j = 2; j <= n; j++) if(C[j][i] != C[1][i]) break;
			if(j != n+1) break;
		}
		if(i != C[1].size()) {
			printf("Case #%d: Fegla Won\n", test_no);
			continue;
		}
		for(i = 0; i < C[1].size(); i++) {
			for(j = 1; j <= n; j++) t_n[j] = N[j][i];
			Ans += get_ans();
		}
		printf("Case #%d: %d\n", test_no, Ans);
	}
	return 0;
}