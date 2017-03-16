#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string ss[101];

int min(int a, int b, int c){
	int m = 2147483647;
	if(m > a)
		m = a;
	if(m > b)
		m = b;
	if(m > c)
		m = c;
	return m;
}

string unique_(string str){
	char s[1000] = {};
	int ind = 0;
	for(int i = 0; i < str.length(); i++){
		s[ind++] = str[i];
		char c = str[i];
		while(i < str.length() && str[i] == c)
			i++;
		i--;
	}
	return string(s);
}

int ans;
int main(){
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int n, T, ctt = 0;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> ss[i];
		int len[1000] = {}, ct[103][104] = {};
		for(int i = 0; i < n; i++)
			len[i] = ss[i].length();
		ans = 1e9;
		for(int i = 0; i < n; i++){
			//string standard = s[i];
			int temp = 0, fg = 1;
			for(int j = 0; j < n; j++){
				fg = fg & (unique_(ss[i]) == unique_(ss[j]));
				if(unique_(ss[i]) == unique_(ss[j]))
					temp += 0;
			}
			if(fg){
				ans = 0;
			}
		}
		printf("Case #%d: ", ++ctt);
		if(ans < 1e9){
			string uni = unique_(ss[0]);
			for(int i = 0; i < n; i++){
				int ind = 0;
				for(int j = 0; j < ss[i].length(); j++){
					while(j < ss[i].length() && ss[i][j] == uni[ind])
						ct[ind][i]++, j++;
					j--;
					ind++;
				}
			}
			for(int i = 0; i < uni.length(); i++){
				sort(ct[i], ct[i]+n);
				for(int j = 0; j < n; j++)
					ans += abs(ct[i][j] - ct[i][n/2]);
			}

			printf("%d\n", ans);
		}
		else
			puts("Fegla Won");
	}
	return 0;
}