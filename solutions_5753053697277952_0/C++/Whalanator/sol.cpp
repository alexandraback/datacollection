#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;


int main() {
	int T;
	cin >> T;
	for (int cas=1;cas<=T;cas++) {
		int cts[26];
		int N;
		cin >> N;
		for (int c=0;c<N;c++) cin >> cts[c];
		printf("Case #%d:",cas);
		while (1) {
			int i=max_element(cts,cts+N)-cts;
			cts[i]--;
			if (cts[i]==-1) break;
			int j=max_element(cts,cts+N)-cts;
			printf(" ");
			int k=max_element(cts+j+1,cts+N)-cts;
			if (cts[j]==cts[i]+1 && (k==N || cts[j]>cts[k])) {
				cts[j]--;
				printf("%c",(char)('A'+j));
			}
			printf("%c",(char)('A'+i));
		}
		printf("\n");
	}
}
