#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
	int i,j,k,l;
	int T,a[4][4];
	int N,L,min,*count,minl;
	char **str;
	int start1,start2;
	ifstream ip("A-small-attempt0.in");;
	ofstream op("output.txt");;
	ip>>T;
	//cout<<T;
	for(l=1;l<=T;l++)
	{
		op<<"Case #"<<l<<": ";
		ip>>N;
		str=new char *[N];
		for(i=0;i<N;i++)
			str[i]=new char[101];
		for(i=0;i<N;i++)
			ip>>str[i];
		//cout<<str[0]<<"\t"<<str[1]<<"\n";
		L=0;
		i=j=0;
		for(k=0;k<strlen(str[0]);k++)
		{
			if(str[0][k]!=str[1][j])
				break;
			start1=k;
			start2=j;
			//cout<<str[0][k+1]<<"\n";
			while(str[0][k+1]!='\0' && (int)str[0][k]==(int)str[0][k+1])
				k++;
			while(str[1][j+1]!='\0' && (int)str[1][j]==(int)str[1][j+1])
				j++;
			if(k-start1+1!=j-start2+1)
			{
				minl=k-start1+start2-j;
				if(minl<0)
					minl=-1*minl;
				L=L+minl;
			}
			j++;
			//cout<<k<<"\t"<<	j<<"\n";
		}
		if(k==strlen(str[0]) && j==strlen(str[1]))
			op<<L<<"\n";
		else
			op<<"Fegla Won\n";		
	}
	return 0;
}
