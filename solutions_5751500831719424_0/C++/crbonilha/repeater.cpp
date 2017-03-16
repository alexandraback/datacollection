#include <stdio.h>
#include <string.h>
#include <algorithm>

char padrao[110];
int padrao_size;
char s[110][110];
int size[110];

void monta_padrao(int a, char * t, int * t_size);
bool checa(int a);
int conta(int a, char b);

int main() {
	int t, n;
	int ans;
	
	scanf("%d", &t);
	for(int test=1; test<=t; test++) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%s", s[i]);
			size[i] = strlen(s[i]);
		}
		
		monta_padrao(0, padrao, &padrao_size);
		//~ printf("%s\n", padrao);
		for(int i=1; i<n; i++) if(!checa(i)) {
			goto stop;
		}
		
		ans = 0;
		for(int i=0; i<padrao_size; i++) {
			ans += std::abs(conta(0, i)-conta(1, i));
		}
		
		printf("Case #%d: %d\n", test, ans);
		continue;
	stop:printf("Case #%d: Fegla Won\n", test);
	}
}

void monta_padrao(int a, char * t, int * t_size) {
	*t_size = 0;
	char old = '.';
	
	for(int i=0; i<size[a]; i++) if(s[a][i] != old) {
		old = s[a][i];
		t[(*t_size)++] = old;
	}
	t[*t_size] = '\0';
}

bool checa(int a) {
	char t[110];
	int t_size;
	monta_padrao(a, t, &t_size);
	
	return (!strcmp(padrao, t));
}

int conta(int a, char b) {
	int cont = -1;
	char old = '.';
	
	for(int i=0; i<size[a]; i++) if(s[a][i] != old) {
		old = s[a][i];
		cont++;
		
		if(cont == b) {
			int total = 1;
			for(int j=i+1; j<size[a] && s[a][j] == old; j++) total++;
			return total;
		}
	}
	
	return 0;
}
