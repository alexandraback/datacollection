#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAXN 110

using namespace std;

int T, N, sol;
int len[MAXN], pos[MAXN];

char s[MAXN][MAXN];

vector <int> v; 

inline void init() {
	sol = 0;
	memset(pos, 0, sizeof pos);
}

void solve(int t) {

	init();
	printf("Case #%d: ", t);

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", s[i]);
		len[i] = strlen(s[i]);
	}
	
	while (true) {
	
		bool kraj = true; 
		int slovo = -1;
		v.clear();
			
		for (int i = 0; i < N; ++i) {
			
			if (pos[i] == len[i]){
				if (!kraj) {
					printf( "Fegla Won\n" );
					return;
				} else {
				continue;
				}
			}
			if (i != 0 && kraj) {
				printf( "Fegla Won\n" );
				return;
			}
			
			kraj = false;
			int cnt = 0;
			char c = s[i][pos[i]];
			
			if (i == 0) slovo = c - 'a';
			if (c - 'a' != slovo) {
				printf("Fegla Won\n");
				return;
			}
			
			while (pos[i] < len[i] && s[i][pos[i]] == c){++cnt; ++pos[i];}
		
			v.push_back(cnt);
			
		}
		
		sort(v.begin(), v.end());
		int mid = v[(int)v.size() / 2];
		
		for (int i = 0; i < (int) v.size(); ++i) sol += abs(v[i] - mid);
	
		if (kraj) break;
	
	}
	
	printf("%d\n", sol);
	
}

int main(void) {

	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) solve(i);

}
