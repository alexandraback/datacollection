#include<cstdio>
#include<algorithm>

using namespace std;

int n, casos, inst;
int sum, ans, ans2, bsf, bsf2, v[30];

int main(){
	scanf(" %d", &casos);
	for(int inst=1;inst<=casos;inst++){
		scanf(" %d", &n);
		
		sum = 0;
		for(int i=0;i<n;i++){
			scanf(" %d", &v[i]);
			sum += v[i];
		}
		
		printf("Case #%d:", inst);
		while(sum){
			bsf = bsf2 = 0;
			ans = ans2 = -1;
			for(int i=0;i<n;i++){
				if(v[i] > bsf){
					bsf2 = bsf; ans2 = ans;
					bsf = v[i]; ans = i;
				}
				else if(v[i] > bsf2){
					bsf2 = v[i]; ans2 = i;
				}
			}
			bool pode = true;
			for(int i=0;i<n;i++){
				if(i != ans && i != ans2 && v[i] > (sum-2)/2) pode = false;
			}
			
			if(pode && ans2 != -1){
				printf(" %c%c", 'A'+ans, 'A'+ans2);
				v[ans]--;
				v[ans2]--;
				sum -= 2;
			}
			else{
				printf(" %c", 'A'+ans);
				v[ans]--;
				sum--;
			}
		}
		printf("\n");
	}
	return 0;
}
