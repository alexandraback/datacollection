#include<bits/stdc++.h>
using namespace std;

ifstream goo;
ofstream gle;

typedef pair<int,int> par;

void solve()
{
	priority_queue<par,vector<par>, less<par> > q;
	int n,a,b;
	char c,c1;
	par p,o;
	goo>>n;
	for(int i=1; i<=n; i++)
	{
		goo>>a;
		q.push(par(a,i));
	}
	while(!q.empty())
	{
		if(q.size()==2)
		{
			p=q.top();
			q.pop();
			o=q.top();
			q.pop();
			a=p.second;
			b=o.second;
			c=a+64;
			c1=b+64;
			for(int i=1; i<=p.first; i++) gle<<c<<c1<<" ";
			break;
		}
		p=q.top();
		q.pop();
		a=p.second;
		c=a+64;
		gle<<c<<" ";
		b=p.first-1;
		if(b>0) q.push(par(b,a));
	}
	gle<<"\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//goo.open("C:\\Users\\Mateusz\\Desktop\\goo.in");
	goo.open("C:\\Users\\Mateusz\\Downloads\\A-large (3).in");
	gle.open("C:\\Users\\Mateusz\\Desktop\\gle.out");
	int t;
	goo>>t;
	for(int i=1; i<=t; i++)
	{
		gle<<"Case #"<<i<<": ";
		solve();
	}
	goo.close();
	gle.close();
	return 0;
}
