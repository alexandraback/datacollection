#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("b.txt", "w", stdout);
	int T;
	string s[110];
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		int n;
		scanf("%d", &n);
		string tt;
		bool flag = 1;
		for(int i = 0; i < n; i++){
			cin >> s[i];
			int len = s[i].length();
			string tmp = "";
			char ch = 0;
			for(int j = 0; j < len; j++){
				if(s[i][j] != ch){
					tmp += s[i][j];
					ch = s[i][j];
				}
			}
			if(i == 0) tt = tmp;
			else{
				if(tt != tmp) flag = 0;
			}
		}
		if(flag == 0){
			printf("Case #%d: Fegla Won\n", t + 1);
		}
		else{
			int val[110][110];
			for(int i = 0; i < n; i++){
				int len = s[i].length();
				int cou = 0, k = 0;
				for(int j = 0; j < len; j++){
					if(s[i][j] == tt[k]){
						cou++;
					}
					else{
						val[i][k] = cou;
						cou = 1;
						k++;
					}
				}
				val[i][k] = cou;
			}
			int ans = 0;
			int len = tt.length();
			//printf("%d\n", len);
			for(int i = 0; i < len; i++){
				int ans1 = 100 * 100;
				for(int j = 1; j < 101; j++){
					int ans2 = 0;
					for(int k = 0; k < n; k++) ans2 += abs(j - val[k][i]);
					ans1 = min(ans1, ans2);
				}
				//printf("%d %d ", i, ans1);
				ans += ans1;
			}
			printf("Case #%d: %d\n", t + 1, ans);
		}
	}
	return 0;
}
