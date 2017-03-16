#include<bits/stdc++.h>

using namespace std;

int checkMajority(int *a,int n)
{
	int i,max=0,total=a[0];
	for(i=1;i<n;++i)
	{
		if(a[max]<a[i])
			max=i;
		total+=a[i];
	}

	if(a[max]*2 > total)
		return -1;

	return max;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,i,j,itr=1,n,count,total;
	cin>>t;
	while(t-- >0)
	{
		cin>>n;
		int arr[n],temp;
		count=total=0;
		for(i=0;i<n;++i)
		{
			cin>>arr[i];
			temp=arr[i];
			if(temp!=0)
				++count;
			total+=temp;
		}
		cout<<"Case #"<<itr++<<": ";
		while(total>0)
		{
				int max=0,max2;
			for(i=1;i<n;++i)
			{
				if(arr[max]<arr[i])
					max=i;
			}
			arr[max]--;
			--total;
				max2=0;
				for(i=1;i<n;++i)
				{
					if(arr[max2]<arr[i])
						max2=i;
				}
				arr[max2]--;
				--total;
				if(checkMajority(arr,n)!=-1)
				{
					cout<<(char)(65+max)<<(char)(65+max2);
				}
				else
				{
					++arr[max2];
					++total;
					cout<<(char)(65+max);
				}

				cout<<" ";
		}
		cout<<endl;

	}
}
