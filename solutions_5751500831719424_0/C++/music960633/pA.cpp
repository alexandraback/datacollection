#include <stdio.h>
#include <string.h>

int abs(int n){ return n>0? n : -n; }

char s[101][101];
char c[101];
int cnt[101][101];
int s_len[101], c_len;

int main(){
	int T, n;
	bool flg;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t){
		scanf("%d", &n);
		for(int i=0; i<n; ++i){
			scanf("%s", s[i]);
			s_len[i] = strlen(s[i]);
		}
		
		c[0] = s[0][0];
		cnt[0][0] = 1;
		c_len = 1;
		
		for(int i=1; i<s_len[0]; ++i){
			if(s[0][i] != s[0][i-1]){
				c[c_len] = s[0][i];
				cnt[0][c_len] = 1;
				c_len++;
			}
			else cnt[0][c_len-1]++;
		}
		
		flg = true;
		for(int i=1; i<n; ++i){
			int pos = 0;
			if(s[i][0] != c[0]) flg = false;
			else cnt[i][0] = 1;
			for(int j=1; j<s_len[i]; ++j){
				if(s[i][j]!=c[pos]){
					pos++;
					if(pos>=c_len || s[i][j]!=c[pos]) flg = false;
					else cnt[i][pos] = 1;
				}
				else cnt[i][pos]++;
			}
			if(pos != c_len-1) flg = false;
		}
		
		if(!flg){
			printf("Case #%d: Fegla Won\n", t);
			continue;
		}
		/*
		for(int i=0; i<n; ++i){
			for(int j=0; j<c_len; ++j) printf("%d ", cnt[i][j]);
			printf("\n");
		}
		*/
		int ans = 0;
		
		for(int j=0; j<c_len; ++j){
			int min = 1000;
			for(int k=1; k<=100; ++k){
				int tmp = 0;
				for(int i=0; i<n; ++i) tmp += abs(cnt[i][j]-k);
				if(tmp<min) min=tmp;
			}
			ans+=min;
		}
			
		printf("Case #%d: %d\n", t, ans);
	}
		
			
	return 0;
}

