#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	int tc,n,a,num[26];
	double sum;
	scanf("%d",&tc);
	for(int i=1; i<=tc; i++){
		sum=0;
		scanf("%d",&n);
		for(int j=0; j<n; j++) {
			scanf("%d",num+j);
			sum+=num[j];
		}
		//printf("sum %f\n", sum );
		printf("Case #%d:", i);
		while (sum>0){
			vector<int> r;
			for(int j=0; j<n; j++)
				if(num[j]>(sum-1)/2) r.push_back(j);
			if(r.size()!=0){
				printf(" ");
				for(int j=0; j<r.size(); j++) {printf("%c",(char)(65+r[j])); num[r[j]]--;}
				sum-=r.size();
			}else{
				int j=0;
				while(num[j]==0) j++;
				printf(" %c",(char)(65+j));
				num[j]--;
				sum--;
			}
		}
		printf("\n");
	}
}