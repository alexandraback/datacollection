#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int> > >S;
pair<int,int>a,b;

int main()
{
	
	ifstream cin("1C1L.in");
	ofstream cout("1C1LA.txt");
	int i,j,k,l,m,n,ind=1,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		while(!S.empty())
		S.pop();
		for(i=0;i<n;i++)
		{
			cin>>j;
			S.push(make_pair(j,i));
		}
		cout<<"Case #"<<ind++<<": ";
		while(!S.empty())
		{
			
			a=S.top();
			S.pop();
			
			
			if(S.size()==1){
			b=S.top();
				if(a.first==b.first)
				{
					k=a.first;
					while(k--)
					cout<<char('A'+a.second)<<char('A'+b.second)<<" ";
						
						break;			
				
				}
				else
				{
					cout<<char('A'+a.second)<<" ";
					a.first--;
					S.push(a);
					
				}
			}
			else{
			cout<<char('A'+a.second)<<" ";
			a.first--;
			if(a.first>0)
			S.push(a);
			}
		}
		cout<<endl;
	}
	
	
	
}
