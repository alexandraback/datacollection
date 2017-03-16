#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	int t,n,a[105][110],i,j,k,len,moves,left,right,leftsum,rightsum,sum,cases;
	char s[105][110],c[105][110],key;
	ifstream fin("a.txt");
	ofstream fout("b.in");
	fin>>t;
	for(cases=1;cases<=t;cases++)
	{
		fin>>n;
		for(i=0;i<n;i++)
		for(j=0;j<110;j++)
		a[i][j]=0;
		for(i=0;i<n;i++) fin>>s[i];
		for(i=0;i<n;i++)
		{
			len=strlen(s[i]);
			k=0;
			key=s[i][0];
			for(j=1;j<len;j++)
			{
				if(s[i][j]!=key)
				{
					c[i][k]=key;
					key=s[i][j];
					k++;
				}
				else
				{
					a[i][k]++;
				}
			}
			c[i][k]=key;
			c[i][k+1]='\0';
		}
		//for(i=0;i<n;i++) fout<<c[i]<<endl;
		for(i=1;i<n;i++)
		{
			if(strcmp(c[i-1],c[i])!=0) {goto falsecase;}
			//fout<<i<<" and "<<i+1<<" is same\n";
		}
		len=strlen(c[0]);
		moves=0;
		for(j=0;j<len;j++)
		{
			sum=0;
			for(i=0;i<n;i++) sum+=a[i][j];
			left=sum/n;
			right=left+1;
			leftsum=0;
			rightsum=0;
			for(i=0;i<n;i++)
			{
				sum=a[i][j]-left;
				if(sum<0) sum=(-sum);
				leftsum+=sum;
			}
			for(i=0;i<n;i++)
			{
				sum=a[i][j]-right;
				if(sum<0) sum=(-sum);
				rightsum+=sum;
			}
			if(rightsum<leftsum) moves+=rightsum;
			else moves+=leftsum;
		}
		fout<<"Case #"<<cases<<": "<<moves<<endl;
		continue;
		falsecase:
			fout<<"Case #"<<cases<<": Fegla Won\n";
	}
}
