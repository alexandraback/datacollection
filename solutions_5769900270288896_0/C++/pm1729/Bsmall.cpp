#include<bits/stdc++.h>
#define ll long long

using namespace std;

int calcU(int r,int c,int n,const string & mask)
{
	int bo[r][c];
	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j)
			bo[i][j] = 0;
	
	for(int i=0;i<r;++i)
	{
				for(int j=0;j<c;++j)
				{
						bo[i][j] = mask[i*c+j];
						//cout<<bo[i][j];
				}
				//cout<<endl;
	}
	int val  = 0;
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			if(bo[i][j] == 1)
			{
				if(i-1 >= 0) val+=bo[i-1][j];
				if(i+1< r)val+=bo[i+1][j];
				if(j-1 >=0) val+=bo[i][j-1];
				if(j+1< c) val+=bo[i][j+1];
			}
			
		}
	}
	return val/2;
}

void printmask(const string & mask)
{
	for(int i =0;i<mask.length();++i)
	{
		cout<<(char)(mask[i]+'0');
	}
	cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	int n,r,c;
	int uh, minuh;
	for(int i=1;i<=t;++i)
	{
		cin>>r>>c>>n;
		string bitmask(n,1);
		bitmask.resize(r*c,0);
		minuh = 10000;
		do
		{
			//printmask(bitmask);
			uh = calcU(r,c,n,bitmask);
			//minuh = min(uh,minuh);
			if(minuh>uh)
			{
				minuh = uh;
			}
			//printmask(bitmask);
		}
		while(prev_permutation(bitmask.begin(),bitmask.end()));
		cout<<"Case #"<<i<<": "<<minuh<<endl;
	}
	return 0;
}
