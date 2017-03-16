#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++){
		int r,c,n;
		scanf("%d %d %d", &r, &c, &n);
		if(n==0){
			printf("Case #%d: %d\n",i,0);
		}
		else if((r-1)*(c-1) != 0){
			if((r*c)%2 == 1){
				int counta = 0;
				int tmp = max(0,n - (r*c)/2);
				counta += 2*min(tmp,4);
				tmp = max(tmp - 4, 0);
				counta += 3*min(tmp,(((c-2)/2)*2)+(((r-2)/2)*2));
				tmp = max(tmp - ((((c-2)/2)*2)+(((r-2)/2)*2)), 0);
				counta += 4*tmp;
				int countb = 0;
				tmp = max(0,n-((r*c)+1)/2);
				countb += 3*min(tmp,((c/2)*2)+((r/2)*2));
				tmp = max(tmp-(((c/2)*2)+((r/2)*2)), 0);
				countb += 4 * tmp;
				printf("Case #%d: %d\n",i,min(counta,countb));
			}
			else{
				int count = 0;
				int tmp = max(0,n-(r*c)/2);
				count += 2*min(tmp,2);
				tmp = max(tmp - 2, 0);
				int x = 0;
				if(c%2 == 1) x += (((r-2)/2)*2) + (c/2) + ((c-2)/2);
				else if(r%2 == 1) x += (((c-2)/2)*2) + (r/2) + ((r-2)/2);
				else x += r + c - 4;
				count += 3*min(tmp,x);
				tmp = max(0,tmp - x);
				count += 4*tmp;
				printf("Case #%d: %d\n",i, count);
			}
		}
		else{
			int count = 0;
			if(r*c%2==1){
			int tmp = max(0,n-((r*c)+1)/2);
			count += 2*tmp;
			}else{
				int tmp = max(0,n-((r*c))/2);
				count += 1*min(tmp,1);
				tmp = max(0,tmp-1);
				count += 2*tmp;
			}
			printf("Case #%d: %d\n",i, count);
		}
	}
	return 0;
}



