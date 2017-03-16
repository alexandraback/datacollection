#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAXN = 30;

int p[MAXN];

bool check(int n) {
	int mx = -1, cnt = 0;
	for(int i=0; i<n; i++) {
		if(p[i] > mx) {
			mx = p[i];
			cnt = 1;
		}
		else if(p[i] == mx)	cnt++;
	}
	return cnt == 2;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int kase=1; kase<=t; kase++) {
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++)	scanf("%d", p+i);
		printf("Case #%d: ", kase);
		int mx = p[0], id;
		while(!check(n)) {
			mx = -1, id = -1;
			for(int i=0; i<n; i++) {
				if(p[i] > mx) {
					mx = p[i];
					id = i;
				}
			}

			putchar('A'+id);
			putchar(' ');
			p[id]--;
		}
		mx = -1;
		for(int i=0; i<n; i++) mx = max(mx, p[i]);

		while(1) {
			bool flag = false;
			for(int i=0; i<n; i++) {
				if(p[i] && p[i] != mx) {
					flag = true;
					putchar('A'+i);
					putchar(' ');
					p[i]--;
				}
			}
			if(!flag)	break;
		}

		while(1) {
			bool flag = false;
			for(int i=0; i<n; i++) {
				if(p[i]) {
					p[i]--;
					putchar('A'+i);
					if(!p[i])	flag = true;
				}
			}
			if(flag)	break;
			putchar(' ');
		}
		putchar('\n');
	}
    
    return 0;
}
