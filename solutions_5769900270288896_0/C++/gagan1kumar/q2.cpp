//#include<iostream>
//#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;
int *B;
int Vmin;
int rc;
int R,C,N;
void findMin(int index)
{
	if(rc<N && index<R*C)
	{
		for(int i=index;i<R*C;i++)
		{
			B[i]=1;
			rc++;
			findMin(i+1);
			rc--;
			B[i]=0;
		}
	}
	else if(rc==N)
	{
		int i,j;
		int c=0;
		for(i=0;i<R-1;i++)
			for(j=0;j<C;j++)
			if(B[i*C+j]==1 && B[C*(i+1)+j]==1) c++;
		for(i=0;i<R;i++)
			for(j=0;j<C-1;j++)
			if(B[i*C+j]==1 && B[i*C+j+1]==1) c++;
		if(Vmin>c) Vmin=c;

	}	
}
void solve()
{
	
	cin>>R>>C>>N;
	B=(int *)malloc(sizeof(int)*R*C);
	for(int i=0;i<R*C;i++)B[i]=0;
	Vmin=INT_MAX;
	rc=0;


	findMin(0);
	cout<<Vmin;
}
int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		printf("Case #%d: ",i );
		solve();
		printf("\n");
	}
	return 0;
}