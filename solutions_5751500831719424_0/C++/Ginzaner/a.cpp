#include <cstdio>
#include <cstring>

using namespace std;

char in[105][105];
int count[105][105];
int maxc[105];
int minc[105];

inline int abs(int a) {
	return a<0?-a:a;
}

inline int max(int a, int b) {
	return a<b?b:a;
}

int main() {
	
	int T;
	scanf("%d ", &T);
	
	for(int k = 1; k <= T; k++) {
		
		printf("Case #%d: ", k);
	
		memset(in, '\n', sizeof(in));
		memset(count, 0, sizeof(count));
	
	
		int N;
		scanf("%d ", &N);
		
		for(int i = 0; i < N; i++) {
			fgets(in[i], 102, stdin);
		}
		
		char sh[105]; 
		memset(sh, 0, sizeof(sh));
		
		int i = 1;
		int c = 0;
		sh[0] = in[0][0];
		count[0][0] = 1;
		
		
		while(in[0][i] != '\n') {
			if(sh[c] != in[0][i]) {
				c++;
				sh[c] = in[0][i];
				count[0][c] = 1;
				minc[c] = 1;
				maxc[c] = 1;
			} else {
				count[0][c]++;
				minc[c]++;
				maxc[c]++;
			}
			i++;
		}
		
		c++;
		
		bool pos = true;
		char sh1[105]; 
		
		for(int j = 1; j < N; j++) {
			memset(sh1, 0, sizeof(sh1));
		
			i = 1;
			int c1 = 0;
			sh1[0] = in[j][0];
			count[j][0] = 1;
			while(in[j][i] != '\n') {
				if(sh1[c1] != in[j][i]) {
					if(minc[c1] > count[j][c1]) {
						minc[c1] = count[j][c1];
					}
					if(maxc[c1] < count[j][c1]) {
						maxc[c1] = count[j][c1];
					}
					c1++;
					sh1[c1] = in[j][i];
					count[j][c1] = 1;
				} else {
					count[j][c1]++;
				}
				i++;
			}
			if(minc[c1] > count[j][c1]) {
				minc[c1] = count[j][c1];
			}
			if(maxc[c1] < count[j][c1]) {
				maxc[c1] = count[j][c1];
			}
			
			c1++;
			
			if(strncmp(sh, sh1, max(c,c1)) != 0) {
				pos = false;
				break;
			}
		}
		
		if(!pos) {
			printf("Fegla Won\n");
			continue;
		}
		
		int moves = 0;
		
		/*for(i = 0; i < N; i++) {
			for(int j = 0; j < c; j++) {
				printf("%d ", count[i][j]);
			}
			printf("\n");
		}*/
		
		for(i = 0; i < c; i++) {
			int movesc = 1000000000;
			for(int j = minc[i]; j <= maxc[i]; j++) {
				int mov = 0;
				for(int l = 0; l < N; l++) {
					mov += abs(count[l][i]-j); 
				}
				if(mov < movesc) movesc = mov;
			}
			moves+= movesc;
		}
		
		printf("%d\n", moves);
		
	}
	
	
	return 0;
}
