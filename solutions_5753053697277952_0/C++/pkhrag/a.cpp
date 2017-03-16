#include <iostream>
#include <string>

using namespace std;

int find_max(int p[],int n)
{
	int x=p[0],po=0;
	for (int i = 0; i < n; i++)
	{
		if (x<p[i])
		{
			x=p[i];
			po=i;
		}
	}
	return po;
}

int main()
{
	int t;
	cin>>t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin>>n;
		int p[n];
		for (int j = 0; j < n; j++)
		{
			cin>>p[j];
		}
		int total=0;
		for (int j = 0; j < n; j++)
		{
			total+=p[j];
		}

		cout<<"Case #"<<i+1<<": ";
		int k;
		while(total>0)
		{
			string s;
			k=find_max(p,n);
			if(!p[k])
				break;
			s+='A'+k;
			p[k]--;
			total--;
			k=find_max(p,n);
			if(!p[k]){
				cout<<s<<' ';
				break;
			}
			p[k]--;
			total--;
			int k1=find_max(p,n);
			if (p[k1]>total/2)
			{
				p[k]++;
				total++;
			}
			else
				s+='A'+k;
			cout<<s<<' ';
		}
		cout<<endl;
	}
	return 0;
}