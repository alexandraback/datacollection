#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;


int choosetop(int *p,int n)
{
	int imin=-1;
	int index=-1;
	for(int i=0;i<n;i++)
	{
		if(imin<p[i])
		{
			index=i;
			imin=p[i];
		}
	}
	return index;
}

int main()
{
	ifstream fin("A-large.in");
	ofstream fout("A-large.out");

	int T;
	fin>>T;
	for(int t=1;t<=T;t++)
	{
		int n=0;
		fin>>n;
		int pcounts[1001];
		memset(pcounts,0,sizeof(pcounts));
		int sum=0;
		for(int i=0;i<n;i++)
		{
			fin>>pcounts[i];
			sum+=pcounts[i];
		}

		bool flag=sum%2;
		int l2=sum/2;
		if(flag)
			l2+=1;
		fout<<"Case #"<<t<<":";
		for(int i=0;i<l2;i++)
		{
			int index=choosetop(pcounts,n);
			char s[3];
			memset(s,0,sizeof(s));
			s[0]='A'+index;
			pcounts[index]--;
			if(flag&&i==l2-2)
			{
				fout<<" "<<s;
				continue;
			}
			index=choosetop(pcounts,n);
			//memset(s,0,sizeof(s));
			s[1]='A'+index;
			pcounts[index]--;
			fout<<" "<<s;
		}
		fout<<endl;
		
		
		

	}

	return 0;
}


