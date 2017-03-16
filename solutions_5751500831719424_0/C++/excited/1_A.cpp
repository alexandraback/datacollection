#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<list>
#include<climits>

using namespace std;	


#define PB push_back
#define X first
#define Y second
#define MOD 1000000009
#define MAX 100000
#define getcx getchar_unlocked


inline void inp( int &n )//fast input function
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
int rem_x,cont[105][105],n;
char a[105][105];
bool is_valid()
{
	char red[105][105];
	for(int i=0;i<n;i++)
	{
		int j=0,pos=0,x=0;
		while(a[i][j])
		{
			char c=a[i][j];
			int cc=0;
			red[i][pos++]=c;
			while(a[i][j] && a[i][j]==c)
			{
				cc++;
				j++;
			}
			cont[i][x++]=cc;
		}
		rem_x=x;
		red[i][pos]=0;
	}
	for(int i=1;i<n;i++)
		if(strcmp(red[0],red[i])!=0)
			return false;
	return true;
}
			
int main()
{
	int t,p=1;
	inp(t);
	while(t--)
	{
		inp(n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",a[i]);
//			for(int j=0;a[i][j];j++)
				//hash[i][a[j]-'a']++;
		}
		//for(int i=0;
		int final_ans=0;
		printf("Case #%d: ",p++);
		if(!is_valid())
		{
			printf("Fegla Won\n");
			continue;
		}
		for(int i=0;i<rem_x;i++)
		{
			int m=-1,ans=0;
			for(int j=0;j<n;j++)
				m=max(m,cont[j][i]);
			int minim=INT_MAX;
			for(int j=1;j<=m;j++)
			{
				
				ans=0;
				for(int k=0;k<n;k++)
					ans+=abs(j-cont[k][i]);
				minim=min(ans,minim);
			}
			final_ans+=minim;
		}
		printf("%d\n",final_ans);
	}
	return 0;
}	
