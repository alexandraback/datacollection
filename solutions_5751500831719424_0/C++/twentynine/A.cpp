#include<iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int main(){
	 freopen("A-small-attempt0 (1).in","r",stdin); 
	 freopen("A-small-attempt0 (1).out","w",stdout);
	int ii,tc;
	scanf("%d",&tc);
	for(ii=1;ii<=tc;ii++){
		int n,i,j,a[105][105],len[105],ans=0;
		char s[105][105],c[105][105];
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("\n%s",s[i]);
		for(i=1;i<=n;i++)len[i]=0;
		for(i=0;i<=100;i++)for(j=0;j<=100;j++)c[i][j]=0;
		for(i=1;i<=n;i++){
			for(j=0;j<strlen(s[i]);j++){
				if(j==0||s[i][j]!=s[i][j-1]){
					c[i][len[i]]=s[i][j];
					len[i]++;
				}
			}
		}
		//for(i=1;i<=n;i++)printf("%s\n",c[i]);
		int yes=1;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				if(strcmp(c[i],c[j])!=0)yes=0;
			}
		}
		
		if(yes==0)printf("Case #%d: Fegla Won\n",ii);
		else {
			int leng=len[1];
			for(i=1;i<=n;i++){ int cnt=0,count=0;
	    		for(j=0;j<strlen(s[i]);j++){
			    	if(j==0||s[i][j]!=s[i][j-1]){
			     		a[i][count]=cnt;
						 cnt=0;
			     		count++;
			    	}
					cnt++;
		    	}
		    	a[i][count]=cnt;
	    	}
	    	//printf("%d\n",leng);
	    	//for(j=1;j<=leng;j++){for(i=1;i<=n;i++)printf("%d ",a[i][j]);printf("\n");}
	    	
	    	
	    	for(j=1;j<=leng;j++){
				int mini=99999999,tp=0;
				for(int k=0;k<=100;k++){
					tp=0;
					for(i=1;i<=n;i++){
			            tp+=abs(a[i][j]-k);
					}
					mini=min(mini,tp);
				}
				
				ans+=mini;
			}
					
				
				
			
			
			printf("Case #%d: %d\n",ii,ans);
			
		}
	}
				
				
		
		
		
         
         
         
         
         
	
	return 0;
}
