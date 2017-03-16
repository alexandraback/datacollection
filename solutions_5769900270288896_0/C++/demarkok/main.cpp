#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > pii;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second       
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

const int inf = 1e9;
                         
bool valid(int i, int j, int h, int w) {
	return i >= 0 && j >= 0 && i < h && j < w; 
}
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1} ;

int n;
int get(int h, int w, int mask) {
    int ed = 0;
    for (int e = mask; e; e >>= 1)
    	ed += (e & 1);
   	if (ed != n)
   		return inf;
   	//printf("%d\n", mask);
    int uk = 0;
    bool tab[16][16];
	forn(i, h) 
		forn(j, w) 
			tab[i][j] = (mask & (1 << uk++));
			/*  
	forn(i, h) {
		forn(j, w)
			printf(tab[i][j] ? "+" : "-");
		printf("\n");
	}
	*/
	int res = 0;
	forn(i, h)
		forn(j, w)
			forn(k, 4)
				if (valid(i + di[k], j + dj[k], h, w))
					if (tab[i][j] && tab[i + di[k]][j + dj[k]])
						++res;
	//printf("%d\n", res);
	return res / 2;
}
     
int main() {
	int t;
	scanf("%d", &t);

	forn(q, t) {
		int h, w;
		scanf("%d%d%d", &h, &w, &n);
		/*
		if ((h * w + 1) / 2 <= n) {
			printf("Case #%d: %d\n", q + 1, 0);                    
			continue;
		}
		*/	
		int res = inf;
		forn(mask, 1 << (h * w)) {
			res = min(res, get(h, w, mask));	
		}
		printf("Case #%d: %d\n", q + 1, res);  
	}

	return 0;
}    
