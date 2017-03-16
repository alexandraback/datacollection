/*krypto...............................jagsxi...!! */

#include<bits/stdc++.h>

using namespace std;
int main() {
freopen("lazy_sort.txt", "r", stdin);freopen("rsol1.txt", "w", stdout);
	// your code goes here
	long long int t,n;
	scanf("%lld",&t);
for(int kkk=1;kkk<=t;kkk++)	{
		scanf("%lld",&n);
		long long int arr[n];
		for(long long int i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		long long int start =arr[0],end=arr[0];
		long long int next_start=1,next_end=n-1,flag=0;
		while(next_start!=next_end)
		{
			if(arr[next_start]-start==-1)
			{
				start = arr[next_start];
				next_start++;
			}
			else if(arr[next_start]-end==1)
			{
				end = arr[next_start];
				next_start++;
			}
			else if(arr[next_end]-end==1)
			{
				end = arr[next_end];
				next_end--;
			}
			else if(arr[next_end]-start==-1)
			{
				start = arr[next_end];
				next_end--;
			}
			else 
			{
				flag++;break;
			}
		}
		start =arr[n-1],end=arr[n-1];
		next_start=0,next_end=n-2;
		while(next_start!=next_end)
		{
			if(arr[next_start]-start==-1)
			{
				start = arr[next_start];
				next_start++;
			}
			else if(arr[next_start]-end==1)
			{
				end = arr[next_start];
				next_start++;
			}
			else if(arr[next_end]-end==1)
			{
				end = arr[next_end];
				next_end--;
			}
			else if(arr[next_end]-start==-1)
			{
				start = arr[next_end];
				next_end--;
			}
			else 
			{
				flag++;break;
			}
		}
		if(flag<2)
			cout<<"Case #"<<kkk<<":"<<" yes"<<endl;
		else 			cout<<"Case #"<<kkk<<":"<<" no"<<endl;

	}
	return 0;
}
