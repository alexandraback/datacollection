// ROH.cpp : Defines the entry point for the console application.
//


#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstdio>
#include<map>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<bitset>
#include<fstream>
#include<set>
#include<stack>
#include<utility>
#include<string>
#include<cstring>
#include<math.h>
#include<time.h>
using namespace std;

#define scan scanf_s
#define sscan sscanf_s
#define get gets_s
#define print printf 
#define mod 1000000007
#define ll long long
#define init int i,j,k,l,m,n,test
#define pause system("pause")
#define inf 1000000000

int reverse(int x)
{
	int i,j,k;
	j=0;i=0;
	k=x;
	while(k>0)
	{
		k/=10;
		j++;
	}
	j--;
	while(x>0)
	{
		i+=(x%10)*pow(10,j);
		x/=10;
		j--;
	}
	return i;
}
int ans=inf;
int calculate(vector<vector<int> > &v, int r,int c)
{
	int k=0;
	int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			if(v[i][j]==1)
			{
				if(j<c-1 && v[i][j+1]==1)
					k++;
				if(i<r-1 && v[i+1][j]==1)
					k++;
			}

		}
		return k;
}
void recurse(int left, vector<vector<int> > &v,int r,int c,int i,int j)
{
	
	if(left==0)
	{
		ans=min(ans,calculate(v,r,c));
		return;
	}
	
	if(i==r)
	{
		return;
	}
	/*if(left>(r-i-1)*c+(c-j))
		return;*/
	v[i][j]=1;
	if(j==c-1)
	{
		
		recurse(left-1,v,r,c,i+1,0);
		
	}
	else recurse(left-1,v,r,c,i,j+1);

	v[i][j]=0;
	if(j==c-1)
	{
		j=0;
		recurse(left,v,r,c,i+1,0);
		
	}
	else recurse(left,v,r,c,i,j+1);

}
void func(int r,int c,int n)
{
	vector<vector<int> > v;
	v.resize(r);
	for(int i=0;i<r;i++)
		v[i].resize(c);
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			v[i][j]=0;
	recurse(n,v,r,c,0,0);
	
}

int main()
{
	init;
	ifstream in("C:\\Users\\Ray\\Desktop\\google\\2\\B-small-attempt1.in");
	ofstream out("C:\\Users\\Ray\\Desktop\\google\\2\\1_out.txt");
	in>>test;
	int r,c;
	j=1;
	while(test--)
	{
		in>>r>>c>>n;
		func(r,c,n);
		out<<"Case #"<<j++<<": "<<ans<<endl;
		ans=inf;
	}
	
	
	pause;
	
}