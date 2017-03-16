#include <bits/stdc++.h>
#define ll long long int

using namespace std;

priority_queue< pair<int, int> > pq;
pair<int, int> a,b;

int main()
{
	ios_base::sync_with_stdio(false);
	int t,p,n,sum;
	cin>>t;
	for(int loop=1;loop<=t;loop++)
	{
		cin>>n;
		sum=0;
		cout<<"Case #"<<loop<<":";
		while(!pq.empty())
			pq.pop();
		for(int i=0;i<n;i++)
		{
			cin>>p;
			sum += p;
			pq.push(make_pair(p,i));
		}
		while(pq.top().first)
		{
			a=pq.top();
			pq.pop();
			b=pq.top();
			pq.pop();
			if(a.first == 1 && sum%2)
			{
				a.first--;
				sum--;
				cout<<" "<<(char)(a.second+65);
			}
			else if(a.first == b.first)
			{
				a.first--;
				b.first--;
				sum-=2;
				cout<<" "<<(char)(a.second+65)<<(char)(b.second+65);
			}
			else if(a.first == 1 || a.first-b.first == 1)
			{
				a.first--;
				sum--;
				cout<<" "<<(char)(a.second+65);
			}
			else
			{
				a.first-=2;
				sum-=2;
				cout<<" "<<(char)(a.second+65)<<(char)(a.second+65);
			}	
			pq.push(a);
			pq.push(b);
		}
		cout<<"\n";	
	}
	return 0;
}