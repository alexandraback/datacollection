#include <iostream>
using namespace std;
int main()
{
int testcases;
int n;
int answer;
int flag;
int k;
int l;
char a[101][101];
int answer1[101];
cin >> testcases;
	for (int i=0;i<testcases;i++)
	{
	cin >> n;
	for (int j=0;j<n;j++)
	{
		cin >> a[j];
	}
	k=0;
	l=0;
	answer=0;
	flag=0;
	for (int p=1;p<n;p++)
	{
	k=0;
	l=0;
	answer1[p]=0;
	while (a[0][k]!='\0' || a[p][l]!='\0')
	{
		if (a[0][k]==a[p][l])
		{
		k++;
		l++;
		}
		else if (a[p][l]==a[p][l-1] && a[p][l-1]==a[0][k-1])
		{
		l++;
		answer1[p]++;
		}
		else if (a[0][k]==a[0][k-1] && a[0][k-1]==a[p][l-1])
		{
		k++;
		answer1[p]++;
		}
		else
		{
			flag=1;
			break;
		
		}
		
	
	}
	if (flag==1) break;
	}
	for (int t=1;t<n;t++)
	{
	if (answer<answer1[t])answer=answer1[t];
	
	}
	if (flag==0) cout <<"Case #"<<i+1<<": "<<answer<<"\n";
	else cout <<"Case #"<<i+1<<": Fegla Won\n";

	}




}
