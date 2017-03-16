/* user :saurabh3240
    contest : round 1
    problem:  A
    platform :Codeam
    date: 16-04-2016
*/
 
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>
 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
 
#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)
 
#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)
 
#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0
 
#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)
 
#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) printf("%lld ",x)
#define pln(x) printf("%lld\n",x)
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")
 
#define fs first
#define sc second
#define ll long long
#define pb push_back
#define MOD 1000000007
#define limit 10000005
using namespace std;

#define ll long long 
#define MOD 1000000007
#define MAXN 108


int main()
{
	
	int t;
	gi(t);
	int z=1;
	while(t--)
	{
		int n;
		gi(n);
		int arr[n];
		priority_queue<pair<int,char> > pq;
		rep(i,n)
		{
			gi(arr[i]);
			pq.push(make_pair (arr[i],'A'+i));
		}
		cout<<"Case #"<<z<<": ";
		while(!pq.empty())
		{
			pair<int,char> p = pq.top();
			int sz = pq.size();
			pq.pop();
			
			if(sz==2)
			{
				
				pair<int,char> q = pq.top();
				if(p.first==q.first)
				{
					pq.pop();
					cout<<p.sc<<q.sc<<" ";
					if(p.first>1)
					{
							q.first--;
					p.first--;
					pq.push(p);
					pq.push(q);
					}	
				
				}
				else
				{
					cout<<p.sc<<" ";
					if(p.first>1)
					{
						p.first--;
						pq.push(p);
					}	
				
				}	
				
			}
			else
			{
				cout<<p.sc<<" ";
				if(p.first>1)
				{
					p.first--;
					pq.push(p);
				}
			}
		}
		z++;
		cout<<endl;
	}
	return 0;
}
