#include<cstdio>
#include<iostream>
using namespace std;
int T,tmp;
int a[17];
int main()
{
	freopen("Qual_A.in","r",stdin);
	freopen("Qual_A.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		int row,bad=0;
		printf("Case #%d: ",i);
		for(int i=1;i<=16;i++)a[i]=1;
		for(int j=0;j<2;j++){
			cin>>row;
			for(int i=1;i<=16;i++){
				scanf("%d",&tmp);
				if(!(i>=4*(row-1)+1 && i<=4*row)) a[tmp]=0;}
		}
		int rec=0;
		for(int i=1;i<=16;i++)
			if(a[i]){
				if(rec) {printf("Bad magician!\n"); bad=1;break;}
				else rec=i;
			}
		if(bad)continue;
		if(rec) printf("%d\n",rec);else printf("Volunteer cheated!\n");
		}
}

