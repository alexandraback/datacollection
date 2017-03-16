#include<stdio.h>
int a[1000];

int max(int x,int y){return x>y?x:y;}

int main(){
	int dn;
	scanf("%d",&dn);
	for(int di=0;di<dn;di++){
		int n,i;
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		int s1=0;
		int tmp=0;
		for(i=0;i<n;i++){
			if(a[i]>=tmp)tmp=a[i];
			else{
				s1+=tmp-a[i];
				tmp=a[i];
			}
		}
		int m=0;
		for(i=1;i<n;i++)m=max(m,a[i-1]-a[i]);
		int s2=0;
		for(i=0;i<n-1;i++){
			if(a[i]>=m)s2+=m;
			else s2+=a[i];
		}
		printf("Case #%d: %d %d\n",di+1,s1,s2);
	}
	return 0;
}