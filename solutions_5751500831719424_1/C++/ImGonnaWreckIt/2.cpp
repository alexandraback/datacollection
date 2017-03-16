#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
	int i,j,k,l;
	int T,a[4][4];
	int N,L,min,max,count,minl,temp;
	char **str;
	int *start;
	int *end;
	ifstream ip("A-large.in");;
	ofstream op("output.txt");;
	ip>>T;
	//cout<<T;
	for(l=1;l<=T;l++)
	{
		op<<"Case #"<<l<<": ";
		ip>>N;
		str=new char *[N];
		start=new int[N];
		end=new int[N];
		for(i=0;i<N;i++)
			str[i]=new char[101];
		for(i=0;i<N;i++)
			ip>>str[i];
		//cout<<str[0]<<"\t"<<str[1]<<"\n";
		L=0;
		i=j=0;
		for(i=0;i<N;i++)
			start[i]=end[i]=0;
		for(k=0;k<strlen(str[0]);)
		{
			for(i=0;i<N;i++)
				if(str[i][start[i]]!=str[0][start[0]])
					break;
			if(i!=N)
				break;
			
			min=101;
			max=0;
			for(i=0;i<N;i++)
			{
				j=start[i];
				while(str[i][j+1]!='\0' && str[i][j]==str[i][j+1])
					j++;
				end[i]=j;
				if(end[i]-start[i]+1>max)
					max=end[i]-start[i]+1;
				if(end[i]-start[i]+1<min)
					min=end[i]-start[i]+1;
			}
			
			if(min==max)
			{
				for(i=0;i<N;i++)
					start[i]=end[i]+1;
				k=start[0];
				continue;
			}
			minl=100*20000;
			for(i=min;i<=max;i++)
			{
				count=0;
				for(j=0;j<N;j++)
				{
					temp=i-(end[j]-start[j]+1);
					if(temp<0)
						temp=-1*temp;
					count+=temp;
				}
				if(count<minl)
					minl=count;
			}
			for(i=0;i<N;i++)
				start[i]=end[i]+1;
			k=start[0];
			L=L+minl;
		}
		for(i=0;i<N;i++)
		{
			if(str[i][start[i]]!='\0')
				break;
		}
		if(i==N)
			op<<L<<"\n";
		else
			op<<"Fegla Won\n";		
	}
	return 0;
}
