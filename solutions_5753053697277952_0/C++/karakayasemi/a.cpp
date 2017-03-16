#include <iostream>
#include <cstdio>
using namespace std;

int member[26];
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cout<<"Case #"<<i+1<<":";
		int N;
		cin>>N;
		int total=0;
		for(int k=0;k<N;k++)
		{
			cin>>member[k];
			total=total+member[k];
		}
		int control=1;
		while(control)
		{
			control=0;
			int best=0;
			int index=-1;
			int index2=-1;
			int best2=0;
			for(int j=0;j<N;j++)
			{
				if(member[j]>best)
				{
					index=j;
					best=member[j];
					control=1;
					index2=-1;
					best2=0;
				}
				if(member[j]==best)
				{
					best2=best;
					index2=j;
				}
			}
			if(control!=0)
			{
				if(best2==0 || total==3)
				{
					member[index]--;
					total--;
					char a=65+index;
					cout<<' '<<a;
				}
				else
				{
					member[index]--;
					member[index2]--;
					total--;
					total--;
					char a=65;
					cout<<' '<<(char)(a+index)<<char(a+index2);
				}
			}
			if(total==2)
			{
				cout<<" ";
				for(int j=0;j<N;j++)
				{
					if(member[j]!=0)
						cout<<(char)(j+65);
				}
				break;
			}
		}
		cout<<endl;
	}
}