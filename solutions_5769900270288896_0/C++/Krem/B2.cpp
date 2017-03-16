#include<cstdio>
#include<algorithm>
#include<cstring>

char tab[200];

int main() {
	int t; scanf("%d", &t);
	for(int _ = 0; _ < t; _++) {
		memset(tab,0,sizeof(tab));
		int r, c, n; scanf("%d%d%d", &r, &c, &n);
		for(int i = 0, j = r*c-1; i < n; i++, j--) {
			tab[j]=1;
		}
		int best_res = 1000000;
		do {
			int res = 0;
			for(int i = 0; i < r*c; i++) {
				if(!tab[i]) continue;
				if(i%c > 0 && tab[i-1])
					res++;
				if(i%c < c-1 && tab[i+1])
					res++;
				if(i/c > 0 && tab[i-c])
					res++;
				if(tab[i+c])
					res++;
			}
			res /= 2;
			if(best_res > res) best_res = res;
		} while(std::next_permutation(tab,tab+r*c));
		printf("Case #%d: %d\n", _+1, best_res);
	}
}
