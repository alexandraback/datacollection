#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <deque>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define y1 yy1

using namespace std;

int tt,t,n,i,mn,cur,j,ii,z,X;
bool can_divide,flag,bit[50];
ll a,b,c,z1,x[50],y[50];

void divide(int x)
{
	for (int i=1; i<=n; i++)
	{
		bit[i]=x%2;
		x>>=1;
	}
	return;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>t;
	for (tt=1; tt<=t; tt++)
	{
		cin>>n;
		for (i=1; i<=n; i++)
			cin>>x[i]>>y[i];
		
		cout<<"Case #"<<tt<<":"<<endl;
		for (i=1; i<=n; i++)
		{
			mn=(int)2e9;
			for (X=0; X<(1<<n); X++)
			{
			 	divide(X);
			 	if (!bit[i]) continue;
			 	cur=0;
			 	for (j=1; j<=n; j++)
			 		cur+=(1-bit[j]);
			 	can_divide=false;
			 	for (j=1; j<=n; j++)
			 	{
			 		if (i==j || (!bit[j])) continue;
			 		flag=true;
			 		a=y[i]-y[j];
			 		b=x[j]-x[i];
			 		c=x[i]*y[j]-x[j]*y[i];
			 		z=0;
			 		for (ii=1; ii<=n; ii++)
			 		{
			 			if (!bit[ii]) continue;
			 			z1=a*x[ii]+b*y[ii]+c;
			 			if (z!=0)
			 			{
			 				if ((z1<0 && z>0) || (z1>0 && z<0))
			 				{
			 					flag=false;
			 					break;
			 				}
			 			}
			 			else
			 			{
			 				if (z1<0) z=-1;
			 				if (z1>0) z=1;
			 			}
			 		}
			 		if (flag)
			 		{
			 			can_divide=true;
			 			break;
			 		}
			 	}
			 	if (can_divide)
			 		mn=min(mn,cur);
			}
			cout<<((mn==(int)2e9)? 0 : mn)<<endl;
		}
	}
	return 0;
}


