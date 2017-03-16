#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream cin("in.txt");
	ofstream cout("outlong.txt");
	int t,n;
	char str[110][110];
	int arr[110][110];
	int arr1[110];
	cin>>t;
	int cas=1;
	while(cas<=t)
	{
		cin>>n;
		for (int i=0;i<n;i++)
		{
			cin>>str[i];
		}
		for (int i=0;i<n;i++)
		{
			int l=strlen(str[i]);
			int k=0;
			for (int j=0;j<l;j++)
			{
				int count=1;
				while(j<l-1&&str[i][j]==str[i][j+1])
				{
					count++;
					j++;
				}
				arr[i][k++]=count;
			}
			k=0;
			for (int j=0;j<l;j++)
			{
				while(j<l-1&&str[i][j]==str[i][j+1])
				{
					j++;
				}
				str[i][k++]=str[i][j];
			}
			str[i][k]='\0';
		}
		int flag=0;
		for(int i=1;i<n;i++)
		{
			int l0=strlen(str[i-1]);
			int l=strlen(str[i]);
			if(l!=l0)
			{
				flag=1;
				break;
			}
			for (int j=0;j<l;j++)
			{
				if(str[i][j]!=str[i-1][j])
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		int l=strlen(str[0]);
		if(flag==1)
		{
			cout<<"Case #"<<cas<<": Fegla Won\n";
		}
		else
		{
			int count=0;
			for (int i=0;i<l;i++)
			{
				int sum=0;
				for (int j=0;j<n;j++)
				{
					arr1[j]=arr[j][i];
				}
				sort(arr1,arr1+n);
				int x=arr1[n/2];
				for (int j=0;j<n;j++)
					sum+=abs(x-arr1[j]);
				if(n%2==0)
				{
					x=arr1[n/2+1];
					int s=0;
					for (int j=0;j<n;j++)
						s+=abs(x-arr1[j]);	
					sum=min(s,sum);
				}
				count+=sum;
			}
			cout<<"Case #"<<cas<<": "<<count<<"\n";
		}
		cas++;
	}
	return 0;
}

