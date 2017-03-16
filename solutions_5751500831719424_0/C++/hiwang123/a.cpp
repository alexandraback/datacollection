#include<stdio.h>
#include<stdlib.h>
int ans(int a){
	if(a<0) return -a;
	return a;
}
int main(void){
	int t,hh;
	scanf("%d",&t);
	for(hh=1;hh<=t;hh++){
		int n;
		scanf("%d",&n);
		int i,j,k;
		char s[104][104];
		for(i=0;i<n;i++)
		  scanf("%s",&s[i]);
		char cc[104][104];
		int ss[104][104];
		int cnt[104];
		for(i=0;i<104;i++)
		  for(j=0;j<104;j++)
		    ss[i][j]=0;
		for(i=0;i<n;i++){
			cnt[i]=0;
		    cc[i][cnt[i]]=s[i][0];
		    ss[i][cnt[i]]=1;
		    for(j=1;s[i][j]!='\0';j++)
		      if(s[i][j]!=s[i][j-1]) ss[i][++cnt[i]]++,cc[i][cnt[i]]=s[i][j];
		      else ss[i][cnt[i]]++;
		    cnt[i]++;
		}
		int ok=1;
		for(i=0;i<n;i++)
		   if(cnt[i]!=cnt[0]) ok=0;
		for(j=0;j<cnt[0];j++)
		   for(i=0;i<n;i++)
		     if(cc[i][j]!=cc[0][j]) ok=0;
		if(ok==0) printf("Case #%d: Fegla Won\n",hh);
		else{
		/*	for(i=0;i<n;i++){
			  for(j=0;j<cnt[0];j++)
			    printf("%d ",ss[i][j]);
			  printf("\n");
			}   */
			int ans=0;
			for(i=0;i<cnt[0];i++){
				int mmin=100000000;
				for(j=1;j<=100;j++){
				  int mm=0;
				  for(k=0;k<n;k++)
				    mm+=abs(j-ss[k][i]);
				  if(mmin>mm) mmin=mm;
				 // printf(" %d ",mmin);
				}
			//	printf("\n");
				ans+=mmin;
			}
			printf("Case #%d: %d\n",hh,ans);
		}
	}
	return 0;
}
