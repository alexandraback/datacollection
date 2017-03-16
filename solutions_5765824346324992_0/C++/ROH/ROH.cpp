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
#define init ll i,j,k,l,m,n,test
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
ll a[10009];
int main()
{
	init;
	ifstream in("C:\\Users\\Ray\\Desktop\\google\\2\\B-small-attempt3.in");
	ofstream out("C:\\Users\\Ray\\Desktop\\google\\2\\1_ans.txt");
	in>>test;
	int b;
	k=0;
	while(test--)
	{
		//cout<<k<<endl;
		//cout<<((ll)1<<62)<<endl;
		in>>b>>n;
		in>>a[0];
		l=a[0];
		for(i=1;i<b;i++)
		{
			in>>a[i];
			l=(l*a[i])/gcd(l,a[i]);
			
		}
		k++;
		ll cost;
		ll cuttings=0;
		for(i=0;i<b;i++)
		{
			cuttings+=(l/a[i]);
		}
		n=n%cuttings;
		if(n==0)
			n=cuttings;
		if(n<=b)
		{
			out<<"Case #"<<k<<": "<<n<<endl;
		}

		else
		{
			
			priority_queue<struct node> pq;
			struct node t;
			for(i=0;i<b;i++)
			{
				t.val=a[i];
				t.index=i+1;
				pq.push(t);
			}
			n-=b;

			while(true)
			{
				//remove the first
				struct node p=pq.top();
				pq.pop();
				n--;
				if(n==0)
				{
					out<<"Case #"<<k<<": "<<p.index<<endl;
					break;
				}
				else
				{
					p.val+=a[p.index-1];
					pq.push(p);
				}
			}

		}



	}
	pause;
	
}