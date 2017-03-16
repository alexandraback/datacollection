#include<iostream>
#include<stdio.h>
#include<string.h>
#define SIZE 10
using namespace std;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.txt","w",stdout);
	int T,cards[SIZE][SIZE],cases,i,j,answer,total,which;
	bool check[20];
	cin>>T;
	for(cases=1;cases<=T;cases++)
	{
		cin>>answer;
		memset(check,0,sizeof(check));
		for(i=1;i<=4;i++)
			for(j=1;j<=4;j++)
				cin>>cards[i][j];
		for(i=1;i<=4;i++)
			check[cards[answer][i]]=true;
		
		cin>>answer;
		for(i=1;i<=4;i++)
			for(j=1;j<=4;j++)
				cin>>cards[i][j];
		total=0;
		which=-1;
		for(i=1;i<=4;i++)
			if(check[cards[answer][i]])
			{
				which=cards[answer][i];
				total++;
			}
		printf("Case #%d: ",cases);
		if(total==0)
			cout<<"Volunteer cheated!\n";
		else if(total==1)
			cout<<which<<endl;
		else
			cout<<"Bad magician!\n";
	}
	return 0;
}