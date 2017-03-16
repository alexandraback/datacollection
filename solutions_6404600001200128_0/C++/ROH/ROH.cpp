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
//#define inf 1000000000


ll  gcd (ll a, ll b )
{
  ll c;
  while ( a != 0 ) {
     c = a;
	 a = b%a; 
	 b = c;
  }
  return b;
}
struct node
{
	ll val;
	ll index;
};
bool operator<(const struct node& a, const struct node &b)
{
	if(a.val!=b.val)
		return (a.val>b.val);
	return (a.index>b.index);
}
int a[10009];
int main()
{
	init;
	ifstream in("C:\\Users\\Ray\\Desktop\\google\\1\\A-small-attempt0.in");
	ofstream out("C:\\Users\\Ray\\Desktop\\google\\1\\1_ans.txt");
	in>>test;
	int b;
	k=0;
	while(test--)
	{
		//cout<<k<<endl;
		//cout<<((ll)1<<62)<<endl;
		in>>n;
		
		int diff=0;
		for(i=0;i<n;i++)
		{
			in>>a[i];
			
			
		}
		for(i=0;i<n-1;i++)
		{
			diff=max(a[i]-a[i+1],diff);
			
			
		}
		k++;
		int rate=0;
		if(diff%10>0)
			rate=(diff/10)+1;
		else rate=diff/10;
		int ans1=0,ans2=0;
		for(i=0;i<(n-1);i++)
		{
			j=a[i]-a[i+1];
			if(j>=0)
			{
				ans1+=j;
				if(a[i]>=diff)
					ans2+=diff;
				else ans2+=a[i];
			}
			else
			{
				ans1+=0;
				if(a[i]>=diff)
					ans2+=diff;
				else ans2+=a[i];
			}
			


		}
		out<<"Case #"<<k<<": "<<ans1<<" "<<ans2<<endl;



	}
	pause;
	
}