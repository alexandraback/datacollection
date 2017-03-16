#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int app[19],ca,x,y;
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&ca);
	for(int i=1;i<=ca;i++){
		memset(app,0,sizeof(app));
		for(int X=1;X<=2;X++){
			scanf("%d",&x);
			for(int j=1;j<=4;j++)
				for(int k=1;k<=4;k++){
					scanf("%d",&y);
					if(j==x) app[y]++;
				}
		}
		int cnt=0;
		for(int X=1;X<=16;X++)
			if(app[X]==2) cnt++;
			printf("Case #%d: ",i);
		if(cnt==0) printf("Volunteer cheated!\n");
		else if(cnt>=2) printf("Bad magician!\n");
		else{
			for(int X=1;X<=16;X++){
				if(app[X]==2) printf("%d\n",X);
			}
		}
	}
	return 0;
}
