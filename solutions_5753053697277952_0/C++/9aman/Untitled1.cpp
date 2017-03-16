#include<bits/stdc++.h>
#include<iostream>
#define mp make_pair
using namespace std;
int main()
{
	int t , n  , temp , p=0;
	freopen("A-small-attempt0.in" , "r",stdin);
	freopen("ut.out","w",stdout);
	cin>>t;
	while(t--)
	{
		p++;
		priority_queue<pair<int,char> >fi;
		cin>>n;
		for(int i =0 ;i<n;i++)
		{
			cin>>temp;
			fi.push(mp(temp , 'A'+i));
		}
		cout<<"Case #"<<p<<": ";
		pair<int,char>temp1 , temp2;
		while(!fi.empty() && fi.size() != 2)
		{
			temp1 = fi.top();
			fi.pop();
			cout<<temp1.second<<" ";
			if(temp1.first != 1)
				fi.push(mp(temp1.first-1 , temp1.second));
		}
		if(fi.size() == 2)
		{
			temp1 = fi.top();
			fi.pop();
			temp2 = fi.top();
			fi.pop();
			while(temp1.first > temp2.first)
			{
				cout<<temp1.second<<" ";
				temp1.first--;
			}
			while(temp1.first < temp2.first)
			{
				cout<<temp2.second<<" ";
				temp2.first--;
			}
			while(temp1.first != 0)
			{
				cout<<temp1.second<<temp2.second<<" ";
				temp1.first--;
			}
		}
		cout<<endl;
	}
}

