#include<stdio.h>
int tab[100000];
int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0 ; e < t ; e++ ){
		int n;
		scanf("%d",&n);
		for(int i = 0 ;i < n ; i++ ) scanf("%d",&tab[i]);
		
		int res1 = 0;
		for(int i = 0 ; i < n-1 ; i++ ){
			if( tab[i+1] < tab[i] ) res1+=tab[i]-tab[i+1];
		}
		int res = 0 ;
		
		int left = 0,right = 10000;
		for(; left <= right ; ){
			int sum = 0;
			int mid = (left+right)/2;
			int chk = 1;
			for(int i = 0 ; i < n-1 ; i++ ){
				if( tab[i] > mid ){
					sum+=mid;
					if( tab[i]-mid>tab[i+1]) chk = 0;
				}else{
					sum+=tab[i];
				}
			}
			if( left == right ){
				res = sum;
				break;
			}
			if( chk == 0 ){
				left=mid+1;
			}else{
				right=mid;
			}
		}
		printf("Case #%d: %d %d\n",e+1,res1,res);
	}
}
