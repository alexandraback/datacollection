#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>

#define MAX 128
#define INF (1<<28)

using namespace std;
char aux[MAX];
int casos, n, res, cnt[MAX], pos[MAX];
string v[MAX];

int verifica(char c){
	int ans, curr;
	for(int k=0;k<n;k++){
		cnt[k] = 0;
		while(pos[k] < v[k].size() && v[k][pos[k]] == c){
			pos[k]++;
			cnt[k]++;
		}
		if(cnt[k] == 0) return INF;
	}
	ans = INF;
	for(int i=1;i<=100;i++){
		curr = 0;
		for(int k=0;k<n;k++) curr += max(i-cnt[k], cnt[k]-i);
		ans = min(curr, ans);
	}
	return ans;
}

int main(){
	char c;
	scanf(" %d", &casos);
	for(int inst=1;inst<=casos;inst++){
		scanf(" %d", &n);
		for(int i=0;i<n;i++){
			scanf(" %s", aux);
			v[i] = aux;
			pos[i] = 0;
		}
		res = 0;
		for(int i=0;i<v[0].size();i++){
			c = v[0][i];
			res += verifica(c);
			if(res >= INF){
				res = INF;
				break;
			}
			while(i < v[0].size() && v[0][i] == c) i++;
			i--;
		}
		for(int i=0;i<n;i++) if(pos[i] != v[i].size()) res = INF;
		printf("Case #%d: ", inst);
		if(res < INF) printf("%d\n", res);
		else printf("Fegla Won\n");
	}
	return 0;
}