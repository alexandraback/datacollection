#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int N;
char str[121][121];
char ide[121][121];
int main(){
	int T;
	scanf("%d",&T);
	for(int ca = 1; ca <= T; ca++){
		for(int i=0;i<121;i++)for(int j=0;j<121;j++)ide[i][j] = 0;
		for(int i=0;i<121;i++)for(int j=0;j<121;j++)str[i][j] = 0;
		scanf("%d ",&N);
		for(int i=0;i<N;i++){
			scanf("%s ",str[i]);
		}
		for(int i=0;i<N;i++){
			char pre = '\0';
			int count = 0;
			for(int j=0;str[i][j] != '\0';j++){
				char c = str[i][j];
				if(c != pre){
					ide[i][count++] = c;
				}
				pre = c;
			}
		}
		bool flag = true;
		for(int i=1;i<N;i++){
			if(strcmp(ide[0],ide[i]) != 0){
				flag = false;
				break;
			}
		}
		if(flag == false){
			printf("Case #%d: Fegla Won\n",ca);
			continue;
		}

		int ans = 0;
		char *target = ide[0];
		int len = strlen(target);
		int index[121];
		for(int i=0;i<121;i++)index[i] = 0;


		for(int i=0;i<len;i++){
			int _ans = 21464836;
			char c = target[i];
			int counter[121];
			for(int j=0;j<121;j++)counter[j] = 0;
			int maxCounter = 0;
			for(int j=0;j<N;j++){
				int tmpCounter = 0;
				for(;;index[j]++){
					if(str[j][index[j]] == c)tmpCounter++;
					else break;
				}
				counter[tmpCounter] ++;
				maxCounter = max(maxCounter, tmpCounter + 1);
			}
			for(int k=1;k<121;k++){
				int total = 0;
				for(int j=1;j<121;j++){
					total += counter[j] * abs(k - j);
				}
				_ans = min(_ans, total);
			}
			ans += _ans;
		}
		printf("Case #%d: %d\n",ca, ans);
	}
	return 0;
}
