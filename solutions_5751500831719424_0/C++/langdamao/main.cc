#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int T,n;
int num[105][105];
char str[105][105];
char strtmp[105];
int a[105];

bool eq(int x,int y){
	if(strlen(str[x])!=strlen(str[y])) return false;
	int l=strlen(str[x]);
	for (int i=0;i<l;i++){
		if(str[x][i]!=str[y][i]) return false;
	}
	return true;
}
int abss(int x){
	if (x<0) return -x;
	return x;
}
int main(){
	scanf("%d",&T);
	int ca=1;
	while(T--){
		scanf("%d",&n);
		memset(num,0,sizeof(num));
		for (int i=0;i<n;i++){
			scanf(" %s",strtmp);
			int l=strlen(strtmp);
			int now=0;
			for (int j=0;j<l;j++){
				if(j==0) {str[i][now]=strtmp[j];num[i][now]++;now++;continue;}
				if(j==0||strtmp[j]==strtmp[j-1]) {num[i][now-1]++;continue;}
				str[i][now]=strtmp[j];
	            num[i][now]++;
				now++;
			}
			str[i][now]='\0';
		}
		//for (int i=0;i<n;i++){
			//for (int j=0;j<strlen(str[i]);j++){
				//cout<<i<<' '<<j<<' '<<num[i][j]<<endl;
			//}
		//}
		bool got=false;
		for (int i=1;i<n;i++){
			if(!eq(0,i)){got=true;break;}
		}
		printf("Case #%d: ",ca++);
		if(got) printf("Fegla Won\n");
		else {
			int l=strlen(str[0]);
			int ret=0;
			for (int i=0;i<l;i++){
				for (int j=0;j<n;j++){
					a[j]=num[j][i];
				}
				sort(a,a+n);
				for (int j=0;j<n;j++){
					ret+=abss(a[j]-a[n/2]);
				}
			}
			printf("%d\n",ret);
		}
	}
	return 0;
}
