#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int arr[26];int n;
int f_max,s_max;
int f,s;

void find_arr()
{
	int max_so_far=0;
	int sec_max=0;
	for(int i=0;i<26;i++)
	{
		if(arr[i]>max_so_far)
		{
			//f_max=arr[i];
			max_so_far=arr[i];
			f=i;
		}
		else if(arr[i]>sec_max)
		{
			sec_max=arr[i];
			s=i;
		}
	}
	f_max=max_so_far;
	s_max=sec_max;
}

int main()
{
	int t;
	scanf("%d",&t);
	int case1=1;
	while(t--)
	{
		//int n;
		scanf("%d",&n);
		for(int i=0;i<26;i++)
		{
			arr[i]=0;
		}
		int total=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			total+=arr[i];
		}
		cout<<"Case #"<<case1<<": ";
		case1++;
		while(total!=0)
		{
			find_arr();
			cout<<(char)(f+65);
			arr[f]--;
			f_max--;
			total--;
			if(total==0)
				break;
			if(f_max < s_max)
			{
				f_max=s_max;
				f=s;
			}
			if(f_max > (total/2))
			{
				//cout<<(char)(f+65);
				cout<<(char)(f+65);
				arr[f]--;
				total--;
			}
			cout<<" ";
		}
		cout<<endl;
	}
}