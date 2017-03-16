
#include <cstdio>
#include <cstring>

int main(){
	
	int testcase; scanf("%d", &testcase);
	int s[17];
	
	for(int t=1; t<=testcase; ++t){
		memset(s, 0, sizeof(s));
		for(int i=0; i<2; ++i){
			int sol;
			scanf("%d", &sol);
			for(int i=0; i<16; ++i){
				int tmp;
				scanf("%d", &tmp);
				if(i >= (sol-1)*4 && i < sol*4){
					s[tmp] ++;
				}
			}
		}
		int ans, count;
		count = 0;
		for(int i=1; i<=16; ++i){
			if(s[i] == 2){
				ans = i;
				++ count;
			}
		}
		printf("Case #%d: ", t);
		if(count == 1){
			printf("%d\n", ans);
		}else if(count == 0){
			printf("Volunteer cheated!\n");
		}else{
			printf("Bad magician!\n");
		}
	}
	return 0;
}
