#include<iostream>
const int N = 4;
int A,B;
int a[N][N],b[N][N];

void solve(int test)
{
	int answer=-1,cnt=0,i,j;
	scanf("%d",&A);
	for(i=0;i<N;i++) for(j=0;j<N;j++) scanf("%d",&a[i][j]);
	scanf("%d",&B);
	for(i=0;i<N;i++) for(j=0;j<N;j++) scanf("%d",&b[i][j]);
	A--;	B--;
	for(i=0;i<N;i++) 
		for(j=0;j<N;j++)
			if(a[A][i]==b[B][j])
			{
				answer=a[A][i];
				cnt++;
			}
	if(cnt==0) printf("Case #%d: Volunteer cheated!\n",test);
	else
	{
		if(cnt==1) printf("Case #%d: %d\n",test,answer);
		else printf("Case #%d: Bad magician!\n",test);
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int Tests;
	scanf("%d",&Tests);
	for(int i=1;i<=Tests;i++) solve(i);
	return 0;
}